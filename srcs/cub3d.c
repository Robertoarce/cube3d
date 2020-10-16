/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:07:00 by titorium          #+#    #+#             */
/*   Updated: 2020/10/15 18:40:12 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<fcntl.h>
#include	"cublib.h"
#include	"libft.h"

#include <mlx.h>



/*
static void ft_printit(t_data data)
{
	printf("\n ==== DATA =====\n");
	printf("data.r ->%d,%d\n",data.r[0],data.r[1]);
	printf("data.f ->%d,%d,%d\n",data.f[0],data.f[1],data.f[2]);
	printf("data.c ->%d,%d,%d\n",data.c[0],data.c[1],data.c[2]);
	printf("data.no ->%s\n",data.no);
	printf("data.so ->%s\n",data.so);
	printf("data.we ->%s\n",data.we);
	printf("data.ea ->%s\n",data.ea);
	printf("data.s ->%s\n",data.s);
	printf("data.map ->%s\n",*data.map);
	printf("data.start ->%d\n",data.start);
	printf("data.player ->%d\n",data.player);
}
*/
int moveup(int keycode, t_data *data)
{
	if (keycode == 'a' || keycode == 65361)
		data->x = data->x - 50;
	if (keycode == 'd' || keycode == 65363)
		data->x = data->x + 50;
	if (keycode == 'w')
		data->y = data->y - 50;
	if (keycode == 's')
		data->y = data->y + 50;
	ft_putstr("\n  y= ");
	ft_putnbr(data->y);
	ft_putstr("\n  x= ");
	ft_putnbr(data->x);
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	mlx_pixel_put(data->mlx_ptr, data->mlx_win,  data->x, data->y, 0xFF0000FF);//put a pixel

	return (0);
}

int main()//int argc, char *argv[])
{
//	t_img		img;
	t_data        data;
//	int			offset;

	if (ft_readall(&data) == -1)
		return (ft_freeinfos(&data));
//	ft_printit(data);
	if (ft_mapcheck(&data) == -1)
		return (ft_freeinfos(&data));
	
    if ((data.mlx_ptr = mlx_init()) == NULL) // init 
        return (ft_error("Error: Can't init mlx, check drivers"));
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, data.r[0], data.r[1], "Cub3D")) == NULL) // create window
		return (ft_error("Error: cannot open a new window"));

//	if ((img.img = mlx_new_image(data.mlx_ptr, 1920,1080)) == NULL) // image
//		return (ft_error("Error: Can't init mlx, check drivers"));

   //img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian); // create a img

	mlx_pixel_put(data.mlx_ptr, data.mlx_win,  data.x, data.y, 0xFF00FFFF);//put a pixel

//	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, img.img, 0, 0);// put the img in the window
	mlx_key_hook(data.mlx_win, moveup, &data);
	ft_putstr("\n outside value of X, x= ");
	ft_putnbr(data.x);
	mlx_loop(data.mlx_ptr);

	return (0);
}
