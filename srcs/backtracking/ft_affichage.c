/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:38:07 by aquan             #+#    #+#             */
/*   Updated: 2018/12/21 10:59:28 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
void	*ft_lines(char *str, char map_nb)
{
	int i;

	i = 0;
	while (i < (map_nb * (map_nb + 1)))
	{
		if ((i + 1 % map_nb) == 0)
			str[i] = '\n';
		++i;
	}
	return (0);
}

void	*ft_place_tetri(char *str, char map_nb, t_lst **tab, char n)
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
		printf("TEST\n");
		while (j < ((*tab)[(int)n].width))
		{		
			if (((*tab)[(int)n].tetri[i]) & (0x1 << 15))
			{	
				index = ((*tab)[(int)n].y) * (map_nb + 1) + ((*tab)[(int)n].x + j);
				str[j++] = 'A' + letter;
		//		k <<= 1;
			}
			printf("VALEUR DE J: %d\n", j);
			printf("VALEUR DE K: %d\n", k);
			k <<= 1;
			j++;
		}
		i++;
	}
	++letter;
	return (0);
}

char	*affichage(char map_nb, t_lst **tab, char nb_tetri)
{	
	int idx_tetri;
	char *str;

	if (!(str = (char*)ft_strnew(map_nb * (map_nb + 1))))
		return (0);
	ft_memset(str, '.', map_nb * (map_nb + 1));
//	str[map_nb * map_nb + 1] = '\0';
	ft_lines(str, map_nb + 1);
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
