/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:02:27 by titorium          #+#    #+#             */
/*   Updated: 2020/12/03 12:35:44 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

/*
***  calculates the dy distance = from y to wall given by wally
*/

int	ft_getdy(int y, t_data data, int *wally)
{
	int dypos;
	int cuadrant;

	*wally = ft_give_nextwall(0, *wally, data);
	cuadrant = ft_cuadrant(data.player.angle);
	if (cuadrant == 1 || cuadrant == 2)
	{
		dypos = (ft_my(y, data) + *wally) * data.map_size.rows_size;
		return (dypos - y);
	}
	dypos = (ft_my(y, data) + *wally + 1) * data.map_size.rows_size;
	return (y - dypos);
}

int	ft_calc_hy(int y, t_data data, int *wally)
{
	int aux;
	int dy;

	dy = ft_getdy(y, data, wally);
	aux = 100000;
	if (data.player.angle != PI && data.player.angle != 0)
		aux = (int)(dy / (sin(data.player.angle)));
	dy = aux;
	if (dy < -2147483640 || dy > 2147483640)
		dy = 1000000;
	return (abs(dy));
}
