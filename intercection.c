/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intercection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:22:05 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/25 00:24:03 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

double	ds_between_two_points(double x, double y, double x1, double y1)
{
	return (sqrt(((x1 - x) * (x1 - x)) + ((y1 - y) * (y1 - y))));
}

double	ft_find_hr(t_data *data, double rotation)
{
	double	a_x;
	double	a_y;

	a_x = INT_MAX;
	a_y = INT_MAX;
	if (rotation >= 0 && rotation < M_PI)
		a_y = floor(data->p_y / TILE_SIZE) * TILE_SIZE + TILE_SIZE ;
	else
		a_y = floor(data->p_y / TILE_SIZE) * TILE_SIZE - 0.0001;
	a_x = data->p_x + ((a_y - data->p_y) / tan(rotation));
	return (find_hr(data, a_x, a_y, rotation));
}

double	ft_find_vr(t_data *data, double rotation)
{
	double	a_x;
	double	a_y;

	a_x = INT_MAX;
	a_y = INT_MAX;
	if (rotation >= 3 * M_PI / 2 || rotation <= M_PI / 2)
		a_x = floor(data->p_x / TILE_SIZE) * TILE_SIZE + TILE_SIZE ;
	else
		a_x = floor(data->p_x / TILE_SIZE) * TILE_SIZE - 0.0001;
	a_y = data->p_y + ((a_x - data->p_x) * tan(rotation));
	return (find_vr(data, a_x, a_y, rotation));
}

void	draw_player(t_data	*data)
{
	double	x;
	size_t	i;

	i = 0;
	x = data->p_rad - (FOV / 2);
	while (i < WIDTH)
	{
		circled(&x);
		if (ft_find_hr(data, x) < ft_find_vr(data, x))
		{
			data->dist = ft_find_hr(data, x);
			data->hit = 'H';
		}
		else
		{
			data->dist = ft_find_vr(data, x);
			data->hit = 'V';
		}
		data->hit_x = data->p_x + data->dist * cos(x);
		data->hit_y = data->p_y + data->dist * sin(x);
		data->ongle = x;
		draw_wall(data, i, data->dist * cos(x - data->p_rad));
		x += FOV / WIDTH;
		i++;
	}
}
