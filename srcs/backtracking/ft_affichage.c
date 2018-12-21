/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:38:07 by aquan             #+#    #+#             */
/*   Updated: 2018/12/21 12:12:38 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_place_tetri(char *str, char map_nb, t_lst **tab, char n)
{	
	static int 				letter = 0;
	unsigned char			j;
	int						i;
	unsigned char			k;
	int index;

	i = 0;
	while (i < ((*tab)[(int)n].height))
	{
		j = 0;
		k = ((*tab)[(int)n].tetri[i]);
		while (j < ((*tab)[(int)n].width))
		{		
			if (1 & k)
			{	
				index = (((*tab)[(int)n].y + i) * (map_nb + 1) + ((*tab)[(int)n].x + j));
			//	index = (((*tab)[(int)n].y) * (map_nb + 1) + ((*tab)[(int)n].x + j));
				printf("i = %d width = %d  index = %d    j = %d\n",i, ((*tab)[(int)n].width), index, j);
			//	str[i * (map_nb + 1) + index] = 'A' + letter;
				str[index] = 'A' + letter;
				printf("i * map_nb + index = %d\n", i * map_nb + index);
			}
			k >>= 1;
			++j;
		}
		++i;
	}
	++letter;
}

char	*affichage(char map_nb, t_lst **tab, char nb_tetri)
{	
	int		idx_tetri;
	char 	*str;
	int		i;

	if (!(str = (char*)ft_strnew(map_nb * (map_nb + 1))))
		return (0);
	ft_memset(str, '.', map_nb * (map_nb + 1));
//	str[map_nb * map_nb + 1] = '\0';
	i = 0;
	while (i < (map_nb))
	{
		str[((i + 1) * (map_nb + 1)) - 1] = '\n';
		++i;
	}
	idx_tetri = 0;
	while (idx_tetri < nb_tetri)
	{
		printf("BOUCLE INFINIE\n"); 
		ft_place_tetri(str, map_nb, tab, (char)idx_tetri);
		idx_tetri++;
	}		
	ft_putstr(str);
//	ft_memdel((void**)str);
	return (0);
}
