/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/18 12:31:03 by abarthel         ###   ########.fr       */
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
		printf("nb_tetri (issamplereturn):  %d\n", issamplevalid(&tab, argv[1]));
//		if (!(nb_tetri = issamplevalid(tab, argv[1])))
//			write(1, "error\n", 6);
//		else
//			backtracking(tab, nb_tetri);
		printf("tet: %d\n", (int)tab[0].tetri[0]);
	}
	return (0);
}
