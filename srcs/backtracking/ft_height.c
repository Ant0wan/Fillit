/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_height.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:02:00 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/12 14:21:20 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	ft_height(unsigned short tetriminos)
{
	if (tetriminos & ~(part3_m))
		return (4);
	else if ((tetriminos & ~(part2_m)) >> 4)
		return (3);
	else if ((tetriminos & ~(part1_m)) >> 8)
		return (2);
	else
		return (1);
}
