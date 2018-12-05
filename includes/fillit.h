/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:56:46 by abarthel          #+#    #+#             */
/*   Updated: 2018/12/05 14:32:08 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // DEBUGG, TO BE DELETED

# define BUFF_SIZE   1
# define BLOCK_SIZE 21

/*
** Enum holding the binary masks for testing tetriminos validity
*/

enum	e_masks
{
	h_mask = 0b0000000000000011,
	v_mask = 0b0000000000000001,
	n_mask = 0b0000000000000000,
};

/*
** Sample test functions
*/

unsigned short	ft_block_to_tetri(char *str);

unsigned short	*ft_stock_tetri(int nb, char *av);

unsigned char	*ft_mapsize(int nb);

int				ft_format_test(int fd);

int				ft_is_tetri_valid(unsigned short tetriminos);

int				issamplevalid(char *argv);

void			ft_printbit(unsigned char byte);

#endif
