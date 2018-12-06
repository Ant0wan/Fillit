/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:05:10 by aquan             #+#    #+#             */
/*   Updated: 2018/12/06 15:05:45 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_position_x(unsigned char *map, unsigned short tetriminos, int map_nb)
{
	unsigned char	row;
	int				nb_bytes;
	int	i;

	row = 0b1111;
	nb_bytes = map_nb * map_nb;
	i = 0;
//	while (i < nb_bytes)
//	{
//		map[i / 8] = map[i / 8] | (tetriminos & (row << i ) << i);
		map[i / 8] = map[i / 8] | (tetriminos >> 8);
		i += 8;
//		i += 2;
		map[i / 8] = map[i / 8] | tetriminos;
//		i = i + 4;
//		++i;
//	}
}
