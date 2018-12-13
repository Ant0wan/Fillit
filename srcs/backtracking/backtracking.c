/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/13 15:11:29 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	while (ft_globalpos(map, tab_tetri, map_nb, nb_tetri))
	{
		write(1, "T\n", 2);
		free(map);
		map = ft_mapgenerator();
		++map_nb;
	}
	ft_printmap(map, map_nb);
	write(1, "\n", 1);
	free(map);
	free(tab_tetri);
	return (0);
}
