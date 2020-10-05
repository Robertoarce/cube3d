/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:01:47 by titorium          #+#    #+#             */
/*   Updated: 2020/10/05 15:31:05 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<fcntl.h>
#include	"cublib.h"
#include	"libft.h"

//#include <mlx.h>

static void ft_init(t_data *data)
{
	data->r[0] = -1;
	data->r[1] = -1;

	data->f[0] = -1;
	data->f[1] = -1;
	data->f[2] = -1;

	data->c[0] = -1;
	data->c[1] = -1;
	data->c[2] = -1;
	
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->s = NULL;

	data->map = ft_strnew2(1);
	data->max_x = 1;
	data->y = 0;
	data->start = -1;
}

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
		if (ft_parse(line, &*data) == -1)	// get line + add info -> to struct
		   return (-1);

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

void ft_freeinfos(t_data *data)
{
	
	free(data->map);
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
	free(data->s);
	ft_strfree(data->map);
}


int main()//int argc, char *argv[])
{

	t_data        data;
	
	if (ft_readall(&data) == -1)
		return (0);
	
/*	
    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
        return (EXIT_FAILURE);
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
*/

/*-----reading the file ------- */
	ft_freeinfos(&data);
return (0);
}





