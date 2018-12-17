/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:21:47 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/17 18:03:23 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		ft_count_hlinks(unsigned int *tetri)
{
	char	links_nb;

	links_nb = 0;
	links_nb = (tetri[0] & 3) == 3 ? links_nb + 1 : links_nb;
	links_nb = (tetri[1] & 3) == 3 ? links_nb + 1 : links_nb;
	links_nb = (tetri[2] & 3) == 3 ? links_nb + 1 : links_nb;
	links_nb = (tetri[3] & 3) == 3 ? links_nb + 1 : links_nb;
	links_nb = (tetri[0] >> 1 & 3) == 3 ? links_nb + 1 : links_nb;
	links_nb = (tetri[1] >> 1 & 3) == 3 ? links_nb + 1 : links_nb;
	links_nb = (tetri[2] >> 1 & 3) == 3 ? links_nb + 1 : links_nb;
	links_nb = (tetri[3] >> 1 & 3) == 3 ? links_nb + 1 : links_nb;
	links_nb = (tetri[0] >> 2 & 3) == 3 ? links_nb + 1 : links_nb;
	links_nb = (tetri[1] >> 2 & 3) == 3 ? links_nb + 1 : links_nb;
	links_nb = (tetri[2] >> 2 & 3) == 3 ? links_nb + 1 : links_nb;
	links_nb = (tetri[3] >> 2 & 3) == 3 ? links_nb + 1 : links_nb;
	return (links_nb);
}

static char		ft_count_vlinks(unsigned int *tetri)
{
	char	links_nb;
	char	a;
	char	b;
	char	c;

	links_nb = 0;
	a = tetri[0] & tetri[1];
	b = tetri[1] & tetri[2];
	c = tetri[2] & tetri[3];
	links_nb = a & 1 ? links_nb + 1 : links_nb;
	links_nb = b & 1 ? links_nb + 1 : links_nb;
	links_nb = c & 1 ? links_nb + 1 : links_nb;
	links_nb = a >> 1 & 1 ? links_nb + 1 : links_nb;
	links_nb = b >> 1 & 1 ? links_nb + 1 : links_nb;
	links_nb = c >> 1 & 1 ? links_nb + 1 : links_nb;
	links_nb = a >> 2 & 1 ? links_nb + 1 : links_nb;
	links_nb = b >> 2 & 1 ? links_nb + 1 : links_nb;
	links_nb = c >> 2 & 1 ? links_nb + 1 : links_nb;
	links_nb = a >> 3 & 1 ? links_nb + 1 : links_nb;
	links_nb = b >> 3 & 1 ? links_nb + 1 : links_nb;
	links_nb = c >> 3 & 1 ? links_nb + 1 : links_nb;
	return (links_nb);
}

char			ft_is_tetri_valid(unsigned int *tetri)
{
	char	links_nb;

	links_nb = ft_count_vlinks(tetri) + ft_count_hlinks(tetri);
	if (links_nb == 3 || links_nb == 4)
		return (1);
	else
		return (0);
}
