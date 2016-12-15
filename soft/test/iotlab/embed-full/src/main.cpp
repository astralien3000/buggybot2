#include <stdio.h>
#include <msg.h>
#include <xtimer.h>

void microcoap_server_loop(void);

extern "C" int _netif_config(int argc, char **argv);

int main(void)
{
    puts("Buggybot embed-io application");

    puts("Waiting for address autoconfiguration...");
    xtimer_sleep(3);

    puts("Configured network interfaces:");
    _netif_config(0, NULL);

    microcoap_server_loop();

    return 0;
}
