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

#include "../../includes/so.h"

static int	count_cols(t_list *grid)
{
	int	max;
	int	i;

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

static void	check_number_args(t_global *g, t_list **error)
{
	if (g->collectible < 1)
		record_error(g, error, "You have less than 1 collection in the map\n");
	if (g->start < 1)
		record_error(g, error, "You have less than 1 player in the map\n");
	if (g->exit < 1)
		record_error(g, error, "You have less than 1 exit in the map\n");
	if (g->start > 1)
		record_error(g, error, "You have more than 1 player in the map\n");
}

static void	check_args(t_global *g, t_list **error)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->number_rows)
	{
		j = -1;
		while (++j < g->number_columns)
		{
			if (g->map[i][j] == 'C')
				g->collectible += 1;
			else if (g->map[i][j] == 'E')
				g->exit += 1;
			else if (g->map[i][j] == 'P')
			{
				g->start += 1;
				g->player.x = i;
				g->player.y = j;
			}
		}
	}
	check_number_args(g, error);
}

static void	convert_grid(t_global *g, t_list *list, t_list **error)
{
	int	i;

	i = 0;
	while (list)
	{
		g->map[i] = ft_strdup(list->content);
		i++;
		list = list->next;
	}
	ft_lstclear(&list, &del_list);
	i = -1;
	while (++i < g->number_rows)
		g->map[i] = add_spaces(g->map[i], g->number_columns);
	check_borders(g, error);
	check_args(g, error);
}

int	count_grid(t_global *g, t_list *grid, t_list **error)
{
	int	column;
	int	rows;

	column = count_cols(grid);
	rows = ft_lstsize(grid);
	if (!column || !rows)
	{
		record_error(g, error, "Map has 0 columns or 0 rows\n");
		return (0);
	}
	g->map = (char **)malloc(sizeof(char *) * rows + 1);
	g->number_columns = column;
	g->number_rows = rows;
	convert_grid(g, grid, error);
	return (1);
}
