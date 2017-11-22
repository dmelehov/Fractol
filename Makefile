# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/10 22:42:29 by dmelehov          #+#    #+#              #
#    Updated: 2017/06/11 17:54:48 by dmelehov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c controls.c fractols1.c drawing.c 
SRCO = $(SRC:.c=.o)

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror -g
GRAPHICS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCO)
	make -C libft/
	gcc -o $(NAME) $(SRCO) $(LIBFT) $(FLAGS) $(GRAPHICS)

%.o: %.c
	gcc -c $(FLAGS) -o $@ $<
clean:
	make clean -C libft/
	/bin/rm -f *.o

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

re: fclean all