/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:27:52 by bmota-si          #+#    #+#             */
/*   Updated: 2024/02/13 18:01:39 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

long	ft_atol(const char *str)
{
	long long	n;
	int			sign;
	int			digit;

	n = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (ft_issign(*str))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (sign == 1 && n > (LONG_MAX - digit) / 10)
			return (LONG_MAX);
		else if (sign == -1 && (-n) < (LONG_MIN + digit) / 10)
			return (LONG_MIN);
		n = n * 10 + digit;
		str++;
	}
	return (n * sign);
}
