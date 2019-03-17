# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 18:44:12 by olrudenk          #+#    #+#              #
#    Updated: 2019/03/16 15:23:59 by olrudenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = olrudenk.filler
VIZO = vizo

FLAGS1 = -Wall -Wextra -Werror
FLAGS2 = -lmlx -framework OpenGL -framework Appkit

SRCS_NAME = ./srcs/auxiliary.c \
		   ./srcs/free.c \
		   ./srcs/game.c \
		   ./srcs/get_data.c \
		   ./srcs/heatmap.c \
		   ./srcs/main.c \
		   ./srcs/update_data.c \

SRCS_VIZO =	./visualizer/srcs/main.c \
			./visualizer/srcs/parse.c \
			./visualizer/srcs/paint.c \
			./visualizer/srcs/update_map.c \
			./visualizer/srcs/auxiliary.c \
			./visualizer/srcs/set_up_window.c \
			./visualizer/srcs/finish.c \

INC_NAME = inc/filler.h

INC_VIZO = visualizer/inc/vizo_filler.h

all: $(NAME) $(VIZO)

OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJ_VIZO = $(SRCS_VIZO:.c=.o)

.PHONY : libft
libft:
	@make -C./libft

$(NAME): libft $(OBJ_NAME) $(OBJ_VIZO)
	@echo "\033[32mCompiling olrudenk.filler and vizo...\033[0m"
	gcc -o $(NAME) $(OBJ_NAME) ./libft/libft.a
	gcc -o $(VIZO) $(OBJ_VIZO) $(FLAGS2) ./libft/libft.a
	@echo "\033[34mCompilation is done. Have fun!\033[0m"

%.o: %.c $(INC_NAME)
	gcc -o $@ -c $< $(FLAGS1)
%.o: %.c $(INC_VIZO)
	gcc -o $@ -c $< $(FLAGS1)

clean:
	@make clean -C ./libft
	@rm -f $(OBJ_NAME) $(OBJ_VIZO)
	@echo "\033[32mDeleting object files... done.\033[0m"

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME) $(VIZO)
	@echo "\033[32mDeleting olrudenk.filler and vizo... done.\033[0m"

re: fclean all
