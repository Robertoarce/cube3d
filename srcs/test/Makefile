# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: titorium <rarce@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/05 13:57:48 by titorium          #+#    #+#              #
#    Updated: 2020/10/05 16:13:10 by titorium         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang -g3 -fsanitize=address -Wall -Wextra -Werror

SRC = get_next_line.c
SRC += get_next_line_utils.c
SRC += ft_parsing.c
SRC += ft_map.c
SRC += ft_outils.c

SRCS = $(SRCS:.c=.o)

all:	
	make -C ../../libft/ 
	$(CC) $(addprefix ./../, ${SRCS}) ../../main.c ../../libft/libft.a  -I./src/ -I./../../libft -I./../../includes -fno-stack-protector 
	./a.out	

.PHONY: all
