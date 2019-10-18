/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:22:43 by adavis            #+#    #+#             */
/*   Updated: 2019/10/18 16:31:57 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_blocks(t_blocks **blocks, char *block)
{
	int		i;
	int		j;

	*blocks = malloc(sizeof(t_blocks));
	(*blocks)->letter = 'A';
	(*blocks)->points = malloc(sizeof(int *) * 4);
	i = -1;
	while (++i < 4)
	{
		(*blocks)->points[i] = malloc(sizeof(int) * 2);
		j = 0;
		while (j < 21 && block[j] != '#')
			j++;
		block[j] = '.';
		(*blocks)->points[i][0] = j % 5;
		(*blocks)->points[i][1] = j / 5;
	}
	(*blocks)->next = NULL;
}

void	add_block(t_blocks **blocks, char *block)
{
	int		i;
	int		j;
	t_blocks	*tmp;

	if (!*blocks)
		return (init_blocks(blocks, block));
	tmp = *blocks;
	while ((*blocks)->next)
		*blocks = (*blocks)->next;
	(*blocks)->next = malloc(sizeof(t_blocks));
	(*blocks)->next->letter = (*blocks)->letter + 1;
	(*blocks)->next->points = malloc(sizeof(int *) * 4);
	i = 0;
	j = -1;
	while (++j < 21)
		if (block[j] == '#')
		{
			(*blocks)->next->points[i] = malloc(sizeof(int) * 2);
			(*blocks)->next->points[i][0] = j % 5;
			(*blocks)->next->points[i][1] = j / 5;
			i++;
		}
	(*blocks)->next->next = NULL;
	*blocks = tmp;
}
