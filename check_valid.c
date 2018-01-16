/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzhan <anzhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:48:46 by anzhan            #+#    #+#             */
/*   Updated: 2018/01/11 10:52:35 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_affinities(char *str, int i)
{
	int count;

	count = 0;
	if (i > 0 && str[i - 1] == '#')
		count++;
	if (i > 4 && str[i - 5] == '#')
		count++;
	if (i < 15 && str[i + 5] == '#')
		count++;
	if (i < 20 && str[i + 1] == '#')
		count++;
	return (count);
}

int	check_affinities(char *str)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '#')
			count += count_affinities(str, i);
	}
	if (count == 8 || count == 6)
		return (1);
	return (0);
}

int	check_map(char *str)
{
	int	i;
	int	count_point;
	int	count_block;
	int	count_nl;

	i = 0;
	count_point = 0;
	count_block = 0;
	count_nl = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count_point++;
		if (str[i] == '#')
			count_block++;
		if (str[i] == '\n')
			count_nl++;
		i++;
	}
	if (count_point == 12 && count_block == 4 && (count_nl == 5 ||
	count_nl == 4))
		return (1);
	return (0);
}

int	check_overall(char *str)
{
	if ((check_map(str) + check_affinities(str)) == 2)
		return (2);
	return (0);
}
