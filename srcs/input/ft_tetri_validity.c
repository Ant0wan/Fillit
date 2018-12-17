/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:21:47 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/17 17:21:56 by abarthel         ###   ########.fr       */
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

static unsigned short	ft_pushleft(unsigned short tetriminos)
{
	unsigned short	tetriminos_lefted;

	tetriminos_lefted = tetriminos;
	while ((tetriminos_lefted & l_mask1) != l_mask1
			&& (tetriminos_lefted & l_mask2) != l_mask2
			&& (tetriminos_lefted & l_mask3) != l_mask3
			&& (tetriminos_lefted & l_mask4) != l_mask4)
		tetriminos_lefted = tetriminos_lefted << 1;
	while (tetriminos_lefted == (tetriminos_lefted & ~(up_mask)))
		tetriminos_lefted = tetriminos_lefted << 4;
	return (tetriminos_lefted);
}

static char			ft_is_tetri_valid(unsigned int *tetri)
{
	char	links_nb;

	links_nb = ft_count_vlinks(tetri) + ft_count_hlinks(tetri);
	if (links_nb == 3 || links_nb == 4)
		return (1);
	else
		return (-1);
}
