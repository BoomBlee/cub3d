# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcaraway <kcaraway@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 18:36:12 by boomblee          #+#    #+#              #
#    Updated: 2020/10/29 22:56:12 by kcaraway         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRCS =  src/lib/ft_memset.c \
		src/lib/ft_bzero.c \
		src/lib/ft_memcpy.c \
		src/lib/ft_memccpy.c \
		src/lib/ft_memmove.c \
		src/lib/ft_memchr.c \
		src/lib/ft_memcmp.c \
		src/lib/ft_strlen.c \
		src/lib/ft_strlcpy.c \
		src/lib/ft_strlcat.c \
		src/lib/ft_strchr.c \
		src/lib/ft_strrchr.c \
		src/lib/ft_isalpha.c \
		src/lib/ft_isdigit.c \
		src/lib/ft_isalnum.c \
		src/lib/ft_isascii.c \
		src/lib/ft_isprint.c \
		src/lib/ft_toupper.c \
		src/lib/ft_tolower.c \
		src/lib/ft_calloc.c \
		src/lib/ft_strdup.c \
		src/lib/ft_strncmp.c \
		src/lib/ft_atoi.c \
		src/lib/ft_strnstr.c \
		src/lib/ft_itoa.c \
		src/lib/ft_substr.c \
		src/lib/ft_strjoin.c \
		src/lib/ft_strtrim.c \
		src/lib/ft_putchar_fd.c \
		src/lib/ft_putstr_fd.c \
		src/lib/ft_putendl_fd.c \
		src/lib/ft_putnbr_fd.c \
		src/lib/ft_strmapi.c \
		src/lib/ft_split.c \
		src/lib/ft_lstadd_front.c \
		src/lib/ft_lstlast.c \
		src/lib/ft_lstnew.c \
		src/lib/ft_lstsize.c \
		src/lib/ft_lstadd_back.c \
		src/lib/ft_lstiter.c \
		src/lib/ft_lstdelone.c \
		src/lib/ft_lstclear.c \
		src/lib/ft_lstmap.c \
		src/lib/ft_strcpy.c \
		src/lib/ft_isspace.c \
		src/gnl/get_next_line.c 

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I ./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	@ar rcs $(NAME) $(OBJS)
	@echo 'libft.a created'

all : $(NAME)

clean :
	@rm -rf $(OBJS)
	@echo 'clean completed'

fclean : clean
	@rm -rf $(NAME)
	@echo 'fclean completed'

re : fclean all