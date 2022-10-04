/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:16:00 by tboumadj          #+#    #+#             */
/*   Updated: 2022/09/22 13:46:02 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_movement(t_player *data)
{
	data->movement += 1;
	ft_printf("move : %d\n", data->movement);
}

void	find_lastcol(t_player *data)
{
	char	**tmp;
	int		i;

	tmp = data->maps;
	i = 0;
	i = ((int)ft_strlen(&tmp[0][i]) - 1);
	data->lastcol = i;
}

void	ft_backslashn(t_player *data)
{
	char	**tmp;

	tmp = data->maps;
	if (tmp[data->total -1][data->lastcol] == '\n' ||
			tmp[data->total -1][data->lastcol] == '\0')
	{
		tmp[data->total -1][data->lastcol] = '\n';
		tmp[data->total -1][data->lastcol +1] = '\0';
	}
}

int	search_ber(const char *str)
{
	int	i;

	i = 0;
	i = ft_strlen(&str[i]);
	if (i < 5)
		return (0);
	if (str[--i] != 'r')
		return (0);
	if (str[--i] != 'e')
		return (0);
	if (str[--i] != 'b')
		return (0);
	if (str[--i] != '.')
		return (0);
	return (1);
}

void	close_action(t_player *data)
{
	ft_find_player(data);
	reset_move(data);
	print_movement(data);
}	
