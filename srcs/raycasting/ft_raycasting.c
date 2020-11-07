/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:03:44 by titorium          #+#    #+#             */
/*   Updated: 2020/11/07 15:58:14 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cublib.h"
#include	"libft.h"

/*
*** This functions tell you the distance until you impact a wall
*/

static int	ft_dist_topright(t_data data, int x, int y)
{
	int rx;
	int ry;
	int dx;
	int dy;

	int counter;

	ft_putstr("\n====== START =");
/*		ft_putstr("\nx =");
		ft_putnbr(x);
		ft_putstr("\t cols=");
		ft_putnbr(ft_xmappos(x, data));
		ft_putstr("\ty =");
		ft_putnbr(y);
		ft_putstr("\t rows=");
		ft_putnbr(ft_ymappos(y, data));

		ft_putstr("\nxmap =");
		ft_putnbr(data.player.posx);
		ft_putstr("\nymap =");
		ft_putnbr(data.player.posy);

		ft_putstr("\ncols size=");
		ft_putnbr(data.map_size.cols_size);
		ft_putstr("\trows size=");
		ft_putnbr(data.map_size.rows_size);
*/
	ft_putstr("\n -----");

	counter = 0;
int	counterx = 1;
int	countery = 1;
	while (counter++ < 11)
	{
		ft_putstr("\n -counter =");
		ft_putnbr(counter);

		rx = (ft_xmappos(x, data) + counterx) * data.map_size.cols_size; //we get left side of next col
		ry = (ft_ymappos(y, data) + countery) * data.map_size.rows_size; //we get upper side 
		dx = rx - x; // distance from sides of the square
		dy = -ry + y; // same but vertical
		dx = (int)(dx / cos(data.player.angle)); //hypotenus distance on x
		dy = (int)(dy / sin(data.player.angle)); // same on y
	
	/*	ft_putstr("\nrx =");
		ft_putnbr(rx);
		ft_putstr("\try =");
		ft_putnbr(ry);

		ft_putstr("\ndx =");
		ft_putnbr(dx);
		ft_putstr("\tdy =");
		ft_putnbr(dy);
*/
		if (dx < dy && dx >= 0 )
		{	
			ft_putstr("dx < dy");
			if ( ft_checkwall(ft_xmappos(rx, data) , ft_ymappos(ry, data) -1 , data) == 1)
			{

			ft_putstr("yes");
				ft_putstr("\ndx =");
				ft_putnbr(dx );

				return(dx);
			}
			ft_putstr("nope");
			counterx++;
		}
	/*	else if (dy < dx && ft_checkwall(x, ry++, data))
		{
			return(dy);
			break;
		}
		else if (dy == dx && (ft_checkwall(x, ry - 1, data ) || ft_checkwall(rx - 1, ry, data)))
		{
			return(dy);
			break;
		}*/
	}
	return (0);
}

static int 	ft_raydist(t_data data, t_cube cube)
{
	double	angle;
	int		x;
	int		y;

	x = cube.x0 + ((cube.x1 - cube.x0) / 2);
	y = cube.y0 + ((cube.y1 - cube.y0) / 2);

	angle = data.player.angle;
//	if (angle > PI * 3 / 2)
//		return (ft_dist_botright(data, x, y, offsetx, offsety));
//	if (angle > PI)
//		return (ft_dist_botleft(data, x, y, offsetx, offsety));
//	if (angle > PI / 2)
//		return (ft_dist_topleft(data, x, y, offsetx, offsety));
	return (ft_dist_topright(data, x, y));
}



void	ft_drawray(t_data data, t_cube playercube, t_pixel *img)
{
	int raydistance;

	raydistance = ft_raydist(data, playercube);
	ft_drawtail(data, img, 0x0000FFFFF, raydistance);
(void) data;
(void) img;
(void) ft_raydist;

}

