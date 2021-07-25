/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 23:25:13 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/25 23:25:13 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so.h"

void	render_valid_pixel(t_sl *sl, int text_id)
{
	int	color;
	int	background;

	color = grep_color(sl->text[text_id], sl->data.text.x, sl->data.text.y);
	background = grep_color(sl->text[text_id], 0, 0);
	if (color != background)
		my_mlx_pixel_put(&sl->win, sl->data.pos_x + sl->data.screen.x,
			sl->data.screen.y, color);
}

void	fill_ratio_data(t_sl *sl, int i, int j)
{
	sl->data.sprt_hei = sl->win.hei / sl->data.rows;
	sl->data.sprt_wid = sl->win.wid / sl->data.cols;
	sl->data.top_px = i * sl->data.sprt_hei;
	sl->data.bot_px = (i + 1) * sl->data.sprt_hei;
	sl->data.right_px = sl->data.sprt_wid;
	sl->data.pos_x = j * (sl->win.wid / sl->data.cols);
	sl->data.screen.x = -1;
}

void	render_texture(t_sl *sl, int j, int i, int text_id)
{
	int	size;

	// fill_ratio_data(sl, i, j);
	// while (sl->data.pos_x + sl->data.screen.x < 0)
		// sl->data.screen.x++;
	while (++sl->data.screen.x <= sl->data.right_px)
	{
		sl->data.text.x = sl->data.screen.x
			* (sl->text[text_id].wid / sl->data.sprt_wid);
		sl->data.screen.y = sl->data.top_px - 1;
		size = -1;
		while (++sl->data.screen.y < sl->data.bot_px)
		{
			++size;
			sl->data.text.y = (size
					* (sl->text[text_id].hei / sl->data.sprt_hei));
			if (sl->data.text.y < 0)
				sl->data.text.y = 0;
			render_valid_pixel(sl, text_id);
		}
	}
}

void	select_texture_to_render(t_global *g, int j, int i)
{
	if (sl->grid[i][j] == '1')
		render_texture(g, j, i, 3);
	else if (sl->grid[i][j] == 'E')
		render_texture(g, j, i, 2);
	else if (sl->grid[i][j] == 'C')
		render_texture(g, j, i, 1);
	else if (sl->grid[i][j] == '0')
		render_texture(g, j, i, 4);
	else if (sl->grid[i][j] == 'P')
		render_texture(g, g->player.x, g->player.y, 0);
}

int	render(t_global *g)
{
	int		i;
	int		j;

	i = -1;
	while (++i < g->number_rows)
	{
		j = -1;
		while (++j < g->number_colums)
			select_texture_to_render(g, j, i);
	}
	mlx_put_image_to_window(g->window.mlx_ptr, g->window.win_ptr, g->window.img.img, 0, 0);
	return (1);
}