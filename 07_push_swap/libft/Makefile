# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbungo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 13:46:09 by wbungo            #+#    #+#              #
#    Updated: 2022/03/03 11:36:09 by wbungo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIST =	ft_atoi.c		ft_isdigit.c	ft_memcpy.c		ft_strlen.c		\
		ft_issign.c		ft_strcmp.c		ft_strdup.c		ft_isalpha.c	\
		ft_putchar_fd.c				\
		ft_putnbr_fd.c				\
		ft_putstr_fd.c				\
		ft_exit_failure.c			\
		ft_exit_success.c			\
		ft_bzero.c

LIST_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

HEADERS = libft.h

OBJ = $(patsubst %.c, %.o, $(LIST))
OBJ_B = $(patsubst %.c, %.o, $(LIST_B))

#D_FILES = $(patsubst %.c, %.d, $(LIST) $(LIST_B))

# COLORS

#GREEN = \033[0;32m
#RED = \033[0;31m
#RESET = \033[0m

FLAGS = -Wall -Werror -Wextra

.PHONY : all clean fclean re 

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $?

%.o : %.c $(HEADERS)
	@gcc $(FLAGS) -c $< -o $@
#	gcc $(FLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

bonus :
	@make OBJ='$(OBJ_B)' all

clean :
	@rm -f $(OBJ) $(OBJ_B) $(D_FILES)

fclean : clean
	@rm -f $(NAME)

re :	fclean all

#ft_putendl_fd.c 
#ft_itoa.c 

#ft_lstadd_back.c 
#ft_lstadd_front.c 
#ft_lstclear.c 
#ft_lstdelone.c 
#ft_lstiter.c 
#ft_lstlast.c 
#ft_lstmap.c
#ft_lstnew.c 
#ft_lstsize.c

#ft_bzero.c 
#ft_calloc.c 

#ft_isalnum.c 
#ft_isalpha.c 
#ft_isascii.c 
#ft_isprint.c 

#ft_memset.c 
#ft_memccpy.c 
#ft_memmove.c 
#ft_memchr.c 
#ft_memcmp.c 

#ft_toupper.c 
#ft_tolower.c 

#ft_strchr.c 
#ft_strrchr.c 
#ft_strncmp.c 
#ft_strlcpy.c 
#ft_strlcat.c 
#ft_strnstr.c 
#ft_substr.c 
#ft_strjoin.c 
#ft_strtrim.c 
#ft_split.c 
#ft_strmapi.c 
#ft_striteri.c 
