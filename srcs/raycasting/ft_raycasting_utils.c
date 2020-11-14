/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:04:47 by titorium          #+#    #+#             */
/*   Updated: 2020/11/14 15:16:45 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

int	ft_mx(int x, t_data data)
{
	int xpos;

	xpos = 0;
	xpos = floor(x / data.map_size.cols_size);
	return (xpos);
}

int	ft_my(int y, t_data data)
{
	int ypos;

	ypos = 0;
	ypos = floor(y / data.map_size.rows_size);
	return (ypos);
}

int	ft_wal(int x, int y, t_data data)
{
	if (x <= data.cols && y <= data.rows && y > -1 && x > -1)
	{
		if (data.map[y][x] == '1' || data.map[y][x] == '2')
			return (1);
	}
	return (0);
}

int	ft_cuadrant(double angle)
{
	if (cos(angle) > 0)
	{
		if (sin(angle) > 0)
			return (1);
		return (4);
	}
	if (sin(angle) > 0)
		return (2);
	return (3);
}
