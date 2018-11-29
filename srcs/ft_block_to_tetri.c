/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block_to_tetri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:32:39 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/29 16:02:02 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned short	ft_block_to_tetri(char *str)
{
	int				u;
	int				i;
	unsigned short	tetriminos;

	i = 0;
	u = 15;
	tetriminos = 0x00;
	while (*str && i < 21)
	{
		if (*str == '.' )
			--u;
		else if (*str == '#')
		{
			tetriminos = tetriminos | (1 << u);
			--u;
		}
		++i;
		++str;
	}
	if (i == 21 || u == -1)
		return (tetriminos);
	return (0x00);
}
