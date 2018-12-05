/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:28:29 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/05 17:19:27 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** nb: number of lines in the map (also columns)
** map: unsignd char table containing the tetriminos (backtracking output)
*/

void	ft_printmap(unsigned char *map, int nb)
{
	int	i;
	int	nb_bits;

	i = -1;
	nb_bits = nb * nb;
	while (++i < nb_bits)
	{
		if (i % nb == 0 && i)
			write(1, "\n\t", 2);
		ft_printbit(map[i / 8] << (i % 8));
	}
}
