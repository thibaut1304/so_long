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

static void	init(t_global *g, char *file, t_list **list, t_list **error)
{
	int		res;
	char	*line;

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
		if (!line[0])
			record_error(g, error, "\\n in map\n");
		if (detect_map_line(line, error, g))
			record_map(line, list);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(g->fd);
}

void	load_window(t_global *g)
{
	g->window.win_ptr = mlx_new_window(g->window.mlx_ptr,
			g->size * g->number_columns,
			g->size * g->number_rows, "so_long");
}

void	load_map(t_global *g)
{
	init_ptr_mlx(g);
	load_imgage(g);
	load_window(g);
	load_texture(g);
	mlx_hook(g->window.win_ptr, 3, 1L << 1, key_release, &g->player);
	mlx_hook(g->window.win_ptr, 2, 1L << 0, exit_window, g);
	mlx_loop_hook(g->window.mlx_ptr, first_display, g);
	mlx_hook(g->window.win_ptr, 33, 1L << 17, &close_cub, g);
	mlx_loop(g->window.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_global	g;
	t_list		*list;
	t_list		*error;

	list = NULL;
	error = NULL;
	init_var(&g);
	if (!begin(&g, argc, argv[1], &error))
	{
		init(&g, argv[1], &list, &error);
		if (!error)
			count_grid(&g, list, &error);
		if (!error)
		{
			ft_lstclear(&list, &del_list);
			load_map(&g);
		}
	}
	if (error)
		print_error(error);
	free_global(list, g, error);
	return (0);
}
