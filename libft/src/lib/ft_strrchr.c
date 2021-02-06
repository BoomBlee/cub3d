/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 06:47:30 by boomblee          #+#    #+#             */
/*   Updated: 2020/05/22 12:42:17 by boomblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	char	*str;

	str = NULL;
	while (*string)
	{
		if (*string == (char)symbol)
			str = (char *)string;
		string++;
	}
	if ((char)symbol == '\0')
		str = (char *)string;
	return (str);
}
