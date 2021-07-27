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
	g->texture[0].name = "./textures/door.xpm";
	// g->texture[0].adr = mlx_get_data_addr()
	// g->window.win_ptr = mlx_new_window(g->window.mlx_ptr, 800, 400, "Test Window");
	// g->img.adr = mlx_get_data_addr(g->img.img, &g->img.bits_per_pxl, &g->img.line_length, &g->img.endian);
}

void	load_imgage(t_win *win)
{
	win->img.img = mlx_new_image(win->mlx_ptr, win->w, win->h);
	win->img.adr = mlx_get_data_addr(win->img.img, &win->img.bits_per_pxl,
			&win->img.line_length, &win->img.endian);
}

void	load_window(t_win *win)
{
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->w, win->h, "so_long");
}

void 	load_map(t_global *g)
{
	init_ptr_mlx(g);
	load_imgage(&g->window);
	load_window(&g->window);
	my_mlx_put_pxl(&g->window.img, 50, 50, RED);
	g->texture[0].ptr = mlx_xpm_file_to_image(g->window.mlx_ptr, g->texture[0].name, &g->texture[0].w, &g->texture[0].h);
	// my_mlx_put_pxl(&g->texture[0].ptr, g->texture[0].w , g->texture[0].h, RED);
	mlx_put_image_to_window(g->window.mlx_ptr, g->window.win_ptr, g->window.img.img, 0, 0);
	mlx_put_image_to_window(g->window.mlx_ptr, g->window.win_ptr, g->texture[0].ptr, 0, 0);

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