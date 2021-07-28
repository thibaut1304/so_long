/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 07:55:43 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/28 07:55:43 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so.h"

void 	del_list(void *grid)
{
	free(grid);
	grid = NULL;
}

void 	my_mlx_put_pxl(t_img *img, int x, int y, int color)
{
	char *dst;

	if (x >= 0 && y >= 0)
	{
		dst = img->adr + (y * img->line_length + x * (img->bits_per_pxl / 8));
		*(unsigned int*)dst = color;
	}
}

int 	close_cub(t_global *g)
{
		printf("End game ...\n");
		free_texture(g);
		free_ptr(g);
		assert (g->window.img.img == NULL);
		free_g(*g);
		exit (0);
}