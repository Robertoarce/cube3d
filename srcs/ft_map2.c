/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:36:35 by titorium          #+#    #+#             */
/*   Updated: 2020/10/07 17:39:57 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cublib.h"

int	ft_top(t_data *data, int place, int x)
{
	if (x == 0 || !data->map[x - 1][place])
		return (ft_error("Error: map is not closed at top"));
	if (ft_findc("210NSEWnsew", data->map[x - 1][place]) == -1)
		return (ft_error("Error: map is not closed at top"));
	return (1);
}

int	ft_bot(t_data *data, int place, int x)
{
	if (data->map[x + 1] == NULL || !data->map[x + 1][place])
		return (ft_error("Error: map is not closed at bot"));
	if (ft_findc("210NSEWnsew", data->map[x + 1][place]) == -1)
		return (ft_error("Error: map is not closed at bot"));
	return (1);
}

int	ft_left(t_data *data, int place, int x)
{
	if (place == 0)
		return (ft_error("Error: map is not closed at left"));
	if (ft_findc("210NSEWnsew", data->map[x][place - 1]) == -1)
		return (ft_error("Error: map is not closed at left"));
	return (1);
}

int	ft_right(t_data *data, int place, int x)
{
	if (data->map[x][place + 1] == '\0')
		return (ft_error("Error: map is not closed at right"));
	if (ft_findc("210NSEWnsew", data->map[x][place + 1]) == -1)
		return (ft_error("Error: map is not closed at right"));
	return (1);
}
