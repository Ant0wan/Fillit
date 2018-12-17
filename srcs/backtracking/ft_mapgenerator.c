/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapgenerator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:24:10 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/13 13:22:10 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int	*ft_mapgenerator(void)
{
	unsigned int	*map;

	if (!(map = (unsigned int*)ft_memalloc(sizeof(unsigned int) * ROW_NB)))
		return (NULL);
	return (map);
}