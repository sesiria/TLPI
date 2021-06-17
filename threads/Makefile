INCLUDE=../lib
LIBSRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC} -ltlpi  -lpthread
CFLAGS = -I ${INCLUDE}
TARGET=simple_thread detached_attrib thread_incr prod_no_condvar prod_condvar thread_multijoin strerror_test strerror_test_tsd strerror_test_tls \
	   thread_cancel thread_cleanup
OBJ=simple_thread.o detached_attrib.o thread_incr.o prod_no_condvar.o prod_condvar.o thread_multijoin.o strerror_test.o strerror.o strerror_tsd.o strerror_tls.o \
    thread_cancel.o thread_cleanup.o
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

prod_no_condvar:prod_no_condvar.o ${LIB}
	${CC} prod_no_condvar.o ${CPPFLAGS} -o $@

prod_condvar:prod_condvar.o ${LIB}
	${CC} prod_condvar.o ${CPPFLAGS} -o $@

thread_multijoin:thread_multijoin.o ${LIB}
	${CC} thread_multijoin.o ${CPPFLAGS} -o $@

strerror_test:strerror_test.o strerror.o ${LIB}
	${CC} strerror_test.o strerror.o ${CPPFLAGS} -o $@

strerror_test_tsd:strerror_test.o strerror_tsd.o ${LIB}
	${CC} strerror_test.o strerror_tsd.o ${CPPFLAGS} -o $@

strerror_test_tls:strerror_test.o strerror_tls.o ${LIB}
	${CC} strerror_test.o strerror_tls.o ${CPPFLAGS} -o $@

thread_cancel:thread_cancel.o ${LIB}
	${CC} thread_cancel.o ${CPPFLAGS} -o $@

thread_cleanup:thread_cleanup.o ${LIB}
	${CC} thread_cleanup.o ${CPPFLAGS} -o $@
clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
