/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 06:18:23 by Kcaraway          #+#    #+#             */
/*   Updated: 2020/11/01 05:31:13 by kcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	exit_error(char *str, int errno, t_all *all)
{
	ft_putstr_fd(str, 0);
	exit(errno);
}

int		start_map(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0' && ft_strchr(" 012", str[i]))
	{
		return (1);
	}
	return (0);
}

t_map	read_map(int all_fd, char *str, char *file, t_all *all)
{
	t_map	map;
	int		line;
	int		gnl;
	int		i;

	i = 0;
	all->list = new_list_map(all->list, str, all);
	map.max.x = ft_strlen(str);
	line = 1;
	while ((gnl = get_next_line(all_fd, &str)) >= 0)
	{
		!str[0] ? exit_error("Error\nempty line\n", 1, all) : (0);
		map.max.x = map.max.x >= ft_strlen(str) ? map.max.x : ft_strlen(str);
		all->list = new_list_map(all->list, str, all);
		line++;
		if (!gnl)
			break ;
	}
	map.max.y = line;
	if (!(map.line = malloc(sizeof(char *) * (line + 1))))
		exit_error("Error\nmalloc map.line\n", 1, all);
	map.line = map_space(map, all);
	map.quantity = count_sprite(map);
	validate_map(map, all);
	return (map);
}

char	**map_space(t_map map, t_all *all)
{
	int			i;
	int			j;
	char		*line;
	t_map_val	*cpy;

	i = -1;
	cpy = all->list;
	while (++i < (int)map.max.y)
	{
		line = cpy->line;
		j = ft_strlen(line);
		if (!(map.line[i] = malloc(sizeof(char) * (map.max.x + 1))))
			exit_error("Error\nmalloc map.line[i]\n", 1, all);
		map.line[i] = ft_memcpy(map.line[i], line, j);
		while (map.max.x > j)
		{
			map.line[i][j] = ' ';
			j++;
		}
		map.line[i][j] = '\0';
		cpy = cpy->next;
	}
	map.line[i] = NULL;
	return (map.line);
}

int		count_sprite(t_map map)
{
	int i;
	int j;
	int count;

	count = 0;
	i = 0;
	map.quantity = 0;
	while (map.line[i])
	{
		j = 0;
		while (map.line[i][j])
		{
			if (map.line[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
