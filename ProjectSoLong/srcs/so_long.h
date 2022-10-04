/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:43:48 by tboumadj          #+#    #+#             */
/*   Updated: 2022/09/27 15:41:27 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     SO_LONG_H
# define    SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define ECHAP		53
# define UP			13
# define DOWN		1
# define LEFT		0
# define RIGHT		2
# define ENTER		76
# define RETURN		36 
# define INTRO		"./img/newintro.xpm"
# define PLAYER		"./img/front4.xpm"
# define PLAYER2	"./img/front2.xpm"
# define PLAYER3	"./img/front3.xpm"
# define PUP        "./img/back-floor.xpm"
# define PUP2		"./img/back2.xpm"
# define PUP3		"./img/back3.xpm"
# define PLEFT      "./img/left-floor.xpm"
# define PLEFT2		"./img/left2.xpm"
# define PLEFT3		"./img/left3.xpm"
# define PRIGHT     "./img/right-floor.xpm"
# define PRIGHT2	"./img/right2.xpm"
# define PRIGHT3	"./img/right3.xpm"
# define WALL		"./img/wall-floor.xpm"
# define EXITF		"./img/exitf-floor.xpm"
# define EXITO      "./img/exito-floor.xpm"
# define COIN		"./img/coin-floor.xpm"
# define MONSTER    "./img/monster-floor.xpm"
# define FLOOR      "./img/floor.xpm"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_matrix
{
	int		x;
	int		y;
	int		**mat;
}				t_matrix;

typedef struct s_move
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		upcount;
	int		downcount;
	int		leftcount;
	int		rightcount;
}				t_move;

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_img;

typedef struct s_maps
{
	t_img		intro;
	t_img		monster;
	t_img		floor;
	t_img		wall;
	t_img		exitf;
	t_img		exito;
	t_img		coin;
	t_img		pup;
	t_img		pup2;
	t_img		pup3;
	t_img		pleft;
	t_img		pleft2;
	t_img		pleft3;
	t_img		pright;
	t_img		pright2;
	t_img		pright3;
	t_img		front2;
	t_img		front3;
}				t_maps;

typedef struct s_player
{
	int			line;
	int			count;
	int			total;
	int			treas;
	int			find;
	int			movement;
	int			lastcol;
	char		*av;
	char		**maps;
	t_move		move;
	t_maps		sprite;
	t_vars		vars;
	t_matrix	matrix;
	t_img		img;
}				t_player;

//-----------------FONC MAPS---------------------//
int		ft_close(t_player *data);
void	ft_close_map(void);
int		ft_close_win(t_player *data);
int		ft_close_error(t_player *data, int x);
int		ft_close_simple(t_player *data);
int		ft_close_intro(t_player *data);
int		print_maps(t_player *maps);
char	*ft_stock_maps(int fd);
void	ft_find_player(t_player *data);
void	find_lastcol(t_player *data);
void	search_find(t_player *data);
void	ft_backslashn(t_player *data);

//---------------ACTION PLAYER--------------------//
int		action_key(int key, t_player *player);
void	player_up(t_player *data);
void	player_down(t_player *data);
void	player_left(t_player *data);
void	player_right(t_player *data);
void	close_action(t_player *data);
void	print_movement(t_player *data);

//-----------------CHECK RULES-------------------//
void	check_rulesmaps(t_player *data);
int		check_minimal(t_player *data);
int		check_minimal_collect(t_player *data);
int		check_minimal_player(t_player *data);
int		check_minimal_exit(t_player *data);
void	check_mapswallh(t_player *data);
void	check_mapswallv(t_player *data);
void	check_mapsrect(t_player *data);
void	check_allrules(t_player *data);
int		search_ber(const char *str);

//------------------ALGOROAD---------------------//
void	init_matrix(t_player *data);
void	value_matrix(t_player *data);
void	create_matrix(t_player *data);
int		algoroad(t_player *data, int **tmp, int i, int j);
int		check_algo(t_player *data, int **tmp, int i, int j);
void	init_algo(t_player *data);

//------------------GAME------------------------//
void	read_map(t_player *data);
void	init_maps(t_player *data);
void	init_intro(t_player *data);
int		init_game(t_player *data);
void	init_img(t_player *data);
void	init_img_player(t_player *data);
void	print_wall(t_player *data);
void	print_wall_part2(t_player *data);
void	print_wall_part3(t_player *data);
void	print_player(t_player *data);
int		print_img(t_player *data);
int		action_intro(int key, t_player *player);
void	reset_move(t_player *data);

// ------------------ SPRITE --------------------//
void	init_player_sprite(t_player *data);
void	init_player_sprite_2part(t_player *data);
void	init_valucount(t_player *data);
void	sprite_down(t_player *data);
void	sprite_up(t_player *data);
void	sprite_left(t_player *data);
void	sprite_right(t_player *data);
void	reset_valuecount(t_player *data);

//--------------------FREE------------------------//
void	free_matrix(t_player *data);
void	free_maps(t_player *data);
void	free_img(t_player *data, int x);
void	free_img_sprites(t_player *data, int x);

#endif
