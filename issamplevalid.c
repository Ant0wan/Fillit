/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issamplevalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:29:58 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/31 17:14:53 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char				ft_block_test(char *buf)
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

static unsigned char	ft_nbtetri(char *buf)
{
	unsigned char	nb_tetri;

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

unsigned char			issamplevalid(t_lst **tab, char *argv)
{
	int				fd;
	unsigned char	nb_tetri;
	char			*buf;
	char			n;

	nb_tetri = 0;
	n = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	if (!(buf = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
		return (0);
	if ((read(fd, buf, BUFF_SIZE)) <= 0 || !(nb_tetri = ft_nbtetri(buf)))
	{
		free(buf);
		close(fd);
		return (0);
	}
	close(fd);
	*tab = ft_stock(buf, nb_tetri);
	free(buf);
	if (!(*tab))
		return (0);
	while (++n < nb_tetri)
		(*tab)[(int)n].y = 0;
	return (nb_tetri);
}
