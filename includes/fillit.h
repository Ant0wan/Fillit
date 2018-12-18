/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:56:46 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/18 12:29:29 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

// DEBUGG
# include <stdio.h>

#define BUFF_SIZE 2048

typedef struct	s_lst
{
	unsigned int	tetri[4];
	char			width;
	char			height;
	char			x;
	char			y;
}				t_lst;

unsigned char	issamplevalid(t_lst **tab, char *av);

void			ft_bzero(void *s, size_t n);

void			*ft_memalloc(size_t size);

t_lst			*ft_stock(char *buf, char nb_tetri);

char			ft_is_tetri_valid(unsigned int *tetri);

#endif
