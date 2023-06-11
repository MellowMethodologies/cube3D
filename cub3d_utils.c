/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:22:05 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/11 23:23:22 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//----------------------------------------------------------------------------//

void	ft_abort(int id)
{
	if (id == 1)
		printf("\e[1;31mError in malloc!\n\e[0m");
	else if (id == 2)
		printf("\e[1;31mArgument please!\n\e[0m");
	exit(1);
}

//----------------------------------------------------------------------------//

int	ft_destroy(t_data *data)
{
	data = NULL;
	exit (0);
}

//----------------------------------------------------------------------------//

void	ft_end(int sig)
{
	(void)sig;
	exit (0);
}

//----------------------------------------------------------------------------//

// int check_wall_collision(t_data *data, t_vars *vars)
// {
// }

void draw_player(t_data	*data)
{
	mlx_put_pixel(data->image ,data->p_x - 1, data->p_y, 0x00FF0000);
	mlx_put_pixel(data->image , data->p_x , data->p_y - 1, 0x00FF0000);
	mlx_put_pixel(data->image , data->p_x, data->p_y + 1, 0x00FF0000);
	mlx_put_pixel(data->image , data->p_x + 1, data->p_y, 0x00FF0000);
	mlx_put_pixel(data->image , data->a_x - 1, data->a_y, 0x003300FF);
	mlx_put_pixel(data->image , data->a_x , data->a_y - 1, 0x003300FF);
	mlx_put_pixel(data->image , data->a_x, data->a_y + 1, 0x003300FF);
	mlx_put_pixel(data->image , data->a_x + 1, data->a_y, 0x003300FF);
}

void		ft_event(void *dat)
{
	double dx;
	double dy;
	t_data *data= dat;

	dx = data->dis_bt_a_p * cos(data->p_rad);
	dy = data->dis_bt_a_p * sin(data->p_rad);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		exit (0);
	if (!is_there_a_wall(data->p_x + 2 * cos(data->p_rad), data->p_y + 2 * sin(data->p_rad), data) && (mlx_is_key_down(data->mlx, MLX_KEY_UP)))
	{
		//up arrow
		data->p_y += 2 * sin(data->p_rad);
		data->p_x += 2 * cos(data->p_rad);
		data->a_x = data->p_x + dx;
		data->a_y = data->p_y + dy;
	}
	if (!is_there_a_wall(data->p_x - 2 * cos(data->p_rad), data->p_y - 2 * sin(data->p_rad), data) && (mlx_is_key_down(data->mlx, MLX_KEY_DOWN)))
	{
		//down arrow
		data->p_y -= 2 * sin(data->p_rad);
		data->p_x -= 2 * cos(data->p_rad);
		data->a_x = data->p_x + dx;
		data->a_y = data->p_y + dy;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		//right arrow
		data->p_rad += M_PI / 30;
		//rotation angle 15degree to the left
		data->a_x = data->p_x + dx;
		data->a_y = data->p_y + dy;
	}
	
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
	   // left arrow
		data->p_rad -= M_PI / 30;

		data->a_x = data->p_x + dx;
		data->a_y = data->p_y + dy;
	}
	mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, data->width,data->height);
   	ft_draw(data);
   	draw_player(data);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	// return 1;
}

//----------------------------------------------------------------------------//