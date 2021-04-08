INCLUDE=../lib
SRC=../lib
CC=gcc
CPPFLAGS = -Wall -std=gnu99
CFLAGS = -I ${INCLUDE}
TARGET=copy seek_io my_tee t_readv
OBJ=copy.o seek_io.o my_tee.o t_readv.o ${SRC}/error_functions.o ${SRC}/get_num.o

${OBJ}:%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

all:${TARGET}

copy:${filter-out seek_io.o my_tee.o t_readv.o,${OBJ}}
	${CC} ${CPPFLAGS} -o $@ $^
seek_io:${filter-out copy.o my_tee.o t_readv.o,${OBJ}}
	${CC} ${CPPFLAGS} -o $@ $^
my_tee:${filter-out copy.o seek_io.o t_readv.o,${OBJ}}
	${CC} ${CPPFLAGS} -o $@ $^
t_readv:${filter-out copy.o seek_io.o my_tee.o,${OBJ}}
	${CC} ${CPPFLAGS} -o $@ $^
clean:
	rm -rf ${TARGET} ${OBJ}
