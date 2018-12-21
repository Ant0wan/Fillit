/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <aquan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:38:07 by aquan             #+#    #+#             */
/*   Updated: 2018/12/21 13:20:52 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_output_fillit(t_lst *tab, char nb_tetri, char map_nb)
{
	char	*str;
	int		i;
	int		nb_bits;

	(void)nb_tetri;
	(void)tab;

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
	}
}

