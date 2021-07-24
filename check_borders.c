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


#include "so.h"

static int	check_top_and_bottom(char **map, int line_count)
{
	int i;
	int flag;

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

static int	check_left_and_right(char **map, int largest_line, t_global *g)
{
	int i;
	int j;
	int flag;

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
		j = largest_line - 1;
		if (map[i][j] != '1')
			flag = 1;
	}
	return (flag);
}

void		check_borders(t_global *g, int line_count, int largest_line)
{
	int		flag;
	char	**map;

	flag = 0;
	map = g->map;
	flag += check_top_and_bottom(map, line_count);
	flag += check_left_and_right(map, largest_line, g);
	if (flag)
		ft_putstr("Map is not correctly closed at borders\n");
}
