/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:22:05 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/11 17:42:27 by sbadr            ###   ########.fr       */
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
	mlx_pixel_put(data->mlx, data->window, data->p_x - 1, data->p_y, 0x00FF0000);
	mlx_pixel_put(data->mlx, data->window, data->p_x , data->p_y - 1, 0x00FF0000);
	mlx_pixel_put(data->mlx, data->window, data->p_x, data->p_y + 1, 0x00FF0000);
	mlx_pixel_put(data->mlx, data->window, data->p_x + 1, data->p_y, 0x00FF0000);
	mlx_pixel_put(data->mlx, data->window, data->a_x - 1, data->a_y, 0x003300FF);
	mlx_pixel_put(data->mlx, data->window, data->a_x , data->a_y - 1, 0x003300FF);
	mlx_pixel_put(data->mlx, data->window, data->a_x, data->a_y + 1, 0x003300FF);
	mlx_pixel_put(data->mlx, data->window, data->a_x + 1, data->a_y, 0x003300FF);
}

int		ft_event(int keycode, t_data *data)
{
	double dx;
	double dy;

	dx = data->dis_bt_a_p * cos(data->p_rad);
	dy = data->dis_bt_a_p * sin(data->p_rad);
	if (keycode == 53)
		exit (0);
	if (!is_there_a_wall(data->p_x + 2 * cos(data->p_rad), data->p_y + 2 * sin(data->p_rad), data) && (keycode == 13 || keycode == 126))
	{
		//up arrow
		data->p_y += 2 * sin(data->p_rad);
		data->p_x += 2 * cos(data->p_rad);
		data->a_x = data->p_x + dx;
		data->a_y = data->p_y + dy;
	}
	if (!is_there_a_wall(data->p_x - 2 * cos(data->p_rad), data->p_y - 2 * sin(data->p_rad), data) && (keycode == 1 || keycode == 125))
	{
		//down arrow
		data->p_y -= 2 * sin(data->p_rad);
		data->p_x -= 2 * cos(data->p_rad);
		data->a_x = data->p_x + dx;
		data->a_y = data->p_y + dy;
	}
	if (keycode == 0 || keycode == 123)
	{
		//right arrow
		data->p_rad -= M_PI / 12;
		//rotation angle 15degree to the left
		data->a_x = data->p_x + dx;
		data->a_y = data->p_y + dy;
	}
	
	if (keycode == 2 || keycode == 124)
	{
	   // left arrow
		data->p_rad += M_PI / 12;

		data->a_x = data->p_x + dx;
		data->a_y = data->p_y + dy;
	}
   	ft_draw(data);
   	draw_player(data);
	return (1);
}

//----------------------------------------------------------------------------//