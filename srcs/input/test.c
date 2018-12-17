/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 10:58:23 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/17 11:10:02 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


char	ft_format_test(char *buf)
{
	int		ret;
	int		i;
	char	hash_nb;

	i = 0;
	hash_nb = 0;
	while (*buf && ++i < 21)
	{
		if (i % 5 != 0 && !(*buf == '#' || *buf == '.'))
			return (-1);
		else if (*buf == '#')
			++hash_nb;
		else if (i % 5 == 0 && *buf != '\n')
			return (-1);
		++buf;
	}
	if (hash_nb != 4)
		return (-1);
	else
		return (1);
}

//char	ft_test(char *buf)
//{

//}

int main()
{
	printf("resultat: %d\n", ft_format_test("....\n....\n####\n....\n"));

	return 0;
}
