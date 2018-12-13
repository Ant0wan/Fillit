/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/13 13:22:20 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char nb_tetri;
	int i;
	char map_min_size;
	unsigned int *map;
	unsigned short *tab_tetri;

	map = NULL;
	tab_tetri = NULL;
	if (argc != 2)
		write(1, "error\n", 6);
	else
	{
		if ((nb_tetri = issamplevalid(argv[1])) == -1)
			write(1, "error\n", 6);
		else
		{
			i = 0;
			map_min_size = ft_mapminsize(nb_tetri);
			tab_tetri = ft_stock_tetri(nb_tetri, argv[1]);
			map = ft_mapgenerator();
			map[0] = 0b00000000000000000000000000000000;
			map[1] = 0b00000000000000000000000000000000;
			map[2] = 0b00000000000000000000000000000000;
			map[3] = 0b00000000000000000000000000000000;
			write(1, "\n>      MAP     <\n\t", 19); // DEBUGG
			while (i < nb_tetri)
			{
				printf("position : %d\n", ft_position_y(map, tab_tetri[i], map_min_size, 0));
				++i;
			}
			write(1, "\t12345678901234567890123456789012", 33);
			ft_printmap(map, map_min_size);
			write(1, "\n", 1);
			write(1, "\n", 1);
		}
	
	free(map);
	free(tab_tetri);
	}
	return (0);
}
