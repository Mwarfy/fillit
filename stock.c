/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matranch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:22:22 by matranch          #+#    #+#             */
/*   Updated: 2018/01/16 18:03:27 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void afficherListe(t_list *liste)
{
	while (liste->next != NULL)
	{
		printf("%s", liste->content);
		printf("x1 = %d \n", liste->x1);
		printf("y1 = %d \n", liste->y1);
		printf("x2 = %d \n", liste->x2);
		printf("y2 = %d \n", liste->y2);
		printf("x3 = %d \n", liste->x3);
		printf("y3 = %d \n", liste->y3);
		printf("x4 = %d \n", liste->x4);
		printf("y4 = %d \n \n", liste->y4);
		liste = liste->next;
	}
}

void	stock_piece(char *str, dblist *liste)
{
	int		i;
	int 	j;
	int 	k;
	int 	l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	t_list *maliste;
	maliste = malloc(sizeof(t_list));
	while(str[i])
	{
		if (i == 5 || i == 10 || i == 15)
		{
			j = 0;
			k++;
		}
		if (str[i] == '#')
		{
			if (l == 0)
			{
				maliste->x1 = j;
				maliste->y1 = k;
			}
			if (l == 1)
			{
				maliste->x2 = j;
				maliste->y2 = k;
			}
			if (l == 2)
			{
				maliste->x3 = j;
				maliste->y3 = k;
			}
			if (l == 3)
			{
				maliste->x4 = j;
				maliste->y4 = k;
			}
			l++;
		}
		i++;
		j++;
	}
	maliste->content = malloc(sizeof(char) * ft_strlen(str) + 1);
	maliste->content = str;
	ft_pushback(liste, maliste);
}

void	replaced(t_list *liste)
{
	int i;
	int j;
	char *str;

	j = 0;
	while(liste->next != NULL)
	{
		i = 0;
		str = liste->content;
		while(i < 21)
		{
			if ((str[i] == '#') && (j == 0))
				str[i] = 'A';
			if ((str[i] == '#') && (j == 1))
				str[i] = 'B';
			if ((str[i] == '#') && (j == 2))
				str[i] = 'C';
			if ((str[i] == '#') && (j == 3))
				str[i] = 'D';
			if ((str[i] == '#') && (j == 4))
				str[i] = 'E';
			i++;
		}
		liste->content = str;
		liste = liste->next;
		j++;
	}
}
