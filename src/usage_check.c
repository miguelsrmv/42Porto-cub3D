/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:42:18 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/23 09:30:08 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Check proper usage at Command Line Interface, exits if inappropriate
void	check_usage(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_fprintf(STDERR_FILENO, "Error\n");
		ft_fprintf(STDERR_FILENO, USAGE_ERROR_MSG);
		exit(INVALID_USAGE);
	}
	if (ft_checkextension(argv[1], ".cub"))
	{
		ft_fprintf(STDERR_FILENO, "Error\n");
		ft_fprintf(STDERR_FILENO, USAGE_ERROR_MSG);
		exit(INVALID_FORMAT);
	}
}

/// @brief 		Check if file exists, has read permissions and is not a dir
/// @param file The input file
/// @return 	File descriptor of the valid file
int	check_file(char *file)
{
	int		file_fd;

	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
	{
		ft_fprintf(STDERR_FILENO, "Error\n");
		ft_fprintf(STDERR_FILENO, "(%s) ", file);
		perror(FILE_ERROR_MSG);
		exit(INVALID_FILE);
	}
	return (file_fd);
}
