/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:36:08 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/30 17:59:09 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	ft_istherespace(unsigned int *map, unsigned int *tetri, char x)
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

static char	ft_position_x(t_lst **tab, unsigned int *map, unsigned char n,
		char limit)
{
	char istherespace;

	istherespace = 0;
	while ((*tab)[(int)n].x >= limit && (istherespace = ft_istherespace(map,
					(*tab)[(int)n].tetri, (*tab)[(int)n].x)))
		(*tab)[(int)n].x -= 1;
	if (!(istherespace))
	{
		ft_placerm(map, (*tab)[(int)n].tetri, (*tab)[(int)n].x);
		return (0);
	}
	else
	{
		(*tab)[(int)n].x = ROW_NB - (*tab)[(int)n].width;
		return (1);
	}
}

char		ft_position_y(t_lst **tab, unsigned int *map, unsigned char n,
		char map_nb)
{
	char limit;
	char istherespace;

	limit = map_nb - (*tab)[(int)n].height;
	istherespace = 0;
	while ((*tab)[(int)n].y <= limit && (istherespace = ft_position_x(tab,
					&map[(int)(*tab)[(int)n].y], n, ROW_NB - map_nb)))
		(*tab)[(int)n].y += 1;
	if (!(istherespace))
		return (0);
	else
		return (1);
}
