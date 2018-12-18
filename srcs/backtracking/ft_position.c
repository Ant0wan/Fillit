/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:36:08 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/18 15:50:15 by abarthel         ###   ########.fr       */
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

static char	ft_position_x(t_lst **tab, unsigned int *map, unsigned char n)
{
	while (ft_istherespace(map, tab[(int)n]->tetri, tab[(int)n]->x))
		tab[(int)n]->x -= 1;
	if (tab[(int)n]->x != -1)
	{
		ft_placerm(map, tab[(int)n]->tetri, tab[(int)n]->x);
		return (0);
	}
	else
		return (1);
}

char		ft_position_y(t_lst **tab, unsigned int *map, unsigned char n)
{
	if (ft_position_x(tab, &map[tab[(int)n]->y], n))
	{
		if (tab[(int)n]->y < 32 - tab[(int)n]->height)
		{
			tab[(int)n]->y += 1;
			return (ft_position_y(tab, &map[tab[(int)n]->y], n));
		}
		else
			return (1);
	}
	else
		return (0);
}
