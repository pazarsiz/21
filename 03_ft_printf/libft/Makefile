# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbungo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 12:53:57 by wbungo            #+#    #+#              #
#    Updated: 2021/12/25 13:52:51 by wbungo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIST = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	   ft_isdigit.c ft_isprint.c ft_strlen.c ft_memset.c ft_memcpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	   ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_strdup.c ft_substr.c \
	   ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c

LIST_B = ft_lstnew_bonus.c \
		 ft_lstadd_front_bonus.c \
		 ft_lstsize_bonus.c \
		 ft_lstlast_bonus.c \
		 ft_lstadd_back_bonus.c \
		 ft_lstdelone_bonus.c \
		 ft_lstclear_bonus.c \
		 ft_lstiter_bonus.c \
		 ft_lstmap_bonus.c

HEADERS = libft.h

OBJ = $(patsubst %.c, %.o, $(LIST))
OBJ_B = $(patsubst %.c, %.o, $(LIST_B))

FLAGS = -Wall -Werror -Wextra

.PHONY : all clean fclean re 

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c $(HEADERS)
	gcc $(FLAGS) -c $< -o $@

bonus : $(OBJ_B) $(HEADERS)
	@make OBJ='$(OBJ_B)' all

clean :
	rm -f $(OBJ) $(OBJ_B)

fclean : clean
	rm -f $(NAME)

re :	fclean all
