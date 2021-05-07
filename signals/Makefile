INCLUDE=../lib
LIBSRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC} -ltlpi
CFLAGS = -I ${INCLUDE}
TARGET=ouch intquit t_kill sig_sender sig_receiver
OBJ=ouch.o intquit.o t_kill.o sig_sender.o sig_receiver.o signal_functions.o
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

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
