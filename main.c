/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:01:47 by titorium          #+#    #+#             */
/*   Updated: 2020/10/07 17:50:12 by titorium         ###   ########.fr       */
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
	data->start = -1;
	data->player = 0;
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

int ft_freeinfos(t_data *data)
{
	if (data->no != NULL)
		free(data->no);
	if (data->so != NULL)
		free(data->so);
	if (data->we != NULL)
		free(data->we);
	if (data->ea != NULL)
		free(data->ea);
	if (data->s != NULL)
		free(data->s);
	if (data->map != NULL)
		ft_strfree(data->map);
	return (0);
}

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


int main()//int argc, char *argv[])
{

	t_data        data;
	
	if (ft_readall(&data) == -1)
		return (ft_freeinfos(&data));
	ft_printit(data);
	if (ft_mapcheck(&data) == -1)
		return (ft_freeinfos(&data));
//	if (ft_checkmap(&data) == -1)
//		return (0);
/*	
    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
        return (EXIT_FAILURE);
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
*/

/*-----reading the file ------- */
	//ft_putstr("\n ===== map time ====  \n");
	ft_print2d(data.map);
	
	ft_freeinfos(&data);
return (0);
}





