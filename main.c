/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:29:45 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/24 20:29:45 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so.h"

static int		check_extension(char *file)
{
	int		i;

	i = 0;
	while (file[i] != '\0')
		i++;
	i -= 4;
	if (i > 0)
		return (ft_strequ(&file[i], ".ber"));
	else
		return (0);
}

void 	record_error(t_global *g, t_list **error, char *str)
{
	t_list 	*new_error;

	g->error += 1;
	new_error = ft_lstnew(ft_strdup(str));
	ft_lstadd_back(error, new_error);
}

static int 	begin(t_global *g, int argc, char *file, t_list **error)
{
	if (argc != 2)
	{
		record_error(g, error, "There must be 2 arguments\n");
		return (1);
	}
	else if (!check_extension(file))
	{
		record_error(g, error, "s not a '.ber' file\n");
		return (1);
	}
	return (0);
}

static void		record_map(t_global *g, char *line, t_list **list)
{
	(void)g;
	t_list	*new_elem;

	new_elem = ft_lstnew(ft_strdup(line));
	ft_lstadd_back(list, new_elem);
}

static int		is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	detect_map_line(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	if (*line == '\0')
		return (0);
	while (line[i])
	{
		if (is_in_charset(line[i], "01CEP") == 0)
			return (0);
		i++;
	}
	return (1);
}

static void 	init(t_global *g, char *file, t_list **list, t_list **error)
{
	int res;
	char *line;

	res = 1;
	g->fd = open(file, O_RDONLY);
	if (g->fd < 0)
	{
		record_error(g, error, "Error open file\n");
		return ;
	}
	while (res > 0)
	{
		res = get_next_line(g->fd, &line);
		if (detect_map_line(line))
			record_map(g, line, list);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
	close(g->fd);
}

static void		free_global(t_list *list, t_global g, t_list *error)
{
	int i;

	i = 0;
	ft_lstclear(&list, &del_list);
	ft_lstclear(&error, &del_list);
	while (i < g.number_rows)
		free(g.map[i++]);
	free(g.map);
}

static void print_error(t_list *error)
{
	char *line;

	line = NULL;
	ft_putstr("Error\n");
	while (error)
	{
		line = ft_strdup(error->content);
		ft_putstr(line);
		free(line);
		error = error->next;
	}
}

int		main(int argc, char **argv)
{
	t_global g;
	t_list *list;
	t_list 	*error;
	int i;

	list = NULL;
	error = NULL;
	g.error = 0;
	i = 0;
	if (!begin(&g, argc, argv[1], &error))
	{
		init(&g, argv[1], &list, &error);
		count_grid(&g, list, &error);
		//affichage double tab
		while (i < g.number_rows)
			printf("%s\n", g.map[i++]);
	}
	print_error(error);
	printf("%d\n", g.error);
	printf("P == %d\n", g.start);
	printf("E == %d\n", g.exit);
	printf("C == %d\n", g.collectible);
	free_global(list, g, error);

	return (0);

}