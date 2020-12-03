/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawplayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:05:34 by titorium          #+#    #+#             */
/*   Updated: 2020/11/18 13:05:15 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

static unsigned long ft_color(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}


void	ft_drawtail(t_data data, t_pixel *img, int color, int paso)
{
	double	angle;
	t_cube	*ptr;

	angle = data.player.angle;
	if ((ptr = malloc(sizeof(t_cube))))
	{
		ptr->x0 = data.player.cube.x0 +
			((data.player.cube.x1 - data.player.cube.x0) / 2);
		ptr->y0 = data.player.cube.y0 +
			((data.player.cube.y1 - data.player.cube.y0) / 2);
		ptr->x1 = cos(angle) * paso + ptr->x0;
		ptr->y1 = sin(angle) * paso + ptr->y0;
		my_mlx_pixel_put(img, (int)ptr->x0, (int)ptr->y0, color);
		ft_drawline(*ptr, img, color, 0);
		free(ptr);
	}
}

void	ft_drawplayer(t_data *data, t_pixel *img)
{
	ft_createplayercube(data, 0, 0);
	ft_drawcube(data->player.cube, img, 0xFF00FF00);
	ft_raycast(data, data->player.cube, img);
	ft_drawtail(*data, img, ft_color(0,0,250)  , 40);
}
