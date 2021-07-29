/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:57:32 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/25 16:57:32 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so.h"

int	exit_window(int key, t_global *all)
{
	if (key == ARROW_UP || key == KEYBORD_W)
		all->player.walk_direction = 1;
	else if (key == ARROW_RIGHT || key == KEYBORD_D)
		all->player.turn_direction = 1;
	else if (key == ARROW_DOWN || key == KEYBORD_S)
		all->player.walk_direction = -1;
	else if (key == ARROW_LEFT || key == KEYBORD_A)
		all->player.turn_direction = -1;
	else if (key == KEYBORD_ESC)
		close_cub(all);
	update_player(all);
	first_display(all);
	return (0);
}

int	key_release(int key, t_player *player)
{
	if (key == ARROW_DOWN || key == ARROW_UP)
		player->walk_direction = 0;
	else if (key == KEYBORD_W || key == KEYBORD_S)
		player->walk_direction = 0;
	else if (key == KEYBORD_A || key == KEYBORD_D)
		player->turn_direction = 0;
	else if (key == ARROW_LEFT || key == ARROW_RIGHT)
		player->turn_direction = 0;
	return (0);
}
