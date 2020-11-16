/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:03:44 by titorium          #+#    #+#             */
/*   Updated: 2020/11/16 17:10:06 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

static int	ft_x(int wallx, int x, t_data data)
{
	if (ft_mx(x, data) + wallx > -1 &&
			ft_mx(x, data) + wallx < data.cols)
		return (1);
	return (0);
}

static int	ft_y(int wally, int y, t_data data, int counter)
{
	if (ft_my(y, data) + wally > -1 &&
				ft_my(y, data) + wally < data.rows && counter < 20)
		return (1);
	return (0);
}

static int	ft_get_distance(t_data data, int x, int y, int counter)
{
	int walx;
	int waly;
	int hx;
	int hy;

	walx = 0;
	waly = 0;
	while (ft_x(walx, x, data) && ft_y(waly, y, data, counter++))
	{
		hx = ft_calc_hx(x, data, &walx);
		hy = ft_calc_hy(y, data, &waly);
		if (abs(hx) <= abs(hy))
		{
			waly = ft_give_prevwall(0, waly, data);
			if (ft_wal(ft_mx(x, data) + walx, ft_my(y, data) + waly, data) == 1)
				return (ft_returndx(hx));
		}
		if (abs(hy) < abs(hx))
		{
			walx = ft_give_prevwall(1, walx, data);
			if (ft_wal(ft_mx(x, data) + walx, ft_my(y, data) + waly, data) == 1)
				return (ft_returndy(hy));
		}
	}
	return (0);
}

static int	ft_raydist(t_data data, t_cube cube, double angle)
{
	int		x;
	int		y;
	int		cuadrant;

	x = cube.x0 + ((cube.x1 - cube.x0) / 2);
	y = cube.y0 + ((cube.y1 - cube.y0) / 2);
	cuadrant = ft_cuadrant(angle);
	return (ft_get_distance(data, x, y, 0));
}

void		ft_raycast(t_data *data, t_cube playercube, t_pixel *img)
{
	double	step;
	double	aux;
	int		raydistance;
	int		counter;

	counter = 0;
	aux = data->player.angle;
	step = PI / 180;
	data->player.angle = ft_addangle(data->player.angle, -30 * step);
	while (counter++ < 61)
	{
		data->player.angle = ft_addangle(data->player.angle, step);
		raydistance = ft_raydist(*data, playercube, data->player.angle);
		ft_drawtail(*data, img, 0x000FFFF00, raydistance);
	}
	data->player.angle = aux;
}
