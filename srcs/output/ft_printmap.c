/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:28:29 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/10 14:58:42 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** nb: number of lines in the map (also columns)
** map: unsignd char table containing the tetriminos (backtracking output)
*/

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
			if (c % nb == 0)
				write(1, "\n\t", 2);
			ft_printbit(map[l] << i);
		}
	}
}
