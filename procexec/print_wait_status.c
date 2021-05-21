#define _GNU_SOURCE                 /* Get strsignal() declaration from <string.h>*/
#include <string.h>
#include <sys/wait.h>
#include "print_wait_status.h"      /* Declaration of printWaitStatus() */
#include "tlpi_hdr.h"

void
printWaitStatus(const char * msg, int status)
{
    if(msg != NULL)
        printf("%s", msg);
    
    if(WIFEXITED(status)) {
        printf("child exited, status = %d\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("child killed by signal %d (%s)",
                WTERMSIG(status), strsignal(WTERMSIG(status)));
#ifdef WCOREDUMP            /* Not in SUSv3, may be absent on some systems */
        if (WCOREDUMP(status))
            printf(" (core dumped)");
#endif
        printf("\n");
    } else if (WIFSTOPPED(status)) {
        printf("child stopped by signal %d (%s)\n",
            WSTOPSIG(status), strsignal(WSTOPSIG(status)));
#ifdef WIFCONTINUED         /* SUSv3 has this , but for older Linux versions and
                               some other UNIX implementations don't */
    } else if (WIFCONTINUED(status)) {
        printf("child continued\n");
#endif
    } else {                /* Should never happen */
        printf("whathappened to this child? (status = %x)\n",
                (unsigned int)status);
    }
}