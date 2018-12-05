/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:24:10 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/05 14:24:56 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** nb: side length of the square, starts min with 4bytes(16bits)
*/

unsigned char	*ft_mapsize(int nb)
{
	int				i;
	int				u;
	int				sq;
	unsigned char	*mapsize;

	if (nb < 4)
		return (NULL);
	i = 0;
	u = 0;
	sq = nb * nb;
	i = sq / 8;
	u = sq % 8;
	if (u != 0)
		i = i + 1;
	if (!(mapsize = (unsigned char*)malloc(sizeof(unsigned char) * i)))
		return (NULL);
	return (mapsize);
}
