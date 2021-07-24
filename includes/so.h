/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:31:27 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/24 20:31:27 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_H
#define  SO_H

#include "../libft/libft.h"

typedef struct 	s_global
{
	char 	**map;
	int 	fd;
	int 	number_columns;
	int 	number_rows;
}				t_global;

void	check_borders(t_global *g, int line_count, int largest_line);
void 	del_list(void *grid);
int		count_grid(t_global *g, t_list *grid);


#endif