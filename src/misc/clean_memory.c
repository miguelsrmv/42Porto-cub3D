/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:15:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/05/13 12:35:21 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_cub3(t_map_data *map_data,
			char *message)
{
	clean_data(map_data, NULL);
	get_next_line(-1);
	if (!ft_strcmp(message, MALLOC_ERROR_MSG)
		|| !ft_strcmp(message, FILE_ERROR_MSG)
		|| !ft_strcmp(message, TEXTURE_ERROR_MSG))
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

void	clean_data(t_map_data *map_data, t_vector_data *vector_data)
{
	if (map_data)
	{
		close(map_data->file_fd);
		if (map_data->window_title)
			free(map_data->window_title);
		if (map_data->textr_path[NORTH])
			free(map_data->textr_path[NORTH]);
		if (map_data->textr_path[SOUTH])
			free(map_data->textr_path[SOUTH]);
		if (map_data->textr_path[EAST])
			free(map_data->textr_path[EAST]);
		if (map_data->textr_path[WEST])
			free(map_data->textr_path[WEST]);
		if (map_data->map_buffer)
			free(map_data->map_buffer);
		if (map_data->map_tab)
			ft_free_tabs((void **)map_data->map_tab);
		free(map_data);
	}
	if (vector_data)
		free(vector_data);
}

void	clean_mlx(t_cube *cube)
{
	int	i;

	mlx_destroy_image(cube->mlx, (cube->image.img));
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(cube->mlx, cube->map_data->texture[i].img);
		i++;
	}
	mlx_destroy_window(cube->mlx, cube->mlx_window);
	mlx_destroy_display(cube->mlx);
	free(cube->mlx);
}
