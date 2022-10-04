/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_road.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:34:32 by tboumadj          #+#    #+#             */
/*   Updated: 2022/09/22 16:25:45 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_matrix(t_player *data)
{
	int	i;
	int	j;

	i = data->total;
	j = data->lastcol;
	data->matrix.mat = malloc(sizeof(int *) * i);
	i = 0;
	while (i < data->total)
	{
		data->matrix.mat[i] = malloc(sizeof(int *) * j);
		i++;
	}
}

void	create_matrix(t_player *data)
{
	char	**tmp;

	tmp = data->maps;
	value_matrix(data);
	init_matrix(data);
	while (data->matrix.y < data->total)
	{
		while (tmp[data->matrix.y][data->matrix.x] != '\n')
		{
			if (tmp[data->matrix.y][data->matrix.x] == '1' ||
				tmp[data->matrix.y][data->matrix.x] == 'M')
				data->matrix.mat[data->matrix.y][data->matrix.x] = 1;
			else if (tmp[data->matrix.y][data->matrix.x] == '0')
				data->matrix.mat[data->matrix.y][data->matrix.x] = 0;
			else if (tmp[data->matrix.y][data->matrix.x] == 'C')
				data->matrix.mat[data->matrix.y][data->matrix.x] = 2;
			else if (tmp[data->matrix.y][data->matrix.x] == 'E')
				data->matrix.mat[data->matrix.y][data->matrix.x] = 5;
			else if (tmp[data->matrix.y][data->matrix.x] == 'P')
				data->matrix.mat[data->matrix.y][data->matrix.x] = 3;
			data->matrix.x++;
		}
		data->matrix.x = 0;
		data->matrix.y++;
	}
}

int	algoroad(t_player *data, int **tmp, int i, int j)
{
	if (tmp[i][j] == 3)
	{
		tmp[i][j] = 7;
		return (1);
	}
	tmp[i][j] = 4;
	if (tmp[i][j +1] != 1 && (j < data->lastcol) &&
		tmp[i][j +1] != 4 && tmp[i][j +1] != 5)
		if (algoroad(data, tmp, i, j +1) == 1)
			return (1);
	if (tmp[i +1][j] != 1 && (i < data->total) &&
			tmp[i +1][j] != 4 && tmp[i +1][j] != 5)
		if (algoroad(data, tmp, i +1, j) == 1)
			return (1);
	if (tmp[i -1][j] != 1 && (i >= 0) && tmp[i -1][j] != 4 && tmp[i -1][j] != 5)
		if (algoroad(data, tmp, i -1, j) == 1)
			return (1);
	if (tmp[i][j -1] != 1 && (j >= 0) && tmp[i][j -1] != 4 && tmp[i][j -1] != 5)
		if (algoroad(data, tmp, i, j -1) == 1)
			return (1);
	return (0);
}

int	check_algo(t_player *data, int **tmp, int i, int j)
{
	if (algoroad(data, tmp, i, j) == 1)
		return (1);
	else
	{
		free_matrix(data);
		ft_close_simple(data);
		return (0);
	}
}

void	init_algo(t_player *data)
{
	int	i;
	int	j;
	int	**tmp;

	i = 0;
	j = 0;
	while (i < data->total)
	{
		while (j < data->lastcol)
		{
			if (data->matrix.mat[i][j] == 2 || data->matrix.mat[i][j] == 5)
			{
				tmp = data->matrix.mat;
				check_algo(data, tmp, i, j);
				free_matrix(data);
				create_matrix(data);
			}
			j++;
		}
		j = 0;
		i++;
	}
	free_matrix(data);
}
