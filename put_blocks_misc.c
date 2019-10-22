/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_blocks_misc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:47:26 by adavis            #+#    #+#             */
/*   Updated: 2019/10/22 20:11:29 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_blocks(t_blocks *blocks)
{
	int		cnt;

	if (!blocks)
		return (0);
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
