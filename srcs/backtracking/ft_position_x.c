/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:05:10 by aquan             #+#    #+#             */
/*   Updated: 2018/12/06 17:50:46 by abarthel         ###   ########.fr       */
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
	diff = (map_nb - 8) < 1 ? ((map_nb - 8) * -1) : (map_nb - 8);
	while (++i < nb_bytes)
	{
		map[i / 8] = (map[i / 8] << i) | tetriminos >> 8;
		i += 8;
		map[i / 8] = map[i / 8] | tetriminos;
	}
}
