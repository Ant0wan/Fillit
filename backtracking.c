/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/30 16:29:28 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	ft_nselector(t_lst **tab, char map_nb, int n, unsigned int *map)
{
	(*tab)[(int)n].x = ROW_NB - (*tab)[(int)n].width;
	(*tab)[(int)n].y = 0;
	while (--n >= 0)
	{
		ft_placerm(&(map[(int)(*tab)[(int)n].y]), (*tab)[(int)n].tetri, (*tab)[(int)n].x);
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

static char			tetri_feeder(t_lst **tab, unsigned int *map, unsigned char nb_tetri, char map_nb)
{
	static int	n = 0;

	while (n < nb_tetri)
	{
		if (ft_position_y(tab, map, n, map_nb))
		{
			n = ft_nselector(tab, map_nb, n, map);
			if (n == -1)
				return (1);
			else
				return (2);
		}
		else
			++n;
	}
	return (0);
}

static char			backtr_manager(t_lst **tab, unsigned int *map, unsigned char nb_tetri, char map_nb)
{
	char	feeder_ret;

	feeder_ret = 0;
	while ((feeder_ret = tetri_feeder(tab, map, nb_tetri, map_nb)) == 2)
		tetri_feeder(tab, map, nb_tetri, map_nb);
	if (feeder_ret)
		return (feeder_ret);
	else
		return (0);
}

void				backtracking(t_lst **tab, unsigned char nb_tetri)
{
	unsigned int	*map;
	char			map_nb;
	char			test = 0;
	char			n;

	n = 0;
	map = ft_mapgenerator();
	map_nb = ft_mapminsize(nb_tetri);
	while ((test = backtr_manager(tab, map, nb_tetri, map_nb)) && map_nb < ROW_NB)
		++map_nb;
	if (test == 1)
		return;
	ft_output_fillit(*tab, nb_tetri, map_nb);
	free(map);
	free(*tab);
}
