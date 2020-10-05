/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: titorium <rarce@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:26:58 by titorium          #+#    #+#             */
/*   Updated: 2020/09/30 10:18:26 by titorium         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include "cublib.h"

static int	ft_categorize2(char **split, int slots, t_data *data)
{
	if (ft_strdif(split[0], "so", -1) == 0
				|| ft_strdif(split[0], "SO", -1) == 0)
			ft_add_so(&*split,slots,&*data);

		if (ft_strdif(split[0], "we", -1) == 0
				|| ft_strdif(split[0], "WE", -1) == 0)
			ft_add_we(&*split,slots,&*data);

		if (ft_strdif(split[0], "ea", -1) == 0
				|| ft_strdif(split[0], "EA", -1) == 0)
			ft_add_ea(&*split,slots,&*data);

		if (ft_strdif(split[0], "s", -1) == 0
				|| ft_strdif(split[0], "S", -1) == 0)
			ft_add_s(&*split,slots,&*data);

			
	return (0);
}




int	ft_categorize(char **split, int slots, t_data *data)
{
	if (slots > 1)
	{
		if (ft_strdif(split[0], "r", -1) == 0
				|| ft_strdif(split[0], "R", -1) == 0)
			return (ft_add_r(&*split,slots,&*data));
		if (ft_strdif(split[0], "f", -1) == 0
				|| ft_strdif(split[0], "F", -1) == 0)
			return(ft_add_f(&*split,slots,&*data));
		if (ft_strdif(split[0], "c", -1) == 0
			|| ft_strdif(split[0], "C", -1) == 0)
			ft_add_c(&*split,slots,&*data);
		if (ft_strdif(split[0], "no", -1) == 0
				|| ft_strdif(split[0], "NO", -1) == 0)
			ft_add_no(&*split,slots,&*data);

	}
	return (ft_categorize2(&*split, slots, &*data));
}



