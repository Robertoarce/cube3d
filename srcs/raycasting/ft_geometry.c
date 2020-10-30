/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:29:23 by titorium          #+#    #+#             */
/*   Updated: 2020/10/28 16:55:07 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cublib.h"
#include	"libft.h"

void	ft_drawcube(t_cube cube, t_pixel *img, int color)
{
	float	x;
	float y;

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

void	ft_drawline(t_cube cube, t_pixel *img, int color)
{
	int		x;
	int		y;
	float	m;

	x = cube.x0;
	y = cube.y0;
	cube.y1 = cube.y1;
	cube.x1 = cube.x1;

	m = (cube.y1 - cube.y0) / (cube.x1 - cube.x0);
	my_mlx_pixel_put(img, x, y, color);
	my_mlx_pixel_put(img, cube.x1, cube.y1, color);
	while ( x < cube.x1 || y < cube.y1)
	{
		if (x < cube.x1)
			x++;
		if (y < cube.y1)
			y = (int)(m * x);
		my_mlx_pixel_put(img, x, y, color);
	}
}
