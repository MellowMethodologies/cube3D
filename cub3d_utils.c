/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:22:05 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/15 17:03:55 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"


void	ft_abort(int id)
{
	if (id == 1)
		printf("\e[1;31mError in malloc!\n\e[0m");
	else if (id == 2)
		printf("\e[1;31mArgument please!\n\e[0m");
	else if (id == 3)
		printf("\e[1;31mError in texture!\n\e[0m");
	exit(1);
}

double	ds_between_two_points(double x, double y, double x1, double y1)
{
	return (sqrt(((x1 - x) * (x1 - x)) + ((y1 - y) * (y1 - y))));
}

float	ft_find_hr(t_data *data, float rotation)
{
	float	a_x = 0;
	float	a_y = 0;
	int		c = 0;

	if (rotation >= 0 && rotation <= M_PI)
	{
		a_y = floor(data->p_y / TILE_SIZE) * TILE_SIZE + TILE_SIZE ;
		c = 1;
	}
	else
		a_y = floor(data->p_y / TILE_SIZE) * TILE_SIZE - 0.01;
	a_x = data->p_x + ((a_y - data->p_y) / tan(rotation));
	while (1)
	{
		if (is_there_a_wall_1(a_x, a_y, data))
		{
			if (c)
				a_y += 0.01;
			break ;
		}
		if (c)
		{
			a_y += TILE_SIZE;
			a_x += TILE_SIZE / tan(rotation);
		}
		else
		{
			a_y -= TILE_SIZE;
			a_x -= TILE_SIZE / tan(rotation);
		}
	}
	return (ds_between_two_points(data->p_x, data->p_y, a_x, a_y));
}

//----------------------------------------------------------------------------//

float	ft_find_vr(t_data *data, float rotation)
{
	int c = 0;
	float	a_x = 0;
	float	a_y = 0;

	if (rotation >= 3*M_PI/2 || rotation <= M_PI/2)
	{
		a_x = floor(data->p_x / TILE_SIZE) * TILE_SIZE + TILE_SIZE ;
		c = 1;
	}
	else
		a_x = floor(data->p_x / TILE_SIZE) * TILE_SIZE - 0.01;
	a_y = data->p_y + ((a_x - data->p_x) * tan(rotation));
	while (1)
	{
		if (is_there_a_wall_1(a_x, a_y, data))
		{
			if (c)
				a_x += 0.01;
			break ;
		}
		if (c)
		{
			a_y +=	TILE_SIZE * tan(rotation);
			a_x +=	TILE_SIZE;
		}
		else
		{
			a_y -=	TILE_SIZE * tan(rotation);
			a_x -=	TILE_SIZE; 
		}
	}
	return (ds_between_two_points(data->p_x, data->p_y , a_x, a_y));
}

//----------------------------------------------------------------------------//

void draw_player(t_data	*data)
{
	float x;

	x = data->p_rad - (FOV / 2);
	size_t i = 0;
	while (i < data->width)
	{
		if (x < 0)
			x += M_PI * 2;
		if (x > 2 * M_PI)
			x -= M_PI * 2;
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
		x += FOV / data->width;
		i++;
	}
}



void draw_mini_map(t_data *data)
{
	int i = 250;
	int j;
	while (i)
	{
		j = 250;
		while (j)
		{
			mlx_put_pixel(data->image, i, j, 0x0000FF00);
			--j;
		}
		--i;
	}
}


//----------------------------------------------------------------------------//