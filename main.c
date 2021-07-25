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

int		main(int argc, char **argv)
{
	t_global 	g;
	t_list 		*list;
	t_list 		*error;
	int 		i;

	list = NULL;
	error = NULL;
	init_var(&g);
	i = 0;
	if (!begin(&g, argc, argv[1], &error))
	{
		init(&g, argv[1], &list, &error);
		count_grid(&g, list, &error);
		//affichage double tab
		while (i < g.number_rows)
			printf("%s\n", g.map[i++]);
	}
	if (error)
		print_error(error);
	printf("P == %d\n", g.start);
	printf("E == %d\n", g.exit);
	printf("C == %d\n", g.collectible);
	free_global(list, g, error);
	return (0);

}