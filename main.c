/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzhan <anzhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:41:28 by anzhan            #+#    #+#             */
/*   Updated: 2018/01/16 16:55:36 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	if (reader(ac, av) == 0)
		return (1);
	printf("SUCCESS");
	return (0);
}
