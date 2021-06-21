/* 
* Retrieving process scheduling plicies and priorities
* file: sched_view.c
* author: sesiria  2021-06-21
* copyright : from the text The linux programming interface 
*/
#include <sched.h>
#include "tlpi_hdr.h"

int main(int argc, char * argv[])
{
    int j, pol;
    struct sched_param sp;

    for(j = 1; j < argc; j++) {
        pol = sched_getscheduler(getLong(argv[j], 0, "pid"));
        if(pol == -1)
            errExit("sched_getscheduler");
        
        if(sched_getparam(getLong(argv[j], 0, "pid"), &sp) == -1)
            errExit("sched_getparam");
        
        printf("%s: %-5s %2d\n", argv[j],
                (pol == SCHED_OTHER) ? "OTHER" :
                (pol == SCHED_RR) ? "RR" :
                (pol == SCHED_FIFO) ? "FIFO" :
#ifdef SCHED_BATCH              /* Linux-specific */
                (pol == SCHED_BATCH) ? "BATCH" :
#endif
#ifdef SCHED_IDLE               /* Linux-specific */
                (pol == SCHED_IDLE) ? "IDLE" :
#endif
                "???", sp.sched_priority);
    }
    
    exit(EXIT_SUCCESS);
}