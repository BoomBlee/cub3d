/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 06:01:46 by Kcaraway          #+#    #+#             */
/*   Updated: 2020/11/04 22:08:23 by kcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		write_all(char *str, t_all *all, int save)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == 'R' && str[i + 1] == ' ')
		return (write_res(all, &str[i + 2], save));
	if (str[i] == 'N' && str[i + 1] == 'O')
		return (write_tex(all, 1, &str[i + 2]));
	if (str[i] == 'S' && str[i + 1] == 'O')
		return (write_tex(all, 3, &str[i + 2]));
	if (str[i] == 'W' && str[i + 1] == 'E')
		return (write_tex(all, 2, &str[i + 2]));
	if (str[i] == 'E' && str[i + 1] == 'A')
		return (write_tex(all, 4, &str[i + 2]));
	if (str[i] == 'S' && str[i + 1] == ' ')
		return (write_tex(all, 0, &str[i + 2]));
	if (str[i] == 'F' && str[i + 1] == ' ')
		return (write_color(all, &all->floor, &str[i + 2]));
	if (str[i] == 'C' && str[i + 1] == ' ')
		return (write_color(all, &all->ceilling, &str[i + 2]));
	if (str[i] != '\0')
		exit_error("Error\n", 1, all);
	return (0);
}

void	init_all(t_all *all)
{
	all->res.x = -1;
	all->res.y = -1;
	all->floor.red = -1;
	all->floor.green = -1;
	all->floor.blue = -1;
	all->floor.transparency = 0;
	all->ceilling.red = -1;
	all->ceilling.green = -1;
	all->ceilling.blue = -1;
	all->ceilling.transparency = 0;
	all->tex[0].path = NULL;
	all->tex[1].path = NULL;
	all->tex[2].path = NULL;
	all->tex[3].path = NULL;
	all->tex[4].path = NULL;
	all->map.line = NULL;
	all->map.quantity = 0;
	all->mlx = mlx_init();
	init_all2(all);
}

void	valid_key(t_all all)
{
	if (all.error.r == -1)
		exit_error("Error\n", 1, &all);
	if (all.error.no == -1)
		exit_error("Error\n", 1, &all);
	if (all.error.so == -1)
		exit_error("Error\n", 1, &all);
	if (all.error.ea == -1)
		exit_error("Error\n", 1, &all);
	if (all.error.we == -1)
		exit_error("Error\n", 1, &all);
	if (all.floor.red == -1)
		exit_error("Error\n", 1, &all);
	if (all.ceilling.red == -1)
		exit_error("Error\n", 1, &all);
	if (all.error.s)
		exit_error("Error\n", 1, &all);
}

t_all	read_all(char *all_file, int save)
{
	t_all	all;
	int		all_fd;
	char	*str;
	int		cnt;

	cnt = 0;
	if ((all_fd = open(all_file, O_RDONLY)) < 0)
		exit_error("Error\n", 1, &all);
	init_all(&all);
	while (get_next_line(all_fd, &str) >= 0)
	{
		if (cnt++ == 0 && str[0] == '\0')
			exit_error("Error\nerror file\n", 1, &all);
		if (start_map(str))
			break ;
		write_all(str, &all, save);
		if (str)
			free(str);
	}
	(cnt == 0) ? exit_error("Error\nerror file\n", 1, &all) : (0);
	valid_key(all);
	all.map = read_map(all_fd, str, all_file, &all);
	if (!(all.sprite = malloc(sizeof(t_sprite) * all.map.quantity)))
		exit_error("Error\nmalloc sprite", 1, &all);
	return (all);
}

t_plr	func_k(t_all *all, int x, int y, t_plr *plr)
{
	if (all->map.line[y][x] == 'N' || all->map.line[y][x] == 'E'
		|| all->map.line[y][x] == 'W' || all->map.line[y][x] == 'S')
		plr_pos(all, plr, x, y);
	all->plr = *plr;
	return (*plr);
}
