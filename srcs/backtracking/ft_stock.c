/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:44:34 by aquan             #+#    #+#             */
/*   Updated: 2018/12/17 15:42:22 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_lst	ft_stock(char nb_tetri)
{
	int i;
	t_lst tetri;
	t_lst **tab;
	
	if (!(tab = (t_lst**)malloc(sizeof(*tab) * nb_tetri + 1)))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		tab[i].tetri[4] = tetri->tetri[4]
		tab[i].x = tetri->x;
		tab[i].y = tetri->y;
		tab[i].width = tetri->width;
		tab[i].height = tetri->height;
		i++;
	}
}
