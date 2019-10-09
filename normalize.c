/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:46:31 by adavis            #+#    #+#             */
/*   Updated: 2019/10/09 17:50:50 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	normalize_coords(t_blocks *blocks)
{
	int		i;
	int		min_x;
	int		min_y;

	while (blocks)
	{
		min_x = 4;
		min_y = 4;
		i = -1;
		while (++i < 4)
		{
			if (blocks->points[i][0] < min_x)
				min_x = blocks->points[i][0];
			if (blocks->points[i][1] < min_y)
				min_y = blocks->points[i][1];
		}
		i = -1;
		while (++i < 4)
		{
			blocks->points[i][0] -= min_x;
			blocks->points[i][1] -= min_y;
		}
		blocks = blocks->next;
	}
}