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

	i = -1;
	while (line[++i])
	{
		if (is_in_charset(line[i], "01CEP") == 0)
		{
			record_error(g, error, "Invalid character in the map\n");
			return (0);
		}
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

char	*add_spaces(char *str, int largest_line)
{
	int		i;
	char	*res;

	i = 0;
	res = malloc(sizeof(char *) * largest_line + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	while (i < largest_line)
	{
		res[i] = ' ';
		i++;
	}
	res[i] = '\0';
	free(str);
	return (res);
}
