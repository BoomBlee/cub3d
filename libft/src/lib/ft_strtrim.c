/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 06:20:00 by boomblee          #+#    #+#             */
/*   Updated: 2020/05/17 09:29:30 by boomblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		k;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	k = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (k > -1)
		while (s1[k] && ft_strchr(set, s1[k]))
			k--;
	if (i > k)
		return (ft_strdup(""));
	str = ft_substr(s1, i, k - i + 1);
	return (str);
}
