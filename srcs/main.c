/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/18 14:26:48 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	unsigned char	nb_tetri;
	t_lst			*tab;

	tab = NULL;
	if (argc != 2)
		write(1, "error\n", 6);
	else
	{
//		printf("nb_tetri (issamplereturn):  %d\n", issamplevalid(&tab, argv[1]));
		if (!(nb_tetri = issamplevalid(&tab, argv[1])))
		{
			printf("invalid"); // DEBUGG
			write(1, "error\n", 6);
		}
		else
		{
			printf("valid\nnb tetri: %d\n", (int)nb_tetri);
//			printf("tet: %d\n", (int)tab[0].tetri[0]);
			backtracking(&tab, nb_tetri);
		}
	}
	return (0);
}
