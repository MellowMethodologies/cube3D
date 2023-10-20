/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:45:29 by sbadr             #+#    #+#             */
/*   Updated: 2023/07/28 11:08:10 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

int	is_there_a_wall_1(double x, double y, t_data *data)
{
	size_t	map_grip_index_y;
	size_t	map_grip_index_x;

	if (x < 0 || y < 0)
		return (1);
	map_grip_index_x = floor(x / TILE_SIZE);
	map_grip_index_y = floor(y / TILE_SIZE);
	if (map_grip_index_y > data->count
		|| ft_strlen(data->str[map_grip_index_y]) <= map_grip_index_x)
		return (1);
	if (data->str[map_grip_index_y][map_grip_index_x] == '1'
			|| data->str[map_grip_index_y][map_grip_index_x] == '1')
		return (1);
	return (0);
}

int	is_there_a_wall(double x, double y, t_data *data)
{
	size_t	map_grip_index_y;
	size_t	map_grip_index_x_1;
	size_t	map_grip_index_x_;
	size_t	map_grip_index_x;

	if (x < 0 || y < 0)
		return (1);
	map_grip_index_x = floor((x + 5) / TILE_SIZE);
	map_grip_index_x_ = floor((x - 5) / TILE_SIZE);
	map_grip_index_x_1 = floor(x / TILE_SIZE);
	map_grip_index_y = floor(y / TILE_SIZE);
	if (map_grip_index_y > data->count
		|| ft_strlen(data->str[map_grip_index_y]) <= map_grip_index_x)
		return (1);
	if (data->str[map_grip_index_y][map_grip_index_x_] == '1'
			|| data->str[map_grip_index_y][map_grip_index_x_] == '1'
			|| data->str[map_grip_index_y][map_grip_index_x_1] == '1')
		return (1);
	return (0);
}

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_vars	vars;

	data.vars = &vars;
	if (ac == 2)
	{
		if (ft_strncmp(".cub", av[1] + (ft_strlen(av[1]) - 4), 4))
		{
			ft_putstr_fd("Error!\ncheck the extension of your map", 2);
			exit(1);
		}
		parser(av[1], &vars);
		ft_textures(&data, &vars);
		mlx_set_setting(MLX_MAXIMIZED, true);
		data.mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
		data.image = mlx_new_image(data.mlx, WIDTH, HEIGHT);
		mlx_loop_hook(data.mlx, ft_event, &data);
		mlx_loop(data.mlx);
		return (0);
	}
	else
		ft_putstr_fd("This program only accept .cub file as an argument", 2);
}
