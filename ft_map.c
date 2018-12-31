/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 16:17:28 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/31 16:14:56 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int	*ft_mapgenerator(void)
{
	unsigned int	*map;

	if (!(map = (unsigned int*)ft_memalloc(sizeof(unsigned int) * ROW_NB)))
		return (NULL);
	return (map);
}

char			ft_mapminsize(t_lst *tab, unsigned char nb_tetri)
{
	unsigned short	nb_bits;
	unsigned char	i;

	i = -1;
	nb_bits = 0;
	if (nb_tetri < 3)
	{
		while (++i < nb_tetri)
		{
			nb_bits = tab[i].height > nb_bits ? tab[i].height : nb_bits;
			nb_bits = tab[i].width > nb_bits ? tab[i].width : nb_bits;
		}
		return (nb_bits);
	}
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
