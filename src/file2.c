/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 06:01:50 by Kcaraway          #+#    #+#             */
/*   Updated: 2020/11/04 04:24:40 by kcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map_val	*free_list(t_map_val *list, t_all *all)
{
	t_map_val	*cpy;

	while (list)
	{
		if (list->line)
			free(list->line);
		cpy = list;
		list = list->next;
		free(cpy);
	}
	exit_error("Error\nmalloc list\n", 1, all);
	return (0);
}

t_map_val	*new_list_map(t_map_val *list, char *line, t_all *all)
{
	t_map_val	*cpy;
	t_map_val	*new;

	if (!(new = (t_map_val *)malloc(sizeof(t_map_val))))
		return (free_list(list, all));
	new->line = line;
	new->next = NULL;
	cpy = list;
	if (cpy == NULL)
		return (new);
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = new;
	return (list);
}

int			valid_map(t_map map, int y, int x)
{
	int		i;
	int		j;

	i = y;
	j = x;
	while (map.line[i][j] != '1' && map.line[i][j] != ' '
	&& i < (int)map.max.y - 1)
		i++;
	if (map.line[i][j] != '1')
		return (0);
	i = y;
	while (map.line[i][j] != '1' && map.line[i][j] != ' ' && i > 0)
		i--;
	if (map.line[i][j] != '1')
		return (0);
	i = y;
	while (map.line[i][j] != '1' && map.line[i][j] != ' ' && j < (int)map.max.x)
		j++;
	if (map.line[i][j] != '1')
		return (0);
	j = x;
	while (map.line[i][j] != '1' && map.line[i][j] != ' ' && j > 0)
		j--;
	return (map.line[i][j] == '1');
}

void		validate_map(t_map map, t_all *all)
{
	int	y;
	int x;

	y = 0;
	while (map.line[y])
	{
		x = 0;
		while (x < (int)map.max.x && map.line[y][x])
		{
			if (map.line[y][x] == '0' || map.line[y][x] == 'N'
			|| map.line[y][x] == 'E' || map.line[y][x] == 'S'
			|| map.line[y][x] == 'W' || map.line[y][x] == '2')
			{
				if (!(valid_map(map, y, x)))
					exit_error("Error\nInvalid map\n", 1, all);
			}
			else if (map.line[y][x] != ' ' && map.line[y][x] != '1'
				&& map.line[y][x] != '2')
			{
				exit_error("Error\nNo map symbols\n", 1, all);
			}
			x++;
		}
		y++;
	}
}

void		valid_res(t_all *all, int save)
{
	if (all->res.x <= 0 || all->res.y <= 0)
		exit_error("Error\nerror resolution\n", 1, all);
	if (!save)
	{
		if (all->res.x > RES_X)
			all->res.x = RES_X;
		if (all->res.y > RES_Y)
			all->res.y = RES_Y;
	}
	else
	{
		if (all->res.x > 20000)
			all->res.x = 20000;
		if (all->res.y > 20000)
			all->res.y = 20000;
	}
}
