/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issamplevalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:21:47 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/29 15:04:29 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// is sample and pieces valid ?
//count nb of pieces

//#include "fillit.h"
#define BUFF_SIZE 1 // temporary
#include <fcntl.h> // temp
#include <unistd.h> // temp
#include <stdio.h> // temp

static int		format_test(int fd)
{
	int		ret;
	int		i;
	int		hash_nb;
	char	buffer[BUFF_SIZE];

	i = 0;
	hash_nb = 0;
	while ((ret = (int)read(fd, buffer, BUFF_SIZE)) > 0 && i < 21)
	{
		if (*buffer == '#')
			hash_nb++;
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

static int		tetriminos_validity(int fd)
{
	int				u;
	int				i;
	unsigned short	tetriminos;
	char			buffer[BUFF_SIZE];

	i = 0;
	u = 0;
	(void)tetriminos;
	while (read(fd, buffer, BUFF_SIZE) > 0 && i < 21)
	{
		if (*buffer == '.' )
		{
			write(1, "0", 1i);
			u++;
		}
		else if (*buffer == '#')
			write(1, "1", 1);
		i++;
	}	

	return (1);
}

int		wrap_test(char *file_path)
{
	int	fd;
	int	check;

	if ((fd = open(file_path, O_RDONLY)) < 0)
		return (-1);
	check = format_test(fd);
	if ((close(fd)) < 0)
		return (-1);
	if (check == -1)
		return (-1);
	if ((fd = open(file_path, O_RDONLY)) < 0)
		return (-1);
	check = tetriminos_validity(fd);
	if ((close(fd)) < 0)
		return (-1);
	else
		return (1);
}


/*
** Main for testings
*/

int		main(int argc, char **argv)
{
	int		ret;

	ret = 0;
	if (argc == 2)
	{
		ret = wrap_test(argv[1]);
		printf("format_test return: %d\n", ret);
	}
	return (0);
}
