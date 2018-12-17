/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issamplevalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:29:58 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/17 17:24:45 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	ft_block_test(char *buf)
{
	int		i;
	char	hash_nb;
	char	backslash;

	i = 0;
	hash_nb = 0;
	backslash = 0;
	while (*(++buf) && ++i < 21)
	{
		if (i % 5 != 0 && !(*buf == '#' || *buf == '.'))
			return (0);
		else if (*buf == '#')
			++hash_nb;
		else if (i % 5 == 0)
		{
			if (*buf == '\n')
				++backslash;
			else
				return (0);
		}
	}
	if (hash_nb != 4 || backslash != 4)
		return (0);
	else
		return (1);
}

static char	ft_nbtetri(char *buf)
{
	char	nb_tetri;

	nb_tetri = 0;
	while (*buf)
	{
		if (ft_block_test((buf - 1)))
		{
			++nb_tetri;
			buf = buf + 20;
		}
		else
			return (0);
		if (!(*buf))
			return (nb_tetri);
		else if (*buf == '\n')
		{
			if (!(*(buf + 1)))
				return (0);
			else
				++buf;
		}
		else
			return (0);
	}
	return (nb_tetri);
}

char		issamplevalid(char *argv)
{
	int		fd;
	char	nb_tetri;
	char	buf[BUFF_SIZE];
	t_lst	*tab;

	nb_tetri = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (-1);
	if ((read(fd, buf, BUFF_SIZE)) <= 0 || !(nb_tetri = ft_nbtetri(buf)))
	{
		close(fd);
		return (-1);
	}
	printf("nb tetri: %d\n", nb_tetri);
	tab = ft_stock(buf, nb_tetri);
//	check tetrimonos valid
//	rempli le tableau
	
	return (0);
}
