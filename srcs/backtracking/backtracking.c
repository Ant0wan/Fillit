/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/14 12:23:01 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_globalpos(unsigned int *map, unsigned short *tab_tetri,
		char map_nb, char nb_tetri)
{
	static int		i = -1;

	if (++i < nb_tetri && !(ft_position_y(map, tab_tetri[i], map_nb, 0)))
	{
		printf("ret 1 i: %d\n", i);
		return (ft_globalpos(map, tab_tetri, map_nb, nb_tetri));
	}
	else if (i < nb_tetri)
	{
		++map_nb;
		--i;
		printf("ret 2 i: %d\n", i);
		return (ft_globalpos(map, tab_tetri, map_nb, nb_tetri));
	}
	else if (i == nb_tetri)
		return (0);
	else
		return (1);
}

char	backtracking(char nb_tetri, char *av)
{
	int				i;
	char			map_nb;
	unsigned int	*map;
	unsigned short	*tab_tetri;

	i = 0;
	map_nb = ft_mapminsize(nb_tetri);
	tab_tetri = ft_stock_tetri(nb_tetri, av);
	map = ft_mapgenerator();
	ft_globalpos(map, tab_tetri, map_nb, nb_tetri);
	ft_printmap(map, map_nb);
	write(1, "\n", 1);
	free(map);
	free(tab_tetri);
	return (0);
}
