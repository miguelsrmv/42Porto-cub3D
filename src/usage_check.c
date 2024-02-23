/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:42:18 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/23 20:38:26 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// @brief Check proper usage at Command Line Interface; exits if inappropriate
void	check_usage(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\n%s", USAGE_ERROR_MSG);
		exit(INVALID_USAGE);
	}
	if (ft_checkextension(argv[1], ".cub"))
	{
		printf("Error\n%s", USAGE_ERROR_MSG);
		exit(INVALID_FORMAT);
	}
}

/// @brief 		Check if file exists, has read permissions and is not a dir
/// @param file The input file
/// @return 	File descriptor of the valid file
int	check_file(char *file)
{
	int		file_fd;
	char	buffer[1];
	int		bytes_read;

	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
	{
		printf("Error\n");
		perror(file);
		exit(INVALID_FILE);
	}
	bytes_read = read(file_fd, buffer, 0);
	if (bytes_read == -1)
	{
		if (errno == EISDIR)
		{
			printf("Error\n");
			perror(file);
		}
		else
			perror(file);
		close(file_fd);
		exit(INVALID_FILE);
	}
	return (file_fd);
}
