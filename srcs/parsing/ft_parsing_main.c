/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:16:57 by titorium          #+#    #+#             */
/*   Updated: 2020/12/07 16:46:45 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cublib.h"

int	ft_parseall(t_data *data)
{
	int		fd;
	int		r;
	char	*line;

	fd = open(data->cubextention, O_RDONLY);	
	while ((r = get_next_line(fd, &line)) > 0)
	{
		if (ft_parse(line, &*data, 0) == -1)
		{
			if (line)
				free(line);
			return (-1);
		}
		free(line);
	}
	if (r == -1)
		line = NULL;
	if (line)
		free(line);
	close(fd);
	if (ft_mapcheck(data) == -1)
		return (-1);
	return (0);
}
