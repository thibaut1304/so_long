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

#define ARROW_UP 65362
#define ARROW_RIGHT 65363
#define ARROW_DOWN 65364
#define ARROW_LEFT 65361

#define KEYBORD_W 119
#define KEYBORD_A 97
#define KEYBORD_S 115
#define KEYBORD_D 100

#define KEYBORD_ESC 65307

#define RED 0xFC031A

typedef struct 	s_img
{
	void 	*img;
	char 	*adr;
	int 	bits_per_pxl;
	int 	line_length;
	int 	endian;
	// int 	wid;
	// int 	hei;
}				t_img;

typedef struct 	s_ptr
{
	void 	*mlx_ptr;
	void 	*win_ptr;
}				t_ptr;

typedef struct 	s_global
{
	char 	**map;
	t_ptr	ptr;
	t_img	img;
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

void	init_ptr_mlx(t_global *g);
int 	close_cub(t_global *g);

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