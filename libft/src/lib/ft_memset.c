/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 06:45:26 by boomblee          #+#    #+#             */
/*   Updated: 2020/05/25 11:08:51 by boomblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *str, int value, size_t num)
{
	size_t	i;
	char	*s;

	i = 0;
	s = str;
	while (i < num)
		s[i++] = (char)value;
	return (s);
}
