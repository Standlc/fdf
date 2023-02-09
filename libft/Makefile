SRCS = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_putnbr_fd.c \
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
		get_next_line.c get_next_line_utils.c \
		ft_strcpy.c			ft_index_of.c \
		ft_str_toupper.c	ft_abs.c \
		

OBJECTS = ${SRCS:.c=.o}

BONUS =	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS = ${BONUS:.c=.o}

FT_PRINTF_OBJS =	ft_printf/srcs/format_handlers_1.o		ft_printf/srcs/format_handlers_2.o \
					ft_printf/srcs/ft_itoa_hexa.o			ft_printf/srcs/ft_itoa_utils.o			\
					ft_printf/srcs/utils.o					ft_printf/ft_printf.o

NAME = libft.a

FT_PRINTF = libftprintf.a

FLAGS = -Wall -Wextra -Werror

all: $(FT_PRINTF) bonus ${NAME} 

%.o: %.c
	cc ${FLAGS} -c $< -o $(<:.c=.o)

${NAME} : ${OBJECTS} ${BONUS_OBJS}
	ar rc ${NAME} ${OBJECTS} ${BONUS_OBJS} $(FT_PRINTF_OBJS)

$(FT_PRINTF):
	make -C ft_printf

clean :
	rm -f ${OBJECTS} ${BONUS_OBJS}
	make clean -C ft_printf

fclean : clean
	rm -f ${NAME}
	make fclean -C ft_printf

re : fclean all

bonus: ${BONUS_OBJS}

.PHONY: all clean fclean re bonus