/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:43:20 by tboumadj          #+#    #+#             */
/*   Updated: 2022/09/27 15:40:59 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	action_intro(int key, t_player *player)
{
	if (key == ENTER)
		init_game(player);
	if (key == RETURN)
		init_game(player);
	if (key == ECHAP)
		ft_close_intro(player);
	return (0);
}

void	init_intro(t_player *data)
{
	check_allrules(data);
	create_matrix(data);
	init_algo(data);
	data->movement = 0;
	data->move.down = 1;
	data->vars.mlx = mlx_init();
	data->vars.win = mlx_new_window(data->vars.mlx, 640, 480, "tboumadj Game");
	data->sprite.intro.img = mlx_new_image(data->vars.mlx, 640, 480);
	data->sprite.intro.img = mlx_xpm_file_to_image(data->vars.mlx, INTRO,
			&data->img.img_width, &data->img.img_height);
	mlx_put_image_to_window(data->vars.mlx, data->vars.win,
		data->sprite.intro.img, 0, 0);
	mlx_hook(data->vars.win, 2, 1L << 0, action_intro, data);
	mlx_hook(data->vars.win, 17, 1L << 17, ft_close, data);
	mlx_loop(data->vars.mlx);
}

void	init_maps(t_player *data)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	fd = open(data->av, O_RDONLY);
	while (i < data->total)
	{
		data->maps[i] = ft_stock_maps(fd);
		i++;
	}
	find_lastcol(data);
	ft_backslashn(data);
	ft_find_player(data);
	search_find(data);
}

void	read_map(t_player *data)
{
	int		i;
	int		fd;
	int		t;
	char	*m;

	i = 0;
	t = 0;
	fd = open(data->av, O_RDONLY);
	if (fd == -1)
		ft_close_map();
	while (fd != 1)
	{
		m = get_next_line(fd);
		i++;
		if (m == NULL)
		{
			free(m);
			break ;
		}
		free(m);
	}
	i--;
	data->maps = malloc(sizeof(char *) * i + 1);
	t = i;
	data->total = t;
}

int	main(int arg, char **argv)
{
	t_player	data;

	if (arg != 2)
	{
		ft_printf("Error Param\n");
		exit (EXIT_FAILURE);
	}
	if (search_ber(argv[1]) != 1)
	{
		ft_printf("Error .ber Expected\n");
		exit (EXIT_FAILURE);
	}
	data.av = argv[1];
	read_map(&data);
	init_maps(&data);
	init_intro(&data);
	init_game(&data);
}
