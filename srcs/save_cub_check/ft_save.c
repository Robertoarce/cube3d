/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:06:10 by rarce             #+#    #+#             */
/*   Updated: 2020/12/07 14:30:40 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cublib.h"
#include	"libft.h"

static int  ft_checksavename(char *tab)
{
    if (ft_strlen(tab) != 6)
        return (-1);
    if (tab[0] == '-' && tab[1] == '-' &&
        tab[2] == 's' && tab[3] == 'a' &&
        tab[4] == 'v' && tab[5] == 'e')
        return (1);
    return (-1);
}

int ft_save(int argc, char **argv)
{
    if (argc > 3 || argc < 1)
        return (-1);
    if (argc == 3 && ft_checksavename(argv[1]) == -1)
        return (-1);
    if (argc == 2)
        return (1);
// TODO : BMP here

    return (1);
}