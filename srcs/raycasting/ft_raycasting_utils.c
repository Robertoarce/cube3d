/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:04:47 by titorium          #+#    #+#             */
/*   Updated: 2020/11/07 11:17:34 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

int	ft_xmappos(int x, t_data data)
{
	int xpos;

	xpos = 0;
	xpos = floor(x / data.map_size.cols_size);
	return (xpos);
}

int	ft_ymappos(int y, t_data data)
{
	int ypos;

	ypos = 0;
	ypos = floor(y / data.map_size.rows_size);
	return (ypos);
}

int	ft_checkwall(int x, int y, t_data data)
{
	ft_putstr("\nchecking the wall");
		ft_putstr("\nx =");
		ft_putnbr(x);
		ft_putstr("\ty =");
		ft_putnbr(y);

	
	if (x <= data.cols && y <= data.rows && y > -1 && x > -1 )
	{
		ft_putstr("\nmap [y][x] =");
		ft_putchar(data.map[y][x]);

		if (data.map[y][x] == '1' || data.map[y][x] == '2')
		{ft_putstr("\n!!! found a  wall!!!");
			return (1);}
	}
	return (0);
}


