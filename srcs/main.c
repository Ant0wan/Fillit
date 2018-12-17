/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/17 14:16:55 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
//	t_tetri *tab_tetri;

	if (argc != 2)
		write(1, "error\n", 6);
	else
	{
		printf("issample %d\n", issamplevalid(argv[1]));
//		if ((nb_tetri = issamplevalid(argv[1])) == -1)
//			write(1, "error\n", 6);
//		else
//			backtracking(nb_tetri, argv[1]);
	}
	return (0);
}
