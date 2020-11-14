/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 10:06:10 by titorium          #+#    #+#             */
/*   Updated: 2020/11/14 14:13:50 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

/*
*** This functions tell you the distance until you impact a wall
*/

int		ft_give_nextwall(int isx, int value, t_data data)
{
	int		result;
	int		cuadrant;
	double	angle;

	angle = data.player.angle;
	cuadrant = ft_cuadrant(angle);
	result = value;
	if (isx == 1)
	{
		if ((int)(angle * 10000) == (int)(PI * (30000 / 2)) ||
				(int)(angle * 10000) == (int)(PI * 10000 / 2))
			return (result);
		if (cuadrant == 4 || cuadrant == 1)
			return (result + 1);
		return (result - 1);
	}
	if ((int)(angle * 10000) == (int)(PI * 10000) ||
			(int)(angle * 10000) == 0)
		return (result);
	if (cuadrant == 3 || cuadrant == 4)
		return (result - 1);
	return (result + 1);
}

int		ft_give_prevwall(int isx, int value, t_data data)
{
	int		result;
	int		cuadrant;
	double	angle;

	angle = data.player.angle;
	cuadrant = ft_cuadrant(angle);
	result = value;
	if (isx == 1)
	{
		if ((int)(angle * 10000) == (int)(PI * (30000 / 2)) ||
				(int)(angle * 10000) == (int)(PI * 10000 / 2))
			return (result);
		if (cuadrant == 4 || cuadrant == 1)
			return (result - 1);
		return (result + 1);
	}
	if ((int)(angle * 10000) == (int)(PI * 10000) ||
			(int)(angle * 10000) == 0)
		return (result);
	if (cuadrant == 3 || cuadrant == 4)
		return (result + 1);
	return (result - 1);
}

int		ft_returndx(int dx)
{
	int aux;

	aux = dx * -1;
	if (dx < 0)
		return (aux);
	aux = dx;
	return (aux);
}

int		ft_returndy(int dy)
{
	int aux;

	aux = dy * -1;
	if (dy < 0)
		return (aux);
	aux = dy;
	return (aux);
}
