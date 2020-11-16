/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moveplayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:12:02 by titorium          #+#    #+#             */
/*   Updated: 2020/11/16 14:34:39 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

static int	ft_checkstep(t_data *data)
{
	int x0;
	int x1;
	int y0;
	int y1;

	ft_createplayercube(data, 0, 0);
	x0 = data->player.cube.x0;
	x1 = data->player.cube.x1;
	y0 = data->player.cube.y0;
	y1 = data->player.cube.y1;
	if (ft_wal(ft_mx(x0, *data), ft_my(y0, *data), *data) == 1)
		return (0);
	if (ft_wal(ft_mx(x1, *data), ft_my(y1, *data), *data) == 1)
		return (0);
	if (ft_wal(ft_mx(x1, *data), ft_my(y0, *data), *data) == 1)
		return (0);
	if (ft_wal(ft_mx(x0, *data), ft_my(y1, *data), *data) == 1)
		return (0);
	return (1);
}

static int	ft_move3(int keycode, t_data *data, double lado)
{
	if (keycode == LEFT)
	{
		data->player.angle = data->player.angle - lado;
		if (data->player.angle < 0)
			data->player.angle = (2 * PI) + data->player.angle;
	}
	return (1);
}

static int	ft_move2(int keycode, t_data *data, double paso, double lado)
{
	int		xbf;
	int		ybf;
	double	angle;

	angle = data->player.angle;
	if (keycode == BACKWD)
	{
		xbf = data->player.dx;
		ybf = data->player.dy;
		data->player.dy = -sin(angle) * paso + data->player.dy;
		data->player.dx = -cos(angle) * paso + data->player.dx;
		if (ft_checkstep(data) == 0)
		{
			data->player.dy = ybf;
			data->player.dx = xbf;
		}
	}
	if (keycode == RIGHT)
	{
		data->player.angle = data->player.angle + lado;
		if (data->player.angle >= (2 * PI))
			data->player.angle = data->player.angle - (2 * PI);
	}
	return (ft_move3(keycode, data, lado));
}

int			ft_move(int keycode, t_data *data)
{
	int		xbf;
	int		ybf;
	double	lado;
	double	paso;
	double	angle;

	angle = data->player.angle;
	lado = 0.2;
	paso = 20 / MINIMAPSIZE;
	if (keycode == FORWD)
	{
		xbf = data->player.dx;
		ybf = data->player.dy;
		data->player.dy = sin(angle) * paso + data->player.dy;
		data->player.dx = cos(angle) * paso + data->player.dx;
		if (ft_checkstep(data) == 0)
		{
			data->player.dy = ybf;
			data->player.dx = xbf;
			ft_createplayercube(data, 0, 0);
		}
	}
	return (ft_move2(keycode, data, paso, lado));
}
