/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:21:47 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/13 13:28:28 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		ft_count_hlinks(unsigned short tetriminos)
{
	char	links_nb;
	char	i;

	links_nb = 0;
	i = 0;
	while (i < 15)
	{
		links_nb = (tetriminos >> i & h_mask) == 3 ? links_nb + 1 : links_nb;
		++i;
	}
	return (links_nb);
}

static char		ft_count_vlinks(unsigned short tetriminos)
{
	char			links_nb;
	char			i;
	unsigned short	a;
	unsigned short	b;
	unsigned short	c;

	links_nb = 0;
	i = 0;
	a = tetriminos >> 12 & tetriminos >> 8;
	b = tetriminos >> 8 & tetriminos >> 4;
	c = tetriminos >> 4 & tetriminos;
	while (i < 4)
	{
		links_nb = a >> i & v_mask ? links_nb + 1 : links_nb;
		links_nb = b >> i & v_mask ? links_nb + 1 : links_nb;
		links_nb = c >> i & v_mask ? links_nb + 1 : links_nb;
		++i;
	}
	return (links_nb);
}

char			ft_is_tetri_valid(unsigned short tetriminos)
{
	char	links_nb;

	links_nb = ft_count_vlinks(tetriminos) + ft_count_hlinks(tetriminos);
	if (links_nb == 3 || links_nb == 4)
		return (1);
	else
		return (-1);
}
