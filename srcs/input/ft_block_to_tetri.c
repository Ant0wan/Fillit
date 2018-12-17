/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block_to_tetri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:32:39 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/13 13:24:46 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	ft_block_to_tetri(char *str)
{
	char			u;
	char			i;
	unsigned short	tetriminos;

	i = 0;
	u = 15;
	tetriminos = n_mask;
	while (*str && i < 21)
	{
		if (*str == '.')
			--u;
		else if (*str == '#')
		{
			tetriminos = tetriminos | (1 << u);
			--u;
		}
		++i;
		++str;
	}
	if (i == 21 || u == -1)
		return (tetriminos);
	return (n_mask);
}
