# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 21:05:20 by ehakam            #+#    #+#              #
#    Updated: 2021/06/13 20:49:32 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	pipex.c \
			pipex_dup.c \
			pipex_init.c \
			pipex_path.c \
			utility/ft_split.c \
			utility/ft_strdup.c \
			utility/ft_strlen.c \
			utility/ft_substr.c \
			utility/p_error.c
NAME	=	pipex
FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	@gcc $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME) infile outfile

re: fclean all