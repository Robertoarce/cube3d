/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infos3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 08:19:57 by titorium          #+#    #+#             */
/*   Updated: 2020/10/15 12:11:20 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cublib.h"

/*
*** THIS FILE SERVES TO TAKE THE INFORMATIONS OF THE MAP - PART 3
*/

/*
*** Add the infortmations needed for = NO
*/

int			ft_add_no(char **split, int slots, t_data *data)
{
	if (slots < 2)
		return (ft_error("\ninvalid input on NO, more arg needed\n"));
	if (ft_validstr(split[1]) == -1)
		return (ft_error("\ninvalid input on NO, more arg needed\n"));
	data->no = ft_strnew(ft_strlen(split[1]));
	ft_strlcpy(data->no, split[1], ft_strlen(split[1]) + 1);
	return (0);
}

/*
*** Add the infortmations needed for = SO
*/

int			ft_add_so(char **split, int slots, t_data *data)
{
	if (slots < 2)
		return (ft_error("\ninvalid input on NO, more arg needed\n"));
	if (ft_validstr(split[1]) == -1)
		return (ft_error("\ninvalid input on NO, more arg needed\n"));
	data->so = ft_strnew(ft_strlen(split[1]));
	ft_strlcpy(data->so, split[1], ft_strlen(split[1]) + 1);
	return (0);
}

/*
*** Add the infortmations needed for = WE
*/

int			ft_add_we(char **split, int slots, t_data *data)
{
	if (slots < 2)
		return (ft_error("\ninvalid input on NO, more arg needed\n"));
	if (ft_validstr(split[1]) == -1)
		return (ft_error("\ninvalid input on NO, more arg needed\n"));
	data->we = ft_strnew(ft_strlen(split[1]));
	ft_strlcpy(data->we, split[1], ft_strlen(split[1]) + 1);
	return (0);
}

/*
*** Add the infortmations needed for = S
*/

int			ft_add_s(char **split, int slots, t_data *data)
{
	if (slots < 2)
		return (ft_error("\ninvalid input on NO, more arg needed\n"));
	if (ft_validstr(split[1]) == -1)
		return (ft_error("\ninvalid input on NO, more arg needed\n"));
	data->s = ft_strnew(ft_strlen(split[1]));
	ft_strlcpy(data->s, split[1], ft_strlen(split[1]) + 1);
	return (0);
}

/*
*** Add the infortmations needed for = EA
*/

int			ft_add_ea(char **split, int slots, t_data *data)
{
	if (slots < 2)
		return (ft_error("\ninvalid input on NO, more arg needed\n"));
	if (ft_validstr(split[1]) == -1)
		return (ft_error("\ninvalid input on NO, more arg needed\n"));
	data->ea = ft_strnew(ft_strlen(split[1]));
	ft_strlcpy(data->ea, split[1], ft_strlen(split[1]) + 1);
	return (0);
}
