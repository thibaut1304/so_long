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

// static void		free_image(t_global *g)
// {
// 	mlx_destroy_image(g->ptr->mlx_ptr, g->img->img);
// 	g->img->img = NULL;
// 	g->img->adr = NULL;
// }

static void		free_ptr(t_ptr *ptr)
{
	if (ptr->mlx_ptr)
	{
		if (ptr->win_ptr)
		{
			// if (g->img->img)
				// free_image(g);
			mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
		}
		mlx_destroy_display(ptr->mlx_ptr);
		free(ptr->mlx_ptr);
		ptr->mlx_ptr = NULL;
	}
}


static int 	close_cub(t_ptr *ptr)
{
		printf("Sortie du programme\n");
		free_ptr(ptr);
		// free_everything(all);
		exit (0);
}

static void	init_ptr_mlx(t_ptr *ptr)
{
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, 800, 400, "Test Window");
	mlx_hook(ptr->win_ptr, 33, 1L << 17, &close_cub, ptr);
	mlx_loop(ptr->mlx_ptr);
}

void	init_var(t_global *g)
{
	g->error = 0;
	g->map = NULL;
	g->exit = 0;
	g->start = 0;
	g->collectible = 0;
	init_ptr_mlx(&g->ptr);
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