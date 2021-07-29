/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:50:45 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/28 06:50:45 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so.h"

void	load_imgage(t_global *g)
{
	int	y;
	int	x;

	y = g->size * g->number_rows;
	x = g->size * g->number_columns;
	g->w = x;
	g->h = y;
	g->window.img.img = mlx_new_image(g->window.mlx_ptr, x, y);
	g->window.img.adr = mlx_get_data_addr(g->window.img.img,
			&g->window.img.bits_per_pxl, &g->window.img.line_length,
			&g->window.img.endian);
}
