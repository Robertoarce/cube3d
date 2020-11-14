/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 10:26:14 by titorium          #+#    #+#             */
/*   Updated: 2020/11/14 15:19:11 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

/*
*** This functions tell you the distance until you impact a wall
*/
/*
***  calculates the dx distance = from x to the wall given by wallx
*/

int	ft_getdx(int x, t_data data, int *wallx)
{
	int dxpos;
	int cuadrant;

	*wallx = ft_give_nextwall(1, *wallx, data);
	cuadrant = ft_cuadrant(data.player.angle);
	if (cuadrant == 1 || cuadrant == 4)
	{
		dxpos = (ft_mx(x, data) + *wallx) * data.map_size.cols_size;
		return (dxpos - x);
	}
	dxpos = (ft_mx(x, data) + *wallx + 1) * data.map_size.cols_size;
	return (x - dxpos);
}

int	ft_calc_hx(int x, t_data data, int *wallx)
{
	int aux;
	int dx;

	dx = ft_getdx(x, data, wallx);
	aux = 100000;
	if (data.player.angle != PI / 2 && data.player.angle != PI * 3 / 2)
		aux = (int)((dx) / (cos(data.player.angle)));
	dx = aux;
	if (dx < -2147483640 || dx > 2147483640)
		dx = 1000000;
	return (abs(dx));
}
