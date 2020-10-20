# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbenlyaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 03:07:26 by kbenlyaz          #+#    #+#              #
#    Updated: 2019/10/13 05:39:46 by kbenlyaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memmove.c ft_strlen.c freetab.c ft_memset.c ft_strmapi.c ft_atoi.c \
		ft_putchar_fd.c ft_strncmp.c ft_bzero.c ft_putendl_fd.c ft_strnstr.c \
		ft_calloc.c ft_putnbr_fd.c ft_strrchr.c ft_isalnum.c ft_putstr_fd.c  \
		ft_strtrim.c ft_isalpha.c ft_split.c ft_substr.c ft_isascii.c \
		ft_strchr.c ft_tolower.c ft_isdigit.c ft_memccpy.c ft_strdup.c \
		ft_toupper.c ft_isprint.c ft_memchr.c ft_strjoin.c ft_itoa.c \
		ft_memcmp.c ft_strlcat.c ft_memcpy.c ft_strlcpy.c \

SRCO= ft_memmove.o ft_strlen.o freetab.o ft_memset.o ft_strmapi.o ft_atoi.o \
		ft_putchar_fd.o ft_strncmp.o ft_bzero.o ft_putendl_fd.o ft_strnstr.o \
		ft_calloc.o ft_putnbr_fd.o ft_strrchr.o ft_isalnum.o ft_putstr_fd.o  \
		ft_strtrim.o ft_isalpha.o ft_split.o ft_substr.o ft_isascii.o \
		ft_strchr.o ft_tolower.o ft_isdigit.o ft_memccpy.o ft_strdup.o \
		ft_toupper.o ft_isprint.o ft_memchr.o ft_strjoin.o ft_itoa.o \
		ft_memcmp.o ft_strlcat.o ft_memcpy.o ft_strlcpy.o\

SRCBONUS = ft_lstsize_bonus.c ft_lstnew_bonus.c ft_lstmap_bonus.c\
		   ft_lstlast_bonus.c ft_lstiter_bonus.c ft_lstdelone_bonus.c\
		   ft_lstclear_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c\

SRCOBONUS = ft_lstsize_bonus.o ft_lstnew_bonus.o ft_lstmap_bonus.o\
		   ft_lstlast_bonus.o ft_lstiter_bonus.o ft_lstdelone_bonus.o\
		   ft_lstclear_bonus.o ft_lstadd_front_bonus.o ft_lstadd_back_bonus.o\

all : $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	ar -rc $(NAME) $(SRCO)
	ranlib $(NAME)
clean:
	/bin/rm  -f $(SRCO) $(SRCOBONUS)

fclean: clean
	/bin/rm -f $(NAME)
re: fclean all

bonus:
	gcc -c -Wall -Wextra -Werror $(SRCBONUS)
	ar -rc $(NAME) $(SRCOBONUS)
	ranlib $(NAME)


