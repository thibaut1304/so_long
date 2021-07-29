/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:48:02 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/28 06:48:02 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so.h"

static void	print_texture(t_global *g, int x, int y, int id)
{
	int	color;
	int	background;

	color = color_utils(g->texture[id], x, y);
	background = color_utils(g->texture[id], 0, 0);
	if (color != background)
	{
		if (x + g->x_pxl <= g->w && y + g->y_pxl <= g->h)
			my_mlx_put_pxl(&g->window.img, x + g->x_pxl, y + g->y_pxl, color);
	}
}

static int	display(t_global *g, int h, int w, int id)
{
	int		width;
	int		height;

	width = -1;
	g->x_pxl = w * g->size;
	g->y_pxl = h * g->size;
	while (++width < g->texture[id].w)
	{
		height = -1;
		while (++height < g->texture[id].h)
			print_texture(g, width, height, id);
	}
	return (0);
}

static void	select_texture(t_global *g, int i, int j)
{
	if (g->map[i][j] == '1')
		display(g, i, j, 0);
	else if (g->map[i][j] == 'P')
		display(g, g->player.x, g->player.y, 2);
	else if (g->map[i][j] == 'C')
		display(g, i, j, 3);
	else if (g->map[i][j] == 'E')
		display(g, i, j, 4);
	else
		display(g, i, j, 1);
}

int	first_display(t_global *g)
{
	int		j;
	int		i;

	i = -1;
	while (++i < g->number_rows)
	{
		j = -1;
		while (++j < g->number_columns)
			select_texture(g, i, j);
	}
	mlx_put_image_to_window(g->window.mlx_ptr, g->window.win_ptr,
		g->window.img.img, 0, 0);
	if (g->end == 1)
	{
		ft_putstr("Good Game !\n");
		close_cub(g);
	}
	return (0);
}
