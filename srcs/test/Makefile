# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: titorium <rarce@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/05 13:57:48 by titorium          #+#    #+#              #
#    Updated: 2020/10/06 12:52:11 by titorium         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub.a

RM = rm

CC = clang -g3 -fsanitize=address -Wall -Wextra -Werror

INCLUDES = -I./../../includes
INCLUDES += -I./../../libft
EXTRARGS = 	-fno-stack-protector 

SRC = get_next_line_utils.c
SRC += get_next_line.c
SRC += ft_parsing.c
SRC += ft_map.c
SRC += ft_outils.c



OBJS = $(addprefix ./../, $(SRC:.c=.o))

all:	$(OBJS)
	make -C ../../libft/ 
	ar rc ${NAME} ${OBJS}
	cp ../../libft/libft.a .
	cc main.c cub.a libft.a

.c.o:
	$(CC) $(INCLUDES) -g -c $< -o ${<:.c=.o}


clean:
	${RM} ${OBJS}
	${RM} *.gch

fclean: clean
	make fclean -C ./libft
	${RM} ${NAME}


re: fclean all


.PHONY: all
