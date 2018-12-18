/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/18 14:06:32 by abarthel         ###   ########.fr       */
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

//static char			tetri_feeder(t_lst **tab, unsigned char nb_tetri)
//{
//	if (ft_position_y)
//	{
//		if (!(tetri--))
//			return (erreur);
//		tetri--;
//		ft_remove(tetri);
//		tetri->x = x--;
//		return (tetri_feeder(tab, nb_tetri));
//	}
//	return (all done !);
//}

void				backtracking(t_lst **tab, unsigned char nb_tetri)
{
	unsigned int	*map;
	char			map_nb;

	map = ft_mapgenerator();
	map_nb = ft_mapminsize(nb_tetri);
	
	free(map);
	free(*tab);
}

//static char	map_define();

//static char	tetri_feeder();




