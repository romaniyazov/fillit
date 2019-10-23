/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_blocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:00:14 by adavis            #+#    #+#             */
/*   Updated: 2019/10/23 15:27:29 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		put_next(char **map, t_blocks *blocks, int size)
{
	int			offset[2];
	t_blocks	*b;

	b = blocks;
	offset[0] = -1;
	offset[1] = 0;
	while (b && b->put)
		b = b->next;
	if (!b)
		return (1);
	while (1)
	{
		if (offset[1] + max(b->points, 1) < size)
			move_offset(b->points, offset, size);
		else
			return (0);
		if (!will_fit(map, b->points, offset[0], offset[1]))
			continue ;
		block_to_map(map, b, offset[0], offset[1]);
		print_map(map);
		ft_putchar('\n');
		usleep(1000000);
		if (put_next(map, blocks, size))
			return (1);
		else
			remove_block(map, b);
	}
}

void	free_map(char **map)
{
	char	**tmp;

	tmp = map;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(map);
}

void	try_mapping(t_blocks *blocks)
{
	char	**map;
	int		i;
	int		size;

	size = map_size(blocks);
	while (1)
	{
		map = (char **)malloc(sizeof(char *) * (size + 1));
		i = -1;
		while (++i < size)
			map[i] = ft_strnew(size);
		map[size] = NULL;
		fill_map(map, size);
		if (put_next(map, blocks, size))
			break ;
		else
			size++;
		free_map(map);
	}
	print_map(map);
	free_map(map);
	free_blocks(blocks);
}
