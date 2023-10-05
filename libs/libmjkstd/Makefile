NAME	=	libmjkstd.a

SRCS	=	isdigit_str.c			\
			convert_alpha_case.c	\
			isupper.c				\
			tolower_str.c			\
			tolower.c				\

OBJS	=	${SRCS:.c=.o}

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

LIBC	=	ar -rcs

REMOVE	=	rm -f

all:		${NAME}

%.o : %.c
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${LIBC} $@ $?

clean:
			${REMOVE} $(OBJS)

fclean:
			@${MAKE} clean
			${REMOVE} ${NAME}

re:
			@${MAKE} fclean
			@${MAKE}

.PHONY:		all clean fclean re