/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzhan <anzhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 22:12:02 by anzhan            #+#    #+#             */
/*   Updated: 2018/01/16 17:59:47 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	error()
{
	ft_putendl("error");
	return (0);
}

int			reader(int ac, char **av)
{
	int		fd;
	char	buffer[BUFF_SIZE + 1];
	int		ret;
	int		nb_tetri;
	int		islast;
	dblist  *liste;
	
	liste = malloc(sizeof(t_list));
	liste->liste = NULL;
	nb_tetri = 0;
	islast = 0;
	if ((fd = open(av[1], O_RDONLY)) < 0 || ac != 2)
		return (error());
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (ret < 21)
			islast++;
		nb_tetri++;
		if (check_overall(buffer) != 2 || nb_tetri > 8)
			return (error());
		buffer[ret] = 0;
		stock_piece(buffer, liste);
		//ft_lstadd(&liste, maliste);
		//ft_pushback(liste, maliste);
	}
	if (close(fd) < 0 || islast != 1)
		return (error());
	view(liste);
	//replaced(liste);
	//afficherListe(maliste);
	return (1);
}
