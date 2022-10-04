/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:30:26 by tboumadj          #+#    #+#             */
/*   Updated: 2022/09/22 13:32:12 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_allrules(t_player *data)
{
	find_lastcol(data);
	check_mapswallh(data);
	check_mapswallv(data);
	check_rulesmaps(data);
	check_mapsrect(data);
	if (check_minimal(data) != 1)
		ft_close_simple(data);
}

void	check_rulesmaps(t_player *data)
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
			if (!(tmp[i][j] == 'P' || tmp[i][j] == '1'
						|| tmp[i][j] == 'E' || tmp[i][j] == '0'
						|| tmp[i][j] == 'C' || tmp[i][j] == 'M'))
				ft_close_simple(data);
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_mapswallh(t_player *data)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

	tmp = data->maps;
	i = 0;
	j = 0;
	k = 0;
	while (tmp[0][j] == '1' && tmp[0][j] != '\n')
		j++;
	if ((int)ft_strlen(&tmp[0][i]) != j +1)
		ft_close_simple(data);
	j = 0;
	i = data->total -1;
	while (tmp[i][j] == '1' && (tmp[i][j] != '\n' || tmp[i][j] != '\0'))
		j++;
	if ((int)ft_strlen(&tmp[i][k]) != j +1)
		ft_close_simple(data);
}

void	check_mapswallv(t_player *data)
{
	char	**tmp;
	int		i;
	int		j;
	int		m;

	find_lastcol(data);
	i = data->lastcol -1;
	m = data->total -1;
	tmp = data->maps;
	j = 0;
	while (j < m)
	{
		if (tmp[j][0] != '1' || tmp[j][i] != '1')
			ft_close_simple(data);
		j++;
	}
}

void	check_mapsrect(t_player *data)
{
	char	**tmp;
	int		i;
	int		j;
	int		m;
	int		t;

	i = 0;
	j = 0;
	m = data->total;
	tmp = data->maps;
	find_lastcol(data);
	t = data->lastcol;
	while (i < m)
	{
		if (t != (int)ft_strlen(&tmp[i][j]) - 1)
			ft_close_simple(data);
		i++;
	}
}
