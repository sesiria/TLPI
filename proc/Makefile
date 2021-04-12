INCLUDE=../lib
SRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${SRC} -ltlpi -lpthread
CFLAGS = -I ${INCLUDE}
TARGET=mem_segments necho
LIB=${SRC}/libtlpi.a
OBJ=mem_segments.o necho.o
LIBOBJ=${SRC}/error_functions.o ${SRC}/get_num.o


all:${LIB} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

mem_segments:mem_segments.o ${LIB}
	${CC}  $^ ${CPPFLAGS} -o $@

necho:necho.o ${LIB}
	${CC}  $^ ${CPPFLAGS} -o $@
clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
