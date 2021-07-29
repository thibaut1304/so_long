/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 06:51:55 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/28 06:51:55 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so.h"

void	load_texture(t_global *g)
{
	int	i;

	i = -1;
	g->texture[0].name = ft_strdup("./textures/icones8/mur.xpm");
	g->texture[1].name = ft_strdup("./textures/icones8/empty.xpm");
	g->texture[2].name = ft_strdup("./textures/icones8/homme.xpm");
	g->texture[3].name = ft_strdup("./textures/icones8/medaille.xpm");
	g->texture[4].name = ft_strdup("./textures/icones8/precision.xpm");
	while (++i < 5)
	{
		g->texture[i].ptr = mlx_xpm_file_to_image(g->window.mlx_ptr,
				g->texture[i].name, &g->texture[i].w, &g->texture[i].h);
		g->texture[i].data = mlx_get_data_addr(g->texture[i].ptr,
				&g->texture[i].bits_per_pxl, &g->texture[i].line_length,
				&g->texture[i].endian);
	}
}
