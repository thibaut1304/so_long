/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:41:57 by thhusser          #+#    #+#             */
/*   Updated: 2021/07/25 02:41:57 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so.h"

int	check_extension(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
		i++;
	i -= 4;
	if (i > 0)
		return (ft_strequ(&file[i], ".ber"));
	else
		return (0);
}

int	begin(t_global *g, int argc, char *file, t_list **error)
{
	if (argc != 2)
	{
		record_error(g, error, "There must be 2 arguments\n");
		return (1);
	}
	else if (!check_extension(file))
	{
		record_error(g, error, "Is not a '.ber' file\n");
		return (1);
	}
	return (0);
}
