/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issamplevalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:29:58 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/13 13:30:00 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


char	ft_format_test(char *buf)
{
	char	i;
	char	hash_nb;

	hash_nb = 0;
	while (*buf)
	{
		i = 1;
		while (*buf && i < 21)
		{
    	    if (i % 5 == 0)
    	   {
    	       	if (*buf != '\n')
					return (-1);
    	   }
			else if (!(*buf == '.'))
			{
				if (*buf == '#')
					++hash_nb;
				else
					return (-1);
			}
			hash_nb = (i + 1) % 21 ? hash_nb : 0;
			++i;
			++buf;
		}
		if (i != 21)
			return (-1);
		else if (i == 21)
			if (!(*buf))
				return (1);
		else if (*buf != '\n')
			return (-1);
		else if (hash_nb > 4)
			return (-1);
		++buf;
	}
	return (1);
}


int main()
{
    printf("resultat: %d\n", ft_format_test(".#..\n.#..\n.#..\n.#..\n\n"));

    return 0;
}


char	ft_format_test(int fd)
{
	int		ret;
	int		i;
	char	hash_nb;
	char	buffer[BUFF_SIZE];

	i = 0;
	hash_nb = 0;
	while ((ret = (int)read(fd, buffer, BUFF_SIZE)) > 0 && i < 21)
	{
		if (*buffer == '#')
			++hash_nb;
		if (hash_nb > 4)
			return (-1);
		if ((i == 20 || (i + 1) % 5 == 0) && *buffer != '\n')
			return (-1);
		else if (i != 20 && ((i + 1) % 5 != 0 && !(*buffer == '#'
						|| *buffer == '.')))
			return (-1);
		hash_nb = (i + 1) % 21 ? hash_nb : 0;
		i = (i + 1) % 21;
	}
	return (1);
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
