/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:40:41 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/25 02:40:41 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so.h"

static void		free_image(t_global *g)
{
	mlx_destroy_image(g->ptr.mlx_ptr, g->img.img);
	g->img.img = NULL;
	g->img.adr = NULL;
}

static void		free_ptr(t_global *g)
{
	if (g->ptr.mlx_ptr)
	{
		if (g->ptr.win_ptr)
		{
			if (g->img.img)
				free_image(g);
			mlx_destroy_window(g->ptr.mlx_ptr, g->ptr.win_ptr);
		}
		mlx_destroy_display(g->ptr.mlx_ptr);
		free(g->ptr.mlx_ptr);
		g->ptr.mlx_ptr = NULL;
	}
}

static void 	free_g(t_global g)
{
	int i;

	i = 0;
	if (g.map)
	{
		while (i < g.number_rows)
			free(g.map[i++]);
		free(g.map);
	}
}

int 	close_cub(t_global *g)
{
		printf("Sortie du programme\n");
		free_ptr(g);
		free_g(*g);
			printf("%f\n", g->player.x);
	printf("%f\n", g->player.y);
		// free_global(list, g, error);
		exit (0);
}

void 	my_mlx_put_pxl(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->adr + (y * img->line_length + x * (img->bits_per_pxl / 8));
	*(unsigned int*)dst = color;
}

void	init_ptr_mlx(t_global *g)
{
	char *path = "./textures/door.xpm";

	g->ptr.mlx_ptr = mlx_init();
	// g->img.img = mlx_new_image(g->ptr.mlx_ptr, 800, 400);
	g->img.img = mlx_xpm_file_to_image(g->ptr.mlx_ptr, path, &g->img.w, &g->img.h);
	g->ptr.win_ptr = mlx_new_window(g->ptr.mlx_ptr, 800, 400, "Test Window");
	g->img.adr = mlx_get_data_addr(g->img.img, &g->img.bits_per_pxl, &g->img.line_length, &g->img.endian);
	// my_mlx_put_pxl(&g->img, 50, 50, RED);
	mlx_put_image_to_window(g->ptr.mlx_ptr, g->ptr.win_ptr, g->img.img, 0, 0);
}

void 	del_list(void *grid)
{
	free(grid);
	grid = NULL;
}

void		free_global(t_list *list, t_global g, t_list *error)
{
	ft_lstclear(&list, &del_list);
	ft_lstclear(&error, &del_list);
	free_g(g);
}