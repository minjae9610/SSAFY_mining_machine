NAME			=	ssafy_mining_machine

SRCSPATH		=	srcs
SRCS			=	ssafy_mining_machine.c	\
					show_mining_machine.c	\
					add_mining_machine.c	\
					del_mining_machine.c	\
					status_mining_machine.c	\
					mining.c				\

CFILES			=	${addprefix ${SRCSPATH}/, ${SRCS}}
OBJS			=	${CFILES:.c=.o}

INC				=	includes

LIBSPATH		=	libs
LIBSPRE			=	lib
LIBS			=	mjkio		\
					mjkstd		\
					mjkqueue	\

LIBFILES		=	${addprefix ${LIBSPATH}/, ${addprefix ${LIBSPRE}, ${LIBS}}}

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

LIBC			=	ar rcs

REMOVE			=	rm -f

all:				${NAME}

%.o : %.c
					${CC} ${CFLAGS} -c $< -o $@ -I ${INC} -I ${LIBSPATH}/libmjkio -I ${LIBSPATH}/libmjkstd -I ${LIBSPATH}/libmjkqueue

${NAME}:			${OBJS}
					@${MAKE} -C ${LIBSPATH}/libmjkio
					@${MAKE} -C ${LIBSPATH}/libmjkstd
					@${MAKE} -C ${LIBSPATH}/libmjkqueue
					${CC} ${OBJS} -o ${NAME} -lpthread -L ${LIBSPATH}/libmjkio -lmjkio -L ${LIBSPATH}/libmjkstd -lmjkstd -L ${LIBSPATH}/libmjkqueue -lmjkqueue

clean:
					${REMOVE} ${OBJS}
					@${MAKE} -C ${LIBSPATH}/libmjkio clean
					@${MAKE} -C ${LIBSPATH}/libmjkstd clean
					@${MAKE} -C ${LIBSPATH}/libmjkqueue clean

fclean:
					@${MAKE} clean
					${REMOVE} ${NAME}
					@${MAKE} -C ${LIBSPATH}/libmjkio fclean
					@${MAKE} -C ${LIBSPATH}/libmjkstd fclean
					@${MAKE} -C ${LIBSPATH}/libmjkqueue fclean

re:
					@${MAKE} fclean
					@${MAKE}

.PHONY:				all clean fclean re