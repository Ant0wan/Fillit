/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:28:29 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/10 15:22:46 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printmap(unsigned int *map, int nb)
{
	int l;
	int c;

	l = -1;
	while (++l < nb)
	{
		c = -1;
		while (++c < nb)
		{
			if (c % ROW_NB == 0)
				write(1, "\n\t", 2);
			ft_printbit(map[l] >> (ROW_NB - c - 1));
		}
	}
}
