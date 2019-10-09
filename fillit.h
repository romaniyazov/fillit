/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:23:28 by adavis            #+#    #+#             */
/*   Updated: 2019/10/09 17:51:04 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"

typedef struct 		s_blocks
{
	char			letter;
	int				**points;
	struct s_blocks	*next;
}					t_blocks;


void	validate(int fd);

void	normalize_coords(t_blocks *blocks);

void	print_blocks(t_blocks *blocks);
void	init_blocks(t_blocks **blocks, char *block);
void	add_block(t_blocks **blocks, char *block);