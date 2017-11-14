/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <livbrandon@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:49:24 by liton             #+#    #+#             */
/*   Updated: 2017/11/14 03:49:54 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

int			tab_end(int tab[LINE][COL])
{
	int		i;
	int		j;

	i = 0;
	while (i < LINE)
	{
		j = 0;
		while (j < COL)
		{
			if (tab[i][j] == 0)
				return (-1);
			++j;
		}
		++i;
	}
	return (0);
}

void		initialize_tab(int tab[LINE][COL])
{
	int		i;
	int		j;

	i = 0;
	while (i < LINE)
	{
		j = 0;
		while (j < COL)
		{
			tab[i][j] = 0;
			++j;
		}
		++i;
	}
}

int				put_p4(int tab[LINE][COL], int place, int player)
{
	int		i;

	i = 5;
	while (i >= 0)
	{
		if (tab[i][place - 1] == 0)
		{
			tab[i][place - 1] = (player == 1) ? 1 : 2;
			return (0);
		}
		--i;
	}
	return (-1);
}

static void		color(int player)
{
	ft_putstr("| ");
	if (player == 1)
		ft_putstr("\033[0;31m");
	if (player == 2)
		ft_putstr("\033[0;33m");
	if(player != 0)
		ft_putchar('O');
	ft_putstr("\033[0m");
	if (player == 0)
		ft_putchar(' ');
	ft_putchar(' ');
}

void			print_p4(int tab[LINE][COL])
{
	int		i;
	int		j;

	i = 0;
	ft_putendl("  1   2   3   4   5   6   7");	
	while (i < LINE)
	{
		ft_putendl("-----------------------------");
		j = -1;
		while (++j < COL)
			color(tab[i][j]);
		ft_putchar('|');
		ft_putchar('\n');
		++i;
	}
	ft_putendl("-----------------------------");
}
