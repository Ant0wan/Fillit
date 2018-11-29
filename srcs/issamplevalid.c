/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issamplevalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:21:47 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/29 12:57:34 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// is sample and pieces valid ?
//count nb of pieces

//#include "fillit.h"
#define BUFF_SIZE 1
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		format_test(char *file_path)
{
	int		fd;
	int		ret;
	int		i;
	char	buffer[BUFF_SIZE];

	if ((fd = open(file_path, O_RDONLY)) < 0)
		return (-1);
	else
	{
		i = 0;
		while ((ret = (int)read(fd, buffer, BUFF_SIZE)) > 0 && i < 21)
		{
			if ((i == 20 || (i + 1) % 5 == 0) && *buffer != '\n')
				return (-1);
			else if (i != 20 && ((i + 1) % 5 != 0 && !(*buffer == '#'
							|| *buffer == '.')))
				return (-1);
			write(1, &buffer[0], 1); // DEBUGG
			i = (i + 1) % 21; 
		}
		return (1);
	}
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
		ret = format_test(argv[1]);
		printf("format_test return: %d\n", ret);
	}
	return (0);
}
