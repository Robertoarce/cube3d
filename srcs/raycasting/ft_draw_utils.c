/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:03:06 by titorium          #+#    #+#             */
/*   Updated: 2020/11/16 17:08:38 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double	ft_addangle(double angle, double paso)
{
	angle = angle + paso;
	if (angle < 0)
		angle = (2 * PI) + angle;
	if (angle >= (2 * PI))
		angle = angle - (2 * PI);
	return (angle);
}
