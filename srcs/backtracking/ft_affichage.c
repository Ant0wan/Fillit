/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:38:07 by aquan             #+#    #+#             */
/*   Updated: 2018/12/20 13:40:15 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "fillit.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = ft_memalloc(size + 1);
	return (str);
}

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		ft_putchar(str[i++]);
}

void	*ft_lines(char *str, int map)
{
	int i;

	i = 0;
	while (*str)
	{
		if ((i % map) == 0)
			*str = '\n';
		++str;
		++i;
	}
	return (0);
}

void	*ft_place_tetri(char *str, int mapsize, t_lst **tab, char n)
{	
	static int 	letter = 0;
	int			j;
	int			i;
	unsigned 	int	k;
	
	i = 0;
	while (i++ < 4)
	{
		j = ((*tab)[(int)n].y) * (mapsize + 1) + ((*tab)[(int)n].x + j);
		k = (268435456);
		while (k > (268435456))
		{
			if ((k & ((*tab)[(int)n].tetri)))
			{
				str[j++] = 'A' + letter;
				k >>= 1;
			}
			while (str[j] < 4)
				(*tab)[(int)n].tetri <<= 1;
			while (str[j] && str[j] != '\n')
				++j;
			k >>= 1;
		}
	}
	++letter;
	return (0);
}


char	*affichage(int map, t_lst **tab, char n)
{	
	int idx_tetri;
	char *str;

	str = ft_strnew(map * map + 1);
	ft_memset(str, '.', map * map + 1);
	str[map * map + 1] = '\0';
	ft_lines(str, map + 1);
	idx_tetri = 0;
	while (idx_tetri < n)
	{
		ft_place_tetri(str, map, tab, n);
		idx_tetri++;
	}		
	ft_putstr(str);
	ft_memdel(str);
	return (0);
}


