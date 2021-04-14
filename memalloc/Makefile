INCLUDE=../lib
SRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${SRC} -ltlpi -lpthread
CFLAGS = -I ${INCLUDE}
TARGET=free_and_sbrk
LIB=${SRC}/libtlpi.a
OBJ=free_and_sbrk.o
LIBOBJ=${SRC}/error_functions.o ${SRC}/get_num.o


all:${LIB} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

free_and_sbrk:free_and_sbrk.o ${LIB}
	${CC}  $^ ${CPPFLAGS} -o $@

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
