/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:36:08 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/18 16:20:13 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	ft_istherespace(unsigned int *map, unsigned int *tetri, char x)
{
	if (x > -1)
	{
//		write(1, "T", 1);
//		printf(">tetri: %d\n", tetri[0]);
//		printf(">map: %d\n", map[0]);
//		printf("x: %d\n", (int)x);
//		printf("mask: %d\n", map[0] & (tetri[0] << x));
		if (map[0] & (tetri[0] << x))
			return (1);
		else if (map[1] & (tetri[1] << x))
			return (1);
		else if (map[2] & (tetri[2] << x))
			return (1);
		else if (map[3] & (tetri[3] << x))
			return (1);
		else
//		{
//			write(1, "T", 1);
			return (0);
//		}
	}
	else
		return (0);
}

static char	ft_position_x(t_lst **tab, unsigned int *map, unsigned char n)
{
//	write(1, "X", 1);
//	printf("tetri0: %d\n", (int)tab[(int)n]->tetri[0]);
//	printf("x: %d\n", (int)tab[(int)n]->x);
	while (ft_istherespace(map, tab[(int)n]->tetri, tab[(int)n]->x))
	{
//		write(1, "X\n", 2);
		tab[(int)n]->x -= 1;
	}
//		write(1, "X\n", 2);
	if (tab[(int)n]->x != -1)
	{
		ft_placerm(map, tab[(int)n]->tetri, tab[(int)n]->x);
		return (0);
	}
	else
		return (1);
}

char		ft_position_y(t_lst **tab, unsigned int *map, unsigned char n)
{
//	printf("y: %d\n", (int)tab[(int)n]->y);
	if (ft_position_x(tab, &map[tab[(int)n]->y], n))
	{
//		write(1, "A", 1);
		if (tab[(int)n]->y < 32 - tab[(int)n]->height)
		{
			tab[(int)n]->y += 1;
			return (ft_position_y(tab, &map[tab[(int)n]->y], n));
		}
		else
			return (1);
	}
	else
	{
//		write(1, "A\n", 2);
		return (0);
	}
}
