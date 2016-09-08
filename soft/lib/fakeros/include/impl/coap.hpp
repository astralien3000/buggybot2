/*
 * Copyright (C) 2015 Kaspar Schleiser <kaspar@schleiser.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include <coap.h>
#include <string.h>

#define COAP_MAX_ENDPOINTS (50)

#define MAX_RESPONSE_LEN 500
static uint8_t response[MAX_RESPONSE_LEN] = { 0 };

static int handle_get_well_known_core(coap_rw_buffer_t *scratch,
                                      const coap_packet_t *inpkt,
                                      coap_packet_t *outpkt,
                                      uint8_t id_hi, uint8_t id_lo);

coap_endpoint_path_t endpoint_paths[COAP_MAX_ENDPOINTS] = {
  { 2, { ".well-known", "core" } },
  {0, {0} }
};

coap_endpoint_t endpoints[COAP_MAX_ENDPOINTS] =
{
    { COAP_METHOD_GET,	handle_get_well_known_core,
        &endpoint_paths[0], "ct=40" },
    { (coap_method_t)0, NULL, NULL, NULL }
};

static int handle_get_well_known_core(coap_rw_buffer_t *scratch,
        const coap_packet_t *inpkt, coap_packet_t *outpkt,
        uint8_t id_hi, uint8_t id_lo)
{
    char *rsp = (char *)response;
    /* resetting the content of response message */
    memset(response, 0, sizeof(response));
    int len = sizeof(response);
    const coap_endpoint_t *ep = endpoints;
    int i;

    len--; // Null-terminated string

    while (NULL != ep->handler) {
        if (NULL == ep->core_attr) {
            ep++;
            continue;
        }

        if (0 < strlen(rsp)) {
            strncat(rsp, ",", len);
            len--;
        }

        strncat(rsp, "<", len);
        len--;

        for (i = 0; i < ep->path->count; i++) {
            strncat(rsp, "/", len);
            len--;

            strncat(rsp, ep->path->elems[i], len);
            len -= strlen(ep->path->elems[i]);
        }

        strncat(rsp, ">;", len);
        len -= 2;

        strncat(rsp, ep->core_attr, len);
        len -= strlen(ep->core_attr);

        ep++;
    }

    return coap_make_response(scratch, outpkt, (const uint8_t *)rsp,
                              strlen(rsp), id_hi, id_lo, &inpkt->tok,
                              COAP_RSPCODE_CONTENT,
                              COAP_CONTENTTYPE_APPLICATION_LINKFORMAT);
}

int handle_hello(coap_rw_buffer_t *scratch,
        const coap_packet_t *inpkt, coap_packet_t *outpkt,
        uint8_t id_hi, uint8_t id_lo)
{
    const char *riot_name = "Hello World !";
    int len = strlen(riot_name);

    memcpy(response, riot_name, len);

    return coap_make_response(scratch, outpkt, (const uint8_t *)response, len,
                              id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT,
                              COAP_CONTENTTYPE_TEXT_PLAIN);
}

coap_endpoint_t* coap_get_endpoint_sentinel(void) {
  for(int i = 0 ; i < COAP_MAX_ENDPOINTS ; i++) {
    if(endpoints[i].method == 0) {
      return &endpoints[i];
    }
  }
  return NULL;
}

void coap_add_endpoint(const char* path, coap_method_t method, coap_endpoint_func func) {
  coap_endpoint_t* endpoint = coap_get_endpoint_sentinel();
  (endpoint+1)->method = (coap_method_t)0;

  endpoint->method = method;
  endpoint->handler = func;
  endpoint->core_attr = "ct=0";

  coap_endpoint_path_t* ep = (coap_endpoint_path_t*)malloc(sizeof(coap_endpoint_path_t));
  ep->count = 0;
  
  uint32_t slash_pos = 0;
  for(uint32_t i = 0 ; i < strlen(path) ; i++) {
    if(path[i] == '/') {
      char* e = (char*)malloc(sizeof(char) * (i+1));
      memcpy(e, path, i);
      e[i] = '\0';
      slash_pos = i+1;
      ep->elems[ep->count] = e;
      ep->count++;
    }
  }
  char* e = (char*)malloc(sizeof(char) * strlen(path)-slash_pos);
  memcpy(e, path+slash_pos, strlen(path)-slash_pos);
  e[strlen(path)-slash_pos] = '\0';
  ep->elems[ep->count] = e;
  ep->count++;

  endpoint->path = ep;
}
