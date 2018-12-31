/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/31 16:24:44 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	unsigned char	nb_tetri;
	t_lst			*tab;

	tab = NULL;
	if (argc != 2)
		write(1, "error\n", 6);
	else
	{
		if (!(nb_tetri = issamplevalid(&tab, argv[1])) || nb_tetri > 26)
			write(1, "error\n", 6);
		else
			backtracking(&tab, nb_tetri);
	}
	return (0);
}
