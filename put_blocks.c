/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_blocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:00:14 by adavis            #+#    #+#             */
/*   Updated: 2019/10/18 21:20:27 by adavis           ###   ########.fr       */
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
}

int		will_fit(char **map, int **points, int ox, int oy)
{
	int		i;

	i = -1;
	while (++i < 4)
		if (map[points[i][1] + oy][points[i][0] + ox] != '.')
			return (0);
	return (1);
}

void	undo_swap(t_blocks **blocks)
{
	t_blocks	*target;
	t_blocks	*tmp;
	t_blocks	*next;

	target = *blocks;
	*blocks = target->next;
	tmp = *blocks;
	next = NULL;
	while (tmp->next)
	{
		if (tmp->next->letter != tmp->letter + 1)
		{
			next = tmp->next;
			tmp->next = target;
			break ;
		}
		tmp = tmp->next;
	}
	target->next = next;
}

int		swap_blocks(t_blocks **blocks, int n)
{
	t_blocks	*prev;
	t_blocks	*target;

	target = *blocks;
	while (n--)
	{
		prev = target;
		target = target->next;
		if (target->next == NULL)
			return (0);
	}
	prev->next = target->next;
	target->next = *blocks;
	*blocks = target;
	return (1);
}

int		put_next(char **map, t_blocks *blocks, int size)
{
	int		ox;
	int		oy;

	ox = 0;
	oy = 0;
	while (!will_fit(map, blocks->points, ox, oy))
	{
		if (max(blocks->points, 1) + oy + 1 < size)
		{
			if (max(blocks->points, 0) + ox < size)
				ox++;
			else
			{
				oy++;
				ox = 0;
			}
		}
		else
			return (0);
	}
	block_to_map(map, blocks, ox, oy);
	blocks->put = 1;
	if (blocks->next && !put_next(map, blocks->next, size))
	{
		remove_block(map, blocks->letter);
		blocks->put = 0;
		return (0);
	}
	return (1);
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

char	rotate_blocks(t_blocks **blocks)
{
	t_blocks	*tmp;
	t_blocks	*head;

	tmp = *blocks;
	*blocks = (*blocks)->next;
	head = *blocks;
	while ((*blocks)->next)
		*blocks = (*blocks)->next;
	(*blocks)->next = tmp;
	tmp->next = NULL;
	*blocks = head;
	return (head->letter);
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
		{
			if (rotate_blocks(&blocks) == 'A')
				size++;
		}
		free_map(map);
	}
	print_map(map);
}
