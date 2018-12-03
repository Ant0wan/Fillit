/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:12:48 by aquan             #+#    #+#             */
/*   Updated: 2018/12/03 15:07:20 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	*ft_stock_tetri(int nb, char *av)
{
	unsigned short *map;
	int i;
	int fd;
	char buf[BLOCK_SIZE];

	if ((fd = open(av, O_RDONLY)) == -1)
		return(NULL);
	else
	{
		if (!(map = (unsigned short*)malloc(sizeof(*map) * nb)))
			return (NULL);
		i = 0;
		while ((read(fd, buf, BLOCK_SIZE)) > 0)
		{
			map[i] = ft_block_to_tetri(buf);
			++i;
		}
	}
	if ((close(fd)) == -1)
	{
		free(map);
		return (NULL);
	}
	else
		return (map);
}

