/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/12 12:24:21 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//void	print_tetri_test(unsigned short *tab, int nb) // DEBUGG FT
//{
//	int	i;
//	i = 0;
//	while (i < nb)
//	{
//		printf("\telem %d: %d\n", i + 1, tab[i]);
//		++i;
//	}
//}

int		main(int argc, char **argv)
{
	(void)argv;
	int		nb_tetri;
	int		map_min_size;
//	int		map_nb;
	int 	i;
	unsigned short	*tab_tetri;
	unsigned int	*map;

	nb_tetri = 0;
	i = 0;
	tab_tetri = NULL;
	map = NULL;
	if (argc != 2)
		write(1, "error\n", 6);
	else
	{
		if ((nb_tetri = issamplevalid(argv[1])) == -1)
			write(1, "error\n", 6);
		else
		{
			printf("> Number of tetriminos: %d\n", nb_tetri);
			map_min_size = ft_mapminsize(nb_tetri);
			printf("Map min size %d\n", map_min_size);
			tab_tetri = ft_stock_tetri(nb_tetri, argv[1]);
//			print_tetri_test(tab_tetri, nb_tetri);
//			write(1, "\n", 1);
			map = ft_mapsize();
			map[0] = 0b11111100000000000000000000000000;
			map[1] = 0b11111000000000000000000000000000;
			map[2] = 0b00000000000000000000000000000000;
			map[3] = 0b00000000000000000000000000000000;
//			map[4] = 0b00000000000000000000000000000000;
//			map[5] = 0b00000000000000000000000000000000;
//			map[6] = 0b00000000000000000000000000000000;
//			map[7] = 0b00000000000000000000000000000000;
//			map[8] = 0b00000000000000000000000000000000;
//			map[9] = 0b00000000000000000000000000000000;
//			map[10] = 0b00000000000000000000000000000000;
//			map[11] = 0b00000000000000000000000000000000;
//			map[12] = 0b00000000000000000000000000000000;
//			map[13] = 0b00000000000000000000000000000000;
//			map[31] = 0b00000000000000000000000000000000;
			write(1, "\n>      MAP     <\n\t", 19); // DEBUGG
//			map_min_size = ROW_NB;
			write(1, "12345678901234567890123456789012", 32);
			while (i < nb_tetri)
			{
				ft_position_y(map, tab_tetri[i], map_min_size, 0);
				++i;
			}
			ft_printmap(map, map_min_size);
			write(1, "\n", 1);
			write(1, "\n", 1);
		}
	
	free(map);
	free(tab_tetri);
	}
	return (0);
}
