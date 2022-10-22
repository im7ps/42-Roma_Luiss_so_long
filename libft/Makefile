# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 17:44:25 by dgioia            #+#    #+#              #
#    Updated: 2022/10/22 19:11:33 by sgerace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

CC= gcc

CFLAGS= -Wall -Werror -Wextra -g

SRCDIR = srcs

LIBSRCS = ft_isalpha.c \
		  ft_isascii.c \
	      ft_isdigit.c \
	      ft_isprint.c \
	      ft_strlcat.c \
	      ft_strlcpy.c \
	      ft_strlen.c \
	      ft_strncmp.c \
		  ft_memset.c \
		  ft_findchar.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_bzero.c \
		  ft_memmove.c \
		  ft_memcpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_atoi.c \
		  ft_calloc.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putnbr_fd.c \
		  ft_putendl_fd.c \
		  ft_striteri.c \
		  ft_strmapi.c \
		  ft_strtrim.c \
		  ft_strjoin.c \
		  ft_substr.c \
		  ft_strdup.c \
		  ft_strnstr.c \
		  ft_itoa.c \
		  ft_lstnew.c \
		  ft_lstadd_front.c \
		  ft_lstsize.c \
		  ft_lstlast.c \
		  ft_lstadd_back.c \
		  ft_lstdelone.c \
		  ft_lstclear.c \
		  ft_lstiter.c \
		  ft_lstmap.c \

PRINTFSRCS = ft_printf_main.c \
				ft_printf_num_utils.c \
				ft_printf_string_utils.c \

GNLSRCS = get_next_line.c\

OBJDIR= obj

LIBOBJ= $(addprefix $(OBJDIR)/lib/,$(LIBSRCS:.c=.o))
GNLOBJ= $(addprefix $(OBJDIR)/gnl/,$(GNLSRCS:.c=.o))
PRINTFOBJ= $(addprefix $(OBJDIR)/printf/,$(PRINTFSRCS:.c=.o))

HEADDIR = includes

LIBHEAD = $(HEADDIR)/libft.h
GNLHEAD = $(HEADDIR)/get_next_line.h
PRINTFHEAD = $(HEADDIR)/ft_printf.h

#Print colors/lneclr
BLUE = "\\033[36m"
RED = "\\033[31m"
WHITE = "\\033[0m"
GREEN = "\\033[32m"
YELLOW = "\\033[33m"
PURPLE = "\\033[35m"
LNECLR = "\\33[2K\\r"

all: $(OBJDIR) $(NAME)

$(NAME): $(LIBOBJ) $(GNLOBJ) $(PRINTFOBJ)
	$(AR) rcs $(NAME) $^
	printf "$(LNECLR)$(GREEN)make libft done$(WHITE)\n"

$(OBJDIR):
	mkdir -p $(OBJDIR)/lib
	mkdir -p $(OBJDIR)/gnl
	mkdir -p $(OBJDIR)/printf

$(OBJDIR)/printf/%.o: $(SRCDIR)/printf/%.c $(PRINTFHEAD) $(LIBHEAD)
	$(CC) $(CFLAGS) -I $(HEADDIR) -o $@ -c $<
	printf "$(LNECLR)$(YELLOW)$(NAME): $<$(WHITE)"

$(OBJDIR)/gnl/%.o: $(SRCDIR)/gnl/%.c $(GNLHEAD) $(LIBHEAD)
	$(CC) $(CFLAGS) -I $(HEADDIR) -o $@ -c $<
	printf "$(LNECLR)$(YELLOW)$(NAME): $<"$(WHITE)

$(OBJDIR)/lib/%.o: $(SRCDIR)/lib/%.c $(LIBHEAD)
	$(CC) $(CFLAGS) -I $(HEADDIR) -o $@ -c $<
	printf "$(LNECLR)$(YELLOW)$(NAME): $<"$(WHITE)

clean:
	$(RM) -rf $(OBJDIR)
	printf "$(PURPLE)clean libft done$(WHITE)\n"

fclean:
	$(RM) -rf $(OBJDIR) $(NAME)
	printf "$(RED)fclean libft done$(WHITE)\n"

re:
	$(MAKE) -s fclean
	$(MAKE) -s all
	printf "$(BLUE)re libft done$(WHITE)\n"

.PHONY: clean all fclean re
.SILENT: clean fclean re $(OBJDIR) $(LIBOBJ) $(PRINTFOBJ) $(GNLOBJ) $(NAME)