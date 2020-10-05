/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 18:22:45 by titorium          #+#    #+#             */
/*   Updated: 2020/10/05 15:58:53 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include "cublib.h"

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
	printf("data.X ->%d\n",data.max_x);
	printf("data.Y ->%d\n",data.y);
	printf("data.start ->%d\n",data.start);
}


static int	ft_adddata(char **split, t_data *data)
{
	int counter;
	int buton;

	counter = 0;
	buton = 0;
	while ((split + counter)[0] != NULL  && split != NULL)
		counter++;
	if (ft_categorize(&*split, counter, &*data) == -1)
		buton = 1;
	while (counter > -1)
		free(split[counter--]);	
	free(split);
ft_printit(*data);
	if (buton == 1)
		return (-1);
	return (0);
}

int			ft_parse(char *line, t_data *data)
{
	int counter;

	counter = 0;
	while (line != NULL & (line)[counter] != '\0')
	{
		if (line[counter] == ' ' || line[counter] == '\t')
			counter++;
		else if ((line[counter] == '1' || line[counter] == '0') 
				&& (data->start == -1 || data->start == 1))
		{
			if (ft_mapappend(line, data) == -1)
				return (-1);
			break;
		}
		else if (ft_findc("rfcnsweRFCNSWE",line[counter]) > -1)
		{
			if (ft_adddata(ft_split(&line[counter],' '),data) == -1 || data->start == 1)
				return (-1);
			break;
		}
		if (data->start == 1)
			data->start = 0;
		break;
	}
	return (0);
}
