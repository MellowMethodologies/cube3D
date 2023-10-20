/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:27:17 by sbadr             #+#    #+#             */
/*   Updated: 2023/07/26 16:02:11 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

void	ft_hooks(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		exit (0);
	mlx_get_mouse_pos(data->mlx, &data->mouse_x, &data->mouse_y);
	if (data->mouse_x > data->mouse_x_old && *data->a == 0)
		data->p_rad += 0.05;
	else if (data->mouse_x < data->mouse_x_old && *data->a == 0)
		data->p_rad -= 0.05;
	if (!is_there_a_wall(data->p_x + ACC * cos(data->p_rad),
			data->p_y + ACC * sin(data->p_rad),
			data) && mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		data->p_y += sin(data->p_rad) * ACC;
		data->p_x += cos(data->p_rad) * ACC;
	}
	if (!is_there_a_wall(data->p_x - ACC * cos(data->p_rad),
			data->p_y - ACC * sin(data->p_rad),
			data) && mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		data->p_y -= sin(data->p_rad) * ACC;
		data->p_x -= cos(data->p_rad) * ACC;
	}
}

void	ft_hooks_(t_data *data)
{
	if (!is_there_a_wall(data->p_x + ACC * cos(data->p_rad + M_PI / 2),
			data->p_y + ACC * sin(data->p_rad + M_PI / 2), data)
		&& mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		data->p_y += sin(data->p_rad + M_PI / 2) * ACC;
		data->p_x += cos(data->p_rad + M_PI / 2) * ACC;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->p_rad += M_PI * ROTATION_SPEED / 180;
		if (data->p_rad >= 2 * M_PI)
			data->p_rad = 0;
	}
	if (!is_there_a_wall(data->p_x + ACC * cos(data->p_rad - M_PI / 2),
			data->p_y + ACC * sin(data->p_rad - M_PI / 2),
			data) && mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		data->p_y += sin(data->p_rad - M_PI / 2) * ACC;
		data->p_x += cos(data->p_rad - M_PI / 2) * ACC;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->p_rad -= M_PI * ROTATION_SPEED / 180;
	norme_it(data);
}

void	norme_it(t_data *data)
{
	if (data->p_rad == 2 * M_PI)
		data->p_rad = 0;
	else if (data->p_rad < 0)
		data->p_rad += 2 * M_PI;
}

void	ft_event(void *dat)
{
	t_data		*data;
	static int	a;

	data = dat;
	mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (mlx_is_key_down(data->mlx, MLX_KEY_M) && a == 0)
		a = 1;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_M) && a == 1)
		a = 0;
	data->a = &a;
	ft_hooks(data);
	ft_hooks_(data);
	if (a == 0)
	{
		mlx_set_mouse_pos(data->mlx, WIDTH / 2, HEIGHT / 2);
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	}
	draw_player(data);
	draw_mini_map(data);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
}
