/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcaraway <kcaraway@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 06:46:33 by boomblee          #+#    #+#             */
/*   Updated: 2020/05/25 11:22:06 by boomblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int res;
	int minus;

	res = 0;
	minus = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (!(ft_memcmp(nptr, "-2147483648", 11)))
		return (-2147483648);
	if (*nptr == '-')
		minus = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
		if (res < 0 && minus == -1)
			return (0);
		else if (res < 0)
			return (-1);
	}
	return (res * minus);
}
