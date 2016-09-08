#include "microcoap_conn.hpp"
#include "coap.hpp"

#include <fakeros/fakeros.hpp>

#include <thread.h>
#include <msg.h>
#include <xtimer.h>

#define MAIN_MSG_QUEUE_SIZE (8)

char ros_thread_stack[THREAD_STACKSIZE_MAIN];
msg_t main_msg_queue[MAIN_MSG_QUEUE_SIZE];

extern "C" int _netif_config(int argc, char** argv);

void* ros_thread_func(void*) {
  printf("ROS Thread !\n");
  msg_init_queue(main_msg_queue, MAIN_MSG_QUEUE_SIZE);

  puts("Waiting for address autoconf...");
  xtimer_sleep(3);

  puts("configured interfaces : ");
  _netif_config(0, NULL);

  coap_add_endpoint("test/lool", COAP_METHOD_GET, handle_hello);
  coap_add_endpoint("test/miew", COAP_METHOD_GET, handle_hello);
  coap_add_endpoint("test/test", COAP_METHOD_GET, handle_hello);
  coap_add_endpoint("test/erf", COAP_METHOD_GET, handle_hello);

  microcoap_server_loop();    
  return NULL;
}

void ros::init(int&, char**, const std::string&) {
  thread_create(ros_thread_stack, sizeof(ros_thread_stack), 0,
		THREAD_CREATE_WOUT_YIELD,
		ros_thread_func, NULL, "ROS thread");
}

void ros::Rate::sleep(void) {
  thread_sleep();
}
