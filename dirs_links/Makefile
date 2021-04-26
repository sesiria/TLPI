INCLUDE=../lib
LIBSRC=../lib
CC=gcc
AR=ar
CPPFLAGS = -Wall -std=gnu99 -L ${LIBSRC} -ltlpi
CFLAGS = -I ${INCLUDE}
TARGET=t_unlink list_files nftw_dir_tree view_symlink t_dirbasename
OBJ=t_unlink.o list_files.o nftw_dir_tree.o view_symlink.o t_dirbasename.o
LIB=${LIBSRC}/libtlpi.a
LIBOBJ=${LIBSRC}/error_functions.o ${LIBSRC}/get_num.o

all:${LIB} ${TARGET}

%.o:%.c
	${CC} -c ${CFLAGS} $< -o $@

${LIB}:${LIBOBJ}
	${AR} -rcs $@ $^

t_unlink:t_unlink.o ${LIB}
	${CC} t_unlink.o ${CPPFLAGS} -o $@

list_files:list_files.o ${LIB}
	${CC} list_files.o ${CPPFLAGS} -o $@

nftw_dir_tree:nftw_dir_tree.o ${LIB}
	${CC} nftw_dir_tree.o ${CPPFLAGS} -o $@

view_symlink:view_symlink.o ${LIB}
	${CC} view_symlink.o ${CPPFLAGS} -o $@

t_dirbasename:t_dirbasename.o ${LIB}
	${CC} t_dirbasename.o ${CPPFLAGS} -o $@

clean:
	rm -rf ${TARGET} ${OBJ} ${LIB} ${LIBOBJ}
