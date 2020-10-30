/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:07:00 by titorium          #+#    #+#             */
/*   Updated: 2020/10/28 19:11:20 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
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
	printf("data.player ->%d\n",data.presence_player);
	printf("data.cols->%d\n",data.cols);
	printf("data.rows ->%d\n",data.rows);
	printf("data.mapsize.x->%d\n",data.map_size.cols_size);
	printf("data.mapsize.y->%d\n",data.map_size.rows_size);
	printf(" ==== DATA =====\n");
}

int main()//int argc, char *argv[])
{
	t_data		data;



	if (ft_parseall(&data) == -1)
		return (ft_freeinfos(&data));

ft_printit(data);


    if ((data.mlx_ptr = mlx_init()) == NULL) // init mlx
        return (ft_error("Error: Can't init mlx, check drivers"));

    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, data.r[0], data.r[1], "Cub3D")) == NULL) // create window
		return (ft_error("Error: cannot open a new window"));

/*--------------------------------------------*/
	mlx_key_hook(data.mlx_win, ft_mainloop, &data);

	mlx_loop(data.mlx_ptr);
	return (0);
}
