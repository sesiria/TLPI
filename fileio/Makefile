INCLUDE=../lib
SRC=../lib
CC=gcc
CPPFLAGS = -Wall -std=gnu99
CFLAGS = -I ${INCLUDE}
TARGET=copy seek_io
OBJ=copy.o seek_io.o ${SRC}/error_functions.o ${SRC}/get_num.o
 
${OBJ}:%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

all:${TARGET}

copy:${filter-out seek_io.o,${OBJ}}
	${CC} ${CPPFLAGS} -o $@ $^
seek_io:${filter-out copy.o,${OBJ}}
	${CC} ${CPPFLAGS} -o $@ $^
clean:
	rm -rf ${TARGET} ${OBJ}
