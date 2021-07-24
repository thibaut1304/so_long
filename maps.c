/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 22:56:32 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/24 22:56:32 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so.h"

static int		count_cols(t_list *grid)
{
	int max;
	int i;

	max = 0;
	while (grid)
	{
		i = ft_strlen(grid->content);
		if (i > max)
			max = i;
		grid = grid->next;
	}
	return (max);
}

static void	convert_grid(t_global *g, t_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		g->map[i] = ft_strdup(list->content);
		i++;
		list = list->next;
	}
	ft_lstclear(&list, &del_list);
	check_borders(g, g->number_rows, g->number_columns);
	// check_walls(g, g->map->number_rows, g->map->number_columns);
}

void 	del_list(void *grid)
{
	free(grid);
	grid = NULL;
}

int		count_grid(t_global *g, t_list *grid)
{
	int column;
	int rows;

	column = count_cols(grid);
	rows = ft_lstsize(grid);
	if (!column || !rows)
	{
		ft_putstr("Map has 0 columns or 0 rows\n");
		return (0);
	}
	g->map = (char **)malloc(sizeof(char *) * rows + 1);
	g->number_columns = column;
	g->number_rows = rows;
	// if (!g->tab)
	// {
	// 	append_error(g, "", "Not enough memory to malloc the map\n");
	// 	return (0);
	// }
	convert_grid(g, grid);
	return (1);
}