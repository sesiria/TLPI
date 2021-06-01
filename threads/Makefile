INCLUDE=../lib
LIBSRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC} -ltlpi  -lpthread
CFLAGS = -I ${INCLUDE}
TARGET=simple_thread detached_attrib thread_incr
OBJ=simple_thread.o detached_attrib.o thread_incr.o
LIB=${LIBSRC}/libtlpi.a
LIBOBJ=${LIBSRC}/error_functions.o ${LIBSRC}/get_num.o



all:${LIB} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

simple_thread:simple_thread.o ${LIB}
	${CC} simple_thread.o ${CPPFLAGS} -o $@

detached_attrib:detached_attrib.o ${LIB}
	${CC} detached_attrib.o ${CPPFLAGS} -o $@

thread_incr:thread_incr.o ${LIB}
	${CC} thread_incr.o ${CPPFLAGS} -o $@

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
