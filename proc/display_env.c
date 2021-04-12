#include "tlpi_hdr.h"

extern char **environ;          /* The global environment list variabled defined in errno.h */

int
main(int argc, char *argv[])
{
    char **ep;

    for(ep = environ; *ep != NULL; ep++)
        puts(*ep);
    exit(EXIT_SUCCESS);
}