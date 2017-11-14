/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <livbrandon@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 23:47:40 by liton             #+#    #+#             */
/*   Updated: 2017/11/14 06:01:16 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

static int			win_line(int tab[LINE][COL], int player)
{
	int		count;
	int		i;
	int		j;

	i = 0;
	while (i < LINE)
	{
		j = 0;
		count = 0;
		while (j < COL)
		{
			if (tab[i][j] == player)
				++count;
			else
				count = 0;
			if (count == 4)
				return (0);
			++j;
		}
		++i;
	}
	return (-1);
}

static int			win_col(int tab[LINE][COL], int player)
{
	int		count;
	int		i;
	int		j;

 	j = 0;
	while (j < COL)
	{
		i = 0;
		count = 0;
		while (i < LINE)
		{
			if (tab[i][j] == player)
				++count;
			else
				count = 0;
			if (count == 4)
				return (0);
			++i;
		}
		++j;
	}
	return (-1);
}

static int			diagonal_right(int tab[LINE][COL], int i, int j, int player)
{
	int		diag;
	int		count;

	diag = 0;
	count = 0;
	while (j - diag >= 0 && i <= LINE - 1)
	{
		if (tab[i] [j - diag] == player)
			count++;
		else
			count = 0;
		if (count == 4)
			return (0);
		++i;
		++diag;
	}
	return (-1);
}

static int			diagonal_left(int tab[LINE][COL], int i, int j, int player)
{
	int		diag;
	int		count;

	diag = 0;
	count = 0;
	while (j + diag <= COL - 1 && i <= LINE - 1)
	{
		if (tab[i] [j + diag] == player)
			count++;
		else
			count = 0;
		if (count == 4)
			return (0);
		++i;
		++diag;
	}
	return (-1);
}

static int			win_diagonal(int tab[LINE][COL], int player)
{
	if (diagonal_left(tab, 2, 0, player) == 0)
		return (0);
	if (diagonal_left(tab, 1, 0, player) == 0)
		return (0);
	if (diagonal_left(tab, 0, 0, player) == 0)
		return (0);
	if (diagonal_left(tab, 0, 1, player) == 0)
		return (0);
	if (diagonal_left(tab, 0, 2, player) == 0)
		return (0);
	if (diagonal_left(tab, 0, 3, player) == 0)
		return (0);
	if (diagonal_right(tab, 2, 6, player) == 0)
		return (0);
	if (diagonal_right(tab, 1, 6, player) == 0)
		return (0);
	if (diagonal_right(tab, 0, 6, player) == 0)
		return (0);
	if (diagonal_right(tab, 0, 5, player) == 0)
		return (0);
	if (diagonal_right(tab, 0, 4, player) == 0)
		return (0);
	if (diagonal_right(tab, 0, 3, player) == 0)
		return (0);
	return (-1);
}

int		win(int tab[LINE][COL], int player)
{
	if (win_line(tab, player) == 0)
		return (0);
	if (win_col(tab, player) == 0)
		return (0);
	if (win_diagonal(tab, player) == 0)
		return (0);
	return (-1);
}	
