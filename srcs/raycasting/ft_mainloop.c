/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mainloop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:34:25 by titorium          #+#    #+#             */
/*   Updated: 2020/10/28 19:11:17 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cublib.h"
#include	"libft.h"

int	ft_mainloop(int keycode, t_data *data) 
{

	if ((data->img.img = mlx_new_image(data->mlx_ptr, data->r[0], data->r[1])) == NULL) // image canvas
		return (ft_error("Error: Can't init new image, check drivers"));
    
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel , &data->img.line_length, &data->img.endian); // image info //32= 4 char x 8 bits

	if (!ft_move(keycode, data))
		return(0);
	
	ft_drawminimap(*data, &data->img);
	ft_drawplayer(*data, &data->img);
	
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img, 0, 0); //image to window
	mlx_do_sync(data->mlx_ptr);

	/*-------------------------------------------*/
	mlx_destroy_image(data->mlx_ptr, data->img.img);

	
	return(1);

}	


