/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 06:47:25 by boomblee          #+#    #+#             */
/*   Updated: 2020/05/14 06:47:28 by boomblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	char *str;

	str = (char *)string;
	while (*str != symbol)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}
