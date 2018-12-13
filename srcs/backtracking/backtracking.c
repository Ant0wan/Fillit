/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/13 13:44:59 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	backtracking(char nb_tetri, char *av)
{
	int i;
	char map_min_size;
	unsigned int *map;
	unsigned short *tab_tetri;

	i = 0;
	map_min_size = ft_mapminsize(nb_tetri);
	tab_tetri = ft_stock_tetri(nb_tetri, av);
	map = ft_mapgenerator();
	while (i < nb_tetri)
	{
		printf("position : %d\n", ft_position_y(map, tab_tetri[i], map_min_size, 0));
		++i;
	}
	ft_printmap(map, map_min_size);
	write(1, "\n", 1);
	free(map);
	free(tab_tetri);
	return (0);
}
