/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_globalpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:06:41 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/13 15:14:29 by abarthel         ###   ########.fr       */
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
		if ((res = ft_position_y(map, tab_tetri[i], map_nb, 0)))
			break;
	if (res)
	{
		printf("cannot place all\n");
		return (1);
	}
	else
		return (0);
}
