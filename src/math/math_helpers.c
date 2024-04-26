/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:46:35 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/26 14:18:44 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Transforms value in degrees into radians
double	degrees_to_radians(int degrees)
{
	return (degrees * M_PI / 180.0);
}

/// @brief Transforms value in radians into degrees
double	radians_to_degrees(double radians)
{
	return (radians * (180.0 / M_PI));
}

/// @brief Gives multiple of "multiple" that's immediately higher than "value"
double	next_multiple(double value, int multiple)
{
	double	quotient;
	double	next_multiple;

	quotient = (double)value / multiple;
	next_multiple = (multiple * (int)(quotient + 1));
	return (next_multiple);
}

/// @brief Gives multiple of "multiple" that's immediately lower than "value"
double	previous_multiple(double value, int multiple)
{
	double	quotient;
	double	previous_multiple;

	quotient = (double)value / multiple;
	previous_multiple = (multiple * (int)quotient);
	return (previous_multiple);
}

/// @brief Gives the absolute difference between two values
int	int_abs_difference(int value_1, int value_2)
{
	if (abs(value_1) > abs(value_2))
		return (abs(value_1) - abs(value_2));
	else
		return (abs(value_2) - abs(value_1));
}
