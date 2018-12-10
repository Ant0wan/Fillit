/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_longueur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:05:54 by aquan             #+#    #+#             */
/*   Updated: 2018/12/10 10:44:41 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int ft_power(int x, unsigned int n) 
{
	int y;
	unsigned int m;
	y = 1; 
	m = 1;
	while (m <= n)
	{
		y *= x;
		m++;
	}
	return y;
}
unsigned short ft_line_mask(int map_nb)
{
	return(ft_power(2, map_nb) - 1);	
}

unsigned short ft_modif_longueur(unsigned short tetriminos, int map_nb)
{
	int i;
	unsigned short tetro_long;
	unsigned short mask;

	i = -1;
	tetro_long = tetrominos;
	while (++i < 4)
	{
		mask = ft_line_mask(4 + map_nb * i);
		mask &= tetro_long;
		tetro_long ^=mask;
		tetro_long <<= map_nb - 4;
	}
	return (tetro_long);
}
