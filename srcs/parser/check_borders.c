/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:05:53 by thhusser          #+#    #+#             */
/*   Updated: 2021/05/17 19:05:53 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so.h"

static int	check_top_and_bottom(char **map, int line_count)
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	while (map[0][++i])
		if (map[0][i] != '1')
			flag = 1;
	i = -1;
	while (map[line_count - 1][++i])
		if (map[line_count - 1][i] != '1')
			flag = 1;
	return (flag);
}

static int	check_left_and_right(char **map, t_global *g)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = -1;
	while (++i < g->number_rows)
	{
		j = 0;
		if (map[i][j] != '1')
			flag = 1;
	}
	i = -1;
	while (++i < g->number_rows)
	{
		j = g->number_columns - 1;
		if (map[i][j] != '1')
			flag = 1;
	}
	return (flag);
}

void	check_borders(t_global *g, t_list **error)
{
	int		flag;
	char	**map;

	flag = 0;
	map = g->map;
	flag += check_top_and_bottom(map, g->number_rows);
	flag += check_left_and_right(map, g);
	if (flag)
		record_error(g, error, "Map is not correctly closed at borders\n");
}
