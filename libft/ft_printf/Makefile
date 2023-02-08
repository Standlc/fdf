SRCS = ft_printf.c srcs/utils.c srcs/format_handlers_1.c \
	srcs/format_handlers_2.c srcs/ft_itoa_utils.c srcs/ft_itoa_hexa.c

OBJECTS = ${SRCS:.c=.o}

NAME = libftprintf.a

.c.o :
	cc -c -Wall -Wextra -Werror $< -o ${<:.c=.o}

${NAME} : ${OBJECTS}
	ar rc ${NAME} $^

all: ${NAME}

clean :
	rm -f ${OBJECTS} ${BONUS_OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all