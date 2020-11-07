/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:29:23 by titorium          #+#    #+#             */
/*   Updated: 2020/11/03 15:28:25 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

void		ft_drawcube(t_cube cube, t_pixel *img, int color)
{
	double x;
	double y;

	x = cube.x0 + 1;
	while (x < cube.x1)
	{
		y = cube.y0 + 1;
		while (y < cube.y1)
		{
			my_mlx_pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
}

static void	ft_adding(int *err, int y, int *cube, int sx)
{
	*err += y;
	*cube += sx;
}

void		ft_drawline(t_cube cube, t_pixel *img, int color, int e2)
{
	int		x;
	int		y;
	int		sx;
	int		sy;
	int		err;

	x = abs(cube.x1 - cube.x0);
	sx = cube.x0 < cube.x1 ? 1 : -1;
	y = abs(cube.y1 - cube.y0) * -1;
	sy = cube.y0 < cube.y1 ? 1 : -1;
	err = x + y;
	while (1)
	{
		my_mlx_pixel_put(img, cube.x0, cube.y0, color);
		if (cube.x0 == cube.x1 && cube.y0 == cube.y1)
			break ;
		e2 = 2 * err;
		if (e2 >= y)
			ft_adding(&err, y, &cube.x0, sx);
		if (e2 <= x)
			ft_adding(&err, x, &cube.y0, sy);
	}
}
