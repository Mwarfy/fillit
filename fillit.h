/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anzhan <anzhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:18:50 by anzhan            #+#    #+#             */
/*   Updated: 2018/01/16 14:47:19 by matranch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 21

int				check_overall(char *str);
int				reader(int ac, char **av);
void 			stock_piece(char *str, dblist *liste);
void			replaced(t_list *liste);
void			afficherListe(t_list *liste);
#endif
