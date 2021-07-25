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

static void 	load_map(t_global *g)
{
	init_ptr_mlx(g);
	mlx_loop(g->ptr.mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_global 	g;
	t_list 		*list;
	t_list 		*error;
	int 		i;

	list = NULL;
	error = NULL;
	init_var(&g);
	i = 0;
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
	// if (g.map)
	// 	while (i < g.number_rows)
	// 		printf("%s\n", g.map[i++]);
	if (error)
		print_error(error);
	free_global(list, g, error);
	return (0);

}