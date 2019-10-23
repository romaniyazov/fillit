/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:23:28 by adavis            #+#    #+#             */
/*   Updated: 2019/10/23 15:55:03 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

typedef struct		s_blocks
{
	char			letter;
	int				**points;
	struct s_blocks	*next;
	int				put;
}					t_blocks;

/*
**	misc.c
*/
void				remove_block(char **map, t_blocks *b);
void				fill_map(char **map, int map_size);
void				print_map(char **map);
int					map_size(t_blocks *blocks);

/*
**	normalize.c
*/
void				normalize_coords(t_blocks *blocks);

/*
**	put_blocks.c
*/
int					put_next(char **map, t_blocks *blocks, int size);
void				free_map(char **map);
void				try_mapping(t_blocks *blocks);

/*
**	put_blocks_misc.c
*/
int					count_blocks(t_blocks *blocks);
int					max(int **points, int xy);
void				block_to_map(char **map, t_blocks *b, int ox, int oy);
int					will_fit(char **map, int **points, int ox, int oy);
void				move_offset(int **points, int offset[], int size);

/*
**	validate.c
*/
int					check_newlines(char *block);
int					count_sharps(char *block);
int					check_links(char *block);
void				error_exit(t_blocks *blocks);
void				validate(int fd);

/*
**	blocks.c
*/
void				init_blocks(t_blocks **blocks, char *block);
void				add_block(t_blocks **blocks, char *block);
void				free_points(int **tab);
void				free_blocks(t_blocks *blocks);

#endif
