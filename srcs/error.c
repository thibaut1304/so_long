/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:39:27 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/25 02:39:27 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so.h"

void	record_error(t_global *g, t_list **error, char *str)
{
	t_list	*new_error;

	g->error += 1;
	new_error = ft_lstnew(ft_strdup(str));
	ft_lstadd_back(error, new_error);
}

void	print_error(t_list *error)
{
	char	*line;

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
