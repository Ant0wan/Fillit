/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/19 18:43:50 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int	*ft_mapgenerator(void)
{
	unsigned int	*map;

	if (!(map = (unsigned int*)ft_memalloc(sizeof(unsigned int) * ROW_NB)))
		return (NULL);
	return (map);
}

static char			ft_mapminsize(unsigned char nb_tetri)
{
	unsigned short	nb_bits;
	unsigned char	i;

	nb_bits = nb_tetri * 4;
	i = 4;
	while (nb_bits > i * i)
	{
		++i;
		if (nb_bits == i * i)
			return (i);
	}
	return (i);
}

//static char			tetri_feeder(t_lst **tab, unsigned int *map,
//		unsigned char nb_tetri, char map_nb)
//{
//	static int	n = 0;
//
//	if (n < nb_tetri && ft_position_y(tab, map, n))
//	{
//		write(1, "O", 1);
//		(*tab)[(int)n].x = 32 - (*tab)[(int)n].width;
//		(*tab)[(int)n].y = 0;
//		n = n - 1;
//		printf("n: %d\n", n);
//		if (n == -1)
//			return (1);
//		else
//		{
//			ft_placerm(map, (*tab)[(int)n].tetri, (*tab)[(int)n].x);
//			if ((*tab)[(int)n].x > 0)
//			{
//				(*tab)[(int)n].x -= 1;
//				return (tetri_feeder(tab, map, nb_tetri, map_nb));
//			}
//			else if ((*tab)[(int)n].y > 31 - (*tab)[(int)n].height)
//			{
//				(*tab)[(int)n].y += 1;
//				(*tab)[(int)n].x = 32 - (*tab)[(int)n].width;
//				return (tetri_feeder(tab, map, nb_tetri, map_nb));
//			}
//			else
//				return (1);
//		}
//	}
//	else if (n < nb_tetri)
//	{
//		++n;
//		return (tetri_feeder(tab, map, nb_tetri, map_nb));
//	}
//	else
//		return (0);
//}

void printBits(size_t const size, void const * const ptr)
{
	unsigned char *b = (unsigned char*) ptr;
	unsigned char byte;
	int i, j;

	for (i=size-1;i>=0;i--)
	{
		for (j=7;j>=0;j--)
		{
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	puts("");
}

static char			tetri_feeder(t_lst **tab, unsigned int *map, unsigned char nb_tetri, char map_nb)
{
	int	n;

	n = 0;
	while (n < nb_tetri)
	{
		printf("tetri n %d\n", n);
		printf("tetri [0]value %d\n", (*tab)[(int)n].tetri[0]);
		printf("tetri [1]value %d\n", (*tab)[(int)n].tetri[1]);
		printf("tetri [2]value %d\n", (*tab)[(int)n].tetri[2]);
		printf("tetri [3]value %d\n", (*tab)[(int)n].tetri[3]);
		if (!(ft_position_x(tab, map, n, 32)))
		{
			printBits(sizeof(map[0]), &map[0]);
			printBits(sizeof(map[1]), &map[1]);
			printBits(sizeof(map[2]), &map[2]);
			printBits(sizeof(map[3]), &map[3]);
			printBits(sizeof(map[4]), &map[4]);
			printBits(sizeof(map[5]), &map[5]);
			printf("\n");
			++n;
		}
		else
			return (1);
	}
	return (0);
}

void				backtracking(t_lst **tab, unsigned char nb_tetri)
{
	unsigned int	*map;
	char			map_nb;
	char	test = 0;

	map = ft_mapgenerator();
	map_nb = ft_mapminsize(nb_tetri);
	map_nb = 32;
	while ((test = tetri_feeder(tab, map, nb_tetri, map_nb)) && map_nb < ROW_NB + 1)
		++map_nb;
	printf("map final size: %d\n", (int)map_nb);
	printf("0 OK, 1 KO: %d\n", (int)test);
	free(map);
	free(*tab);
}
