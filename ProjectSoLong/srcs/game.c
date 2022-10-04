/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:20:54 by tboumadj@student  #+#    #+#             */
/*   Updated: 2022/09/27 14:28:53 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_player *data)
{
	mlx_destroy_window(data->vars.mlx, data->vars.win);
	mlx_destroy_image(data->vars.mlx, data->sprite.intro.img);
	data->vars.mlx = mlx_init();
	data->vars.win = mlx_new_window(data->vars.mlx, data->lastcol * 45,
			data->total * 45, "tboumadj Game");
	init_img(data);
	init_img_player(data);
	init_player_sprite(data);
	init_player_sprite_2part(data);
	init_valucount(data);
	mlx_hook(data->vars.win, 2, 1L << 0, action_key, data);
	mlx_hook(data->vars.win, 17, 1L << 17, ft_close, data);
	mlx_loop_hook(data->vars.mlx, print_img, data);
	mlx_loop(data->vars.mlx);
	return (0);
}

void	init_img(t_player *data)
{
	data->sprite.wall.img = mlx_xpm_file_to_image(data->vars.mlx, WALL,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.wall.img == NULL)
		ft_close_error(data, 1);
	data->sprite.exitf.img = mlx_xpm_file_to_image(data->vars.mlx, EXITF,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.exitf.img == NULL)
		ft_close_error(data, 2);
	data->sprite.exito.img = mlx_xpm_file_to_image(data->vars.mlx, EXITO,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.exito.img == NULL)
		ft_close_error(data, 3);
	data->sprite.coin.img = mlx_xpm_file_to_image(data->vars.mlx, COIN,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.coin.img == NULL)
		ft_close_error(data, 4);
	data->sprite.monster.img = mlx_xpm_file_to_image(data->vars.mlx, MONSTER,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.monster.img == NULL)
		ft_close_error(data, 5);
	data->sprite.floor.img = mlx_xpm_file_to_image(data->vars.mlx, FLOOR,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.floor.img == NULL)
		ft_close_error(data, 6);
}

void	init_img_player(t_player *data)
{
	data->img.img = mlx_xpm_file_to_image(data->vars.mlx, PLAYER,
			&data->img.img_width, &data->img.img_height);
	if (data->img.img == NULL)
		ft_close_error(data, 7);
	data->sprite.pup.img = mlx_xpm_file_to_image(data->vars.mlx, PUP,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.pup.img == NULL)
		ft_close_error(data, 8);
	data->sprite.pleft.img = mlx_xpm_file_to_image(data->vars.mlx, PLEFT,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.pleft.img == NULL)
		ft_close_error(data, 9);
	data->sprite.pright.img = mlx_xpm_file_to_image(data->vars.mlx, PRIGHT,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.pright.img == NULL)
		ft_close_error(data, 10);
}

void	print_wall(t_player *data)
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
			if (tmp[i][j] == '1')
				mlx_put_image_to_window(data->vars.mlx, data->vars.win,
					data->sprite.wall.img, j * 45, i * 45);
			else if (tmp[i][j] == '0')
				mlx_put_image_to_window(data->vars.mlx, data->vars.win,
					data->sprite.floor.img, j * 45, i * 45);
			j++;
		}
		j = 0;
		i++;
	}
}

void	print_player(t_player *data)
{
	if (data->move.down == 1)
		sprite_down(data);
	if (data->move.up == 1)
		sprite_up(data);
	if (data->move.left == 1)
		sprite_left(data);
	if (data->move.right == 1)
		sprite_right(data);
	return ;
}
