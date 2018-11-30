/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:21:47 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/30 14:21:02 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// is sample and pieces valid ?
//count nb of pieces

//#include "fillit.h"
#define BUFF_SIZE 1 // temporary
#include <fcntl.h> // temp
#include <unistd.h> // temp
#include <stdio.h> // temp

enum	e_masks // TO DEL 'CAUSE IN .H ALREADY
{
		h_mask = 0b0000000000000011,
		v_mask = 0b0000000000000001,
};

static int		ft_count_hlinks(unsigned short tetriminos)
{
	int		links_nb;
	int		i;

	links_nb = 0;
	i = 0;
	while (i < 15)
	{
		links_nb = (tetriminos >> i & h_mask) == 3 ? links_nb + 1 : links_nb;
		++i;
	}
	return (links_nb);
}

static int		ft_count_vlinks(unsigned short tetriminos)
{
	int				links_nb;
	int				i;
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

int				ft_count_links(unsigned short tetriminos)
{
	int	links_nb;

	links_nb = 0;
	links_nb = ft_count_vlinks(tetriminos) + ft_count_hlinks(tetriminos);
	return (links_nb);
}

int		main(void)
{
	printf("%d\n", ft_count_links(0b0011001100000000));
	return (0);
}
