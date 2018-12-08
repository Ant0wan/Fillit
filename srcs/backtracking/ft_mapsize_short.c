/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapsize_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:24:30 by aquan             #+#    #+#             */
/*   Updated: 2018/12/08 16:32:57 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	*ft_mapsize(int i) //i de map_min_size
{
	unsigned short *mapsize;
	
	if (!(mapsize = (unsigned short*)ft_memalloc(sizeof(unsigned short) * 16)))
		return (NULL);
	return (mapsize);
}
