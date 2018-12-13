/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_y.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:10:51 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/13 10:55:26 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_position_y(unsigned int *map, unsigned short tetriminos,
		int map_nb, int l)
{
	char	res;
	char	height;

	height = ft_height(tetriminos);
	if ((res = ft_position_x(map, tetriminos, map_nb, l))
			&& l < map_nb - height)
	{
		printf("res: %d\n", res);
		return (ft_position_y(map, tetriminos, map_nb, ++l));
	}
	else if (res && l >= map_nb - height)
	{
		printf("2res: %d\n", res);
		return (1);
	}
	else
		return (0);
}
