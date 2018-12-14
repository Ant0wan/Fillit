/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_y.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:10:51 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/14 12:26:17 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_position_y(unsigned int *map, unsigned short tetriminos,
		char map_nb, int l)
{
	char	height;
	char res;

	height = ft_height(tetriminos);
	if (!(res = ft_position_x(map, tetriminos, map_nb, l)))
	{
		printf("y tetri placed\n");
		return (0);
	}
	else if (res && l < map_nb - height)
	{
		printf("y placement failed so move down\n");
		return (ft_position_y(map, tetriminos, map_nb, ++l));
	}
	else
	{
		printf("y placement totally failed\n");
		return (1);
	}
}
