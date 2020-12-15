/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:13:02 by titorium          #+#    #+#             */
/*   Updated: 2020/12/15 12:16:03 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

static int	ft_findfile(t_data *data)
{
	int fd;

	if ((fd = open(data->cubextention, O_DIRECTORY)) != -1)
		return (ft_error("\nERROR: not valid directory"));
	if ((fd = open(data->cubextention, O_RDONLY)) == -1)
		return (ft_error("\nERROR: file not found\n"));
	return(1);
}

/*
***		Initialize game values
*/

static void	ft_init_player(t_data *data)
{	
	data->player.posx = 0;
	data->player.posy = 0;
	data->player.dx = 0;
	data->player.dy = 0;
	data->player.angle = 0;
	data->player.dir = 0;
	data->player.speed = 0;
	data->player.firstcube = 0;
	data->player.movespeed = 0.16;
	data->player.rotspeed = 6 * PI / 180;

}
/*
***		Initialize game values
*/

int	ft_init(t_data *data)
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
	data->presence_player = 0;
	data->x = 1;
	data->y = 1;
	data->rows = 0;
	data->cols = 0;
	ft_init_player(data);

	if (ft_findfile(data) == -1)
		return (-1);
	return(0);
}
