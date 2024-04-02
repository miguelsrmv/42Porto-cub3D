/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:36:23 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/03 00:34:48 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  The fputc() function writes the character c (converted to an ``unsigned
**	char'') to the output stream pointed to by stream.
**  42 PDF] Outputs the character ’c’ to the standard output.
*/

#include "libft.h"

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}
