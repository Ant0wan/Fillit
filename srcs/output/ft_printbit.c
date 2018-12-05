/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:29:23 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/05 14:31:14 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printbit(unsigned char byte)
{
	unsigned char	mask;

	mask = 0b00000001;
	if ((byte << 0 & mask) == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}
