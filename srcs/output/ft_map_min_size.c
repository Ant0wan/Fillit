/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_min_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:51:01 by aquan             #+#    #+#             */
/*   Updated: 2018/12/05 18:06:43 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_map_min_size(int nb_tetri)
{
	int i;

	i = 0;
	while (nb > i * i)
	{
		i++;
		if (nb == i * i)
			return (i);
	}
	i++;
	return (i);
}
