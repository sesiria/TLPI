INCLUDE=../lib
INCLUDE1=../users_groups
LIBSRC=../lib
LIBSRC1=../users_groups
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC}  -ltlpi
CPPFLAGS1 = -Wall -std=gnu99 -L ${LIBSRC} -L ${LIBSRC1} -ltlpi -lugid
CFLAGS = -I ${INCLUDE} -I ${INCLUDE1}
TARGET=t_stat t_chown t_umask
OBJ=t_stat.o file_perms.o t_chown.o t_umask.o
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

t_stat:t_stat.o file_perms.o ${LIB}
	${CC} t_stat.o file_perms.o ${CPPFLAGS} -o $@

t_chown:t_chown.o ${LIBOBJ1} ${LIB}
	${CC} t_chown.o  ${CPPFLAGS1} -o $@

t_umask:t_umask.o file_perms.o ${LIB}
	${CC} t_umask.o file_perms.o ${CPPFLAGS} -o $@

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIB1} ${LIBOBJ}
