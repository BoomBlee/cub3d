/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.21-school.r>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 02:39:04 by boomblee          #+#    #+#             */
/*   Updated: 2020/11/01 05:38:18 by kcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <string.h>
# define BUFFER_SIZE 1

typedef	struct	s_gnl
{
	int			size;
	int			error;
	char		*pointer;
}				t_gnl;

int				get_next_line(int fd, char **line);

#endif
