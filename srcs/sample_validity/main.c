/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:21:47 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/30 11:20:47 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//#include "fillit.h"
#define BUFF_SIZE 1 // temporary
#include <fcntl.h> // temp
#include <unistd.h> // temp
#include <stdio.h> // temp

int		ft_format_test(int fd);

int		wrap_test(char *file_path)
{
	int	fd;
	int	check;

	if ((fd = open(file_path, O_RDONLY)) < 0)
		return (-1);
	check = ft_format_test(fd);
	if ((close(fd)) < 0)
		return (-1);
	if (check == -1)
		return (-1);
	if ((fd = open(file_path, O_RDONLY)) < 0)
		return (-1);
//	check = ft_tetri_validity();
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
