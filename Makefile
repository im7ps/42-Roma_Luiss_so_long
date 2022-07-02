NAME	=	so_long

CC		=	gcc

CFLAGS	=	-Wall -Wextra

SRC	=	so_long.c\

OBJ	=	$(SRC:.c=.o)

LIBFT = libft/libft.a

RM		=	rm -rf

%.o: %.c
			@($(CC) ${CFLAGS} -g -c $< -o $@)

$(NAME):	$(OBJ)
			@make -C ./libft
			@($(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT))

all:		$(NAME)

clean:
			@(${RM} $(OBJ))

fclean: 	clean
			@(${RM} $(NAME) ${OBJ})

re:			fclean all

.PHONY:		all clean fclean re