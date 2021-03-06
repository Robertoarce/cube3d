/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_categorize_rfc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:10:05 by titorium          #+#    #+#             */
/*   Updated: 2020/10/23 10:10:08 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cublib.h"

/*
*** THIS FILE SERVES TO TAKE THE INFORMATIONS OF THE MAP - PART 2
*/

/*
*** Add the infortmations needed for = R
*/

int			ft_add_r(char **split, int slots, t_data *data)
{
	int counter;
	int buton;

	buton = 0;
	counter = 1;
	if (slots < 3)
		buton = -1;
	while ((split + counter)[0] != NULL && split != NULL)
	{
		if (ft_isposnum(split[counter]) == -1 ||
				ft_atoi(split[counter]) < 1 ||
				ft_atoi(split[counter]) > 7000)
		{
			buton = -1;
			break ;
		}
		data->r[counter - 1] = ft_atoi(split[counter]);
		counter++;
	}
	if (buton == -1)
	{
		return (ft_error("\ninvalid input on R\n"));
	}
	return (0);
}

/*
*** Add the infortmations needed for = F (part 2)
*/

static int	ft_add_f2(char **ptr, int counter, t_data *data, int *buton)
{
	while (ptr[counter] != NULL && ptr[counter][0] != '\0')
	{
		if (ft_isposnum(ptr[counter]) == -1 ||
				ft_atoi(ptr[counter]) < 0 ||
				ft_atoi(ptr[counter]) > 255)
		{
			*buton = -1;
			free(ptr[counter]);
			break ;
		}
		data->f[counter] = ft_atoi(ptr[counter]);
		free(ptr[counter]);
		counter++;
	}
	return (counter);
}

/*
*** Add the infortmations needed for = F (part 1)
*/

int			ft_add_f(char **split, int slots, t_data *data)
{
	int		counter;
	int		buton;
	char	**ptr;

	buton = 0;
	counter = 0;
	if (slots < 2)
	{
		ft_error("\ninvalid input on F, more arg needed\n");
		return (-1);
	}
	ptr = ft_split(split[1], ',');
	counter = ft_add_f2(&*ptr, counter, &*data, &buton);
	free(ptr);
	if (buton == -1 || counter < 3)
	{
		ft_error("\ninvalid input on F\n");
		return (-1);
	}
	return (0);
}

/*
*** Add the infortmations needed for = C (part 2)
*/

static int	ft_add_c2(char **ptr, int counter, t_data *data, int *buton)
{
	while (ptr[counter] != NULL && ptr[counter][0] != '\0')
	{
		if (ft_isposnum(ptr[counter]) == -1 ||
				ft_atoi(ptr[counter]) < 0 ||
				ft_atoi(ptr[counter]) > 255)
		{
			*buton = -1;
			free(ptr[counter]);
			break ;
		}
		data->c[counter] = ft_atoi(ptr[counter]);
		free(ptr[counter]);
		counter++;
	}
	return (counter);
}

/*
*** Add the infortmations needed for = C (part 1)
*/

int			ft_add_c(char **split, int slots, t_data *data)
{
	int		counter;
	int		buton;
	char	**ptr;

	buton = 0;
	counter = 0;
	if (slots < 2)
	{
		ft_error("\ninvalid input on C, more arg needed\n");
		return (-1);
	}
	ptr = ft_split(split[1], ',');
	counter = ft_add_c2(&*ptr, counter, &*data, &buton);
	free(ptr);
	if (buton == -1 || counter < 3)
	{
		ft_error("\ninvalid input on C\n");
		return (-1);
	}
	return (0);
}
