/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:18:09 by tboumadj          #+#    #+#             */
/*   Updated: 2022/09/27 14:53:11 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_stock_maps(int fd)
{
	char	*tmp2;
	int		i;

	tmp2 = get_next_line(fd);
	i = 0;
	while (tmp2[i])
		i++;
	if (tmp2[i] == '\n' || tmp2[i -1] == '\n')
		tmp2[i +1] = '\0';
	else
	{
		tmp2[i] = '\n';
		tmp2[i +1] = '\0';
	}
	return (tmp2);
}

int	ft_close_simple(t_player *data)
{
	ft_printf("ERROR RULES DOESNT RESPECTED\n");
	free_maps(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_close_intro(t_player *data)
{
	mlx_destroy_window(data->vars.mlx, data->vars.win);
	mlx_destroy_image(data->vars.mlx, data->sprite.intro.img);
	free_maps(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_close_win(t_player *data)
{
	print_movement(data);
	ft_printf("YOU WIN!\n");
	mlx_destroy_window(data->vars.mlx, data->vars.win);
	free_img(data, 42);
	free_maps(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_close_error(t_player *data, int x)
{
	ft_printf("ERROR RULES DOESNT RESPECTED\n");
	mlx_destroy_window(data->vars.mlx, data->vars.win);
	free_img(data, x);
	free_maps(data);
	exit(EXIT_FAILURE);
	return (0);
}
