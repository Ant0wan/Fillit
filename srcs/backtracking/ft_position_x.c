/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:36:08 by aquan             #+#    #+#             */
/*   Updated: 2018/12/13 13:02:13 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	ft_ismovable(unsigned int *map, unsigned short tetriminos,
		int n, int c)
{
	if (map[0] & ((tetriminos & ~(part0_m)) << c) >> n)
		return (1);
	else if (map[1] & (((tetriminos & ~(part1_m)) << 4) << c) >> n)
		return (1);
	else if (map[2] & (((tetriminos & ~(part2_m)) << 8) << c) >> n)
		return (1);
	else if (map[3] & (((tetriminos & ~(part3_m)) << 12) << c) >> n)
		return (1);
	else
		return (0);
}

static char	ft_isplaceable(unsigned int *map, unsigned short tetriminos,
		int n, int c)
{
	if ((map[0] | (((tetriminos & ~(part0_m)) << c) >> n))
			== (map[0] ^ (((tetriminos & ~(part0_m)) << c) >> n))
			&& (map[1] | ((((tetriminos & ~(part1_m)) << 4) << c) >> n))
			== (map[1] ^ ((((tetriminos & ~(part1_m)) << 4) << c) >> n))
			&& (map[2] | ((((tetriminos & ~(part2_m)) << 8) << c) >> n))
			== (map[2] ^ ((((tetriminos & ~(part2_m)) << 8) << c) >> n))
			&& (map[3] | ((((tetriminos & ~(part3_m)) << 12) << c) >> n))
			== (map[3] ^ ((((tetriminos & ~(part3_m)) << 12) << c) >> n)))
		return (1);
	else
		return (0);
}

char		ft_position_x(unsigned int *map, unsigned short tetriminos,
		int map_nb, int l)
{
	char	n;
	char	c;
	char	thick;

	n = 0;
	c = ROW_NB / 2;
	thick = ft_thickness(tetriminos);
	while (ROW_NB / 2 - c + n + thick < map_nb
			&& ft_ismovable(&map[l], tetriminos, n, c))
	{
		if (c)
			--c;
		else
			++n;
	}
	if (ft_isplaceable(&map[l], tetriminos, n, c))
	{
		map[l] = map[l] | ((tetriminos & ~(part0_m)) << c) >> n;
		map[l + 1] = map[l + 1] | (((tetriminos & ~(part1_m)) << 4) << c) >> n;
		map[l + 2] = map[l + 2] | (((tetriminos & ~(part2_m)) << 8) << c) >> n;
		map[l + 3] = map[l + 3] | (((tetriminos & ~(part3_m)) << 12) << c) >> n;
		return (0);
	}
	else
		return (1);
}
