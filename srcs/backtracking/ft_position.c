/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:36:08 by aquan             #+#    #+#             */
/*   Updated: 2018/12/11 13:21:17 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_position(unsigned int *map, unsigned short tetriminos, int map_nb)
{
	int	c;
	int	l;
	int n;

	c = ROW_NB / 2;
	n = ROW_NB - 2 ;
	l = 0;
	while (c &&
			(map[l] & ((tetriminos & ~(part0_m)) << c)
			 || map[l + 1] & ((tetriminos & ~(part1_m)) << 4) << c
			 || map[l + 2] & ((tetriminos & ~(part2_m)) << 8) << c
			 || map[l + 3] & ((tetriminos & ~(part3_m)) << 12) << c))
		--c;
	if ((map[l] | ((tetriminos & ~(part0_m)) << c)) == (map[l] ^((tetriminos & ~(part0_m)) << c)) && (map[l + 1] | (((tetriminos & ~(part1_m)) << 4) << c)) == (map[l + 1] ^(((tetriminos & ~(part1_m)) << 4) << c)) && (map[l + 2] | (((tetriminos & ~(part2_m)) << 8) << c)) == (map[l + 2] ^(((tetriminos & ~(part2_m)) << 8) << c)) && (map[l + 3] | (((tetriminos & ~(part3_m)) << 12) << c)) == (map[l + 3] ^(((tetriminos & ~(part3_m)) << 12) << c)))
	{
		map[l] = (map[l] | (tetriminos & ~(part0_m)) << c) >> n;
		map[l + 1] = (map[l + 1] | ((tetriminos & ~(part1_m)) << 4) << c) >> n;
		map[l + 2] = (map[l + 2] | ((tetriminos & ~(part2_m)) << 8) << c) >> n;
		map[l + 3] = (map[l + 3] | ((tetriminos & ~(part3_m)) << 12) << c) >> n;
	}
	(void)map_nb;
}
