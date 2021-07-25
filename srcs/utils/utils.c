/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:38:41 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/25 15:38:41 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so.h"

int	detect_map_line(char *line, t_list **error, t_global *g)
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
		{
			record_error(g, error, "Invalid character in the map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void		record_map(char *line, t_list **list)
{
	t_list	*new_elem;

	new_elem = ft_lstnew(ft_strdup(line));
	ft_lstadd_back(list, new_elem);
}

int		is_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}