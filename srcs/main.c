/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:29:45 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/24 20:29:45 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so.h"

static void 	init(t_global *g, char *file, t_list **list, t_list **error)
{
	int res;
	char *line;

	res = 1;
	g->fd = open(file, O_RDONLY);
	if (g->fd < 0)
	{
		record_error(g, error, "Error open file\n");
		return ;
	}
	while (res > 0)
	{
		res = get_next_line(g->fd, &line);
		if (detect_map_line(line, error, g))
			record_map(line, list);
		if (*error)
			break ;
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(g->fd);
}

void	init_ptr_mlx(t_global *g)
{
	g->window.mlx_ptr = mlx_init();
	// g->texture[0].adr = mlx_get_data_addr()
	// g->window.win_ptr = mlx_new_window(g->window.mlx_ptr, 800, 400, "Test Window");
	// g->img.adr = mlx_get_data_addr(g->img.img, &g->img.bits_per_pxl, &g->img.line_length, &g->img.endian);
}

void	load_imgage(t_global *g)
{
	int y = g->size * g->number_rows;
	int x = g->size * g->number_columns;
	g->w = x;
	g->h = y;
	g->window.img.img = mlx_new_image(g->window.mlx_ptr, x, y);
	g->window.img.adr = mlx_get_data_addr(g->window.img.img, &g->window.img.bits_per_pxl, &g->window.img.line_length, &g->window.img.endian);
}

void	load_window(t_global *g)
{
	g->window.win_ptr = mlx_new_window(g->window.mlx_ptr, g->size * g->number_columns, g->size * g->number_rows, "so_long");
}


int	grep_color(t_texture text, int x, int y)
{
	char	*dst;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > text.w)
		x = text.w;
	if (y > text.h)
		y = text.h;
	dst = text.data + (y * text.line_length + x * text.bits_per_pxl / 8);
	return (*(unsigned int *)dst);
}

void	print_texture(t_global *g, int x, int y, int id)
{
	int	color;
	int	background;

	color = grep_color(g->texture[id], x, y);
	background = grep_color(g->texture[id], 5, 5);
	if (color != background)
	{
		if (x + g->x_pxl <= g->w && y + g->y_pxl <= g->h)
			my_mlx_put_pxl(&g->window.img, x + g->x_pxl, y + g->y_pxl, color);
	}
	// else
		// my_mlx_put_pxl(&g->window.img, x + g->x_pxl, y + g->y_pxl, RED);

	// static int i = 0;
	// printf("%d\n", i++);
}

int	display(t_global *g, int h, int w, int id)
{
	printf("map[%d][%d] \n", h, w);
	int width = 0;
	g->x_pxl = w * g->size;
	g->y_pxl = h * g->size;
	// printf("test\n");
	while (width < g->texture[id].w)
	{
		int height = 0;
		while (height < g->texture[id].h)
		{
	// printf("Passage numero : %d\n", i++);

			print_texture(g, width, height, id);
			// my_mlx_put_pxl(&g->window.img, width, height, RED);
			height++;
		}
		width++;
	}

	// mlx_put_image_to_window(g->window.mlx_ptr, g->window.win_ptr,
		// get_img_ptr(mlx, 0), 0, 0);
	return (0);
}

void	select_texture(t_global *g, int i, int j)
{
	if (g->map[i][j] == '1')
		display(g, i, j, 0);
	else if (g->map[i][j] == 'P')
		display(g, i, j, 2);
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

	i = 0;
	while (i < g->number_rows)
	{
		j = 0;
		while (j < g->number_columns)
		{
	// printf("map[%d][%d] \n", i, j);

			select_texture(g, i, j);
			// my_mlx_put_pxl(&g->window.img, width, height, RED);
			j++;
		}
		i++;
	}
// 	// mlx_put_image_to_window(g->window.mlx_ptr, g->window.win_ptr,
// 		// get_img_ptr(mlx, 0), 0, 0);
	return (0);
}

void 	load_texture(t_global *g)
{
	int i;

	i = 0;
	g->texture[0].name = ft_strdup("./textures/icones8/mur.xpm");
	g->texture[1].name = ft_strdup("./textures/icones8/empty.xpm");
	g->texture[2].name = ft_strdup("./textures/icones8/homme.xpm");
	g->texture[3].name = ft_strdup("./textures/icones8/medaille.xpm");
	g->texture[4].name = ft_strdup("./textures/icones8/precision.xpm");
	while (i < 5)
	{
		g->texture[i].ptr = mlx_xpm_file_to_image(g->window.mlx_ptr, g->texture[i].name, &g->texture[i].w, &g->texture[i].h);
		g->texture[i].data = mlx_get_data_addr(g->texture[i].ptr, &g->texture[i].bits_per_pxl, &g->texture[i].line_length, &g->texture[i].endian);
		i++;
	}
}
void 	load_map(t_global *g)
{
	init_ptr_mlx(g);
	load_imgage(g);
	load_window(g);
	load_texture(g);
	// g->texture[1].ptr = mlx_xpm_file_to_image(g->window.mlx_ptr, g->texture[1].name, &g->texture[1].w, &g->texture[1].h);
	// g->texture[2].ptr = mlx_xpm_file_to_image(g->window.mlx_ptr, g->texture[2].name, &g->texture[2].w, &g->texture[2].h);
	// g->texture[1].data = mlx_get_data_addr(g->texture[1].ptr, &g->texture[1].bits_per_pxl, &g->texture[1].line_length, &g->texture[1].endian);
	// g->texture[2].data = mlx_get_data_addr(g->texture[2].ptr, &g->texture[2].bits_per_pxl, &g->texture[2].line_length, &g->texture[2].endian);
	
	// display(g, 0, 0, 0);
	first_display(g);
	mlx_put_image_to_window(g->window.mlx_ptr, g->window.win_ptr, g->window.img.img, 0, 0);
	// mlx_put_image_to_window(g->window.mlx_ptr, g->window.win_ptr, g->texture[0].ptr, 0, 0);

	mlx_hook(g->window.win_ptr, 3, 1L << 1, key_release, &g->player);
	mlx_hook(g->window.win_ptr, 2, 1L << 0, exit_window, g);
	// mlx_loop_hook(g->win.mlx_p, render, g);
	mlx_hook(g->window.win_ptr, 33, 1L << 17, &close_cub, g);
	mlx_loop(g->window.mlx_ptr);
}


int		main(int argc, char **argv)
{
	t_global 	g;
	t_list 		*list;
	t_list 		*error;

	list = NULL;
	error = NULL;
	init_var(&g);
	if (!begin(&g, argc, argv[1], &error))
	{
		init(&g, argv[1], &list, &error);
		count_grid(&g, list, &error);
		if (!error)
		{
			ft_lstclear(&list, &del_list);
			load_map(&g);
		}
		//affichage double tab
	}
	// int i = 0;
	// if (g.map)
		// while (i < g.number_rows)
			// printf("%s\n", g.map[i++]);
	if (error)
		print_error(error);
	free_global(list, g, error);
	return (0);

}