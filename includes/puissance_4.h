/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance_4.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <livbrandon@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:17:27 by liton             #+#    #+#             */
/*   Updated: 2017/11/14 03:22:40 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_4_H
# define PUISSANCE_4_H

# define LINE 6
# define COL 7
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	initialize_tab(int tab[LINE][COL]);
void	print_p4(int tab[LINE][COL]);
int		win(int tab[LINE][COL], int player);
int		put_p4(int tab[LINE][COL], int place, int player);
void	solve_puissance_4(int tab[LINE][COL], char *player[2]);
int		tab_end(int tab[LINE][COL]);
#endif
