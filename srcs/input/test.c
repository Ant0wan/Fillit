/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 10:58:23 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/17 11:35:51 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


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
		printf("%c\n", *buf);
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
		if ((res = ft_format_test(buf)))
		{
			buf = buf + 21;
			printf("res %d\n", (int)res);
		}
		else
			return (1);
		if (*buf == '\n' && !(*(buf + 1)))
			return (1);
		printf("%c\n", *buf);
	}
	return (0);
}

int main()
{
	printf("resultat ok0 ko1  : %d\n", ft_test("....\n....\n####\n....\n\n"));

	return 0;
}
