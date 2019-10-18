/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:23:28 by adavis            #+#    #+#             */
/*   Updated: 2019/10/18 21:19:31 by adavis           ###   ########.fr       */
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
	int				put;
}					t_blocks;


void	validate(int fd);

void	normalize_coords(t_blocks *blocks);

void	print_blocks(t_blocks *blocks);
void	init_blocks(t_blocks **blocks, char *block);
void	add_block(t_blocks **blocks, char *block);

int		count_blocks(t_blocks *blocks);
int		max(int **points, int xy);
int		put_next();
void	try_mapping(t_blocks *blocks);

void	remove_block(char **map, char letter);
void	fill_map(char **map, int map_size);
void	print_map(char **map);
int		map_size(t_blocks *blocks);
