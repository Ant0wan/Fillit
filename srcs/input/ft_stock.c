/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:44:34 by aquan             #+#    #+#             */
/*   Updated: 2018/12/17 17:45:41 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int	assign_tetri(char *s)
{
	unsigned int	shape;
	char			a;
	char			b;
	char			c;
	char			d;

	a = 0;
	b = 0;
	c = 0;
	d = 0;
	shape = 0;
	if (*s == '#')
		a = 1;
	if (*(s + 1) == '#')
		b = 1;
	if (*(s + 2) == '#')
		c = 1;
	if (*(s + 3) == '#')
		d = 1;
	shape = shape ^ ((a << 3) | (b << 2) | (c << 1) | (d << 0));
	return (shape);
}

t_lst	*ft_stock(char *buf, char nb_tetri)
{
	char	i;
	t_lst	*tab;

	if (!(tab = (t_lst*)ft_memalloc(sizeof(t_lst) * nb_tetri)))
		return (NULL);
	i = 0;
	while (i < nb_tetri)
	{
		tab[i].tetri[0] = assign_tetri(buf);
		printf("tetri: %d\n", tab[i].tetri[0]);
		tab[i].tetri[1] = assign_tetri((buf + 5)); 
		tab[i].tetri[2] = assign_tetri((buf + 10));
		tab[i].tetri[3] = assign_tetri((buf + 15));
//		tab[i].width = 0; // to change
//		tab[i].height = 0; // to change
//		tab[i].x = 32 - width;
//		tab[i].y = 0;
		++i;
		buf += 21;
	}
	return (tab);
}
