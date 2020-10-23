/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:29:23 by titorium          #+#    #+#             */
/*   Updated: 2020/10/19 17:30:05 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cublib.h"
#include	"libft.h"

void	ft_plotline(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1)
{
	int x;
	int y;
	int dx;
	int dy;
	int d;
ft_putstr("\n arrived");
	dx = x1 - x0;
	dy = y1 - y0;
	d = 2 * dy - dx;
	y = y0;
	x = x0;
	while (x < x1)
	{
		mlx_pixel_put(&mlx_ptr, &win_ptr, x, y, 0xFF00FFFF);
        if (d > 0)
		{
               y = y + 1;
               d = d - 2*dx;
		}
        d = d + 2*dy;
		x++;
	}

}
