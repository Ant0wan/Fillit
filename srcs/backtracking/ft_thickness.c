/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thickness.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:02:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/11 16:39:22 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	ft_indexlimit(unsigned short tetriminos)
{
	char	index;
	char	res;
	char	d;

	d = -1;
	index = 8;
	while (++d < 4)
	{
		res = ((tetriminos & ~(part0_m)) >> 12) & (v_mask << d);
		index = res < index && res > 0 ? res : index;
		res = ((tetriminos & ~(part1_m)) >> 8) & (v_mask << d);
		index = res < index && res > 0 ? res : index;
		res = ((tetriminos & ~(part2_m)) >> 4) & (v_mask << d);
		index = res < index && res > 0 ? res : index;
		res = (tetriminos & ~(part3_m)) & (v_mask << d);
		index = res < index && res > 0 ? res : index;
	}
	return (index);
}

char		ft_thickness(unsigned short tetriminos)
{
	char	thick;

	thick = ft_indexlimit(tetriminos);
	if (thick == 1)
		thick = 4;
	else if (thick == 2)
		thick = 3;
	else if (thick == 4)
		thick = 2;
	else if (thick == 8)
		thick = 1;
	return (thick);
}
