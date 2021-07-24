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

static int 	begin(int argc, char *file)
{
	if (argc != 2)
	{
		ft_putstr("There must be 2 arguments\n");
		return (1);
	}
	else if (!check_extension(file))
	{
		ft_putstr("Is not a '.ber' file\n");
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


static void 	init(t_global *g, char *file, t_list **list)
{
	int res;
	char *line;

	res = 1;
	g->fd = open(file, O_RDONLY);
	if (g->fd < 0)
	{
		ft_putstr("Error open file\n");
		return ;
	}
	while (res > 0)
	{
		res = get_next_line(g->fd, &line);
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
	t_global g;
	t_list *list;

	list = NULL;
	if (!begin(argc, argv[1]))
	{
		init(&g, argv[1], &list);
		if (!count_grid(&g, list))
			ft_lstclear(&list, &del_list);

		int i = 0;
		while (i < g.number_rows)
			printf("%s\n", g.map[i++]);
	}
	return (0);

}