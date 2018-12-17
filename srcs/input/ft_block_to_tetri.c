/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block_to_tetri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:32:39 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/17 15:30:39 by abarthel         ###   ########.fr       */
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

unsigned int		*ft_block_to_tetri(char *str)
{
	unsigned int	tetri[4];

	tetri[0] = assign_tetri(str);
	tetri[1] = assign_tetri((str + 5));
	tetri[2] = assign_tetri((str + 10));
	tetri[3] = assign_tetri((str + 15));
	return (tetri);
}
