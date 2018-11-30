/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:21:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/30 17:29:31 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		write(1, "error\n", 6);
	else
	{
		if (issamplevalid(argv[1]) == -1)
			write(1, "error\n", 6);
		else
			write(1, "ok\n", 3); // backtracking algo
	}
	return (0);
}
