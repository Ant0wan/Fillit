/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:24:10 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/03 15:48:23 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned char *ft_mapsize(int nb)
{
	int i;
	int u;
	unsigned char *mapsize;

	i = 0;
	u = 0;
	i = nb / 4;
	u = nb % 4;
	if (u != 0)
		i = i + 1;
	if (!(mapsize = (unsigned char*)malloc(sizeof(unsigned char) * (i - 1) + 2)))
		return (NULL);
	return (mapsize);
}
