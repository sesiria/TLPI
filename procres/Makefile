INCLUDE=../lib
LIBSRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC} -ltlpi
CFLAGS = -I ${INCLUDE}
TARGET= rlimit_nproc
OBJ= rlimit_nproc.o print_rlimit.o
LIB=${LIBSRC}/libtlpi.a 
LIBOBJ=${LIBSRC}/error_functions.o ${LIBSRC}/get_num.o



all:${LIB} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

rlimit_nproc:rlimit_nproc.o print_rlimit.o ${LIB}
	${CC} rlimit_nproc.o print_rlimit.o ${CPPFLAGS} -o $@

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
