# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbungo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 12:53:57 by wbungo            #+#    #+#              #
#    Updated: 2022/03/04 16:58:44 by wbungo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER	 = checker
LIBFT = libft/libft.a
FLAGS = -Wall -Werror -Wextra
CC = gcc
HEADERS = push_swap.h ./libft/libft.h 

LIST_P = 		process_args.c check_input.c sort_stack.c	\
				simplify_array.c sort_five.c sort_big.c		\
				sort_three.c

LIST_C = 		checker.c get_next_line.c check_input.c		\
				simplify_array.c

LIST_LIBFT = 	./libft/ft_atoi.c		./libft/ft_issign.c		\
			 	./libft/ft_memcpy.c		./libft/ft_isdigit.c	\
			 	./libft/ft_putchar_fd.c	./libft/ft_putnbr_fd.c	\
			 	./libft/ft_putstr_fd.c	./libft/ft_strdup.c		\
			 	./libft/ft_strcmp.c		./libft/ft_strlen.c		\
				./libft/ft_bzero.c		./libft/ft_isalpha.c	\
				./libft/ft_exit_failure.c						\
				./libft/ft_exit_success.c

LIST_OPS =		operations/sa.c			operations/ra.c 		\
				operations/pa_pb.c 								\
				operations/rra.c		operations/stack_big.c

OBJ_P = $(patsubst %.c, %.o, $(LIST_P) $(LIST_LIBFT) $(LIST_OPS))

OBJ_C = $(patsubst %.c, %.o, $(LIST_C) $(LIST_LIBFT) $(LIST_OPS))

#D_FILES = $(patsubst %.c, %.d, $(LIST) $(LIST_B))

all : $(PUSH_SWAP)

$(PUSH_SWAP) : $(OBJ_P) $(HEADERS)
	@$(MAKE) all -C ./libft
	@cp $(LIBFT) $(PUSH_SWAP)
	@$(CC) $(OBJ_P) $(LIBFT) -o $(PUSH_SWAP)
	@printf "\e[38;5;226m./$@ successfully build\e[0m\n"

bonus : $(OBJ_C) $(HEADERS)
#	@$(MAKE) all -C ./libft
	@cp $(LIBFT) $(CHECKER)
	@$(CC) $(OBJ_C) $(LIBFT) -o $(CHECKER)
	@printf "\e[38;5;46m./$(CHECKER) successfully build\e[0m\n"

%.o : %.c $(HEADERS)
	@$(CC) $(FLAGS) -c $< -o $@

#include $(wildcard $(D_FILES))

clean :
	@rm -f $(OBJ_P) $(OBJ_C)
	@$(MAKE) clean -C ./libft
	@printf "\e[38;5;206m.o files deleted\e[0m\n"

fclean : clean
	@rm -f $(PUSH_SWAP) $(CHECKER)
	@$(MAKE) fclean -C ./libft        
	@printf "\e[38;5;200mBinaries deleted\e[0m\n"

re :	fclean all

.PHONY : all clean fclean re 
