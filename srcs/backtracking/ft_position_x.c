/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:36:08 by aquan             #+#    #+#             */
/*   Updated: 2018/12/11 17:11:51 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_position_x(unsigned int *map, unsigned short tetriminos, int map_nb)
{
	int	c;
	int	l;
	int n;
	char	thick;

	c = ROW_NB / 2;
	n = 0;
	l = 0;
	thick = ft_thickness(tetriminos);
	while (((c || n < ROW_NB / 2 - thick) && (ROW_NB / 2 - c + n) < map_nb) &&
			(map[l] & ((tetriminos & ~(part0_m)) << c) >> n
			 || map[l + 1] & (((tetriminos & ~(part1_m)) << 4) << c) >> n
			 || map[l + 2] & (((tetriminos & ~(part2_m)) << 8) << c) >> n
			 || map[l + 3] & (((tetriminos & ~(part3_m)) << 12) << c) >> n))
	{
		if (c)
			--c;
		else
			++n;
	}
	if ((map[l] | (((tetriminos & ~(part0_m)) << c) >> n))
			== (map[l] ^(((tetriminos & ~(part0_m)) << c) >> n))
			&& (map[l + 1] | ((((tetriminos & ~(part1_m)) << 4) << c) >> n))
			== (map[l + 1] ^((((tetriminos & ~(part1_m)) << 4) << c) >> n))
			&& (map[l + 2] | ((((tetriminos & ~(part2_m)) << 8) << c) >> n))
			== (map[l + 2] ^((((tetriminos & ~(part2_m)) << 8) << c) >> n))
			&& (map[l + 3] | ((((tetriminos & ~(part3_m)) << 12) << c) >> n))
			== (map[l + 3] ^((((tetriminos & ~(part3_m)) << 12) << c) >> n)))
	{
		map[l] = map[l] | ((tetriminos & ~(part0_m)) << c) >> n;
		map[l + 1] = map[l + 1] | (((tetriminos & ~(part1_m)) << 4) << c) >> n;
		map[l + 2] = map[l + 2] | (((tetriminos & ~(part2_m)) << 8) << c) >> n;
		map[l + 3] = map[l + 3] | (((tetriminos & ~(part3_m)) << 12) << c) >> n;
	}
	printf("c = %d\n", c);
	printf("\tn = %d\n", n);
	(void)map_nb;
}
