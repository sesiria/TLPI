INCLUDE=../lib
INCLUDE1=../time
LIBSRC=../lib
LIBSRC1=../time
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC} -ltlpi
CPPFLAGS1 = -Wall -std=gnu99 -L ${LIBSRC} -L ${LIBSRC1} -ltlpi -lcurr_time -lrt
CFLAGS = -I ${INCLUDE} -I ${INCLUDE1}
TARGET=real_timer timed_read t_nanosleep ptmr_sigev_signal ptmr_sigev_thread demo_timerfd
OBJ=real_timer.o timed_read.o t_nanosleep.o ptmr_sigev_signal.o itimerspec_from_str.o ptmr_sigev_thread.o demo_timerfd.o
LIB=${LIBSRC}/libtlpi.a
LIB1=${LIBSRC1}/libcurr_time.a
LIBOBJ=${LIBSRC}/error_functions.o ${LIBSRC}/get_num.o
LIBOBJ1=${LIBSRC1}/curr_time.o 

all:${LIB} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

${LIB1}:${LIBOBJ1}
	${AR} -rcs $@ $^

real_timer:real_timer.o ${LIB}
	${CC} real_timer.o ${CPPFLAGS} -o $@

timed_read:timed_read.o ${LIB}
	${CC} timed_read.o ${CPPFLAGS} -o $@

t_nanosleep:t_nanosleep.o ${LIB}
	${CC} t_nanosleep.o ${CPPFLAGS} -o $@

ptmr_sigev_signal:ptmr_sigev_signal.o itimerspec_from_str.o ${LIB} ${LIB1}
	${CC} ptmr_sigev_signal.o itimerspec_from_str.o ${CPPFLAGS1} -o $@

ptmr_sigev_thread:ptmr_sigev_thread.o itimerspec_from_str.o ${LIB} ${LIB1}
	${CC} ptmr_sigev_thread.o itimerspec_from_str.o ${CPPFLAGS1} -o $@

demo_timerfd:demo_timerfd.o itimerspec_from_str.o ${LIB}
	${CC} demo_timerfd.o itimerspec_from_str.o ${CPPFLAGS} -lrt -o $@

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIB1} ${LIBOBJ} ${LIBOBJ1}
