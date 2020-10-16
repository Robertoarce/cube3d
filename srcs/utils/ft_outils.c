/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:06:56 by titorium          #+#    #+#             */
/*   Updated: 2020/10/15 18:29:00 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cublib.h"
#include "printf.h"

/*
***	 Print Error message.
*/

int		ft_error(char *tab)
{
	ft_putstr_fd(tab, 2);
	return (-1);
}

/*
***	 Check if there are  only numbers (
*/

int		ft_isposnum(char *tab)
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

/*
***	 Print values of all data.
*/

/*
***void	ft_printit(t_data data)
***{
***	ft_putstr("\n ==== DATA =====\n");
***	ft_printf("data.r ->%d,%d\n");
***	, data.r[0], data.r[1]);
***	ft_printf("data.f ->%d,%d,%d\n", data.f[0], data.f[1], data.f[2]);
***	ft_printf("data.c ->%d,%d,%d\n", data.c[0], data.c[1], data.c[2]);
***	ft_printf("data.no ->%s\n", data.no);
***	ft_printf("data.so ->%s\n", data.so);
***	ft_printf("data.we ->%s\n", data.we);
***	ft_printf("data.ea ->%s\n", data.ea);
***	ft_printf("data.s ->%s\n", data.s);
***	ft_printf("data.map ->%s\n", *data.map);
***	ft_printf("data.start ->%d\n", data.start);
***	ft_printf("data.player ->%d\n", data.player);
***}a
*/
