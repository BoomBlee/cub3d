/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 06:01:40 by Kcaraway          #+#    #+#             */
/*   Updated: 2020/11/04 04:42:22 by kcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_all2(t_all *all)
{
	all->error.plr = -1;
	all->error.r = -1;
	all->error.no = -1;
	all->error.s = -1;
	all->error.ea = -1;
	all->error.we = -1;
	all->error.s = -1;
	all->count_sprite = 0;
	all->list = NULL;
}

void	sreen_shot(t_all all, t_plr plr, char *str)
{
	all = read_all(str, 1);
	all = draw_screen(all, &plr);
	refresh_image(all, &plr, 1);
	exit_error("saved screenshot\n", 0, &all);
}

int		main(int argc, char **argv)
{
	t_all	all;
	t_plr	plr;

	if (argc < 2)
		exit_error("Error\nNo map\n", 0, &all);
	if (argc > 3)
		exit_error("Error\ntoo many arg\n", 0, &all);
	all = read_all(argv[1], 0);
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save\0", 7) == 0)
		{
			sreen_shot(all, plr, argv[1]);
		}
		else
			exit_error("Error\nargc != \"--save\"\n", 1, &all);
	}
	all.win = mlx_new_window(all.mlx, all.res.x, all.res.y, "test");
	mlx_key_hook(all.win, ft_key, &all);
	mlx_hook(all.win, 02, 1L << 0, ft_key, &all);
	all = draw_screen(all, &plr);
	refresh_image(all, &plr, 0);
	all.plr = plr;
	mlx_hook(all.win, 17, 1L << 17, ft_close, &all);
	mlx_loop(all.mlx);
}

int		ft_key(int keycode, t_all *all, t_plr *plr)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(all->mlx, all->win);
		exit_error("Player closed cub3D\n", 0, all);
	}
	if (keycode == XK_w || keycode == XK_a || keycode == XK_s
	|| keycode == XK_d)
	{
		move_plr(all, keycode);
	}
	if (keycode == XK_Left)
	{
		all->plr.angle -= 0.1;
		while (all->plr.angle <= -M_PI * 2)
			all->plr.angle += M_PI * 2;
	}
	if (keycode == XK_Right)
	{
		all->plr.angle += 0.1;
		while (all->plr.angle >= M_PI * 2)
			all->plr.angle -= M_PI * 2;
	}
	refresh_image(*all, plr, 0);
}
