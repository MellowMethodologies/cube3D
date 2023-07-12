#include "./includes/cube.h"

int		is_there_a_wall(double x, double y, t_data *data)
{
	(void)data;
	if (x > data->width || y > data->height || x < 0 || y < 0)
		return 1;
	size_t map_grip_index_x = x / TILE_SIZE;
	size_t map_grip_index_x1 = (x + 1) / TILE_SIZE;
	size_t map_grip_index_x2 = (x - 1) / TILE_SIZE;
	size_t map_grip_index_y = y / TILE_SIZE;
	size_t map_grip_index_y1 = (y + 1) / TILE_SIZE;
	size_t map_grip_index_y2 = (y - 1) / TILE_SIZE;
	if (map_grip_index_y > data->height / TILE_SIZE || ft_strlen(data->str[map_grip_index_y]) <= map_grip_index_x )
		return 1;
	if (data->str[map_grip_index_y][map_grip_index_x] && (data->str[map_grip_index_y][map_grip_index_x] == '1' 
	|| data->str[map_grip_index_y][map_grip_index_x2] == '1' || data->str[map_grip_index_y][map_grip_index_x1] == '1' \
	|| data->str[map_grip_index_y1][map_grip_index_x] == '1' || data->str[map_grip_index_y2][map_grip_index_x] == '1'))
		return 1;
	return 0;
}

int		is_there_a_wall_1(double x, double y, t_data *data)
{
	(void)data;
	if (x > data->width || y > data->height || x < 0 || y < 0)
		return 1;
	size_t map_grip_index_x = x / TILE_SIZE;
	size_t map_grip_index_y = y / TILE_SIZE;
	if (map_grip_index_y >= data->count || ft_strlen(data->str[map_grip_index_y]) < map_grip_index_x)
		return 1;
	if (data->str[map_grip_index_y][map_grip_index_x] == '1' || data->str[map_grip_index_y][map_grip_index_x] == ' ')
		return 1;
	return 0;
}

void error(void)
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
		if (ft_strncmp(".cub", av[1] + (ft_strlen(av[1]) - 4), 4) != 0)
		{
			ft_putstr_fd("Error!\ncheck the extension of your map", 2);
			exit(1);
		}
		parser(av[1], &vars);
   		signal(SIGINT, ft_end);
   		ft_textures(&data, &vars);
		mlx_set_setting(MLX_MAXIMIZED, true);
		data.mlx = mlx_init(data.width, data.height, "cub3D", false);
		data.image = mlx_new_image(data.mlx, data.width,data.height);
		data.map = mlx_new_image(data.mlx, 250, 250);
		mlx_loop_hook(data.mlx,ft_event, &data);
		mlx_loop(data.mlx);
		return (0);
	}
	else
		ft_putstr_fd("This program only accept .cub file as an argument", 2);
}
