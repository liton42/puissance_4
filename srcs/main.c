/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <livbrandon@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:17:10 by liton             #+#    #+#             */
/*   Updated: 2018/02/07 01:26:18 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

static void			padding_name(int tab[LINE][COL], char *player)
{
	ft_putchar('\n');
	print_p4(tab);
	ft_putchar('\n');
	ft_putstr(player);
	ft_putstr(" choose a number:\n");
}

static void			solve_support(int tab[LINE][COL], int p)
{
	char	*nb;

	while (42)
	{
		get_next_line(0, &nb);
		if (nb[0] == '\0' || nb[1] != '\0' || nb[0] <= 48 || nb[0] > 55)
		{
			ft_putstr("Try again.\n");
			ft_strdel(&nb);
			continue;
		}
		if (put_p4(tab, ft_atoi(nb), p + 1) == -1)
		{
			ft_putstr("You can't play here.\n");
			ft_strdel(&nb);
			continue;
		}
		ft_strdel(&nb);
		break;
	}
}

static void			retry(int tab[LINE][COL], char *player[2], int p)
{
	char	*y;

	if (win(tab, p + 1) == 0)
	{
		ft_putchar('\n');
		print_p4(tab);
		ft_putchar('\n');
		ft_putstr(player[p]);
		ft_putstr(" WIN !!!!!\n");
		while (42)
		{
			ft_putstr("Do you want to replay ? (y/n).\n");
			get_next_line(0, &y);
			if ((y[0] != 'y' || y[0] != 'n') && y[1] != '\0')
				continue ;
			if (y[0] == 'y')
			{
				initialize_tab(tab);
				if (p == 0) 
					ft_swap_string(&player[0], &player[1]);
				solve_puissance_4(tab, player);
			}
			else
				exit(0);
		}
	}
}

void			solve_puissance_4(int tab[LINE][COL], char *player[2])
{
	char	*replay;
	int		p;

	p = 0;
	while (42)
	{
		padding_name(tab, player[p]);
		solve_support(tab, p);	
		retry(tab, player, p);
		if (tab_end(tab) == 0)
		{
			ft_putchar('\n');
			print_p4(tab);
			ft_putchar('\n');
			ft_putstr("No one wins, do you want to replay ? (y/n)\n");
			get_next_line(0, &replay);
			if (ft_strcmp(replay, "y") == 0)
			{
				initialize_tab(tab);
				solve_puissance_4(tab, player);
			}
			else
				exit(0);
		}
		p = (p == 0) ? 1 : 0;
	}
}

int				main(void)
{
	int		tab[LINE][COL];
	char	*player[2];

	initialize_tab(tab);
	ft_putendl("Player 1 name:");
	get_next_line(0, &player[0]);
	ft_putendl("Player 2 name:");
	get_next_line(0, &player[1]);
	ft_putstr("\n");
	solve_puissance_4(tab, player);
}
