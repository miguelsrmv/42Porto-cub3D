/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_expander.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:13:32 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/04/27 18:01:26 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	expand_map(t_map_data **map_data)
{
	char	**expanded_map;
	int		i;

	(*map_data)->map_height
		= (((*map_data)->map_height - 2) * STEPS_PER_TILE) + 2;
	(*map_data)->map_width
		= (((*map_data)->map_width - 2) * STEPS_PER_TILE) + 2;
	expanded_map = (char **)malloc(sizeof(char *) * (*map_data)->map_height);
	if (!expanded_map)
		exit_cub3(*map_data, MALLOC_ERROR_MSG);
	i = 0;
	while (i < (*map_data)->map_height)
	{
		expanded_map[i] = (char *)malloc(sizeof(char) * (*map_data)->map_width);
		if (!expanded_map[i])
		{
			ft_free_tabs((void **)expanded_map);
			exit_cub3(*map_data, MALLOC_ERROR_MSG);
		}
		i++;
	}
	fill_in_larger_map(expanded_map, (*map_data)->map_tab);
	ft_free_tabs((void **)(*map_data)->map_tab);
	(*map_data)->map_tab = expanded_map;
}

void	fill_in_larger_map(char **expanded_map, char **map_tab)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (map_tab[i])
	{
		count = 0;
		if (i == 0 || !map_tab[i + 1])
		{
			expand_width(expanded_map[j], map_tab[i]);
			j++;
		}
		else
		{
			while (count < STEPS_PER_TILE)
			{
				expand_width(expanded_map[j + count], map_tab[i]);
				count++;
			}
			j += count;
		}
		i++;
	}
	expanded_map[j] = NULL;
}

void	expand_width(char *expanded_string, char *string)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (string[i])
	{
		count = 0;
		if (i == 0 || !string[i + 1])
			expanded_string[j++] = string[i];
		else
		{
			while (count++ < STEPS_PER_TILE)
				expanded_string[j++] = string[i];
		}
		i++;
	}
	expanded_string[j] = '\0';
}
