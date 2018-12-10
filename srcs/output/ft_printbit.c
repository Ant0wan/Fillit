/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:29:23 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/10 15:09:00 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printbit(unsigned char byte)
{
	if ((byte & (1 << 0)) == 1)
		write(1, "#", 1);
	else
		write(1, ".", 1);
}
