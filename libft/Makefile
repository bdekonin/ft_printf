# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bdekonin <bdekonin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/29 12:24:22 by bdekonin       #+#    #+#                 #
#    Updated: 2020/01/17 10:31:13 by bdekonin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_strchr.c \
ft_strdup.c	ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c \
ft_strtrim.c

OFILES = $(SRCS:.c=.o)

BONUS_SRC = $(SRCS) ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstclear_bonus.c \
ft_lstmap_bonus.c

BONUS_OFILES = $(OFILES) $(BONUS_SRC:.c=.o)

INCLUDES = libft.h

all: $(NAME)

$(NAME): $(OFILES) $(INCLUDES)
	@ar rcs $(NAME) $?
	@echo "\033[92mCreated a Library and Object Files.\033[0m"

bonus: $(NAME) $(BONUS_OFILES) $(BONUS_SRC)
	@touch bonus
	@ar rcs $(NAME) $?

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $<

clean:
	@/bin/rm -f $(BONUS_OFILES)
	@/bin/rm -f a.out
	@/bin/rm -f bonus
	@echo "\033[92mRemoved All Object Files.\033[0m"

fclean:    clean
	@/bin/rm -f $(NAME)
	@echo "\033[92mRemoved .a file and all .o files.\033[0m"

re: fclean all
