/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:28:29 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/11 12:36:42 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printmap(unsigned int *map, int nb)
{
	int l;
	int c;

	l = -1;
	(void)nb;
	while (++l < 32)
	{
		c = -1;
		while (++c < 32)
		{
			if (c % ROW_NB == 0)
				write(1, "\n\t", 2);
			ft_printbit(map[l] >> (ROW_NB - c - 1));
		}
	}
}
