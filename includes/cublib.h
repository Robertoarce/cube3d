/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cublib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:44:04 by titorium          #+#    #+#             */
/*   Updated: 2020/10/15 18:30:12 by titorium         ###   ########.fr       */
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
# include <fcntl.h>

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
	int				start;
	int				player;
	int				x;
	int				y;
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

/*
*** 				UTILS				
*/

int		ft_error(char *tab);
int		ft_isposnum(char *tab);

int		ft_freeinfos(t_data *data);
int		ft_readall(t_data *data);
int		ft_validstr(char *data);

int		ft_mapappend(char *ptr, t_data *data);
int		ft_mapcheck(t_data *data);

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




#endif
