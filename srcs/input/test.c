/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 10:58:23 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/17 13:05:03 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_format_test(char *buf)
{
	int		i;
	char	hash_nb;
	char	backslash;

	i = 0;
	hash_nb = 0;
	backslash = 0;
	while (*buf && ++i < 21)
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
		++buf;
	}
	if (hash_nb != 4)
		return (0);
	if (backslash != 4)
		return (0);
	else
		return (1);
}

char	ft_test(char *buf)
{
	char res;

	res = 0;
	while (*buf)
	{
		if (ft_format_test(buf))
			buf = buf + 20;
		else
			return (1);
		if (!(*buf))
			return (0);
		else if (*buf == '\n')
			++buf;
		else
			return (1);
	}
	return (0);
}