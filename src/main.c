/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:12:46 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/02/13 18:52:55 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_usage(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return ;
}

void	check_map(char *file)
{
	(void)file;
	return ;
}

void	run_cub3d(char *file)
{
	(void)file;
	return ;
}

int	main(int argc, char **argv)
{
	check_usage(argc, argv);
	check_map(argv[1]);
	run_cub3d(argv[1]);
	return (SUCCESS);
}
