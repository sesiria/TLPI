#define _XOPEN_SOURCE
#include <time.h>
#include <locale.h>
#include "tlpi_hdr.h"

#define SBUF_SIZE 1000

int main(int argc, char*argv[])
{
    struct tm tm;
    char sbuf[SBUF_SIZE];
    char *ofmt;

    if(argc < 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s input-date-time in-format [out-format]\n", argv[0]);
    
    if(setlocale(LC_ALL, "") == NULL)
        errExit("setlocale");       /* Use locale settings in conversions */

    memset(&tm, 0, sizeof(struct tm));          /* Initialize 'tm' */
    if(strptime(argv[1], argv[2], &tm) == NULL)
        fatal("strptime");
    
    tm.tm_isdst = -1;               /* Not set by strptime(); tells mktime()
                                       to determine if DST is in effect */
    printf("calendar time (seconds since Epoch): %ld\n", (long)mktime(&tm));

    ofmt = (argc > 3) ? argv[3] : "%H:%M:%s %A, %d %B %Y %z";
    if (strftime(sbuf, SBUF_SIZE, ofmt, &tm) == 0)
        fatal("strftime returned 0");
    printf("strftime() yields: %s\n", sbuf);
    
    exit(EXIT_SUCCESS);
}