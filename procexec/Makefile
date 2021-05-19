INCLUDE=../lib
INCLUDE1=../time
LIBSRC=../lib
LIBSRC1=../time
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC} -ltlpi
CPPFLAGS1 = -Wall -std=gnu99 -L ${LIBSRC} -L ${LIBSRC1} -ltlpi -lcurr_time
CFLAGS = -I ${INCLUDE} -I ${INCLUDE1}
TARGET=t_fork fork_file_sharing footprint t_vfork fork_whos_on_first fork_sig_sync
OBJ=t_fork.o fork_file_sharing.o footprint.o t_vfork.o fork_whos_on_first.o fork_sig_sync.o
LIB=${LIBSRC}/libtlpi.a
LIB1=${LIBSRC1}/libcurr_time.a
LIBOBJ=${LIBSRC}/error_functions.o ${LIBSRC}/get_num.o
LIBOBJ1=${LIBSRC1}/curr_time.o 

all:${LIB} ${LIB1} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

${LIB1}:${LIBOBJ1}
	${AR} -rcs $@ $^

t_fork:t_fork.o ${LIB}
	${CC} t_fork.o ${CPPFLAGS} -o $@

fork_file_sharing:fork_file_sharing.o ${LIB}
	${CC} fork_file_sharing.o ${CPPFLAGS} -o $@

footprint:footprint.o ${LIB}
	${CC} footprint.o ${CPPFLAGS} -o $@

t_vfork:t_vfork.o ${LIB}
	${CC} t_vfork.o ${CPPFLAGS} -o $@

fork_whos_on_first:fork_whos_on_first.o ${LIB}
	${CC} fork_whos_on_first.o ${CPPFLAGS} -o $@

fork_sig_sync:fork_sig_sync.o ${LIB}
	${CC} fork_sig_sync.o ${CPPFLAGS1} -o $@

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
