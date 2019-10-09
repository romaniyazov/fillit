/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:24:46 by adavis            #+#    #+#             */
/*   Updated: 2019/10/09 17:51:16 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_newlines(char *block)
{
	if (block[4] != '\n')
		return (0);
	if (block[9] != '\n')
		return (0);
	if (block[14] != '\n')
		return (0);
	if (block[19] != '\n')
		return (0);
	if (block[20] != '\n')
		return (0);
	return (1);
}

int		count_sharps(char *block)
{
	int		i;
	int		sharps;
	int		points;

	sharps = 0;
	points = 0;
	i = -1;
	while (++i < 21)
	{
		if (block[i] == '#')
			sharps++;
		else if (block[i] == '.')
			points++;
	}
	if (sharps == 4 && points == 12)
		return (1);
	else
		return (0);	
}

int		check_links(char *block)
{
	int		i;
	int		links;

	links = 0;
	i = -1;
	while (++i < 21)
	{
		if (block[i] == '#')
		{
			if (i > 4 && block[i - 5] == '#')
				links++;
			if (i > 0 && block[i - 1] == '#')
				links++;
			if (i < 19 && block[i + 1] == '#')
				links++;
			if (i < 15 && block[i + 5] == '#')
				links++;
		}
	}
	if (links == 6 || links == 8)
		return (1);
	else
		return (0);
}

void	validate(int fd)
{
	t_blocks	*blocks;
	char		*block;

	blocks = NULL;
	block = ft_strnew(21);
	while (read(fd, block, 21) > 0)
	{
		if (check_newlines(block) && count_sharps(block) && check_links(block))
			add_block(&blocks, block);
		else
			ft_printf("Error.\n");
	}
	normalize_coords(blocks);
	print_blocks(blocks);
	ft_strdel(&block);
}
