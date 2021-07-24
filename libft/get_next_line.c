/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:35:42 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/24 21:46:34 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_realloc(char *line, int *i)
{
	int		l;
	char	*str;

	l = 0;
	if (!(str = malloc(*i * 2)))
		return (NULL);
	*i *= 2;
	while (line && line[l])
	{
		str[l] = line[l];
		l++;
	}
	while (l < *i)
	{
		str[l] = 0;
		l++;
	}
	free(line);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int r;
	int i;
	int malloc_size;

	r = 1;
	i = -1;
	malloc_size = 50;
	if (!line)
		return (-1);
	*line = NULL;
	if (!(*line = ft_realloc(*line, &malloc_size)))
		return (-1);
	while ((r = read(fd, &(*line)[++i], 1)))
	{
		if ((*line)[i] == 10)
			break ;
		if (i == malloc_size - 2)
			if (!(*line = ft_realloc(*line, &malloc_size)))
				return (-1);
	}
	(*line)[i] = 0;
	return (r);
}
