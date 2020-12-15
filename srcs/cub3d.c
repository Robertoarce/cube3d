/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:07:00 by titorium          #+#    #+#             */
/*   Updated: 2020/12/15 15:39:20 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	"cublib.h"
#include	"libft.h"


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
	printf("data.player ->%d\n",data.presence_player);
	printf("data.player.posx ->%d\n",data.player.posx);
	printf("data.player.posy ->%d\n",data.player.posy);
	printf("data.player.angle ->%f\n",data.player.angle);
	printf("data.player ->%d\n",data.presence_player);
	printf("data.cols->%d\n",data.cols);
	printf("data.rows ->%d\n",data.rows);
	printf("data.mapsize.x(cols size))->%d\n",data.map_size.cols_size);
	printf("data.mapsize.y(row size)->%d\n",data.map_size.rows_size);
	printf(" ==== MAP =====\n");
	int counter = 0;
	while (data.map[counter] != NULL)
	{
		printf( "%s\n",data.map[counter]);
		counter++;
	}
}

/*
*** Main loop: create image + move + drawminimap + drawplayer 
***				+ raycast + put on window + sync + destroy
*/


int	ft_mainloop(int keycode, t_data *data)
{

ft_putstr("\nr 0 >>>=");
ft_putnbr(data->r[0]);
ft_putstr("\nr 1 >>>>=");
ft_putnbr(data->r[1]);

	if ((data->img.img = mlx_new_image(data->mlx,
					data->r[0], data->r[1])) == NULL)
		return (ft_error("Error: Can't init new image, check drivers"));
ft_putstr("\narrived here");
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);


	ft_move(keycode, data);
	ft_drawminimap(*data, &data->img);
	ft_drawplayer(&*data, &data->img);
	//ft_draw3d(&*data, &data->img);

	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_do_sync(data->mlx);
	mlx_destroy_image(data->mlx, data->img.img);
	return (0);
}

static int	ft_window_init(t_data *data)
{    
	if ((data->mlx = mlx_init()) == NULL) // init mlx
        return (ft_error("Error: Can't init mlx, check drivers"));
    if ((data->win = mlx_new_window(data->mlx, data->r[0], data->r[1], "Cub3D")) == NULL) // create window
		return (ft_error("Error: cannot open a new window"));
	if ((data->img.img = mlx_new_image(data->mlx,
					data->r[0], data->r[1])) == NULL)
		return (ft_error("Error: Can't init new image, check drivers"));
	return (1);
}

int main(int argc, char *argv[])
{
	t_data	data;

///  ------  parse all
	if (ft_save(argc, argv) == -1 )
        return (ft_error("Error: too few or the parameters given are wrong"));
	if (ft_cub(argc, argv, &data.cubextention) == -1)
        return (ft_error("Error: the cub given are wrong"));
	if (ft_init(&data) == -1)
		return(ft_error("Error: initializing"));
	if (ft_parseall(&data) == -1)
		return (ft_freeinfos(&data));

	if (ft_window_init(&data) == -1)
		return (-1);

//ft_printit(data);
(void)ft_printit;


ft_putstr("\nr 0=");
ft_putnbr(data.r[0]);
ft_putstr("\nr 1 =");
ft_putnbr(data.r[1]);

	mlx_loop_hook(data.mlx, ft_mainloop, &data);

	mlx_loop(data.mlx);


	//mlx_key_hook(data.win, ft_mainloop, &data);

	return (1);
}



	//mlx_hook(data.win, 2, 1L << 0, ft_key_pressed, &data);
	//mlx_hook(data.win, 3, 1L << 1, ft_key_realeased, &data);
	//mlx_hook(data.win, 33, 1L << 17, ft_exit, &data);