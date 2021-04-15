INCLUDE=../lib
SRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${SRC} -ltlpi -lcrypt
CFLAGS = -I ${INCLUDE}
TARGET=check_password
LIB=${SRC}/libtlpi.a
OBJ=check_password.o
LIBOBJ=${SRC}/error_functions.o ${SRC}/get_num.o


all:${LIB} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

check_password:check_password.o ${LIB}
	${CC}  $^ ${CPPFLAGS} -o $@

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
