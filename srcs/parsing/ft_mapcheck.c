/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:36:15 by titorium          #+#    #+#             */
/*   Updated: 2020/11/07 11:37:16 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cublib.h"

static void	ft_getplayerangle(char c, t_data *data)
{
	if (c == 'N' || c == 'n')
		data->player.angle = PI + PI / 2;
	if (c == 'S' || c == 's')
		data->player.angle = PI / 2;
	if (c == 'E' || c == 'e')
		data->player.angle = 0;
	if (c == 'W' || c == 'w')
		data->player.angle = PI;
}

/*
*** CHECKS MAP + adds the  player pos x
*/

static int	ft_lettercheck(char *line)
{
	int counter;

	counter = 0;
	while (line[counter] != '\0')
	{
		if (ft_findc(" 012NSEWnsew", line[counter]) == -1)
			return (ft_error("Error: invalid map, one letter is not valid"));
		counter++;
	}
	return (0);
}

static int	ft_playercheck(char *line, t_data *data, int x)
{
	int counter;

	counter = 0;
	while (line[counter] != '\0')
	{
		if (ft_findc("NSEWnsew", line[counter]) > -1)
		{
			data->presence_player = data->presence_player + 1;
			data->player.posy = x;
			data->player.posx = counter;
			ft_getplayerangle(line[counter], data);
		}
		counter++;
	}
	if (data->presence_player > 1)
		return (ft_error("Error: invalid map, more than 1 player"));
	return (0);
}

static int	ft_closecheck(char *line, t_data *data, int x)
{
	int counter;

	counter = 0;
	while (line[counter] != '\0')
	{
		if (ft_findc("02NSEWnsew", line[counter]) > -1)
		{
			if (!(ft_top(data, counter, x) == 1 &&
						ft_bot(data, counter, x) == 1 &&
						ft_left(data, counter, x) == 1 &&
						ft_right(data, counter, x) == 1))
				return (-1);
		}
		counter++;
	}
	return (0);
}

/*
***	START MAP CHECK -
*/

int			ft_mapcheck(t_data *data)
{
	int	x;

	x = 0;
	while (data->map[x] != NULL)
	{
		if (ft_lettercheck(data->map[x]) == -1)
			return (-1);
		if (ft_playercheck(data->map[x], &*data, x) == -1)
			return (-1);
		if (ft_closecheck(data->map[x], &*data, x) == -1)
			return (-1);
		x++;
	}
	if (data->presence_player < 1)
		return (ft_error("Error: invalid map, less than 1 player"));
	data->map_size.cols_size = (data->r[0] / MINIMAPSIZE) / data->cols;
	data->map_size.rows_size = (data->r[1] / MINIMAPSIZE) / data->rows;
	ft_createplayercube(data, 0, 0);
	return (0);
}
