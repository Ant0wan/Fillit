/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbyte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:29:23 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/03 17:01:23 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fillit.h"

#include <unistd.h>

void	ft_printbyte(unsigned char byte)
{
	int	i;
	unsigned char	mask;

	i = 8;
	mask = 0b00000001;
	while (--i >= 0)
		if ((byte >> i & mask) == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
}

int	main(void)
{
	ft_printbyte(0b00010001);
	return (0);
}
