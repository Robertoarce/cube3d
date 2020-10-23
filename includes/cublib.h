/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:44:04 by titorium          #+#    #+#             */
/*   Updated: 2020/10/23 11:00:07 by titorium         ###   ########.fr       */
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

#  ifndef AZERTY
#   define FORWD 	122
#   define BACKWD 	115
#   define LEFT 	113
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
	int cols_size;
	int rows_size;
}				t_cube;

typedef struct	s_player
{
	int		posx;
	int		posy;
	float	dx;
	float	dy;
	float	angle;
}				t_player;



typedef struct    s_data
{
	void			*mlx_ptr;
	void			*mlx_win;

	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
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
}                 t_data;


/*
*** 				PARSING
*/
void	ft_init(t_data *data);
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

int		ft_parseall(t_data *data);
int		ft_mapappend(char *ptr, t_data *data);
int		ft_mapcheck(t_data *data);

/*
*** 				UTILS				
*/

int		ft_error(char *tab);
int		ft_isposnum(char *tab);
int		ft_freeinfos(t_data *data);
int		ft_validstr(char *data);

/*
*** 				GAME MOVEMENT				
*/


int		ft_top(t_data *data, int place, int x);
int		ft_bot(t_data *data, int place, int x);
int		ft_left(t_data *data, int place, int x);
int		ft_right(t_data *data, int place, int x);

/*
***					RAYCASTING
*/

typedef struct  s_pixel 
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_pixel;



typedef struct	s_ray
{
	double		posx; //position x du joueur
	double		posy; //position y du joueur
	double		dirx; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double		diry; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double		planx; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double		plany; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double		raydirx; //calcul de direction x du rayon
	double		raydiry; //calcul de direction y du rayon
	double		camerax; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int		mapx; // coordonée x du carré dans lequel est pos
	int		mapy; // coordonnée y du carré dans lequel est pos
	double		sidedistx; //dist rayon jusqu'au premier point d'intersection vertical (=un coté x)
	double		sidedisty; //dist rayon jusqu'au premier point d'intersection horizontal (= un coté y)
	double		deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadisty; //diste que le rayon parcours entre chaque point d'intersection horizontal
	int		stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x pose
	int		stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int		hit; // 1 si un mur a ete touche, 0 sinon
	int		side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		perpwalldist; // distance du joueur au mur
	int		lineheight; //hauteur de la ligne a dessiner
	int		drawstart; //position de debut ou il faut dessiner
	int		drawend; //position de fin ou il faut dessiner
	int		x; //permet de parcourir tous les rayons
}					t_ray;



void    my_mlx_pixel_put(t_pixel *data, int x, int y, int color);
void	ft_drawcube(t_cube *cube, t_pixel *img, int color);
void	ft_drawplayer(t_data data, t_pixel *img);
void	ft_drawminimap(t_data *data, t_pixel *img);





#endif
