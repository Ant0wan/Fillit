/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placerm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:10:51 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/17 10:34:39 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_placerm(unsigned int *map, unsigned int *tetri, int x)
{
	map[0] ^= tetri[0] << x;
	map[1] ^= tetri[1] << x;
	map[2] ^= tetri[2] << x;
	map[3] ^= tetri[3] << x;
}
