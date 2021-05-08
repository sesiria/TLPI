INCLUDE=../lib
LIBSRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC} -ltlpi
CFLAGS = -I ${INCLUDE}
TARGET=ouch intquit t_kill sig_sender sig_receiver nonreentrant sigmask_longjmp sigmask_siglongjmp t_sigaltstack t_sigqueue catch_rtsigs t_sigsuspend t_sigwaitinfo signalfd_sigval
OBJ=ouch.o intquit.o t_kill.o sig_sender.o sig_receiver.o signal_functions.o nonreentrant.o sigmask_longjmp.o sigmask_siglongjmp.o t_sigaltstack.o t_sigqueue.o catch_rtsigs.o t_sigsuspend.o t_sigwaitinfo.o signalfd_sigval.o
LIB=${LIBSRC}/libtlpi.a
LIBOBJ=${LIBSRC}/error_functions.o ${LIBSRC}/get_num.o

all:${LIB} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

ouch:ouch.o ${LIB}
	${CC} ouch.o ${CPPFLAGS} -o $@

intquit:intquit.o ${LIB}
	${CC} intquit.o ${CPPFLAGS} -o $@

t_kill:t_kill.o ${LIB}
	${CC} t_kill.o ${CPPFLAGS} -o $@

sig_sender:sig_sender.o ${LIB}
	${CC} sig_sender.o ${CPPFLAGS} -o $@

sig_receiver:sig_receiver.o signal_functions.o ${LIB}
	${CC} sig_receiver.o signal_functions.o ${CPPFLAGS} -o $@

nonreentrant:nonreentrant.o ${LIB}
	${CC} nonreentrant.o ${CPPFLAGS} -lcrypt -o $@

sigmask_siglongjmp.o : sigmask_longjmp.c
	${CC} -o $@ -DUSE_SIGSETJMP -c sigmask_longjmp.c ${CFLAGS}

sigmask_longjmp:sigmask_longjmp.o signal_functions.o ${LIB}
	${CC} sigmask_longjmp.o signal_functions.o ${CPPFLAGS} -o $@

sigmask_siglongjmp:sigmask_siglongjmp.o signal_functions.o ${LIB}
	${CC} sigmask_siglongjmp.o signal_functions.o ${CPPFLAGS} -o $@

t_sigaltstack:t_sigaltstack.o ${LIB}
	${CC} t_sigaltstack.o ${CPPFLAGS} -o $@

t_sigqueue:t_sigqueue.o ${LIB}
	${CC} t_sigqueue.o ${CPPFLAGS} -o $@

catch_rtsigs:catch_rtsigs.o ${LIB}
	${CC} catch_rtsigs.o ${CPPFLAGS} -o $@

t_sigsuspend:t_sigsuspend.o signal_functions.o ${LIB}
	${CC} t_sigsuspend.o signal_functions.o ${CPPFLAGS} -o $@

t_sigwaitinfo:t_sigwaitinfo.o ${LIB}
	${CC} t_sigwaitinfo.o ${CPPFLAGS} -o $@

signalfd_sigval:signalfd_sigval.o ${LIB}
	${CC} signalfd_sigval.o ${CPPFLAGS} -o $@

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
