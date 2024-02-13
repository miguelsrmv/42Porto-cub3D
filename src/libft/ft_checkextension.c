/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkextension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:09:35 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/13 21:23:26 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkextension(const char *str, const char *suffix)
{
	size_t		str_len;
	size_t		suffix_len;
	const char	*str_end;

	str_len = ft_strlen(str);
	suffix_len = ft_strlen(suffix);
	if (str_len < suffix_len)
		return (1);
	str_end = str + (str_len - suffix_len);
	return (ft_strcmp(str_end, suffix));
}
