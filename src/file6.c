/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 06:01:45 by Kcaraway          #+#    #+#             */
/*   Updated: 2020/11/05 00:46:08 by kcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	plr_pos(t_all *all, t_plr *plr, int x, int y)
{
	if (all->error.plr == -1)
	{
		plr->pos.x += SCALE * x + SCALE / 2;
		plr->pos.y += SCALE * y + SCALE / 2;
		if (all->map.line[y][x] == 'N')
			plr->angle = M_PI_2;
		if (all->map.line[y][x] == 'W')
			plr->angle = 0.000001;
		if (all->map.line[y][x] == 'E')
			plr->angle = M_PI + 0.000001;
		if (all->map.line[y][x] == 'S')
			plr->angle = 3 * M_PI_2;
		all->error.plr++;
	}
	else
		exit_error("Error\ndouble plr\n", 1, all);
}

void	move_plr(t_all *all, int keycode)
{
	t_xy move;

	move = all->plr.pos;
	if (keycode == XK_w)
		func_move(&move, all, keycode);
	if (keycode == XK_s)
		func_move(&move, all, keycode);
	if (keycode == XK_a)
		func_move(&move, all, keycode);
	if (keycode == XK_d)
		func_move(&move, all, keycode);
	if (all->map.line[(int)(move.y / SCALE)][(int)(all->plr.pos.x /
	SCALE)] != '1' && all->map.line[(int)(move.y / SCALE)]
	[(int)(all->plr.pos.x / SCALE)] != '2')
		all->plr.pos.y = move.y;
	if (all->map.line[(int)(all->plr.pos.y / SCALE)][(int)(move.x /
	SCALE)] != '1' && all->map.line[(int)(all->plr.pos.y
	/ SCALE)][(int)(move.x / SCALE)] != '2')
		all->plr.pos.x = move.x;
}

t_all	draw_screen(t_all all, t_plr *plr)
{
	int x;
	int y;

	y = 0;
	while (all.map.line[y] && y < all.map.max.y)
	{
		x = 0;
		while (all.map.line[y][x])
		{
			if (all.map.line[y][x] == 'N' || all.map.line[y][x] == 'E'
				|| all.map.line[y][x] == 'W' || all.map.line[y][x] == 'S')
			{
				all.plr = func_k(&all, x, y, plr);
			}
			if (all.map.line[y][x] == '2')
				write_sprite(&all, (double)x, (double)y);
			x++;
		}
		y++;
	}
	if (all.error.plr == -1)
		exit_error("Error\nNo plr\n", 11, &all);
	return (all);
}

void	write_sprite(t_all *all, double x, double y)
{
	all->sprite[all->count_sprite].x = (SCALE * x + SCALE / 2);
	all->sprite[all->count_sprite].y = (SCALE * y + SCALE / 2);
	all->count_sprite++;
}

void	pixel_put(t_all all, int x, int y, int color)
{
	char	*dst;

	dst = all.data.addr + (y * all.data.ll
	+ x * (all.data.bpr / 8));
	if (!(color == 0))
		*(unsigned int*)dst = color;
}
