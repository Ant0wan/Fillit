/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:56:46 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/11 17:28:20 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE   1
# define BLOCK_SIZE 21
# define ROW_NB		32

/*
** Enum holding the binary masks for testing tetriminos validity
*/

enum	e_masks
{
	h_mask = 0b0000000000000011,
	v_mask = 0b0000000000000001,
	n_mask = 0b0000000000000000,
	l_mask1 = 0b1000000000000000,
	l_mask2 = 0b0000100000000000,
	l_mask3 = 0b0000000010000000,
	l_mask4 = 0b0000000000001000,
	up_mask = 0b1111000000000000,
	part0_m = 0b0000111111111111,
	part1_m = 0b1111000011111111,
	part2_m = 0b1111111100001111,
	part3_m = 0b1111111111110000,
};

/*
** Sample test functions
*/

unsigned short	ft_block_to_tetri(char *str);

unsigned short	*ft_stock_tetri(int nb, char *av);

unsigned int	*ft_mapsize(void);

int				ft_format_test(int fd);

int				ft_is_tetri_valid(unsigned short tetriminos);

int				issamplevalid(char *argv);

int				ft_mapminsize(int nb_tetri);

void			ft_printbit(unsigned char byte);

void			ft_printmap(unsigned int *map, int nb);

void			ft_bzero(void *s, size_t n);

void			*ft_memalloc(size_t size);

int				ft_position_x(unsigned int *map, unsigned short tetriminos,
		int map_nb, int l);

void			ft_position_y(unsigned int *map, unsigned short tetriminos,
		int map_nb, int l);

char			ft_thickness(unsigned short tetriminos);

#endif
