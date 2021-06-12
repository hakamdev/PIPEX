# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 21:05:20 by ehakam            #+#    #+#              #
#    Updated: 2021/06/12 16:54:22 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= pipex.c utility/ft_split.c
NAME	= pipex

all: $(NAME)

$(NAME): $(SRC)
	@gcc $(SRC) -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME) infile outfile

re: fclean all