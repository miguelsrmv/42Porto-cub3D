/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:05:58 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/17 13:24:40 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief 					Fills struct map_data with colours
void	check_floor_ceiling_texture(char **line_as_tab,
		t_map_data **map_data)
{
	char	**colours;

	colours = ft_split(line_as_tab[1], ',');
	if (!colours)
		exit_cub3(*map_data, MALLOC_ERROR_MSG);
	if (check_colours_tab(colours, map_data) == INVALID)
	{
		ft_free_tabs((void **)colours);
		exit_cub3(*map_data, HEADER_ERROR_MSG);
	}
	if (!ft_strcmp(line_as_tab[0], "F"))
	{
		(*map_data)->floor_color[0] = ft_atoi(colours[0]);
		(*map_data)->floor_color[1] = ft_atoi(colours[1]);
		(*map_data)->floor_color[2] = ft_atoi(colours[2]);
	}
	else if (!ft_strcmp(line_as_tab[0], "C"))
	{
		(*map_data)->ceiling_color[0] = ft_atoi(colours[0]);
		(*map_data)->ceiling_color[1] = ft_atoi(colours[1]);
		(*map_data)->ceiling_color[2] = ft_atoi(colours[2]);
	}
	ft_free_tabs((void **)colours);
}

/// @brief 				Validates colours' format & structure
enum e_HeaderType	check_colours_tab(char **colours_tab,
		t_map_data **map_data)
{
	int		colour_count;
	int		i;
	char	*colour;

	colour_count = 0;
	while (colours_tab[colour_count])
	{
		colour = ft_strtrim(colours_tab[colour_count], " \t");
		if (!colour)
			exit_cub3(*map_data, MALLOC_ERROR_MSG);
		i = 0;
		while (colour[i])
		{
			if (!ft_isdigit(colour[i++]))
			{
				free(colour);
				return (INVALID);
			}
		}
		colour_count++;
		free(colour);
	}
	if (colour_count == 3)
		return (VALID_INFO);
	return (INVALID);
}
