/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 06:47:20 by boomblee          #+#    #+#             */
/*   Updated: 2020/05/16 06:19:46 by boomblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (dst[k] && k < size)
		k++;
	i = k;
	while (src[k - i] && k < size - 1)
	{
		dst[k] = src[k - i];
		k++;
	}
	dst[k] = '\0';
	return (i + ft_strlen(src));
}
