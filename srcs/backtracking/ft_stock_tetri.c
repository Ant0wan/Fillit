/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:12:48 by aquan             #+#    #+#             */
/*   Updated: 2018/12/13 13:32:35 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

unsigned short			*ft_stock_tetri(char nb, char *av)
{
	unsigned short	*tab_tetr;
	int				i;
	int				fd;
	char			buf[BLOCK_SIZE];

	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	else
	{
		if (!(tab_tetr = (unsigned short*)ft_memalloc(sizeof(*tab_tetr) * nb)))
			return (NULL);
		i = 0;
		while ((read(fd, buf, BLOCK_SIZE)) > 0)
		{
			tab_tetr[i] = ft_pushleft(ft_block_to_tetri(buf));
			++i;
		}
	}
	if ((close(fd)) == -1)
	{
		free(tab_tetr);
		return (NULL);
	}
	else
		return (tab_tetr);
}
