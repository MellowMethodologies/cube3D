#include "cube.h"

int		is_there_a_wall(int x, int y, t_data *data)
{
	(void)data;
	int map_grip_index_x = floor(x / 50);
	int map_grip_index_y = floor(y / 50);
	if(data->str[map_grip_index_y][map_grip_index_x] == '1')
		return 1;
	return 0;
}

int	main(int ac, char **av)
{
	t_data	data;
	t_vars	vars;

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
    	ft_draw(&data);
		draw_player(&data);
		mlx_loop_hook(data.mlx,ft_event, &data);
		mlx_loop(data.mlx);
		return (0);
	}
	else
		ft_putstr_fd("This program only accept .cub file as an argument", 2);
}