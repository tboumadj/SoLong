/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:25:28 by tboumadj          #+#    #+#             */
/*   Updated: 2022/09/22 14:34:07 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_find(t_player *data)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

	tmp = data->maps;
	i = 0;
	j = 0;
	k = 0;
	while (i < data->total)
	{
		while (tmp[i][j] != '\n')
		{
			if (tmp[i][j] == 'C')
				k += 1;
			j++;
		}
		j = 0;
		i++;
	}
	data->treas = k;
	data->find = 0;
}

int	check_minimal(t_player *data)
{
	if (check_minimal_collect(data) == 1 && check_minimal_player(data) == 1
		&& check_minimal_exit(data) == 1)
		return (1);
	else
		return (0);
}

int	check_minimal_collect(t_player *data)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

	tmp = data->maps;
	i = 0;
	j = 0;
	k = 0;
	while (i < data->total)
	{
		while (tmp[i][j] != '\n')
		{
			if (tmp[i][j] == 'C')
				k += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (k >= 1)
		return (1);
	else
		return (0);
}

int	check_minimal_player(t_player *data)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

	tmp = data->maps;
	i = 0;
	j = 0;
	k = 0;
	while (i < data->total)
	{
		while (tmp[i][j] != '\n')
		{
			if (tmp[i][j] == 'P')
				k += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (k == 1)
		return (1);
	else
		return (0);
}

int	check_minimal_exit(t_player *data)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

	tmp = data->maps;
	i = 0;
	j = 0;
	k = 0;
	while (i < data->total)
	{
		while (tmp[i][j] != '\n')
		{
			if (tmp[i][j] == 'E')
				k += 1;
			j++;
		}
		j = 0;
		i++;
	}
	if (k == 1)
		return (1);
	else
		return (0);
}
