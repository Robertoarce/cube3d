# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: titorium <rarce@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 09:23:07 by titorium          #+#    #+#              #
#    Updated: 2020/10/07 17:55:11 by titorium         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	cub3d

LIBFT		=	./libft/libft.a
INCLUDE		=	-I./includes/
INCLUDE		+=	-I./libft/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRC			=	main.c
SRCS		=	get_next_line.c
SRCS		+=	get_next_line_utils.c
SRCS		+=	ft_parsing.c
SRCS		+=	ft_infos.c
SRCS		+=	ft_infos2.c
SRCS		+=	ft_infos3.c
SRCS		+=	ft_outils.c
SRCS		+=	ft_map.c
SRCS		+=	ft_map2.c



OBJ			=	${SRC:.c=.o}
OBJS		=	$(addprefix ./srcs/, ${SRCS:.c=.o})



.c.o:
	${CC} ${CFLAGS} $(INCLUDE) -g -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} $(OBJ)
	make -C ./libft
	ar -rcs $(NAME) $(OBJ) $(OBJS)

all:	${NAME}

clean:
	make clean -C ./libft
	${RM} ${OBJS} $(OBJ)

fclean: clean
	make fclean -C ./libft
	${RM} ${NAME}

re:	fclean all

.PHONY : all clean fclean re
