/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 17:16:28 by rarce             #+#    #+#             */
/*   Updated: 2020/10/20 15:07:22 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str2len(const char **s)
{
	int counter;

	if (!**s || !*s)
		return (0);
	counter = 0;
	while (s[counter] != NULL)
		counter++;
	return (counter);
}
