/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 06:01:44 by Kcaraway          #+#    #+#             */
/*   Updated: 2020/11/05 00:46:34 by kcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	refresh_image(t_all all, t_plr *plr, int save)
{
	if (!(all.data.img = mlx_new_image(all.mlx, all.res.x, all.res.y)))
		exit_error("Error\nerror data.img\n", 1, &all);
	all.data.addr = mlx_get_data_addr(all.data.img, &all.data.bpr, &all.data.ll,
	&all.data.endian);
	ft_draw_plr(&all, save);
	rendering_spr(&all, save);
	if (save == 0)
		mlx_put_image_to_window(all.mlx, all.win, all.data.img, 0, 0);
	else
		ft_bmp(all);
	mlx_destroy_image(all.mlx, all.data.img);
}

int		create_trgb(t_color color)
{
	return (color.transparency << 24 | color.red << 16
	| color.green << 8 | color.blue);
}

void	ft_close(t_all *all)
{
	exit_error("plr closed cub3D\n", 0, all);
}

void	func_qwerf(t_all *all)
{
	while (all->map.line[(int)(all->plr.tmp.y / SCALE)][(int)(all->plr.tmp.x
	/ SCALE)] != '1')
	{
		all->plr.tmp.x -= cos(all->plr.start);
		if (all->map.line[(int)(all->plr.tmp.y / SCALE)][(int)(all->plr.tmp.x
		/ SCALE)] == '1')
		{
			all->plr.tmp.x += cos(all->plr.start);
			all->plr.flag = 1;
			break ;
		}
		all->plr.tmp.y -= sin(all->plr.start);
		if (all->map.line[(int)(all->plr.tmp.y / SCALE)][(int)(all->plr.tmp.x
		/ SCALE)] == '1')
		{
			all->plr.tmp.y += sin(all->plr.start);
			all->plr.tmp.x += cos(all->plr.start);
			all->plr.flag = 2;
			break ;
		}
	}
}

void	ft_draw_plr(t_all *all, int save)
{
	int		i;

	i = 0;
	all->plr.start = all->plr.angle - M_PI_2 / 3;
	all->plr.end = all->plr.angle + M_PI_2 / 3;
	while (all->plr.start < all->plr.end && i < all->res.x)
	{
		all->plr.tmp.x = all->plr.pos.x;
		all->plr.tmp.y = all->plr.pos.y;
		all->plr.flag = -1;
		func_qwerf(all);
		all->plr.dist = 1.0 * ((all->plr.pos.y - all->plr.tmp.y)
		/ sin(all->plr.start)) * cos(all->plr.start - all->plr.angle);
		all->dist_wall[i] = all->plr.dist;
		all->plr.flag = wall_selection(all->plr.start, all->plr.flag);
		all->pp.x = all->plr.tmp.x;
		all->pp.y = all->plr.tmp.y;
		draw_wall2(all, i, all->plr.start, all->plr.flag);
		all->plr.start += (M_PI / 3) / all->res.x;
		i++;
	}
}
