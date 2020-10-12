# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: titorium <rarce@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 09:23:07 by titorium          #+#    #+#              #
#    Updated: 2020/10/12 14:58:03 by titorium         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	cub3d
 
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror



LIBS		=	minilibx-linux/libmlx.a
LIBS		+=	minilibx-linux/libmlx_Linux.a
LIBS		+=	minilibx-linux/libmlx_x86_64.a
LIBS		+=	-I./includes/
LIBS		+=	-I./libft/
LIBS		+=	./libft/libft.a
#cc main.c -L -lmlx -L./minilibx-linux/libmlx -lXext -lX11 -lm -lbsd minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a minilibx-linux/libmlx_x86_64.a
#cc main.c -L -lmlx -L./minilibx-linux/libmlx -lXext -lX11 -lm -lbsd minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a minilibx-linux/libmlx_x86_64.a  -I./libft  ./srcs/ft_infos2.c -I./includes ./srcs/ft_infos3.c ./srcs/ft_infos.c ./srcs/ft_map2.c ./srcs/ft_map.c ./srcs/ft_outils.c ./srcs/ft_parsing.c ./srcs/get_next_line.c ./srcs/get_next_line_utils.c  libft.a


INCLUDE		=	-L	-lmlx
INCLUDE		+=	-lXext
INCLUDE		+=	-lX11	
INCLUDE		+=	-lm
INCLUDE		+=	-lbsd

RM			=	rm -f

SRCS		=	get_next_line.c
SRCS		+=	get_next_line_utils.c
SRCS		+=	ft_parsing.c
SRCS		+=	ft_infos.c
SRCS		+=	ft_infos2.c
SRCS		+=	ft_infos3.c
SRCS		+=	ft_outils.c
SRCS		+=	ft_map.c
SRCS		+=	ft_map2.c


OBJS		=	$(addprefix ./srcs/, ${SRCS:.c=.o})

.c.o:
	${CC} ${CFLAGS} $(INCLUDE) -g -c $< -o ${<:.c=.o}

all:	${NAME}


$(NAME):	$(OBJS)
	make -C ./libft
	ar -rcs $(NAME) $(OBJ) $(OBJS)
	$(CC)	$(CFLAGS) $(LIBS) $(INCLUDE) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o	$(NAME)	

clean:
	make clean -C ./libft
	${RM} ${OBJS} $(OBJ)

fclean: clean
	make fclean -C ./libft
	${RM} ${NAME}

re:	fclean all

.PHONY : all clean fclean re
