/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 02:03:45 by kcaraway          #+#    #+#             */
/*   Updated: 2020/11/01 06:28:15 by kcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/includes/libft.h"
# include "game.h"
# include <math.h>
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
# include <X11/Xlib.h>
# include <X11/Xutil.h>

void		exit_error(char *str, int errno, t_all *all);
int			start_map(char *str);
t_map		read_map(int all_fd, char *str, char *file, t_all *all);
char		**map_space(t_map map, t_all *all);
int			count_sprite(t_map map);

t_map_val	*free_list(t_map_val *list, t_all *all);
t_map_val	*new_list_map(t_map_val *list, char *line, t_all *all);
int			valid_map(t_map map, int y, int x);
void		validate_map(t_map map, t_all *all);
void		valid_res(t_all *all, int save);

int			space_digit(char *str, int i);
void		func_move(t_xy *move, t_all *all, int keycode);

int			ft_orn(char *str);
int			write_res(t_all *all, char *str, int save);
void		valid_color(int col, t_all *all);
int			write_color(t_all *all, t_color *color, char *str);
int			write_tex(t_all *all, int f, char *str);

int			write_all(char *str, t_all *all, int save);
void		init_all(t_all *all);
void		valid_key(t_all all);
t_all		read_all(char *all_file, int save);
t_plr		func_k(t_all *all, int x, int y, t_plr *plr);

void		plr_pos(t_all *all, t_plr *plr, int x, int y);
void		move_plr(t_all *all, int keycode);
t_all		draw_screen(t_all all, t_plr *plr);
void		write_sprite(t_all *all, double x, double y);
void		pixel_put(t_all all, int x, int y, int color);
void		ft_close(t_all *all);

int			ft_key(int keycode, t_all *all, t_plr *plr);
void		refresh_image(t_all all, t_plr *plr, int save);
void		ft_draw_plr(t_all *all, int save);
int			wall_selection(double angle, int flag);
void		draw_wall2(t_all *all, int x, double angle, int flag);

void		drawing_wall(t_all all, int x, int flag, int max);
void		ft_sprite(t_all *all);
void		sort_spr(t_all *all);
void		draw_sprite(t_all *all, t_sprite sp);

void		rendering_spr(t_all *all, int save);
void		ft_bmp_header(t_all all, int fd);
void		ft_image_header(t_all all, int fd);
void		ft_bmp(t_all all);
void		valid_name_file(char *name);

#endif
