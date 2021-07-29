/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:53:58 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/28 06:53:58 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so.h"

static int	check_move(t_global *g, int x, int y)
{
	if (g->collectible > 0 && g->map[x][y] == 'E')
		return (1);
	if (g->collectible == 0 && g->map[x][y] == 'E')
		g->end = 1;
	return (0);
}

static void	print_move(t_global *g)
{
	ft_putstr("Move :");
	ft_putnbr(g->move);
	ft_putstr("\n");
}

void	update_player(t_global *g)
{
	int	x;
	int	y;

	x = g->player.x - g->player.walk_direction;
	y = g->player.y + g->player.turn_direction;
	if (!check_move(g, x, y))
	{
		if (g->map[x][y] != '1' ||
			(x >= g->number_rows && x <= g->number_rows) ||
			(y >= g->number_columns && y <= g->number_columns))
		{
			if (g->player.turn_direction != 0 || g->player.walk_direction != 0)
			{
				if (g->map[x][y] == 'C')
					g->collectible -= 1;
				g->map[g->player.x][g->player.y] = '0';
				g->player.x = x;
				g->player.y = y;
				g->map[g->player.x][g->player.y] = 'P';
				g->move += 1;
				print_move(g);
			}
		}
	}
}
