/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:14:17 by titorium          #+#    #+#             */
/*   Updated: 2020/10/23 10:52:43 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cublib.h"
#include	"libft.h"

void            my_mlx_pixel_put(t_pixel *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	ft_drawcube(t_cube *cube, t_pixel *img, int color)
{
	int	x;
	int y;

	x = cube->x0+1;
	while (x < cube->x1)
	{
		y = cube->y0+1;
		while (y < cube->y1)
		{
			my_mlx_pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}

void	ft_drawline(t_cube *cube, t_pixel *img, int color)
{
	int		x;
	int		y;
	float	m;

	x = cube->x0;
	y = cube->y0;
	m = (cube->y1 - cube->y0) / (cube->x1 - cube->x0);
	my_mlx_pixel_put(img, x, y, color); // initial point
	my_mlx_pixel_put(img, cube->x1, cube->y1, color); // final point
	while ( x < cube->x1 || y < cube->y1)
	{
		if (x < cube->x1)
			x++;
		if (y < cube->y1)
			y = (int)(m * x);
		my_mlx_pixel_put(img, x, y, color); // point
	}
}

void ft_drawplayer(t_data data, t_pixel *img)
{
	int xdistance;
	int ydistance;
	t_cube	cube;

	cube.cols_size = (data.r[0] / 4) / data.cols;
	cube.rows_size = (data.r[1] / 4) / data.rows;

	xdistance = cube.x1 - cube.x0;
	ydistance = cube.y1 - cube.y0;

	xdistance = xdistance / 3;
	ydistance = ydistance / 3;

	cube.x1 = cube.x1 - (xdistance / 2);
	cube.y1 = cube.y1 - (ydistance / 2);


	ft_drawcube(&cube, img, 0xFFFFFF00);
}

