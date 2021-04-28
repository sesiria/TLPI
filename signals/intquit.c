#include <signal.h>
#include "tlpi_hdr.h"

static void
sigHandler(int sig)
{
    static int count = 0;

    if(sig == SIGINT) {
        count++;
        printf("Caught SIGINT (%d)\n", count);
        return;                 /* Resume execution at point of interruption */
    }

    /* Must be SIGQUIT - print a message and terminate the process */
    printf("Caught SIGQUIT - that's all folks!\n");
    exit(EXIT_SUCCESS);
}

int main(int artc, char*argv[]) 
{
    /* Establish same handler for SIGINT and SIGQUIT */
    if(signal(SIGINT, sigHandler) == SIG_ERR)
        errExit("signal");
    if(signal(SIGQUIT, sigHandler) == SIG_ERR)
        errExit("signal");
    
    for(;;)
        pause();
}