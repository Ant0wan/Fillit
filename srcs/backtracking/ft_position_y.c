/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_y.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:10:51 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/11 17:18:39 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_position_y(unsigned int *map, unsigned short tetriminos, int map_nb)
{
	ft_position_x(map, tetriminos, map_nb, 0);	
}
