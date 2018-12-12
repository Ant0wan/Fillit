/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thickness.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:02:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/12 14:39:28 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		ft_thickness(unsigned short tetriminos)
{
	char	d;

	d = -1;
	while (++d < 3)
	{
		if (((tetriminos & ~(part0_m)) >> 12) & (v_mask << d))
			return (4 - d);
		else if (((tetriminos & ~(part1_m)) >> 8) & (v_mask << d))
			return (4 - d);
		else if (((tetriminos & ~(part2_m)) >> 4) & (v_mask << d))
			return (4 - d);
		else if ((tetriminos & ~(part3_m)) & (v_mask << d))
			return (4 - d);
	}
	return (1);
}
