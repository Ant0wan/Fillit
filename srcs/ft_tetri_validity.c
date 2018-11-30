/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_validity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:21:47 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/30 13:45:43 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// is sample and pieces valid ?
//count nb of pieces

//#include "fillit.h"
#define BUFF_SIZE 1 // temporary
#include <fcntl.h> // temp
#include <unistd.h> // temp
#include <stdio.h> // temp

enum	e_masks
{
		h_mask = 0b0000000000000011,
		v_mask = 0b0000000000000001,
};

static int		ft_count_hlinks(unsigned short tetriminos)
{
	int		links_nb;
	int		move;

	links_nb = 0;
	move = 0;
	while (move < 15)
	{
		links_nb = (tetriminos >> move & h_mask) == 3 ? links_nb + 1 : links_nb;
		++move;
	}
	return (links_nb);
}

static int		ft_count_vlinks(unsigned short tetriminos)
{
	int		links_nb;
	int		move;

	links_nb = 0;
	move = 0;

	

	return (links_nb);
}

int		main(void)
{
	printf("%d\n", ft_count_vlinks(0b0001000100010001));
	return (0);
}
