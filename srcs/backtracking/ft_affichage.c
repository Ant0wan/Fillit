/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:38:07 by aquan             #+#    #+#             */
/*   Updated: 2018/12/19 16:13:40 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "fillit.h"
/*
   char	*ft_lines(char *str, int mapsize)
   {
   int i;
   i = 0;
   while (*str)
   {
   if ((i++ % mapsize) == 0)
 *str = '\n';
 str++;
 }
 }
 */

void	ft_bzero(void *s, size_t n)
{
	unsigned long		i;
	char				*c;

	c = (char*)s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}


void	*ft_memalloc(size_t size)
{
	void *mem;

	if (size == 0)
		return (NULL);
	if (!(mem = malloc((size))))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

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

void	*ft_lines(char *str, int mapsize)
{
	int i;

	i = 0;
	while (*str)
	{
		if ((i % mapsize) == 0)
			*str = '\n';
		++str;
		++i;
	}
	return (0);
}

void	*ft_place_tetri(char *str, int mapsize, t_lst **tab)
{	
	static int 	letter = 0;
	int			j;
	int			i;
	unsigned 	int	n;
	
	i = 4;
	while (i-- < 4)
	{
		j = (*tab)->y * mapsize + (*tab)->x + j;
		n = (2^28);
		while (n > (2^28))
		{
			if ((n & ((*tab)->tetri[0])))
			{
				str[j++] = 'A' + letter;
				n >>= 1;
			}
			while (str[j] < 4)
				(*tab)->tetri[0] <<= 1;
			while (str[j] && str[j] != '\n')
				++j;
			n >>= 1;
		}
	}
	++letter;
	return (0);
}


char	*affichage(int mapsize, t_lst **tab)
{	
	int i;
	char *str;
	//	char *ptr;

	str = ft_strnew(mapsize * mapsize + 1);
	memset(str, '.', mapsize * mapsize + 1);
	str[mapsize * mapsize + 1] = '\0';
	ft_lines(str, mapsize + 1);
	while (*str >= 0)
	{
		ft_place_tetri(str, mapsize, tab);;
		--str;
	}		
	ft_putstr(str);
	free(str);
	return (0);
}


int main(void)
{
	int a = 5;
	char *tab;
	tab = strdup("...#...#...#...#");
	affichage(a, &tab);
	return (0);	
}
