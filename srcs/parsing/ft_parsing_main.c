/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:16:57 by titorium          #+#    #+#             */
/*   Updated: 2020/10/23 11:42:17 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cublib.h"

int	ft_parseall(t_data *data)
{
	int		fd;
	int		r;
	char	*line;

	fd = open("infos.cub", O_RDONLY);
	ft_init(&*data);
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
