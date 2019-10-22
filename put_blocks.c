/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_blocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:00:14 by adavis            #+#    #+#             */
/*   Updated: 2019/10/22 16:05:47 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_blocks(t_blocks *blocks)
{
	int		cnt;

	cnt = 1;
	while ((blocks = blocks->next))
		cnt++;
	return (cnt);
}

int		max(int **points, int xy)
{
	int		i;
	int		max;

	max = 0;
	i = -1;
	while (++i < 4)
	{
		if (points[i][xy] > max)
			max = points[i][xy];
	}
	return (max);
}

void	block_to_map(char **map, t_blocks *b, int ox, int oy)
{
	int		i;

	i = -1;
	while (++i < 4)
		map[b->points[i][1] + oy][b->points[i][0] + ox] = b->letter;
	b->put = 1;
}

int		will_fit(char **map, int **points, int ox, int oy)
{
	int		i;
	int		size;
	char	**tmp;

	tmp = map;
	size = 0;
	while (*tmp)
	{
		size++;
		tmp++;
	}
	i = -1;
	while (++i < 4)
	{
		if (points[i][1] + oy >= size || points[i][0] + ox >= size)
			return (0);
		if (map[points[i][1] + oy][points[i][0] + ox] != '.')
			return (0);
	}
	return (1);
}

void		move_offset(int **points, int offset[], int size)
{
	if (offset[0] + max(points, 0) < size)
		offset[0]++;
	else
	{
		offset[1]++;
		offset[0] = 0;
	}
}

int			put_next(char **map, t_blocks *blocks, int size)
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
	//free_blocks(blocks);
}
