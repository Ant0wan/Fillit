/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/30 22:27:26 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

static char	ft_nselector(t_lst **tab, char map_nb, int n, unsigned int *map)
{
	(*tab)[(int)n].x = ROW_NB - (*tab)[(int)n].width;
	(*tab)[(int)n].y = 0;
	while (--n >= 0)
	{
		ft_placerm(&(map[(int)(*tab)[(int)n].y]), (*tab)[(int)n].tetri,
				(*tab)[(int)n].x);
		if ((*tab)[(int)n].x > ROW_NB - map_nb)
		{
			(*tab)[(int)n].x -= 1;
			return (n);
		}
		else if ((*tab)[(int)n].y < map_nb - (*tab)[(int)n].height)
		{
			(*tab)[(int)n].y += 1;
			(*tab)[(int)n].x = ROW_NB - (*tab)[(int)n].width;
			return (n);
		}
		else
		{
			(*tab)[(int)n].x = ROW_NB - (*tab)[(int)n].width;
			(*tab)[(int)n].y = 0;
		}
	}
	return (-1);
}

static char	tetri_feeder(t_lst **tab, unsigned int *map, char map_nb)
{
	static int	n = 0;

	if (n == -1)
		n = 0;
	if (!(ft_position_y(tab, map, n, map_nb)))
		++n;
	else
		n = ft_nselector(tab, map_nb, n, map);
	return (n);
}

void		backtracking(t_lst **tab, unsigned char nb_tetri)
{
	unsigned int	*map;
	char			map_nb;
	char			ret;

	ret = 0;
	map = ft_mapgenerator();
	map_nb = ft_mapminsize(nb_tetri);
	while (map_nb < ROW_NB)
	{
		ret = tetri_feeder(tab, map, map_nb);
		if (ret == -1)
			++map_nb;
		else if (ret == nb_tetri)
			break ;
	}
	ft_output_fillit(*tab, nb_tetri, map_nb);
	free(map);
	free(*tab);
}
