# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: titorium <rarce@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 09:23:07 by titorium          #+#    #+#              #
#    Updated: 2020/10/26 14:12:41 by titorium         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	cub3d

# --------- SYSTEM TARGETING -- #
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	MLX_DIR	= ./minilibx-linux
	MLX 	= -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
	ENV		= -D LINUX
	CC		=	clang
else
	MLX_DIR	= ./minilibx_mms_20200219
	MLX 	= -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit
	ENV		=
	CC		=	gcc
endif

CFLAGS		=	-Wall -Wextra -Werror -g

# --------- SOURCES ------------------- #

# Main
SRCS		= cub3d.c

#	GNL
SRCS		+=	gnl/get_next_line.c
SRCS		+=	gnl/get_next_line_utils.c

#	UTILS
SRCS		+= utils/ft_outils.c

#	PROCESS
SRCS		+= process/ft_start.c
SRCS		+= process/ft_finish.c

#	PARSING
SRCS		+=	parsing/ft_categorize.c
SRCS		+=	parsing/ft_categorize_rfc.c
SRCS		+=	parsing/ft_categorize_rest.c
SRCS		+=	parsing/ft_map.c
SRCS		+=	parsing/ft_mapcheck.c
SRCS		+=	parsing/ft_mapcheck2.c
SRCS		+=	parsing/ft_parsing_main.c
SRCS		+=	parsing/ft_parsing_main2.c

#	RAYCASTING


SRCS		+=	raycasting/ft_mainloop.c
SRCS		+=	raycasting/ft_draw_utils.c
SRCS		+=	raycasting/ft_geometry.c
SRCS		+=	raycasting/ft_drawminimap.c
SRCS		+=	raycasting/ft_drawplayer.c
SRCS		+=	raycasting/ft_moveplayer.c




#cc main.c -L -lmlx -L./minilibx-linux/libmlx -lXext -lX11 -lm -lbsd minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a minilibx-linux/libmlx_x86_64.a
#cc main.c -L -lmlx -L./minilibx-linux/libmlx -lXext -lX11 -lm -lbsd minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a minilibx-linux/libmlx_x86_64.a  -I./libft  ./srcs/ft_infos2.c -I./includes ./srcs/ft_infos3.c ./srcs/ft_infos.c ./srcs/ft_map2.c ./srcs/ft_map.c ./srcs/ft_outils.c ./srcs/ft_parsing.c ./srcs/get_next_line.c ./srcs/get_next_line_utils.c  libft.a



# --------- INCLUDES  ------------------- #

LIBFT		= ./srcs/libft/libft.a
LIBFTPATH	= ./srcs/libft/
INC_MINIX	= -I./includes/
INC_MINIX	+= -I$(LIBFTPATH)
INC_MINIX	+= -I$(MLX_DIR)


# --------- OBJS ----------------------- #

OBJS		=	$(addprefix ./srcs/, ${SRCS:.c=.o})

#-----------------------------#
#------- COMPILATION ---------#
#-----------------------------#

all: $(NAME)

.c.o:
	${CC} $(INC_MINIX) $(ENV) ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	$(MAKE) -C $(LIBFTPATH)
	cp $(LIBFT) ./$(NAME)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(INC_MINIX)  $(OBJS)  -o	$@ $(MLX) -L$(LIBPATH) -lft $(LIBFT)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFTPATH)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE)

.PHONY : all clean fclean re
