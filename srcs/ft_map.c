/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 10:34:18 by titorium          #+#    #+#             */
/*   Updated: 2020/10/05 16:01:16 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cublib.h"

int	ft_mapappend(char *line, t_data *data)
{
	if (line != NULL)
		return (-1);
	data->map = ft_append(data->map,line);
	return(1);
}
