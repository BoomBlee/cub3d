/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 06:01:43 by Kcaraway          #+#    #+#             */
/*   Updated: 2020/11/04 23:15:43 by kcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_color(t_all *all, int flag, int h, int w)
{
	double	column_h;

	column_h = (SCALE / all->plr.dist) * (all->res.x / 2) / tan(FOV / 2);
	all->tex[flag].color = (all->tex[flag].addr + (((h * all->tex[flag].heigth)
	/ (int)column_h) * all->tex[flag].ll + w * (all->tex[flag].bpr / 8)));
}

void	drawing_wall(t_all all, int x, int flag, int max)
{
	int		w;
	int		h;
	double	hit;
	int		y;
	double	column_h;

	w = 0;
	h = 0;
	column_h = (SCALE / all.plr.dist) * (all.res.x / 2.0) / tan(FOV / 2);
	y = all.res.y / 2.0 - column_h / 2.0;
	if (flag == 1 || flag == 3)
		hit = fmod(all.pp.x, SCALE) / SCALE;
	else if (flag == 2 || flag == 4)
		hit = fmod(all.pp.y, SCALE) / SCALE;
	w = all.tex[flag].width * hit;
	while (y < max - 1)
	{
		if (y >= 0)
		{
			get_color(&all, flag, h, w);
			pixel_put(all, x, y, *(unsigned int *)all.tex[flag].color);
		}
		h++;
		y++;
	}
}

void	ft_sprite(t_all *all)
{
	int				i;

	i = 0;
	while (i < all->count_sprite)
	{
		all->sprite[i].angle = atan2(all->sprite[i].y - all->plr.pos.y, \
							all->sprite[i].x - all->plr.pos.x) + M_PI;
		while (all->sprite[i].angle - all->plr.angle > M_PI)
			all->sprite[i].angle -= 2.0 * M_PI;
		while (all->sprite[i].angle - all->plr.angle < -M_PI)
			all->sprite[i].angle += 2.0 * M_PI;
		all->sprite[i].angle -= all->plr.angle;
		all->sprite[i].dist = sqrt(pow(all->sprite[i].x - all->plr.pos.x, 2)
		+ pow(all->sprite[i].y - all->plr.pos.y, 2));
		all->sprite[i].size = (SCALE / all->sprite[i].dist) * (all->res.x / 2)
		/ tan(FOV / 2);
		all->sprite[i].x_offset = all->res.x / (FOV * (180.0 / M_PI)) *
		((180.0 / M_PI * all->sprite[i].angle)
		+ 30.0) - all->sprite[i].size / 2;
		all->sprite[i].y_offset = all->res.y / 2 - all->sprite[i].size / 2;
		all->sprite[i].step = all->tex[0].heigth / all->sprite[i].size;
		all->sprite[i].tex_pos = 0;
		i++;
	}
}

void	sort_spr(t_all *all)
{
	int				i;
	int				j;
	t_sprite		tmp;

	i = 0;
	while (i < all->count_sprite)
	{
		j = 0;
		while (j < all->count_sprite - 1)
		{
			if (all->sprite[j].dist < all->sprite[j + 1].dist)
			{
				tmp = all->sprite[j];
				all->sprite[j] = all->sprite[j + 1];
				all->sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
