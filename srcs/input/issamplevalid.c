/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issamplevalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:29:58 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/17 14:08:53 by abarthel         ###   ########.fr       */
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

static char	ft_format_test(char *buf)
{
	while (*buf)
	{
		if (ft_block_test((buf - 1)))
		{
			buf = buf + 20;
		}
		else
			return (1);
		if (!(*buf))
			return (0);
		else if (*buf == '\n')
		{
			if (!(*(buf + 1)))
				return (1);
			else
				++buf;
		}
		else
			return (1);
	}
	return (0);
}

char		issamplevalid(char *argv)
{
	int		fd;
	char	nb_tetriminos;
	char	buf[BUFF_SIZE];

	nb_tetriminos = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (-1);
	if ((read(fd, buf, BUFF_SIZE)) <= 0)
	{
		close(fd);
		return (-1);
	}
	if ((ft_format_test(buf)) == -1)
	{
		close (fd);
		return (-1);
	}
	if ()


		// STILL START HERE
	else if ((close(fd)) == -1)
		return (-1);
	if ((ft_is_tetri_valid(ft_block_to_tetri(buf))) == -1)
	{
		close(fd);
		return (-1);
	}
	++nb_tetriminos;
	return (nb_tetriminos);
}
