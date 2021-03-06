/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:44:04 by titorium          #+#    #+#             */
/*   Updated: 2020/12/15 12:29:13 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBLIB_H
# define CUBLIB_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	32
# endif

# define SUCCESS		0
# define FAILURE		-1
# define TRUE			1
# define FALSE			0


# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"
# include <mlx.h>


/*
***	-----------	Standard Keys	-----------------
*/

# ifdef __linux__

#  define ESC 		65307
#  define EXIT_BTN	33

#  ifndef QWERTY
#   define FORWD 	119
#   define BACKWD 	115
#   define LEFT 	97
#   define RIGHT 	100
#   define TURN_L 	65363
#   define TURN_R 	65361
#  endif

#  ifdef QWERTY
#   define FORWD 	119
#   define BACKWD 	115
#   define LEFT 	97
#   define RIGHT 	100
#   define TURN_L 	65363
#   define TURN_R 	65361
#  endif
# endif

# ifdef __APPLE__
#  define FORWD 	13
#  define BACKWD 	1
#  define LEFT 		0
#  define RIGHT 	2
#  define TURN_L 	124
#  define TURN_R 	123
#  define ESC 		53
#  define EXIT_BTN	17
# endif

# define PI 3.14159265358979323
# define MINIMAPSIZE 1
# define PASO 
/*
***	-----------	 Get next line Lib	-----------------
*/

int		get_next_line(int fd, char **line);
int		ft_findnl(char *tab);
char	*ft_strncpy(char *dst, char *src, int size);

/*
***	-----------	 Cub3D  Lib	 ------------------------
*/

/*
*** 				GAME DATA
*/
typedef struct s_cube
{
	int	x0;
	int x1;
	int y0;
	int y1;
}				t_cube;

typedef	struct	s_cell
{
	int		cols_size;
	int		rows_size;
}				t_cell;

/*
*** dir = 1 right / -1 left
***	speed = 1 foward / -1 backwards
***	move_speed = movement per sec
*** rot_speed = rotation speed, 6 degrees (PI/360 * 6 )
*/

typedef struct	s_player
{
	int		posx;
	int		posy;
	double	dx;
	double	dy;
	double	angle;
	int		dir;
	int		speed;
	double	movespeed;
	double	rotspeed;
	int		firstcube;
	t_cube	cube;
	t_cell	size;
}				t_player;

typedef struct s_move
{
	int fwd;
	int bck;
	int left;
	int right;
	int turn_l;
	int turn_r;
	/* data */
}				t_move;


typedef struct  s_pixel 
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_pixel;


typedef struct    s_data
{
	void			*mlx;
	void			*win;

	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	char			*cubextention;
	int				r[3];
	int				f[4];
	int				c[4];
	char			**map;
	int				cols;
	int				rows;
	int				start;
	int				presence_player;
	int				x;
	int				y;
	t_player		player;
	t_cell			map_size;
	t_move			move;
	t_pixel			img;
	t_cube			cube;
}                 t_data;


/*
*** 				PARSING
*/
int		ft_init(t_data *data);
int		ft_parse(char *line, t_data *data, int counter);
int		ft_categorize(char **split, int slots, t_data *data);
int		ft_add_r(char **split, int slots, t_data *data);
int		ft_add_f(char **split, int slots, t_data *data);
int		ft_add_c(char **split, int slots, t_data *data);
int		ft_add_no(char **split, int slots, t_data *data);
int		ft_add_so(char **split, int slots, t_data *data);
int		ft_add_we(char **split, int slots, t_data *data);
int		ft_add_ea(char **split, int slots, t_data *data);
int		ft_add_s(char **split, int slots, t_data *data);

int		ft_top(t_data *data, int place, int x);
int		ft_bot(t_data *data, int place, int x);
int		ft_left(t_data *data, int place, int x);
int		ft_right(t_data *data, int place, int x);

int		ft_parseall(t_data *data);
int		ft_mapappend(char *ptr, t_data *data);
int		ft_mapcheck(t_data *data);

/*
*** 				SAVE & CUB CHECK				
*/

int		ft_save(int arg, char **argv);
int ft_cub(int argc, char **argv, char **cubextention);

/*
*** 				UTILS				
*/

int		ft_error(char *tab);
int		ft_isposnum(char *tab);
int		ft_freeinfos(t_data *data);
int		ft_validstr(char *data);

/*
***					MAIN cube3d.c
*/
int		ft_mainloop(int keycode, t_data *data);

/*
***					MECANICS
*/

int		ft_move(int keycode, t_data *data);

int		ft_key_pressed(int keycode, t_data *data);
int		ft_key_realeased(int keycode, t_data *data);
int		ft_exit(int keycode, t_data *data);

/*
***					DRAWING
*/


void	ft_drawcube(t_cube cube, t_pixel *img, int color);
void	ft_drawline(t_cube cube, t_pixel *img, int color, int e2);
void	ft_drawplayer(t_data *data, t_pixel *img);
void	ft_drawminimap(t_data data, t_pixel *img);

void	ft_drawtail(t_data data, t_pixel *img, int color, int paso);

/*
***					DRAWING UTILS
*/

void    my_mlx_pixel_put(t_pixel *data, int x, int y, int color);
long double	ft_addangle(long double angle,long  double paso);

/*
***					RAYCASTING
*/

void	ft_raycast(t_data *data, t_cube cube, t_pixel *img);
int		ft_get_distance(t_data data, int x, int y, int counter);
int		ft_raydist(t_data data, t_cube cube, double angle);

/*
***					RAYCASTING UTILS 1 2 3
*/

int		ft_mx(int x, t_data data);
int		ft_my(int y, t_data data);
int		ft_wal(int x, int y, t_data data);
int		ft_cuadrant(double angle);

int		ft_give_nextwall(int isx, int value, t_data data);
int		ft_give_prevwall(int isx, int value, t_data data);

int		ft_getdx(int x, t_data data, int *wallx);
int		ft_getdy(int y, t_data data, int *wally);

int		ft_returndx(int dx);
int		ft_returndy(int dy);
int		ft_calc_hx(int x, t_data data, int *wallx);
int		ft_calc_hy(int y, t_data data, int *wally);

/*
***					RAYCASTING  PLAYER UTILS
*/

void	ft_createplayercube(t_data *data, int xdistance, int ydistance);
void	ft_createplayercube2(t_data *data, int xdistance, int ydistance);

/*
***					RAYCASTING  3D
*/

void	ft_draw3d(t_data *data, t_pixel *img);


#endif