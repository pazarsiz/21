# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbungo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 12:53:57 by wbungo            #+#    #+#              #
#    Updated: 2022/04/04 13:19:03 by wbungo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a
FLAGS = -Wall -Werror -Wextra
CC = gcc
HEADERS = ft_printf.h ./libft/libft.h 

LIST = ft_printf.c ft_analyze_1.c ft_analyze_2.c ft_output.c ft_convert_diuxp.c

LIST_LIBFT = ./libft/ft_atoi.c ./libft/ft_itoa.c ./libft/ft_memcpy.c \
		./libft/ft_strdup.c ./libft/ft_strjoin.c ./libft/ft_strlen.c

OBJ = $(patsubst %.c, %.o, $(LIST))

all : $(NAME)

$(NAME) : $(OBJ) $(HEADERS) $(LIST_LIBFT)
	$(MAKE) all -C ./libft
	cp $(LIBFT) $(NAME) 
	ar rcs $(NAME) $?

%.o : %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	$(MAKE) clean -C ./libft

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re :	fclean all

.PHONY : all clean fclean re 
