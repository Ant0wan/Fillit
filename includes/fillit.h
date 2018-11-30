/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:56:46 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/30 14:36:18 by abarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

/*
** issamplevalid.c
*/

# define BUFF_SIZE   1
# define BLOCK_SIZE 21

int				wrap_test(char *file_path);

/*
** Structure storing tetriminos
*/

typedef struct	s_tetriminos
{
	unsigned short	elem;
	void			*next;
}				t_tetriminos;

/*
** Enum holding the binary masks for testing tetriminos validity
*/

enum	e_masks
{
	h_mask = 0b0000000000000011,
	v_mask = 0b0000000000000001,
};

#endif
