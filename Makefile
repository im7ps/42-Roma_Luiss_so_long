NAME	=	so_long

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	ft_main.c \
			ft_image.c \
			ft_key_hooks.c \
			ft_window.c \
			ft_map.c \
			ft_map_checker.c \
			ft_utils.c \
			ft_moves.c \
			ft_simple_mov.c \

OBJ	=	$(SRC:.c=.o)

LIBFT = libft/libft.a

MLX		=	./libmlx.dylib

RM		=	rm -rf

%.o: %.c
			$(CC) ${CFLAGS} -g -c $< -o $@

$(NAME):	$(OBJ)
			@make -C ./libft
			$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) $(MLX) $(LIBFT)

all:		$(NAME)

clean:
			@make clean -C libft
			${RM} $(OBJ)

fclean: 	clean
			@make fclean -C libft
			${RM} $(NAME) ${OBJ}

re:			fclean all

.PHONY:		all clean fclean re