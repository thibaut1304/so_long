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
#include "../minilibx/mlx.h"

typedef struct 	s_ptr
{
	void 	*mlx_ptr;
	void 	*win_ptr;
}				t_ptr;

typedef struct 	s_global
{
	char 	**map;
	t_ptr	ptr;
	int 	fd;
	int 	number_columns;
	int 	number_rows;
	int 	start;
	int 	collectible;
	int 	exit;
	int 	error;
}				t_global;

void 	record_error(t_global *g, t_list **error, char *str);
void 	print_error(t_list *error);

void	free_global(t_list *list, t_global g, t_list *error);
void	init_var(t_global *g);

int		check_extension(char *file);
int 	begin(t_global *g, int argc, char *file, t_list **error);

void	record_map(char *line, t_list **list);
int		is_in_charset(char c, char *charset);
int		detect_map_line(char *line, t_list **error, t_global *g);

void	check_borders(t_global *g, t_list **error);
void 	del_list(void *grid);
int		count_grid(t_global *g, t_list *grid, t_list **error);


#endif