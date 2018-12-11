/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poslimit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:02:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/11 15:13:56 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>


int		ft_poslimit(unsigned short tetriminos, int map_nb)
{
	//int	max;
	(void)map_nb;
	(void)tetriminos;

	printf("tetri: %u\n", ((tetriminos & ~(part0_m)) >> 12));
	printf("tetri: %u\n", ((tetriminos & ~(part1_m)) >> 8));
	printf("tetri: %u\n", ((tetriminos & ~(part2_m)) >> 4));
	printf("tetri: %u\n", ((tetriminos & ~(part3_m)) >> 0));

	return (0);
}

int	main(void)
{
	int ok;

	ok = ft_poslimit(0b0001000100010001, 32);
	return (0);
}
