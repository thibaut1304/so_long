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

#include "includes/so.h"


void	init_var(t_global *g)
{
	g->error = 0;
	g->map = NULL;
	g->exit = 0;
	g->start = 0;
	g->collectible = 0;
}

void 	del_list(void *grid)
{
	free(grid);
	grid = NULL;
}

void		free_global(t_list *list, t_global g, t_list *error)
{
	int i;

	i = 0;
	ft_lstclear(&list, &del_list);
	ft_lstclear(&error, &del_list);
	if (g.map)
	{
		while (i < g.number_rows)
			free(g.map[i++]);
		free(g.map);
	}
}