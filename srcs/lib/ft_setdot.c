/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setdot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:09:45 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/21 12:51:20 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_bdot(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_ptr;

	i = -1;
	s_ptr = (unsigned char*)s;
	while (++i < n)
		s_ptr[i] = '.';
	s_ptr[i] = 0x00;
}

void	*ft_setdot(size_t size)
{
	void	*p_mem;

	p_mem = (void*)malloc(size);
	if (!p_mem)
		return (NULL);
	ft_bdot(p_mem, size);
	return (p_mem);
}
