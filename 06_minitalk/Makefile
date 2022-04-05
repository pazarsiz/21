SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra
HEADERS  = minitalk.h libft/libft.h

LIST_S = server.c

LIST_C = client.c

LIST_L = ./libft/ft_atoi.c	./libft/ft_memalloc.c		\
		 ./libft/ft_itoa.c	./libft/ft_iswhitespaces.c	\
		 ./libft/ft_bzero.c	./libft/ft_strlen.c

COMMON = error.c

OBJ_S = $(patsubst %.c, %.o, $(LIST_S) $(LIST_L) $(COMMON))

OBJ_C = $(patsubst %.c, %.o, $(LIST_C) $(LIST_L) $(COMMON))

all : $(SERVER) $(CLIENT)

$(SERVER) : $(OBJ_S) $(HEADERS)
	@$(CC) $(OBJ_S) $(LIBS) -o $@
	@printf "\e[38;5;226m./$@ successfully build\e[0m\n"

$(CLIENT) : $(OBJ_C) $(HEADERS)
	@$(CC) $(OBJ_C) $(LIBS) -o $@
	@printf "\e[38;5;46m./$@ successfully build\e[0m\n"

%.o : %.c $(HEADERS)
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ_S) $(OBJ_C)
	@make clean -C ./libft
	@printf "\e[38;5;207m.o files deleted\e[0m\n"
#	rm -f *.o

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@make fclean -C ./libft
	@printf "\e[38;5;199mBinaries deleted\e[0m\n"

re: fclean all
