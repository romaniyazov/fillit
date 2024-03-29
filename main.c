/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:21:09 by adavis            #+#    #+#             */
/*   Updated: 2019/10/22 16:09:12 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putendl(" map_file");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	validate(fd);
	return (0);
}
