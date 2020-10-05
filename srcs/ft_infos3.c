/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infos3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 08:19:57 by titorium          #+#    #+#             */
/*   Updated: 2020/09/30 10:21:26 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cublib.h"


int			ft_add_no(char **split, int slots, t_data *data)
{
	if (slots < 2)
	{
		ft_error("\ninvalid input on NO, more arg needed\n");
		return (-1);

	}
	if (ft_validstr(split[1]) == -1 )
	{
			ft_error("\ninvalid input on NO, more arg needed\n");
			return (-1);
	}
		ft_putstr("\n+++++++\n");
		ft_putstr(split[0]);
		ft_putstr("\n");
		ft_putstr(split[1]);
		data->no = ft_strnew(ft_strlen(split[1]));
		ft_strlcpy(data->no ,split[1],ft_strlen(split[1])+1);
	return (0);
}

int			ft_add_so(char **split, int slots, t_data *data)
{
	if (slots < 2)
	{
		ft_error("\ninvalid input on NO, more arg needed\n");
		return (-1);

	}
	if (ft_validstr(split[1]) == -1 )
	{
			ft_error("\ninvalid input on NO, more arg needed\n");
			return (-1);
	}
		ft_putstr("\n+++++++\n");
		ft_putstr(split[0]);
		ft_putstr("\n");
		ft_putstr(split[1]);
		data->so = ft_strnew(ft_strlen(split[1]));
		ft_strlcpy(data->so ,split[1],ft_strlen(split[1])+1);
	return (0);
}

int			ft_add_we(char **split, int slots, t_data *data)
{
	if (slots < 2)
	{
		ft_error("\ninvalid input on NO, more arg needed\n");
		return (-1);

	}
	if (ft_validstr(split[1]) == -1 )
	{
			ft_error("\ninvalid input on NO, more arg needed\n");
			return (-1);
	}
		ft_putstr("\n+++++++\n");
		ft_putstr(split[0]);
		ft_putstr("\n");
		ft_putstr(split[1]);
		data->we = ft_strnew(ft_strlen(split[1]));
		ft_strlcpy(data->we ,split[1],ft_strlen(split[1])+1);
	return (0);
}

int			ft_add_s(char **split, int slots, t_data *data)
{
	if (slots < 2)
	{
		ft_error("\ninvalid input on NO, more arg needed\n");
		return (-1);

	}
	if (ft_validstr(split[1]) == -1 )
	{
			ft_error("\ninvalid input on NO, more arg needed\n");
			return (-1);
	}
		ft_putstr("\n+++++++\n");
		ft_putstr(split[0]);
		ft_putstr("\n");
		ft_putstr(split[1]);
		data->s = ft_strnew(ft_strlen(split[1]));
		ft_strlcpy(data->s ,split[1],ft_strlen(split[1])+1);
	return (0);
}

int			ft_add_ea(char **split, int slots, t_data *data)
{
	if (slots < 2)
	{
		ft_error("\ninvalid input on NO, more arg needed\n");
		return (-1);

	}
	if (ft_validstr(split[1]) == -1 )
	{
			ft_error("\ninvalid input on NO, more arg needed\n");
			return (-1);
	}
		ft_putstr("\n+++++++\n");
		ft_putstr(split[0]);
		ft_putstr("\n");
		ft_putstr(split[1]);
		data->ea = ft_strnew(ft_strlen(split[1]));
		ft_strlcpy(data->ea ,split[1],ft_strlen(split[1])+1);
	return (0);
}


