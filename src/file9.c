/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 06:01:41 by Kcaraway          #+#    #+#             */
/*   Updated: 2020/11/01 06:28:49 by kcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rendering_spr(t_all *all, int save)
{
	int	i;

	i = 0;
	ft_sprite(all);
	sort_spr(all);
	while (i < all->count_sprite)
	{
		draw_sprite(all, all->sprite[i]);
		i++;
	}
}

void	ft_bmp_header(t_all all, int fd)
{
	int		t;
	short	d;

	write(fd, "BM", 2);
	t = 14 + 40 + (int)all.res.y * (int)all.res.x * 4;
	write(fd, &t, sizeof(t));
	d = 0;
	write(fd, &d, sizeof(d));
	write(fd, &d, sizeof(d));
	t = 14 + 40;
	write(fd, &t, sizeof(t));
}

void	ft_image_header(t_all all, int fd)
{
	int		t;
	short	d;

	t = 40;
	write(fd, &t, sizeof(t));
	t = (int)all.res.x;
	write(fd, &t, sizeof(t));
	t = (int)all.res.y;
	write(fd, &t, sizeof(t));
	d = 1;
	write(fd, &d, sizeof(d));
	d = 32;
	write(fd, &d, sizeof(d));
	t = 0;
	write(fd, &t, sizeof(t));
	t = (int)all.res.x * (int)all.res.y * 4;
	write(fd, &t, sizeof(t));
	t = 2795;
	write(fd, &t, sizeof(t));
	write(fd, &t, sizeof(t));
	t = 0;
	write(fd, &t, sizeof(t));
	write(fd, &t, sizeof(t));
}

void	ft_bmp(t_all all)
{
	int		fd;
	char	*img;
	int		i;

	i = all.res.y;
	fd = open("screen.bmp", O_RDWR | O_CREAT | O_TRUNC, 00666);
	if (fd < 0)
		exit_error("Error\nerror fd\n", 1, &all);
	ft_bmp_header(all, fd);
	ft_image_header(all, fd);
	img = all.data.addr;
	while (i-- > 1)
		img += (int)all.res.x * 4;
	while (i < all.res.y)
	{
		write(fd, img, (int)all.res.x * 4);
		img -= (int)all.res.x * 4;
		i++;
	}
	close(fd);
}

void	valid_name_file(char *name)
{
	int i;

	i = ft_strlen(name);
	if (ft_strncmp(".cub", &name[i - 4], 4))
	{
		ft_putstr_fd("Error\nerror file name\n", 1);
		exit(1);
	}
}
