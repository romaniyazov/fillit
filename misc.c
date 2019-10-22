/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:57:00 by adavis            #+#    #+#             */
/*   Updated: 2019/10/22 19:46:14 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_block(char **map, t_blocks *b)
{
	char	*tmp;

	while (*map)
	{
		tmp = *map;
		while (*tmp)
		{
			if (*tmp == b->letter)
				*tmp = '.';
			tmp++;
		}
		map++;
	}
	b->put = 0;
}

void	fill_map(char **map, int map_size)
{
	int		i;

	while (*map)
	{
		i = -1;
		while (++i < map_size)
			(*map)[i] = '.';
		map++;
	}
}

void	print_map(char **map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (*map)
	{
		tmp = *map;
		while (*tmp)
		{
			ft_putchar(*tmp);
			tmp++;
		}
		ft_putchar('\n');
		map++;
	}
}

int		map_size(t_blocks *blocks)
{
	int		map_size;
	int		blocks_cnt;

	blocks_cnt = count_blocks(blocks);
	map_size = 1;
	while (map_size * map_size < blocks_cnt * 4)
		map_size++;
	return (map_size);
}
