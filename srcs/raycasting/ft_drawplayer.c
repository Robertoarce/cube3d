/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawplayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:05:34 by titorium          #+#    #+#             */
/*   Updated: 2020/10/30 15:03:43 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

void	ft_drawplayer(t_data data, t_pixel *img)
{
	int xdistance;
	int ydistance;

	xdistance = 0;
	ydistance = 0;

	data.player.size.cols_size = data.map_size.cols_size;
	data.player.size.rows_size = data.map_size.rows_size;


		data.player.cube.x0 = data.player.posx * data.player.size.cols_size;
		data.player.cube.y0 = data.player.posy * data.player.size.rows_size;
		data.player.cube.x1 = (data.player.posx + 1) *
			data.player.size.cols_size;
		data.player.cube.y1 = (data.player.posy + 1) *
			data.player.size.rows_size;
		xdistance = data.player.cube.x1 - data.player.cube.x0;
		ydistance = data.player.cube.y1 - data.player.cube.y0;

		xdistance = xdistance * 3 / 5;
		ydistance = ydistance * 3 / 5;

		data.player.cube.x1 = data.player.cube.x1 - (xdistance / 2) + data.player.dx ;
		data.player.cube.y1 = data.player.cube.y1 - (ydistance / 2) + data.player.dy;
		data.player.cube.x0 = data.player.cube.x0 + (xdistance / 2) + data.player.dx;
		data.player.cube.y0 = data.player.cube.y0 + (ydistance / 2) + data.player.dy;


		if (data.player.cube.x1 < data.player.cube.x0 + xdistance/2 )
			data.player.cube.x1 = data.player.cube.x0 + xdistance/2;

		if (data.player.cube.x0 < 0)
			data.player.cube.x0 = 0;

		if (data.player.cube.y1 < data.player.cube.y0 + ydistance/2 )
			data.player.cube.y1 = data.player.cube.y0 + ydistance/2;

		if (data.player.cube.y0 < 0)
			data.player.cube.y0 = 0;


		ft_drawcube(data.player.cube, img, 0xFFFFFF00);
}
