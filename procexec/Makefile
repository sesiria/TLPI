INCLUDE=../lib
INCLUDE1=../time
INCLUDE2=../users_groups
LIBSRC=../lib
LIBSRC1=../time
LIBSRC2=../users_groups
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC} -ltlpi
CPPFLAGS1 = -Wall -std=gnu99 -L ${LIBSRC} -L ${LIBSRC1} -ltlpi -lcurr_time
CPPFLAGS2 = -Wall -std=gnu99 -L ${LIBSRC} -L ${LIBSRC2} -ltlpi -lugid_functions
CFLAGS = -I ${INCLUDE} -I ${INCLUDE1} -I ${INCLUDE2}
TARGET=t_fork fork_file_sharing footprint t_vfork fork_whos_on_first fork_sig_sync exit_handlers fork_stdio_buf multi_wait child_status make_zombie \
		multi_SIGCHLD t_execve envargs t_execlp t_execle t_execl closeonexec t_system acct_on acct_view t_clone
OBJ=t_fork.o fork_file_sharing.o footprint.o t_vfork.o fork_whos_on_first.o fork_sig_sync.o exit_handlers.o fork_stdio_buf.o multi_wait.o child_status.o print_wait_status.o make_zombie.o \
		multi_SIGCHLD.o t_execve.o envargs.o t_execlp.o t_execle.o t_execl.o closeonexec.o t_system.o acct_on.o acct_view.o t_clone.o
LIB=${LIBSRC}/libtlpi.a
LIB1=${LIBSRC1}/libcurr_time.a
LIB2=${LIBSRC2}/libugid_functions.a
LIBOBJ=${LIBSRC}/error_functions.o ${LIBSRC}/get_num.o
LIBOBJ1=${LIBSRC1}/curr_time.o 
LIBOBJ2=${LIBSRC2}/ugid_functions.o

all:${LIB} ${LIB1}  ${LIB2} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

${LIB1}:${LIBOBJ1}
	${AR} -rcs $@ $^

${LIB2}:${LIBOBJ2}
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

fork_sig_sync:fork_sig_sync.o ${LIB} ${LIB1}
	${CC} fork_sig_sync.o ${CPPFLAGS1} -o $@

exit_handlers:exit_handlers.o ${LIB}
	${CC} exit_handlers.o ${CPPFLAGS} -o $@

fork_stdio_buf:fork_stdio_buf.o ${LIB}
	${CC} fork_stdio_buf.o ${CPPFLAGS} -o $@

multi_wait:multi_wait.o ${LIB} ${LIB1}
	${CC} multi_wait.o ${CPPFLAGS1} -o $@

child_status:child_status.o print_wait_status.o ${LIB}
	${CC} child_status.o print_wait_status.o ${CPPFLAGS} -o $@

make_zombie:make_zombie.o ${LIB}
	${CC} make_zombie.o ${CPPFLAGS} -o $@

multi_SIGCHLD:multi_SIGCHLD.o print_wait_status.o ${LIB} ${LIB1}
	${CC} multi_SIGCHLD.o print_wait_status.o ${CPPFLAGS1} -o $@

t_execve:t_execve.o ${LIB}
	${CC} t_execve.o ${CPPFLAGS} -o $@

envargs:envargs.o ${LIB}
	${CC} envargs.o ${CPPFLAGS} -o $@

t_execlp:t_execlp.o ${LIB}
	${CC} t_execlp.o ${CPPFLAGS} -o $@

t_execle:t_execle.o ${LIB}
	${CC} t_execle.o ${CPPFLAGS} -o $@

t_execl:t_execl.o ${LIB}
	${CC} t_execl.o ${CPPFLAGS} -o $@

closeonexec:closeonexec.o ${LIB}
	${CC} closeonexec.o ${CPPFLAGS} -o $@

t_system:t_system.o print_wait_status.o ${LIB} ${LIB1}
	${CC} t_system.o print_wait_status.o ${CPPFLAGS1} -o $@

acct_on:acct_on.o ${LIB}
	${CC} acct_on.o ${CPPFLAGS} -o $@

acct_view:acct_view.o ${LIB} ${LIB2}
	${CC} acct_view.o ${CPPFLAGS2} -o $@

t_clone:t_clone.o ${LIB}
	${CC} t_clone.o ${CPPFLAGS} -o $@
clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
