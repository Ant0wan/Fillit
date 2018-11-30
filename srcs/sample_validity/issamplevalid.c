/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issamplevalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:29:58 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/30 17:41:04 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			issamplevalid(char *argv)
{
	int		fd;
	int		nb_tetriminos;
	char	buf[BLOCK_SIZE];

	nb_tetriminos = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (-1);
	else if ((ft_format_test(fd)) == -1)
		return (-1);
	else if ((close(fd)) == -1)
		return (-1);
	else if ((fd = open(argv, O_RDONLY)) == -1)
		return (-1);
	while ((read(fd, buf, BLOCK_SIZE)) > 0)
	{
		if ((ft_is_tetri_valid(ft_block_to_tetri(buf))) == -1)
		{
			close(fd);
			return (-1);
		}
		++nb_tetriminos;
	}
	if ((close(fd)) == -1)
		return (-1);
	return (nb_tetriminos);
}
