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

static void	free_image(t_global *g)
{
	mlx_destroy_image(g->window.mlx_ptr, g->window.img.img);
	g->window.img.img = NULL;
	g->window.img.adr = NULL;
}

void	free_ptr(t_global *g)
{
	if (g->window.mlx_ptr)
	{
		if (g->window.win_ptr)
		{
			if (g->window.img.img)
				free_image(g);
			mlx_destroy_window(g->window.mlx_ptr, g->window.win_ptr);
		}
		mlx_destroy_display(g->window.mlx_ptr);
		free(g->window.mlx_ptr);
		g->window.mlx_ptr = NULL;
	}
}

void	free_g(t_global g)
{
	int	i;

	i = 0;
	if (g.map)
	{
		while (i < g.number_rows)
			free(g.map[i++]);
		free(g.map);
	}
}

void	free_texture(t_global *g)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (g->texture[i].ptr)
		{
			mlx_destroy_image(g->window.mlx_ptr, g->texture[i].ptr);
			g->texture[i].ptr = NULL;
			g->texture[i].data = NULL;
		}
		if (g->texture[i].name)
		{
			free(g->texture[i].name);
			g->texture[i].name = NULL;
		}
		i++;
	}
}

void	free_global(t_list *list, t_global g, t_list *error)
{
	ft_lstclear(&list, &del_list);
	ft_lstclear(&error, &del_list);
	free_texture(&g);
	free_g(g);
}
