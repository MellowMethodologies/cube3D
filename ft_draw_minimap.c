/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:08:25 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/24 23:35:21 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

//----------------------------------------------------------------------------//

void	ft_draw_mm_line(t_data *data, double ongle)
{
	double	x;
	double	y;
	int		count;

	count = 15;
	while (count > 4)
	{
		x = 75 + cos(ongle) * count;
		y = 75 + sin(ongle) * count;
		mlx_put_pixel(data->image, x, y, 0x0000FF00FF);
		count--;
	}
}

//----------------------------------------------------------------------------//

void	ft_draw_mm_player(t_data *data)
{
	double	x;
	double	y;
	double	ongle;
	double	incre;
	int		count;

	ongle = 0;
	incre = (10 * M_PI) / 180;
	while (ongle <= 2 * M_PI)
	{
		count = 4;
		while (count)
		{
			x = 75 + cos(ongle) * count;
			y = 75 + sin(ongle) * count;
			mlx_put_pixel(data->image, x, y, 0x0000FF00FF);
			count--;
		}
		ongle = ongle + incre;
	}
	ft_draw_mm_line(data, data->p_rad);
	ft_draw_mm_line(data, (data->p_rad) + (M_PI / 180));
	ft_draw_mm_line(data, (data->p_rad) - (M_PI / 180));
}

//----------------------------------------------------------------------------//

void	ft_draw_mm_walls(t_data *data, int x, int y, int x1)
{
	int	y1;

	y1 = y;
	while (x < (x1 + 150))
	{
		y = data->p_y - 75;
		data->j = 0;
		while (y < (y1 + 150))
		{
			if (ds_between_two_points(x, y, data->p_x, data->p_y) <= 70)
			{
				if (is_there_a_wall_1(x, y, data))
					mlx_put_pixel(data->image, data->i, data->j, 0x00CCFFFFFF);
				else
					mlx_put_pixel(data->image, data->i, data->j, 0x00000000);
			}
			else if (ds_between_two_points(x, y, data->p_x, data->p_y) > 70
				&& ds_between_two_points(x, y, data->p_x, data->p_y) < 75)
				mlx_put_pixel(data->image, data->i, data->j, 0x0000FF00FF);
			y++;
			data->j++;
		}
		data->i++;
		x++;
	}
}

//----------------------------------------------------------------------------//

void	draw_mini_map(t_data *data)
{
	data->i = 0;
	data->j = 0;
	ft_draw_mm_walls(data, data->p_x - 75, data->p_y - 75, data->p_x - 75);
	ft_draw_mm_player(data);
}
