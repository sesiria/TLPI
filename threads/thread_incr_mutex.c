#include <pthread.h>
#include "tlpi_hdr.h"

static volatile int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void *                       /* Loop 'arg' times incrementing 'glob' */
threadFunc(void * arg) {
    int loops = *((int *) arg);
    int loc, j, s;
    for(j = 0; j < loops; j++) {
        s = pthread_mutex_lock(&mtx);
        if(s != 0)
            errExitEN(s, "pthread_mutex_lock");
        loc = glob;
        loc++;
        glob = loc;
        
        s = pthread_mutex_unlock(&mtx);
        if(s != 0)
            errExitEN(s, "pthread_mutex_unlock");
    }
    return NULL;
}

int main(int argc, char * argv[])
{
    pthread_t t1, t2;
    int loops, s;

    loops = (argc > 1) ? getInt(argv[1], GN_GT_0, "num-loops") : 10000000;

    s = pthread_create(&t1, NULL, theadFunc, &loops);
    if(s != 0)
        errExitEN(s, "pthread_create");
    s = pthread_create(&t2, NULL, threadFunc, &loops);
    if(s != 0)
        errExitEN(s, "pthread_create");
}