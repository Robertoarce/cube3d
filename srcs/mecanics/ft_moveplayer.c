/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moveplayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:12:02 by titorium          #+#    #+#             */
/*   Updated: 2020/12/15 12:28:21 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"
/*
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
}*/

int ft_move(int keycode, t_data *data)
{
	double	newX;
	double	newY;
	double	step;

	(void)keycode;
	step = data->player.speed * data->player.movespeed;

	data->player.angle = data->player.dir * data->player.rotspeed;

	newX = data->player.posx + cosh(data->player.angle) * step;
	newY = data->player.posy + sinh(data->player.angle) * step;

	data->player.posx = newX;
	data->player.posy = newY;
	return (1);
}