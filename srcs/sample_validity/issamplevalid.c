/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issamplevalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:29:58 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/30 15:08:19 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fillit.h"

#define BLOCK_SIZE 21
#include <fcntl.h> // temp
#include <unistd.h> // temp
#include <stdio.h> // temp

int				ft_format_test(int fd);

int				ft_is_tetri_valid(unsigned short tetriminos);

unsigned short	ft_block_to_tetri(char *str);

int		issamplevalid(char *argv)
{
	int		fd;
	int 	ret;
	char	buf[BLOCK_SIZE];

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (-1);
	else if ((ft_format_test(fd)) == -1)
		return (-1);
	else if ((close(fd)) == -1)
		return (-1);
	else if ((fd = open(argv, O_RDONLY)) == -1)
		return (-1);
	while ((read(fd, buf, BLOCK_SIZE)) > 0)
		if ((ret = ft_is_tetri_valid(ft_block_to_tetri(buf))) == -1)
		{
			close(fd);
			return (-1);
		}
	else if ((close(fd)) == -1)
		return (-1);
	return (ret);
}

int	main(int argc, char **argv)
{
	printf("valid ? => %d\n", issamplevalid(argv[1]));
	return (0);
}
