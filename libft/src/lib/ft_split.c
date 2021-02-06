/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 10:23:11 by boomblee          #+#    #+#             */
/*   Updated: 2020/05/25 17:53:33 by boomblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	quantity_str(char const *s, char c)
{
	size_t quantity;
	size_t flag;

	flag = 0;
	quantity = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		else if (!flag)
		{
			flag = 1;
			quantity++;
		}
		s++;
	}
	return (quantity);
}

size_t	quantity_symbol(char const *s, char c, size_t i)
{
	size_t res;

	res = 0;
	while (s[i] && s[i] != c)
	{
		res++;
		i++;
	}
	return (res);
}

char	**free_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**str;
	size_t	q;
	size_t	k;

	i = 0;
	if (!s)
		return (NULL);
	q = quantity_str(s, c);
	if (!(str = ft_calloc(q + 1, sizeof(char *))))
		return (NULL);
	k = 0;
	while (s[i] && k < q)
	{
		while (s[i] == c)
			i++;
		if (!(str[k] = ft_substr(s, i, quantity_symbol(s, c, i))))
			return (free_str(str));
		i += quantity_symbol(s, c, i);
		k++;
	}
	return (str);
}
