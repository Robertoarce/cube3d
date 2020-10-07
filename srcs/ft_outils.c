/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:06:56 by titorium          #+#    #+#             */
/*   Updated: 2020/10/06 17:36:27 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cublib.h"

int	ft_error(char *tab)
{
	ft_putstr_fd(tab, 2);
	return (-1);
}

int	ft_isposnum(char *tab)
{
	int counter;

	counter = 0;
	while (tab && tab[counter] != '\0')
	{
		if (ft_isdigit(tab[counter]) == 0)
			return (-1);
		if (counter > 4)
			return (-1);
		counter++;
	}
	return (1);
}
