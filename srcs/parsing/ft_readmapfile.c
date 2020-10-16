/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmapfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:04:12 by titorium          #+#    #+#             */
/*   Updated: 2020/10/15 18:22:44 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cublib.h"

int	ft_readall(t_data *data)
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
	return (0);
}
