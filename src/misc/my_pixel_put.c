/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:33:31 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/08 16:30:12 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief My pixel put
void	my_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*target;

	target = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)target = color;
}

/// @brief Converts RGB to int for minilibx
int	convert_rgb_to_int(int *RGB)
{
	return ((RGB[0] << 16) | (RGB[1] << 8) | RGB[2]);
}
