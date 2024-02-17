/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:15:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/17 13:18:43 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_cub3(t_map_data *map_data,
			char *message)
{
	clean_map_data(map_data);
	if (!ft_strcmp(message, MALLOC_ERROR_MSG))
	{
		ft_fprintf(STDERR_FILENO, "Error\n");
		perror(message);
		exit(errno);
	}
	else
	{
		ft_fprintf(STDERR_FILENO, "Error\n");
		printf("%s", message);
		exit(EXIT_FAILURE);
	}
}

void	clean_map_data(t_map_data *map_data)
{
	if (map_data)
	{
		close(map_data->file_fd);
		if (map_data->north_texture)
			free(map_data->north_texture);
		if (map_data->south_texture)
			free(map_data->south_texture);
		if (map_data->west_texture)
			free(map_data->west_texture);
		if (map_data->east_texture)
			free(map_data->east_texture);
		free(map_data);
	}
}
