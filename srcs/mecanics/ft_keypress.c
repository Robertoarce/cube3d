/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:16:48 by rarce             #+#    #+#             */
/*   Updated: 2020/12/15 12:38:07 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

int		ft_key_pressed(int keycode, t_data *data)
{
	if (keycode == FORWD)
		data->move.fwd = 1;
	else if (keycode == BACKWD)
		data->move.bck = 1;
	else if (keycode == LEFT)
		data->move.left = 1;
	else if (keycode == RIGHT)
		data->move.right = 1;
	else if (keycode == TURN_L)
		data->move.turn_l = 1;
	else if (keycode == TURN_R)
		data->move.turn_r = 1;
	return (0);
}

int		ft_key_realeased(int keycode, t_data *data)
{
	if (keycode == FORWD)
		data->move.fwd = 0;
	else if (keycode == BACKWD)
		data->move.bck = 0;
	else if (keycode == LEFT)
		data->move.left = 0;
	else if (keycode == RIGHT)
		data->move.right = 0;
	else if (keycode == TURN_L)
		data->move.turn_l = 0;
	else if (keycode == TURN_R)
		data->move.turn_r = 0;
	return (0);
}

int		ft_exit(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_freeinfos(data);
	return (0);
}