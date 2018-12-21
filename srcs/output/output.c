/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <aquan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:38:07 by aquan             #+#    #+#             */
/*   Updated: 2018/12/21 14:11:09 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_fitit(t_lst *tab, char *str, char nb_tetri, char map_nb)
{
	(void)tab;
	(void)nb_tetri;
	int	i;

	i = -1;
	while (++i < nb_tetri)	
	{
		str[3] = 'A' + i;
		str[3 + (map_nb + 1)] = 'A' + i;
		str[3 + (map_nb + 1) * 2] = 'A' + i;
		str[3 + (map_nb + 1) * 3] = 'A' + i;
	}
}


void	ft_output_fillit(t_lst *tab, char nb_tetri, char map_nb)
{
	char	*str;
	int		i;
	int		nb_bits;

	i = 0;
	nb_bits = (map_nb + 1) * map_nb;
	if (!(str = (char*)ft_setdot(sizeof(char) * nb_bits)))
		return;
	else
	{
		++i;
		while (++i < nb_bits)
			if (!((i + 1) % (map_nb + 1)))
				str[i] = '\n';
		ft_fitit(tab, str, nb_tetri, map_nb);
		write(1, str, nb_bits);
	}
}
