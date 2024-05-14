/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabashee <aabashee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:25:33 by mfirdous          #+#    #+#             */
/*   Updated: 2024/05/14 20:52:28 by aabashee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_img		img;
	t_player	p;
	t_map		map;
	t_keys		keys;

	init_data(&map);// initialize the game data.
	parsing(argc, argv, &map, &p);	// Parse the command-line arguments and the map file.
	mlx.img = &img;// Set up the MLX library and create the game window.
	mlx.p = &p;
	mlx.map = &map;
	mlx.keys = &keys;

	return (0);
}
