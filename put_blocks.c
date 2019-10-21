/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_blocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:00:14 by adavis            #+#    #+#             */
/*   Updated: 2019/10/21 20:26:40 by adavis           ###   ########.fr       */
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

int			put_next(char **map, t_blocks *blocks, int size)
{
	int			ox;
	int			oy;
	t_blocks	*b;

	b = blocks;
	ox = -1;
	oy = 0;
	while (b && b->put)
		b = b->next;
	if (!b)
		return (1);
	while (1)
	{
		if (oy < size)
		{
			if (ox < size)
				ox++;
			else
			{
				oy++;
				ox = 0;
			}
		}
		else
			return (0);
		if (!will_fit(map, b->points, ox, oy))
			continue ;
		block_to_map(map, b, ox, oy);
		if (put_next(map, blocks, size))
			return (1);
		else
			remove_block(map, b->letter);
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
			size++;
		free_map(map);
	}
	print_map(map);
}
