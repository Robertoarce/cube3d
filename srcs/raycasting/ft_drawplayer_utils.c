/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawplayer_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:18:45 by titorium          #+#    #+#             */
/*   Updated: 2020/11/16 14:37:27 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

void	ft_createplayercube2(t_data *data, int xdistance, int ydistance)
{
	data->player.cube.x1 = data->player.cube.x1 -
		(xdistance / 2) + data->player.dx;
	data->player.cube.y1 = data->player.cube.y1 -
		(ydistance / 2) + data->player.dy;
	data->player.cube.x0 = data->player.cube.x0 +
		(xdistance / 2) + data->player.dx;
	data->player.cube.y0 = data->player.cube.y0 +
		(ydistance / 2) + data->player.dy;
	if (data->player.cube.x1 < data->player.cube.x0 + xdistance / 2)
		data->player.cube.x1 = data->player.cube.x0 + xdistance / 2;
	if (data->player.cube.x0 < 0)
		data->player.cube.x0 = 0;
	if (data->player.cube.y1 < data->player.cube.y0 + ydistance / 2)
		data->player.cube.y1 = data->player.cube.y0 + ydistance / 2;
	if (data->player.cube.y0 < 0)
		data->player.cube.y0 = 0;
}

void	ft_createplayercube(t_data *data, int xdistance, int ydistance)
{
	data->player.size.cols_size = data->map_size.cols_size;
	data->player.size.rows_size = data->map_size.rows_size;
	data->player.cube.x0 = data->player.posx * data->player.size.cols_size;
	data->player.cube.y0 = data->player.posy * data->player.size.rows_size;
	data->player.cube.x1 = (data->player.posx + 1) *
		data->player.size.cols_size;
	data->player.cube.y1 = (data->player.posy + 1) *
		data->player.size.rows_size;
	xdistance = data->player.cube.x1 - data->player.cube.x0;
	ydistance = data->player.cube.y1 - data->player.cube.y0;
	xdistance = xdistance * 3 / 5;
	ydistance = ydistance * 3 / 5;
	ft_createplayercube2(data, xdistance, ydistance);
}
