#include <stdio.h>
#include <msg.h>
#include <xtimer.h>

extern void view_loop(void);
extern void control_loop(void);
extern void alive_loop(void);

extern "C" int _netif_config(int argc, char **argv);

char view_stack [THREAD_STACKSIZE_MAIN];

void* view_thread(void*) {
  view_loop();
  return NULL;
}

char alive_stack [THREAD_STACKSIZE_MAIN];

void* alive_thread(void*) {
  alive_loop();
  return NULL;
}

int main(void)
{
    puts("Buggybot embed-io application");

    puts("Waiting for address autoconfiguration...");
    xtimer_sleep(3);

    puts("Configured network interfaces:");
    _netif_config(0, NULL);

    thread_create(view_stack, sizeof(view_stack), 0, THREAD_CREATE_WOUT_YIELD, view_thread, NULL, "view thread");
    thread_create(alive_stack, sizeof(alive_stack), 0, THREAD_CREATE_WOUT_YIELD, alive_thread, NULL, "alive thread");

    control_loop();

    return 0;
}
