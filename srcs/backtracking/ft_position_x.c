/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:05:10 by aquan             #+#    #+#             */
/*   Updated: 2018/12/07 14:14:02 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_position_x(unsigned char *map, unsigned short tetriminos, int map_nb)
{
	unsigned char	row;
	int				nb_bytes;
	int	i;
	int	c;
	int				diff;

	row = 0b1111;
	nb_bytes = map_nb * map_nb;
	i = 0;
	c = 0;
	diff = map_nb - 8 < 0 ? (map_nb - 8) * -1 : map_nb - 8;
	(void)tetriminos;
	if (i < nb_bytes)
	{
		/* First 4 bits in the unsignd short */
		map[i / 8] = map[i / 8] | 1 << (7 - (c % 8));
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << (7 - (c % 8));
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << (7 - (c % 8));
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << (7 - (c % 8));
		++i;
		c += diff + 1;
//		printf("i  :  %d\n", i);
		map[i / 8] = map[i / 8] | 1 << (7 - (c % 8));
		++i;
		++c;
//		printf("at i  :  %d\n", i);
		map[i / 8] = map[i / 8] | 1 << (7 - (c % 8));
	}
}
