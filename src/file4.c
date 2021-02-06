/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 06:01:49 by Kcaraway          #+#    #+#             */
/*   Updated: 2020/11/04 21:54:28 by kcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_orn(char *str)
{
	int i;

	i = -1;
	while (ft_isspace(*str))
		str++;
	if (*str >= '0' && *str <= '9')
	{
		i = 0;
		while (*str >= '0' && *str <= '9')
		{
			if (i < 999999)
				i = i * 10 + *str - '0';
			str++;
		}
	}
	return (i);
}

int		write_res(t_all *all, char *str, int save)
{
	int i;

	i = 0;
	if (all->error.r == -1)
	{
		all->res.x = ft_orn(str);
		while ((str[i]) == ' ')
			i++;
		while (ft_isdigit(str[i]))
			i++;
		all->res.y = ft_orn(&str[i]);
		valid_res(all, save);
		if (!(all->dist_wall = malloc(sizeof(double)
			* all->res.x)))
			exit_error("Error\nmalloc all->dist_wall", 1, all);
		all->error.r++;
		i = space_digit(str, i);
		if (str[i])
			exit_error("Error\nerror resolutoion\n", 1, all);
	}
	else
		exit_error("Error\ndouble resolutoion\n", 1, all);
	return (0);
}

void	valid_color(int col, t_all *all)
{
	if (col < 0 || col > 255)
		exit_error("Error\nerror color\n", 1, all);
}

int		write_color(t_all *all, t_color *color, char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	(color->red == -1 && str[i] != ',') ? color->red = ft_orn(&str[i])
		: exit_error("Error\nerror color\n", 1, all);
	valid_color(color->red, all);
	while (ft_isdigit(str[i]) || str[i] == ' ')
		i++;
	if ((color->blue == -1) && str[i++] == ',')
		color->blue = ft_orn(&str[i]);
	valid_color(color->blue, all);
	while (ft_isdigit(str[i]) || str[i] == ' ')
		i++;
	if ((color->green == -1) && str[i++] == ',')
		color->green = ft_orn(&str[i]);
	valid_color(color->green, all);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	i = space_digit(str, i);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	str[i] ? exit_error("Error\nsymbol before color\n", 1, all) : (0);
	return (0);
}

int		write_tex(t_all *all, int f, char *str)
{
	int	j;

	j = 0;
	f == 0 ? all->error.s++ : (0);
	f == 1 ? all->error.no++ : (0);
	f == 2 ? all->error.we++ : (0);
	f == 3 ? all->error.so++ : (0);
	f == 4 ? all->error.ea++ : (0);
	while (ft_isspace(str[j]))
		j++;
	if (!(all->tex[f].path))
		all->tex[f].path = str + j;
	else
		exit_error("Error\ndouble tex\n", 1, all);
	if (!(all->tex[f].img = mlx_xpm_file_to_image(all->mlx, str + j,
	&all->tex[f].width, &all->tex[f].heigth)))
		exit_error("Error\nerror tex\n", 1, all);
	all->tex[f].addr = mlx_get_data_addr(all->tex[f].img,
	&all->tex[f].bpr, &all->tex[f].ll,
	&all->tex[f].endian);
	return (0);
}
