/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:56:46 by abarthel          #+#    #+#             */
/*   Updated: 2018/11/29 14:37:54 by abarthel         ###   ########.fr       */
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

# define BUFF_SIZE 1

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
	mask1 = 0x00, // Not valid
	mask2 = 0x01, // Not valid
};

#endif
