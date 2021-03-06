/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:34:18 by titorium          #+#    #+#             */
/*   Updated: 2020/10/23 11:43:08 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cublib.h"

/*
***	START MAP PARSING - APPEND LINE + count rows
*/

int			ft_mapappend(char *line, t_data *data)
{
	if (line == NULL)
		return (ft_error("line in map is empty?"));
	data->map = ft_append(data->map, line);
	if (data->cols < ft_strlen(line))
		data->cols = ft_strlen(line);
	data->rows++;
	data->start = 1;
	return (1);
}
