/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 06:01:51 by Kcaraway          #+#    #+#             */
/*   Updated: 2020/11/04 23:15:11 by kcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		space_digit(char *str, int i)
{
	while ((str[i]) == ' ')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while ((str[i]) == ' ')
		i++;
	return (i);
}

void	func_move(t_xy *move, t_all *all, int keycode)
{
	if (keycode == XK_w)
	{
		move->x -= cos(all->plr.angle) * MOVE;
		move->y -= sin(all->plr.angle) * MOVE;
	}
	if (keycode == XK_s)
	{
		move->x += cos(all->plr.angle) * MOVE;
		move->y += sin(all->plr.angle) * MOVE;
	}
	if (keycode == XK_a)
	{
		move->x -= cos(all->plr.angle - M_PI_2) * MOVE;
		move->y -= sin(all->plr.angle - M_PI_2) * MOVE;
	}
	if (keycode == XK_d)
	{
		move->x -= cos(all->plr.angle + M_PI_2) * MOVE;
		move->y -= sin(all->plr.angle + M_PI_2) * MOVE;
	}
}

void	draw_sprite(t_all *all, t_sprite sp)
{
	int				i;
	int				j;

	i = -1;
	while (++i < sp.size)
	{
		if (sp.x_offset + i > all->res.x || sp.x_offset + i < 0
		|| all->dist_wall[i + (int)sp.x_offset] < sp.dist)
			continue;
		sp.tex_x = i / sp.size * all->tex[0].width;
		sp.tex_pos = 0;
		j = -1;
		while (++j < sp.size)
		{
			sp.tex_y = (unsigned int)sp.tex_pos & (all->tex[0].heigth - 1);
			sp.color = (unsigned int *)(all->tex[0].addr + \
				(sp.tex_y * all->tex[0].ll + sp.tex_x * (all->tex[0].bpr / 8)));
			sp.tex_pos += sp.step;
			if (sp.y_offset + j > all->res.y || sp.y_offset + i < 0 ||
			sp.y_offset + j < 0)
				continue;
			pixel_put(*all, (int)(sp.x_offset + i), (int)(sp.y_offset + j),
			*sp.color);
		}
	}
}

int		wall_selection(double ang, int flag)
{
	while (ang >= M_PI * 2)
		ang -= M_PI * 2;
	while (ang <= -M_PI * 2)
		ang += M_PI * 2;
	if (flag == 1)
	{
		if ((ang > -M_PI_2 && ang < M_PI_2) || (ang > 3 * M_PI_2
		&& ang < M_PI * 2) || (ang < -3 * M_PI_2 && ang > -M_PI * 2))
			return (2);
		if ((ang < -M_PI_2 && ang > -3 * M_PI_2)
		|| (ang <= 3 * M_PI_2 && ang >= M_PI_2))
			return (4);
	}
	if (flag == 2)
	{
		if ((ang >= 0 && ang <= M_PI) || (ang <= -M_PI && ang >= -M_PI * 2))
			return (1);
		if ((ang <= 0 && ang >= -M_PI) || (ang >= M_PI && ang <= M_PI * 2))
			return (3);
	}
}

void	draw_wall2(t_all *all, int x, double angle, int flag)
{
	double	column_h;
	int		y1;
	int		y2;
	int		a;

	a = 0;
	if (all->plr.dist <= 0.1)
		all->plr.dist = 0.1;
	column_h = (SCALE / all->plr.dist) * (all->res.x / 2) / tan(FOV / 2);
	y1 = all->res.y / 2.0 - column_h / 2.0;
	if ((y2 = all->res.y / 2 + column_h / 2) > all->res.y)
		y2 = all->res.y;
	if (y2 <= 0)
		y2 = all->res.y;
	while (a < y1)
		pixel_put(*all, x, a++, create_trgb(all->ceilling));
	drawing_wall(*all, x, flag, y2);
	while (y2 < all->res.y)
		pixel_put(*all, x, y2++, create_trgb(all->floor));
}
