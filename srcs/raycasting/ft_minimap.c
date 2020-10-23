/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:11:41 by titorium          #+#    #+#             */
/*   Updated: 2020/10/23 11:01:05 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cublib.h"
#include	"libft.h"


void	ft_drawminimap(t_data *data, t_pixel *img)
{	
	int		cols;
	int		rows;
	t_cube	cube;

	cube.cols_size = (data->r[0] / 4) / data->cols;
	cube.rows_size = (data->r[1] / 4) / data->rows;
	rows = 0;
	while (rows < data->rows)
	{
		cube.y0 = cube.rows_size * (rows);
		cube.y1 = cube.rows_size * (rows + 1);
		cols = 0;
	while (cols < data->cols)	
	{
		cube.x0 = cube.cols_size * (cols);
		cube.x1 = cube.cols_size * (cols + 1);
		if (data->map[rows][cols] == '1' && ft_strlen(data->map[rows]) >= cols)
			ft_drawcube(&cube, &*img, 0xFF00FFFF);
		cols++;
	}
	rows++;
	}
}
