/* 
* Modifying process scheduling policies and priorities
* file: sched_set.c
* author: sesiria  2021-06-21
* copyright : from the text The linux programming interface
* issue when return EPERM
* https://www.jianshu.com/p/2db1c9948ab2
* https://elkpi.com/topics/2017/11/centos7-docker-sched_rr-operation_not_permitted.html
* #>echo 950000 > /sys/fs/cgroup/cpu/user.slice/cpu.rt_runtime_us
*/

#include <sched.h>
#include "tlpi_hdr.h"

int main(int argc, char * argv[])
{
    int j, pol;
    struct sched_param sp;

    if(argc < 3 || strchr("rfobi", argv[1][0]) == NULL)
        usageErr("%s policy priority [pid...]\n"
                "    policy is 'r' (RR), 'f' (FIFO), "
#ifdef SCHED_BATCH              /* Linux-specific */
                "'b' (BATCH), "
#endif
#ifdef SCHED_IDLE               /* Linux-specific */
                "'i' (IDLE), "
#endif
                "or 'o' (OTHER)\n",
                argv[0]);
    
    pol = (argv[1][0] == 'r') ? SCHED_RR :
                (argv[1][0] == 'f') ? SCHED_FIFO :
#ifdef SCHED_BATCH
                (argv[1][0] == 'b') ? SCHED_BATCH :
#endif
#ifdef SCHED_IDLE
                (argv[1][0] == 'i') ? SCHED_IDLE :
#endif
                SCHED_OTHER;
    
    sp.sched_priority = getInt(argv[2], 0, "priority");
    for(j = 3; j < argc; j++)
        if(sched_setscheduler(getLong(argv[j], 0, "pid"), pol, &sp) == -1)
            errExit("sched_setscheduler");

    exit(EXIT_SUCCESS);
}