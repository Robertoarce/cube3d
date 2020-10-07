/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@42.student.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:04:41 by rarce             #+#    #+#             */
/*   Updated: 2020/10/07 17:56:59 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cublib.h"
#include "libft.h"

char	*ft_strncpy(char *dst, char *src, int size)
{
	int counter;
	int start;

	if (size == -1)
		size = ft_strlen(src);
	counter = 0;
	start = 0;
	while (dst[start] != '\0')
		start++;
	while (size-- && src[counter] != '\0')
	{
		dst[start + counter] = src[counter];
		counter++;
	}
	dst[start + counter] = '\0';
	return (dst);
}

int		ft_findnl(char *tab)
{
	int counter;

	if (tab != NULL && tab[0])
	{
		counter = 0;
		while (tab[counter] != '\0')
		{
			if (tab[counter] == '\n')
				return (counter);
			counter++;
		}
	}
	return (-1);
}

int		ft_validstr(char *tab)
{
	if (ft_strlen(tab) < 1)
		return (-1);
	return (0);
}
