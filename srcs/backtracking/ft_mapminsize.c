/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_min_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:51:01 by aquan             #+#    #+#             */
/*   Updated: 2018/12/06 15:38:28 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_mapminsize(int nb_tetri)
{
	int	i;
	int	nb_bits;

	i = 0;
	nb_bits = nb_tetri * 4;
	while (nb_bits > i * i)
	{
		++i;
		if (nb_bits == i * i)
			return (i);
	}
	return (i);
}
