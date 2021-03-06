/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:01:47 by titorium          #+#    #+#             */
/*   Updated: 2020/10/15 17:17:27 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include 	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<fcntl.h>
#include	"cublib.h"
#include	"libft.h"

#include <mlx.h>

int	ft_readall(t_data *data)
{
	int fd;
	int r;
	char *line;
	
	fd = open("infos.cub", O_RDONLY);
	ft_init(&*data);

	while((r = get_next_line(fd, &line)) > 0) // while we have a line
	{
		printf("%d |%s\n", r, line);
		if (ft_parse(line, &*data, 0) == -1)	// get line + add info -> to struct
		{
			if (line)
				free(line);
		   	return (-1);
		}

	//	if (ft_checkinput(line,&* tdata)  == -1); //check we have all values
	//		return(-1);

		free(line);
	}
	if (r == -1)
		line = NULL;
	if (line)
		free(line);
	close(fd);
	return (0);
}

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
