#include "cube.h"

int		is_there_a_wall(int x, int y, t_data *data)
{
	(void)data;
	int map_grip_index_x = floor(x / 50);
	int map_grip_index_y = floor(y / 50);
	printf("->%d\n",map_grip_index_x);
	printf("->%d\n",map_grip_index_y);
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
		data.mlx = mlx_init();
		data.window = mlx_new_window(data.mlx, data.width, data.height, "cub3d");
    	ft_draw(&data);
		draw_player(&data);
		mlx_hook(data.window, 2, 0, ft_event, &data);
   		mlx_hook(data.window, 17, 0, ft_destroy, &data);
		mlx_loop(data.mlx);
		return (0);
	}
	else
		ft_putstr_fd("This program only accept .cub file as an argument", 2);
}