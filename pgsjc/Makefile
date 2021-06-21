INCLUDE=../lib
LIBSRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC} -ltlpi
CFLAGS = -I ${INCLUDE}
TARGET= t_setsid catch_SIGHUP disc_SIGHUP job_mon
OBJ= t_setsid.o catch_SIGHUP.o disc_SIGHUP.o job_mon.o
LIB=${LIBSRC}/libtlpi.a
LIBOBJ=${LIBSRC}/error_functions.o ${LIBSRC}/get_num.o



all:${LIB} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

t_setsid:t_setsid.o ${LIB}
	${CC} t_setsid.o ${CPPFLAGS} -o $@

catch_SIGHUP:catch_SIGHUP.o ${LIB}
	${CC} catch_SIGHUP.o ${CPPFLAGS} -o $@

disc_SIGHUP:disc_SIGHUP.o ${LIB}
	${CC} disc_SIGHUP.o ${CPPFLAGS} -o $@

job_mon:job_mon.o ${LIB}
	${CC} job_mon.o ${CPPFLAGS} -o $@

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
