/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:15:24 by titorium          #+#    #+#             */
/*   Updated: 2020/10/05 14:18:14 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int main()
{
/*	char line[]="abcd";
	char line2[]="efg";
	char line3[]="hijk";
	char line4[]="lmno";
	char line5[]="pqrst";
	char line6[]="duyv";
*/	char **ptr;
//	char *aux;
//	char f[6][2] = {{0}, {2}, {3}, {4}, {5}, {6}}; 
//	char p[6][4] = {{"1af"}, {"2r"}, {"3v"}, {"4sf"}, {"5r"}, {"6t"}}; 

int counter = 5;

ptr = ft_strnew2(6);

counter=0;
/*
while (counter<8)
{
	printf("\n ptr[%d]= %d",counter, f[counter][0]);
	printf("\n ptr[%d]= %s",counter, p[counter]);
	counter++;
}*/

printf("\n ====\n");


ptr = ft_append(ptr,"14gv");
ptr = ft_append(ptr,"2sad");
ptr = ft_append(ptr,"3sadf");
ptr = ft_append(ptr,"4sadf");
ptr = ft_append(ptr,"5sadf");
ptr = ft_append(ptr,"6 lksdf");

ft_putstr("\n printing...\n");
ft_print2d(ptr);
ft_putstr("\n finish\n");
ft_strfree(ptr);

return (0);
}
