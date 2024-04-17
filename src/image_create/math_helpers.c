/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:46:35 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/17 11:51:53 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	degrees_to_radians(int degrees)
{
	return (degrees * M_PI / 180.0);
}

int	radians_to_degrees(double radians)
{
	return (radians * (180.0 / M_PI));
}
