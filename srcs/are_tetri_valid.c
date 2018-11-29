/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issamplevalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:21:47 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/29 16:31:31 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// is sample and pieces valid ?
//count nb of pieces

//#include "fillit.h"
#define BUFF_SIZE 1 // temporary
#include <fcntl.h> // temp
#include <unistd.h> // temp
#include <stdio.h> // temp

int		format_test(int fd);

static int		tetriminos(int fd)
{
	int				u;
	int				i;
	unsigned short	tetriminos;
	char			buffer[BUFF_SIZE];

	i = 0;
	u = 15;
	tetriminos = 0x00;
	while (read(fd, buffer, BUFF_SIZE) > 0 && i < 21)
	{
		if (*buffer == '.' )
			--u;
		else if (*buffer == '#')
		{
			tetriminos = tetriminos | (1 << u);
			--u;
		}
		++i;
	}
//	printf("tetri: %d\n", tetriminos);
	printf("u: %d\n", u);
//	test joins
//
	return (1);
}
