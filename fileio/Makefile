INCLUDE=../lib
SRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${SRC} -ltlpi -lpthread
CFLAGS = -I ${INCLUDE}
TARGET=copy seek_io my_tee t_readv large_file
LIB=${SRC}/libtlpi.a
OBJ=copy.o seek_io.o my_tee.o t_readv.o large_file.o
LIBOBJ=${SRC}/error_functions.o ${SRC}/get_num.o


all:${LIB} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

copy:copy.o ${LIB}
	${CC}  $^ ${CPPFLAGS} -o $@
seek_io:seek_io.o 
	${CC}  $^ ${CPPFLAGS} -o $@
my_tee:my_tee.o ${LIB}
	${CC}  $^ ${CPPFLAGS} -o $@
t_readv:t_readv.o ${LIB}
	${CC}  $^ ${CPPFLAGS} -o $@
large_file:large_file.o ${LIB}
	${CC}  $^ ${CPPFLAGS} -o $@
clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
