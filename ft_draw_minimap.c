/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:08:25 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/18 17:51:16 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

//----------------------------------------------------------------------------//

void	ft_draw_mm_player(t_data *data)
{
	double	x;
	double	y;
	double	ongle;
	double	incre;
	int		count;

	ongle = 0;
	incre = (5 * M_PI) / 180;
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
}

//----------------------------------------------------------------------------//

void	ft_draw_mm_line(t_data *data, double ongle)
{
	float	x;
	float	y;
	int		count = 15;

	while (count > 0)
	{
		x = 75 + cos(ongle) * count;
		y = 75 + sin(ongle) * count;
		mlx_put_pixel(data->image, x, y, 0x0000FF00FF);
		count--;
	}
}

//----------------------------------------------------------------------------//

void    ft_draw_mm_walls(t_data *data, int x, int y)
{
	int i = 0;
	int j = 0;
	int x1;
	int y1;

	x = data->p_x - 75;
	y = data->p_y - 75;
	x1 = data->p_x - 75;
	y1 = data->p_y - 75;
	// printf("%.2f\n", ds_between_two_points(x , y, 75, 75));
	// exit (0);
	while (x < (x1 + 150))
	{
		y = data->p_y - 75;
		j = 0;
		while (y < (y1 +150))
		{
			if (ds_between_two_points(x , y, data->p_x, data->p_y) <= 70)
			{
				if (is_there_a_wall_1(x, y, data))
					mlx_put_pixel(data->image, i, j, 0x00CCFFFFFF);
				else
					mlx_put_pixel(data->image, i, j, 0x00000000);
			}
			y++;
			j++;
		}
		i++;
		x++;
	}
	ft_draw_mm_player(data);
	ft_draw_mm_line(data, data->p_rad);
	ft_draw_mm_line(data, (data->p_rad) + (M_PI / 180));
	ft_draw_mm_line(data, (data->p_rad) - (M_PI / 180));
}

//----------------------------------------------------------------------------//

void	ft_draw_mm_background(t_data *data, int x, int y)
{
	while (y < 150)
	{
		x = 0;
		while (x < 150)
		{
			mlx_put_pixel(data->image, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

//----------------------------------------------------------------------------//

void draw_mini_map(t_data *data, int x, int y)
{

	// ft_draw_mm_background(data, 0, 0);
	x = 0;
	y = 0;
	ft_draw_mm_walls(data, 0, 0);
}