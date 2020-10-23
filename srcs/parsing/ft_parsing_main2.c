/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_main2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:16:19 by titorium          #+#    #+#             */
/*   Updated: 2020/10/23 10:16:21 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cublib.h"

static int	ft_adddata(char **split, t_data *data)
{
	int counter;
	int buton;

	counter = 0;
	buton = 0;
	while ((split + counter)[0] != NULL && split != NULL)
		counter++;
	if (ft_categorize(&*split, counter, &*data) == -1)
		buton = 1;
	while (counter > -1)
		free(split[counter--]);
	free(split);
	if (buton == 1)
		return (-1);
	return (0);
}

void		ft_switch(t_data *data)
{
	if (data->start == 1)
		data->start = 0;
}

int			ft_parse(char *line, t_data *data, int counter)
{
	while (line != NULL)
	{
		while (line[counter] == ' ' || line[counter] == '\t')
			counter++;
		if ((line[counter] == '1' || line[counter] == '0') &&
				(data->start == -1 || data->start == 1))
		{
			if (ft_mapappend(line, data) == -1)
				return (-1);
			break ;
		}
		else if (ft_findc("rfcnsweRFCNSWE", line[counter]) > -1 &&
				data->start == -1)
		{
			ft_switch(data);
			if (ft_adddata(ft_split(&line[counter], ' '), data) == -1 ||
					data->start == 1)
				return (-1);
			break ;
		}
		else
			ft_switch(data);
		break ;
	}
	return (0);
}
