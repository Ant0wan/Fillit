/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/21 16:09:42 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int	*ft_mapgenerator(void)
{
	unsigned int	*map;

	if (!(map = (unsigned int*)ft_memalloc(sizeof(unsigned int) * ROW_NB)))
		return (NULL);
	return (map);
}

static char			ft_mapminsize(unsigned char nb_tetri)
{
	unsigned short	nb_bits;
	unsigned char	i;

	nb_bits = nb_tetri * 4;
	i = 4;
	while (nb_bits > i * i)
	{
		++i;
		if (nb_bits == i * i)
			return (i);
	}
	return (i);
}

static char	ft_nselector(t_lst **tab, char map_nb, int n, unsigned int *map)
{
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
	}
	return (-1);
}

static char			tetri_feeder(t_lst **tab, unsigned int *map, unsigned char nb_tetri, char map_nb)
{
	static int	n = 0;
	int res;

	res = 0;
	while (n < nb_tetri)
	{
		res = (int)ft_position_y(tab, map, n, map_nb);
		if (res)
		{
			n = ft_nselector(tab, map_nb, n, map);
			if (n == -1)
				return (1);
			else
				return (tetri_feeder(tab, map, nb_tetri, map_nb));
		}
		else
		{
			++n;
		}
	}
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
	while ((test = tetri_feeder(tab, map, nb_tetri, map_nb)) && map_nb < ROW_NB)
	{
		write(1, "map++\n",6);
//		n = -1;
//		while (++n < nb_tetri)
//		{
//			(*tab)[(int)n].x = ROW_NB - (*tab)[(int)n].width;
//			(*tab)[(int)n].y = 0;
//		}
//		free(map);
//		map = ft_mapgenerator();
		++map_nb;
	}
	if (test == 1)
		return;
	ft_output_fillit(*tab, nb_tetri, map_nb);
	free(map);
	free(*tab);
}
