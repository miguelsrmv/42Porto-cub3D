/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:39:16 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/26 16:58:41 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	test_map_data(t_map_data *map_data)
{
	ft_printf("File Fd:\t%i\n", map_data->file_fd);
	ft_printf("North texture:\t%s\n", map_data->north_texture);
	ft_printf("South texture:\t%s\n", map_data->south_texture);
	ft_printf("East texture:\t%s\n", map_data->east_texture);
	ft_printf("West texture:\t%s\n", map_data->west_texture);
	ft_printf("Floor:\t\t%i,%i,%i\n", map_data->floor_color[0],
		map_data->floor_color[1], map_data->floor_color[2]);
	ft_printf("Ceiling:\t%i,%i,%i\n", map_data->ceiling_color[0],
		map_data->ceiling_color[1], map_data->ceiling_color[2]);
}

void	test_tab_data(t_map_data *map_data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	printf("Here's the tabbed data:\n\n");
	while (map_data->map_tab[y])
	{
		x = 0;
		while (map_data->map_tab[y][x])
		{
			printf("%c", map_data->map_tab[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n\nPlayer starting position is:\n");
	printf("X: %i\n", map_data->start_pos[1]);
	printf("Y: %i\n", map_data->start_pos[0]);
	printf("Orientation: %c\n\n", map_data->cardinal_direction);
}
