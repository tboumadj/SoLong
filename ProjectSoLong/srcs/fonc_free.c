/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:05:21 by tboumadj          #+#    #+#             */
/*   Updated: 2022/09/27 15:39:58 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(t_player *data)
{
	int	i;

	i = 0;
	while (i < data->total)
	{
		free(data->matrix.mat[i]);
		i++;
	}
	free(data->matrix.mat);
}

void	free_maps(t_player *data)
{
	int	i;

	i = 0;
	while (i < data->total)
	{
		free(data->maps[i]);
		i++;
	}
	free(data->maps);
}

void	free_img(t_player *data, int x)
{
	if (data->sprite.wall.img != NULL && x > 1)
		mlx_destroy_image(data->vars.mlx, data->sprite.wall.img);
	if (data->sprite.exitf.img != NULL && x > 2)
		mlx_destroy_image(data->vars.mlx, data->sprite.exitf.img);
	if (data->sprite.exito.img != NULL && x > 3)
		mlx_destroy_image(data->vars.mlx, data->sprite.exito.img);
	if (data->sprite.coin.img != NULL && x > 4)
		mlx_destroy_image(data->vars.mlx, data->sprite.coin.img);
	if (data->sprite.monster.img != NULL && x > 5)
		mlx_destroy_image(data->vars.mlx, data->sprite.monster.img);
	if (data->sprite.floor.img != NULL && x > 6)
		mlx_destroy_image(data->vars.mlx, data->sprite.floor.img);
	if (data->img.img != NULL && x > 7)
		mlx_destroy_image(data->vars.mlx, data->img.img);
	if (data->sprite.pup.img != NULL && x > 8)
		mlx_destroy_image(data->vars.mlx, data->sprite.pup.img);
	if (data->sprite.pleft.img != NULL && x > 9)
		mlx_destroy_image(data->vars.mlx, data->sprite.pleft.img);
	if (data->sprite.pright.img != NULL && x > 10)
		mlx_destroy_image(data->vars.mlx, data->sprite.pright.img);
	free_img_sprites(data, x);
}

void	free_img_sprites(t_player *data, int x)
{
	if (data->sprite.front2.img != NULL && x > 11)
		mlx_destroy_image(data->vars.mlx, data->sprite.front2.img);
	if (data->sprite.front3.img != NULL && x > 12)
		mlx_destroy_image(data->vars.mlx, data->sprite.front3.img);
	if (data->sprite.pup2.img != NULL && x > 13)
		mlx_destroy_image(data->vars.mlx, data->sprite.pup2.img);
	if (data->sprite.pup3.img != NULL && x > 14)
		mlx_destroy_image(data->vars.mlx, data->sprite.pup3.img);
	if (data->sprite.pleft2.img != NULL && x > 15)
		mlx_destroy_image(data->vars.mlx, data->sprite.pleft2.img);
	if (data->sprite.pleft3.img != NULL && x > 16)
		mlx_destroy_image(data->vars.mlx, data->sprite.pleft3.img);
	if (data->sprite.pright2.img != NULL && x > 17)
		mlx_destroy_image(data->vars.mlx, data->sprite.pright2.img);
	if (data->sprite.pright3.img != NULL && x > 18)
		mlx_destroy_image(data->vars.mlx, data->sprite.pright3.img);
}

int	ft_close(t_player *data)
{
	mlx_destroy_window(data->vars.mlx, data->vars.win);
	free_img(data, 42);
	free_maps(data);
	exit(EXIT_SUCCESS);
	return (0);
}
