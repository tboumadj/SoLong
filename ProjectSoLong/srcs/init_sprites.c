/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:29:12 by tboumadj          #+#    #+#             */
/*   Updated: 2022/09/27 14:29:16 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player_sprite(t_player *data)
{
	data->sprite.front2.img = mlx_xpm_file_to_image(data->vars.mlx, PLAYER2,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.front2.img == NULL)
		ft_close_error(data, 11);
	data->sprite.front3.img = mlx_xpm_file_to_image(data->vars.mlx, PLAYER3,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.front3.img == NULL)
		ft_close_error(data, 12);
	data->sprite.pup2.img = mlx_xpm_file_to_image(data->vars.mlx, PUP2,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.pup2.img == NULL)
		ft_close_error(data, 13);
	data->sprite.pup3.img = mlx_xpm_file_to_image(data->vars.mlx, PUP3,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.pup3.img == NULL)
		ft_close_error(data, 14);
}

void	init_player_sprite_2part(t_player *data)
{
	data->sprite.pleft2.img = mlx_xpm_file_to_image(data->vars.mlx, PLEFT2,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.pleft2.img == NULL)
		ft_close_error(data, 15);
	data->sprite.pleft3.img = mlx_xpm_file_to_image(data->vars.mlx, PLEFT3,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.pleft3.img == NULL)
		ft_close_error(data, 16);
	data->sprite.pright2.img = mlx_xpm_file_to_image(data->vars.mlx, PRIGHT2,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.pright2.img == NULL)
		ft_close_error(data, 17);
	data->sprite.pright3.img = mlx_xpm_file_to_image(data->vars.mlx, PRIGHT3,
			&data->img.img_width, &data->img.img_height);
	if (data->sprite.pright3.img == NULL)
		ft_close_error(data, 18);
}

void	init_valucount(t_player *data)
{
	data->move.downcount = 0;
	data->move.upcount = 0;
	data->move.leftcount = 0;
	data->move.rightcount = 0;
}

void	reset_valuecount(t_player *data)
{
	if (data->move.upcount == 3)
		data->move.upcount = 0;
	if (data->move.downcount == 3)
		data->move.downcount = 0;
	if (data->move.leftcount == 3)
		data->move.leftcount = 0;
	if (data->move.rightcount == 3)
		data->move.rightcount = 0;
}

int	print_img(t_player *data)
{
	char	*itoa;

	mlx_clear_window(data->vars.mlx, data->vars.win);
	print_wall(data);
	print_wall_part2(data);
	print_wall_part3(data);
	print_player(data);
	mlx_string_put(data->vars.mlx, data->vars.win, 20, 25, 0Xff3333, "MOVE : ");
	itoa = ft_itoa(data->movement);
	mlx_string_put(data->vars.mlx, data->vars.win, 90, 25, 0Xff3333, itoa);
	free(itoa);
	return (0);
}
