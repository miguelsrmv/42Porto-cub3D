/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:05:58 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/23 20:45:42 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Fills struct map_data with colours
void	check_floor_ceiling_texture(char **line_as_tab,
		t_map_data **map_data)
{
	char	**colours;

	if (ft_tablen((void **)line_as_tab) > 2)
		unite_colours(line_as_tab);
	colours = ft_split(line_as_tab[1], ',');
	if (!colours)
	{
		ft_free_tabs((void **)line_as_tab);
		exit_cub3(*map_data, MALLOC_ERROR_MSG);
	}
	if (check_colours_tab(colours) == INVALID)
	{
		ft_free_tabs((void **)line_as_tab);
		ft_free_tabs((void **)colours);
		exit_cub3(*map_data, COLOUR_ERROR_MSG);
	}
	if (!ft_strcmp(line_as_tab[0], "F"))
		fill_in_colours((*map_data)->floor_color, colours);
	else if (!ft_strcmp(line_as_tab[0], "C"))
		fill_in_colours((*map_data)->ceiling_color, colours);
	ft_free_tabs((void **)colours);
	ft_free_tabs((void **)line_as_tab);
}

/// @brief Unites all colour values into one single formated string ("R,G,B")
void	unite_colours(char **line_as_tab)
{
	char	*joined_tab;
	char	*temp;
	int		i;

	i = 1;
	joined_tab = (char *)malloc(sizeof(char) * 1);
	joined_tab[0] = '\0';
	while (line_as_tab[i])
	{
		temp = joined_tab;
		joined_tab = ft_strjoin(joined_tab, line_as_tab[i]);
		if (temp)
			free(temp);
		i++;
	}
	i = 1;
	while (line_as_tab[i])
	{
		free(line_as_tab[i]);
		if (i == 1)
			line_as_tab[i] = joined_tab;
		i++;
	}
}

/// @brief Checks if colours only contain digits
/// @param colours is line_as_tab after unite_colours() processing
enum e_HeaderType	check_colours_tab(char **colours)
{
	int		colour_count;
	int		i;

	colour_count = 0;
	while (colours[colour_count])
	{
		i = 0;
		while (colours[colour_count][i])
		{
			if (!ft_isdigit(colours[colour_count][i++]))
				return (INVALID);
		}
		colour_count++;
	}
	if (colour_count == 3)
		return (VALID_INFO);
	return (INVALID);
}

/// @brief			Fills in colors ou map_data
/// @param color 	Color array on map_data struct
void	fill_in_colours(int *color, char **colours)
{
	color[0] = ft_atoi(colours[0]);
	color[1] = ft_atoi(colours[1]);
	color[2] = ft_atoi(colours[2]);
}

/// @brief Checks if colours are within normal range
void	check_colour_values(t_map_data **map_data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if ((*map_data)->ceiling_color[i] < 0
			|| (*map_data)->ceiling_color[i] > 255)
			exit_cub3(*map_data, COLOUR_ERROR_MSG);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if ((*map_data)->floor_color[i] < 0
			|| (*map_data)->floor_color[i] > 255)
			exit_cub3(*map_data, COLOUR_ERROR_MSG);
		i++;
	}
}
