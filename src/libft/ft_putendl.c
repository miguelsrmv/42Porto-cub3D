/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:40:39 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/03 00:33:20 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 		Outputs the string ’s’ to the standard output, followed by a
**		newline.
*/

#include "libft.h"

void	ft_putendl(char *s)
{
	if (s)
	{
		ft_putstr(s);
		ft_putchar('\n');
	}
}
