/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_globalpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:06:41 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/13 14:28:12 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_globalpos(unsigned int *map, unsigned short *tab_tetri,
		char map_nb, char nb_tetri)
{
	int		i;
	char	res;

	i = -1;
	while (++i < nb_tetri)
		res = ft_position_y(map, tab_tetri[i], map_nb, 0);
	if (res)
		return (1);
	else
		return (0);
}
