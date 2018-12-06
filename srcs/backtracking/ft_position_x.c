/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:05:10 by aquan             #+#    #+#             */
/*   Updated: 2018/12/06 13:05:10 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_position_x(unsigned char *map, unsigned short tetriminos)
{
	unsigned char row;
	unsigned short tetri_b;

	row = 0b1111;	
	tetri_b = 0;
	while (i < 15)
	{
		tetri_b = tetri_b | (tetriminos & (row << i)) << i;
		i = i + 4;
	}
}
