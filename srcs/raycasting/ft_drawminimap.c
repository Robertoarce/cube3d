/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawminimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:05:23 by titorium          #+#    #+#             */
/*   Updated: 2020/11/16 14:06:05 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

void	ft_drawminimap(t_data data, t_pixel *img)
{
	int	cols;
	int	rows;

	rows = 0;
	while (rows < data.rows)
	{
		data.cube.y0 = data.map_size.rows_size * (rows);
		data.cube.y1 = data.map_size.rows_size * (rows + 1);
		cols = 0;
		while (cols < data.cols)
		{
			data.cube.x0 = data.map_size.cols_size * (cols);
			data.cube.x1 = data.map_size.cols_size * (cols + 1);
			if (data.map[rows][cols] == '1' &&
					ft_strlen(data.map[rows]) >= cols)
				ft_drawcube(data.cube, &*img, 0x0000AAAA);
			cols++;
		}
		rows++;
	}
}
