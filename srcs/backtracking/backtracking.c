/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/18 12:49:55 by abarthel         ###   ########.fr       */
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

static char			ft_mapminsize(char nb_tetri)
{
	int		nb_bits;
	char	i;

	nb_bits = nb_tetri * 4;
	i = 0;
	while (nb_bits > i * i)
	{
		++i;
		if (nb_bits == i * i)
			return (i);
	}
	return (i);
}

void	backtracking(char nb_tetri, char *av)
{
	char			map_nb;
	unsigned int	*map;
	unsigned short	*tab_tetri;

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

static char	map_define();

static char	tetri_feeder();




