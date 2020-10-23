/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:36:15 by titorium          #+#    #+#             */
/*   Updated: 2020/10/23 11:49:04 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cublib.h"

/*
*** CHECKS MAP
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

static int	ft_playercheck(char *line, t_data *data)
{
	int counter;

	counter = 0;
	while (line[counter] != '\0')
	{
		if (ft_findc("NSEWnsew", line[counter]) > -1)
		{
			data->presence_player = data->presence_player + 1;
			data->player.posx = ft_findc("NSEWnsew", line[counter]);
			data->player.posy = counter;
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
***	START MAP PARSING - APPEND LINE
*/

int			ft_mapcheck(t_data *data)
{
	int	x;
	x = 0;
	while (data->map[x] != NULL)
	{
		if (ft_lettercheck(data->map[x]) == -1)
			return (-1);
		if (ft_playercheck(data->map[x], &*data) == -1)
			return (-1);
		if (ft_closecheck(data->map[x], &*data, x) == -1)
			return (-1);
		x++;
	}
	if (data->presence_player < 1)
		return (ft_error("Error: invalid map, less than 1 player"));
	return (0);
}
