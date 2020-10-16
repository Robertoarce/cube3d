/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:13:02 by titorium          #+#    #+#             */
/*   Updated: 2020/10/15 16:55:51 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

/*
***		Initialize game values
*/

void	ft_init(t_data *data)
{
	data->r[0] = -1;
	data->r[1] = -1;
	data->f[0] = -1;
	data->f[1] = -1;
	data->f[2] = -1;
	data->c[0] = -1;
	data->c[1] = -1;
	data->c[2] = -1;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->s = NULL;
	data->map = ft_strnew2(1);
	data->start = -1;
	data->player = 0;
	data->x = 500;
	data->y = 500;
}