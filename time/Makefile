INCLUDE=../lib
LIBSRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC} -ltlpi
CFLAGS = -I ${INCLUDE}
TARGET=calendar_time
OBJ=calendar_time.o
LIB=${LIBSRC}/libtlpi.a
LIBOBJ=${LIBSRC}/error_functions.o ${LIBSRC}/get_num.o



all:${LIB} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^


calendar_time:calendar_time.o ${LIB}
	${CC} calendar_time.o ${CPPFLAGS} -o $@

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
