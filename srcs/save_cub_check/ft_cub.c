/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarce <rarce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:30:21 by rarce             #+#    #+#             */
/*   Updated: 2020/12/07 17:07:36 by rarce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cublib.h"
#include	"libft.h"

static int  ft_checkend(char *tab)
{
    int counter;

    counter = ft_strlen(tab);
    if (ft_strlen(tab) < 5)
        return (-1);
    if (tab[counter - 4] == '.' && tab[counter - 3] == 'c' &&
        tab[counter - 2] == 'u' && tab[counter - 1] == 'b')
        return (1);
    return (-1);
}

int ft_cub(int argc, char **argv, char **cubextention)
{
    
    if (argc == 3 && ft_checkend(argv[2]) == -1)
        return (-1);
    if (argc == 2 && ft_checkend(argv[1]) == -1)
        return (-1);

    
    *cubextention = argv[1];

    //check if file exists

    return (1);
}