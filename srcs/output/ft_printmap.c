/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:28:29 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/10 15:20:32 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printmap(unsigned int *map, int nb)
{
	int l;
	int c;
	int i;
	int max;

	l = -1;
	i = -1;
	(void)nb;
	max = ROW_NB * ROW_NB;
	while (++l < ROW_NB)
	{
		c = -1;
		while (++c < ROW_NB)
		{
			if (c % 32 == 0)
				write(1, "\n\t", 2);
			ft_printbit(map[l] >> (ROW_NB - c - 1));
		}
	}
}
