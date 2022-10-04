/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:40:42 by tboumadj          #+#    #+#             */
/*   Updated: 2022/09/22 15:08:27 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_player(t_player *data)
{
	char	**tmp;
	int		i;
	int		j;

	tmp = data->maps;
	i = 0;
	j = 0;
	while (i < data->total)
	{
		while (tmp[i][j] != '\n')
		{
			if (tmp[i][j] == 'P')
				break ;
			j++;
		}
		if (tmp[i][j] == 'P')
			break ;
		j = 0;
		i++;
	}
	data->line = i;
	data->count = j;
}

void	value_matrix(t_player *data)
{
	data->matrix.y = 0;
	data->matrix.x = 0;
	data->img.img_width = 45;
	data->img.img_height = 45;
}

void	print_wall_part2(t_player *data)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = data->maps;
	while (i < data->total)
	{
		while (j < data->lastcol)
		{
			if (tmp[i][j] == 'C')
				mlx_put_image_to_window(data->vars.mlx, data->vars.win,
					data->sprite.coin.img, j * 45, i * 45);
			else if (tmp[i][j] == 'M')
				mlx_put_image_to_window(data->vars.mlx, data->vars.win,
					data->sprite.monster.img, j * 45, i * 45);
			j++;
		}
		j = 0;
		i++;
	}
}

void	print_wall_part3(t_player *data)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = data->maps;
	while (i < data->total)
	{
		while (j < data->lastcol)
		{
			if (tmp[i][j] == 'E')
			{
				if (data->treas == data-> find)
					mlx_put_image_to_window(data->vars.mlx, data->vars.win,
						data->sprite.exito.img, j * 45, i * 45);
				else
					mlx_put_image_to_window(data->vars.mlx, data->vars.win,
						data->sprite.exitf.img, j * 45, i * 45);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
