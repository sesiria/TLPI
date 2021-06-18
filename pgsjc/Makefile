INCLUDE=../lib
LIBSRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC} -ltlpi
CFLAGS = -I ${INCLUDE}
TARGET= t_setsid
OBJ= t_setsid.o
LIB=${LIBSRC}/libtlpi.a
LIBOBJ=${LIBSRC}/error_functions.o ${LIBSRC}/get_num.o



all:${LIB} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

t_setsid:t_setsid.o ${LIB}
	${CC} t_setsid.o ${CPPFLAGS} -o $@


clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
