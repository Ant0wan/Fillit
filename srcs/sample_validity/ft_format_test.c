/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:21:47 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/13 13:25:48 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
