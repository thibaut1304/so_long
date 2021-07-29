/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:43:55 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/28 06:43:55 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so.h"

int	color_utils(t_texture text, int x, int y)
{
	char	*dst;

	dst = text.data + (y * text.line_length + x * text.bits_per_pxl / 8);
	return (*(unsigned int *)dst);
}

void	init_ptr_mlx(t_global *g)
{
	g->window.mlx_ptr = mlx_init();
}
