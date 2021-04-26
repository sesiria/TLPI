INCLUDE=../lib
INCLUDE1=../users_groups
LIBSRC=../lib
LIBSRC1=../users_groups
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC}  -L ${LIBSRC1} -ltlpi -lacl -lugid
CFLAGS = -I ${INCLUDE} -I ${INCLUDE1}
TARGET=acl_view
OBJ=acl_view.o
LIB=${LIBSRC}/libtlpi.a
LIB1=${LIBSRC1}/libugid.a
LIBOBJ=${LIBSRC}/error_functions.o ${LIBSRC}/get_num.o
LIBOBJ1=${LIBSRC1}/ugid_functions.o 

all:${LIB} ${LIB1} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

${LIB1}:${LIBOBJ1}
	${AR} -rcs $@ $^

acl_view:acl_view.o  ${LIB} ${LIB1}
	${CC} acl_view.o ${CPPFLAGS} -o $@

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIB1} ${LIBOBJ}
