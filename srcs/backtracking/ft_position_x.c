/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:05:10 by aquan             #+#    #+#             */
/*   Updated: 2018/12/07 16:13:54 by abarthel         ###   ########.fr       */
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
//	diff = 8 - map_nb > 0 ? (8 - map_nb) : (map_nb - 8);
	diff = 0;

	printf("diff : %d\n", diff);
	(void)tetriminos;
	if (i < nb_bytes)
	{
		/* First 4 bits in the unsignd short */
		map[i / 8] = map[i / 8] | 1 << ((((7 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << ((((6 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << ((((5 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << ((((4 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
//		i += map_nb - 4;
		map[i / 8] = map[i / 8] | 1 << ((((3 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << ((((2 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << ((((1 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << ((((0 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
//		i += map_nb - 4;
		map[i / 8] = map[i / 8] | 1 << ((((7 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << ((((6 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << ((((5 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << ((((4 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
//		i += map_nb - 4; only if map_nb > 4
		map[i / 8] = map[i / 8] | 1 << ((((3 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << ((((2 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << ((((1 - (diff * (i / 4))) % 8) + 8) % 8);
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << ((((0 - (diff * (i / 4))) % 8) + 8) % 8);
	}
}
