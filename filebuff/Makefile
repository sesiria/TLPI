INCLUDE=../lib
LIBSRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC} -ltlpi
CFLAGS = -I ${INCLUDE}
TARGET=direct_read
OBJ=direct_read.o
LIB=${LIBSRC}/libtlpi.a
LIBOBJ=${LIBSRC}/error_functions.o ${LIBSRC}/get_num.o

all:${LIB} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

direct_read:direct_read.o ${LIB}
	${CC} direct_read.o ${CPPFLAGS} -o $@

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
