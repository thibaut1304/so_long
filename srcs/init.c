/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 20:25:51 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/25 20:25:51 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so.h"

static void	init_window(t_win *win)
{
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
	win->w = 800;
	win->h = 800;
}

static void	init_image(t_img *img)
{
	img->img = NULL;
	img->adr = NULL;
	img->bits_per_pxl = 0;
	img->line_length = 0;
	img->endian = 0;
	img->w = 800;
	img->h = 800;
}

static void	init_player(t_player *player)
{
	player->x = -1;
	player->y = -1;
	player->turn_direction = 0;
	player->walk_direction = 0;
}

static void	init_texture(t_global *g)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g->texture[i].ptr = NULL;
		g->texture[i].data = NULL;
		g->texture[i].name = NULL;
		g->texture[i].bits_per_pxl = 0;
		g->texture[i].line_length = 0;
		g->texture[i].endian = 0;
		g->texture[i].w = 0;
		g->texture[i].h = 0;
		i++;
	}
}

void	init_var(t_global *g)
{
	g->error = 0;
	g->map = NULL;
	g->exit = 0;
	g->start = 0;
	g->collectible = 0;
	g->number_rows = -1;
	g->number_columns = -1;
	g->size = 40;
	g->w = 0;
	g->h = 0;
	g->x_pxl = 0;
	g->y_pxl = 0;
	g->move = 0;
	g->fd = 0;
	g->end = 0;
	init_window(&g->window);
	init_image(&g->img);
	init_player(&g->player);
	init_texture(g);
}
