/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 06:45:41 by boomblee          #+#    #+#             */
/*   Updated: 2020/05/22 11:44:58 by boomblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = dest;
	s = (char *)src;
	i = 0;
	if (!src && !dest)
		return (NULL);
	if (s < d)
	{
		while (i < n)
		{
			i++;
			d[n - i] = s[n - i];
		}
	}
	else
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	return (dest);
}
