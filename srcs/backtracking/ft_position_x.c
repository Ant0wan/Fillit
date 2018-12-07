/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:05:10 by aquan             #+#    #+#             */
/*   Updated: 2018/12/07 15:42:07 by abarthel         ###   ########.fr       */
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
	diff = 8 - map_nb > 0 ? (8 - map_nb) : (map_nb - 8);
	printf("diff : %d\n", diff);
	(void)tetriminos;
	if (i < nb_bytes)
	{
		/* First 4 bits in the unsignd short */
		map[i / 8] = map[i / 8] | 1 << (7 - (diff * 0));
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << (6 - (diff * 0));
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << (5 - (diff * 0));
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << (4 - (diff * 0));
		++i;
		i += map_nb - 4;
		map[i / 8] = map[i / 8] | 1 << (7 - (diff * 1));
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << (6 - (diff * 1));
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << (5 - (diff * 1));
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << (4 - (diff * 1));
		++i;
		i += map_nb - 4;
		map[i / 8] = map[i / 8] | 1 << (7 - (diff * 2));
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << (6 - (diff * 2));
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << (5 - (diff * 2));
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << (4 - (diff * 2));
		++i;
		i += map_nb - 4;
		map[i / 8] = map[i / 8] | 1 << (7 - (diff * 3));
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << ((((6 - (diff * 3)) % 8) + 8) % 8);
		++i;
		++c;
		map[i / 8] = map[i / 8] | 1 << ((((5 - (diff * 3)) % 8) + 8) % 8);
		++i;
		++c;
	}
}
