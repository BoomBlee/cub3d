/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 04:00:58 by kcaraway          #+#    #+#             */
/*   Updated: 2020/11/04 23:32:10 by kcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# define SCALE	64

# define M_PI		3.14159265358979323846
# define M_PI_2		1.57079632679489661923
# define MOVE		32
# define FOV 60 * (M_PI / 180)

# define RES_X 1600
# define RES_Y 900

typedef	struct	s_map_val
{
	char				*line;
	struct s_map_val	*next;
}				t_map_val;

typedef struct	s_xy
{
	double	x;
	double	y;
}				t_xy;

typedef struct	s_plr
{
	t_xy	pos;
	t_xy	dir;
	t_xy	ray_dir;
	t_xy	plane;
	t_xy	camera;
	t_xy	side_dist;
	double	dist;
	t_xy	map;
	double	angle;
	double	start;
	double	end;
	t_xy	tmp;
	int		flag;
}				t_plr;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpr;
	int		ll;
	int		endian;
}				t_data;

typedef struct	s_color
{
	int transparency;
	int red;
	int green;
	int blue;
}				t_color;

typedef struct	s_tex
{
	int		width;
	int		heigth;
	void	*img;
	char	*addr;
	int		bpr;
	int		ll;
	int		endian;
	char	*path;
	char	**str;
	char	*color;
}				t_tex;

typedef struct	s_map
{
	char	**line;
	int		quantity;
	t_xy	max;
}				t_map;

typedef struct	s_error
{
	int r;
	int no;
	int so;
	int we;
	int ea;
	int s;
	int f;
	int c;
	int plr;
}				t_error;

typedef struct	s_sprite
{
	double			x;
	double			y;
	double			angle;
	double			dist;
	double			size;
	double			x_offset;
	double			y_offset;
	double			step;
	double			tex_pos;
	unsigned int	*color;
	int				tex_y;
	int				tex_x;
}				t_sprite;

typedef struct	s_all
{
	t_xy		res;
	t_tex		tex[5];
	t_color		floor;
	t_color		ceilling;
	t_map		map;
	void		*mlx;
	void		*win;
	t_plr		plr;
	t_data		data;
	t_error		error;
	t_xy		pp;
	t_sprite	*sprite;
	int			count_sprite;
	double		*dist_wall;
	t_map_val	*list;
}				t_all;

#endif
