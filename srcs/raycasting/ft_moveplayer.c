/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moveplayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:12:02 by titorium          #+#    #+#             */
/*   Updated: 2020/10/30 15:01:59 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cublib.h"
#include	"libft.h"

int ft_move(int keycode, t_data  *data)
{
	int paso;
	int top;
	int bot;
	
	paso = 7;
	top = 65;
	bot = 150;
	if (keycode == FORWD)
		data->player.dy = data->player.dy - paso;
	if (keycode == BACKWD)
		data->player.dy = data->player.dy + paso;
	if (keycode == LEFT)
		data->player.dx = data->player.dx - paso;
	if (keycode == RIGHT)
		data->player.dx = data->player.dx + paso;

	return (1);
}


