INCLUDE=../lib
LIBSRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC} -ltlpi
CFLAGS = -I ${INCLUDE}
TARGET= t_setpriority sched_set sched_view
OBJ= t_setpriority.o sched_set.o sched_view.o
LIB=${LIBSRC}/libtlpi.a 
LIBOBJ=${LIBSRC}/error_functions.o ${LIBSRC}/get_num.o



all:${LIB} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

t_setpriority:t_setpriority.o ${LIB}
	${CC} t_setpriority.o ${CPPFLAGS} -o $@

sched_set:sched_set.o ${LIB}
	${CC} sched_set.o ${CPPFLAGS} -o $@

sched_view:sched_view.o ${LIB}
	${CC} sched_view.o ${CPPFLAGS} -o $@

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
