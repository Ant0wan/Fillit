/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:36:08 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/13 13:32:55 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	ft_istherespace(unsigned int *map, unsigned int *tetri, char x)
{
	if (x > -1)
	{
		if (map[0] & (tetri[0] << x))
			return (1);
		else if (map[1] & (tetri[1] << x))
			return (1);
		else if (map[2] & (tetri[2] << x))
			return (1);
		else if (map[3] & (tetri[3] << x))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

char	ft_position_x(t_lst t_elem, unsigned int *map) // should we pass the whole table or just element of table ?
{
	char	*x;
	
	x = &(t_elem->x); // eq of (32 - tab_te[n_tetri]->width) computed at storage time
	while (ft_istherespace(map, t_elem->tetri, *x))
		*x -= 1;
	if (*x != -1)
	{
		ft_place(map, t_elem->tetri, *x);
		return (0);
	}
	else
		return (1)
}