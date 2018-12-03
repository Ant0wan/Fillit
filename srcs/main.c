/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/03 14:55:09 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	(void)argv;
	int		nb_tetri;

	nb_tetri = 0;
	if (argc != 2)
		write(1, "error\n", 6);
	else
	{
		if ((nb_tetri = issamplevalid(argv[1])) == -1)
			write(1, "error\n", 6);
		else
		{
			printf("nb of tetri: %d\n", nb_tetri);
			write(1, "Sotckage tetriminos ==> \n", 25); // backtracking algo
			
		}
	}
	return (0);
}
