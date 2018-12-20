/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:38:07 by aquan             #+#    #+#             */
/*   Updated: 2018/12/20 17:46:49 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_place_tetri(char *str, char map_nb, t_lst **tab)
{	
	static int 	letter = 0;
	int			j;
	int			i;
	unsigned 	int	k;
	
	i = 0;
	while (i++ < 4)
	{
		j = ((*tab)[(int)n].y) * (map_nb + 1) + ((*tab)[(int)n].x + j);
		k = (ROW_NB);
		while (k > (ROW_NB - (*tab[(int)n].width)))
		{
			if ((k & ((*tab)[(int)n].tetri[0]) ||
			k & ((*tab)[(int)n].tetri[1]) ||
			k & ((*tab)[(int)n].tetri[2]) || 
			k & ((*tab)[(int)n].tetri[3])))
			{
				str[j++] = 'A' + letter;
				k >>= 1;
			}
			while (str[j] < 4)
			{	
				(*tab)[(int)n].tetri[0] <<= 1;
				(*tab)[(int)n].tetri[1] <<= 1;
				(*tab)[(int)n].tetri[2] <<= 1;
				(*tab)[(int)n].tetri[3] <<= 1;
			}
			while (str[j] && str[j] != '\n')
				++j;
			k >>= 1;
		}
	}
	++letter;
	return (0);
}

char	*affichage(char map_nb, t_lst **tab, char nb_tetri)
{	
	int idx_tetri;
	char *str;

	str = ft_strnew(map * map + 1);
	ft_memset(str, '.', map * map + 1);
	str[map * map + 1] = '\0';
	ft_lines(str, map + 1);
	idx_tetri = 0;
	while (idx_tetri < nb_tetri)
	{
		ft_place_tetri(str, map_nb, tab);
		idx_tetri++;
	}		
	ft_putstr(str);
	ft_memdel(str);
	return (0);
}

int main ()
{
	printf("%d", affichage(map_nb, tab, nb_tetri));
		ilose(fd);
}
