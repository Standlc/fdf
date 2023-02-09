NAME		=	fdf

SRCS		=	main.c								sources/draw/draw_line.c \
				sources/get_map/get_map.c			sources/get_map/loader.c \
				sources/camera_settings.c			sources/draw/display_map.c \
				sources/close_program.c				sources/projection_methods.c \
				sources/draw/gradient.c				sources/get_map/get_map_utils.c \
				sources/get_map/check_map_file.c	sources/draw/draw_controls.c \
				sources/handle_key.c

OBJS		=	$(SRCS:.c=.o)

LIB			=	libft.a

LIBFT		=	libft

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

#LINUX
#INCLUDES	=	-Iminilibx-linux -Ilibft
#MINILIBX	=	minilibx-linux
#XFLAGS		=	-lmlx -lXext -lX11

#MACOS
INCLUDES	=	-Iminilibx_macos -Ilibft
MINILIBX	=	minilibx_macos
XFLAGS		=	-lmlx -framework OpenGL -framework AppKit

MATH_LIB	=	-lm

RM			=	rm -f

all : libs $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(OBJS) $(LIBFT)/libft.a  -L$(MINILIBX) $(XFLAGS) $(MATH_LIB) -o $(NAME)

%.o : %.c fdf.h Makefile
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libs:
		@$(MAKE) -C $(LIBFT)
		@$(MAKE) -C $(MINILIBX)

clean:
		@$(RM) $(OBJS)
		@$(MAKE) clean -C $(LIBFT)
		@$(MAKE) clean -C $(MINILIBX)

fclean:	clean
		@$(RM) $(NAME)
		@$(MAKE) fclean -C $(LIBFT)
		@$(MAKE) clean -C $(MINILIBX)

re:		fclean all

.PHONY: all libs clean fclean re
