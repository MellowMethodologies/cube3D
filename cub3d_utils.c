/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:22:05 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/13 10:26:36 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

//----------------------------------------------------------------------------//

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

//----------------------------------------------------------------------------//
void draw_line(t_data *data, double dis, double rotation)
{
	double end_x = data->p_x + dis * cos(rotation);
	double end_y = data->p_y + dis * sin(rotation);

	int x0 = data->p_x;
	int y0 = data->p_y;
	int x1 = (int)end_x;
	int y1 = (int)end_y;
	
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx - dy;
	
	while (1) {
		mlx_put_pixel(data->image, x0, y0, 0x00FF0099);
		if ((x0 == x1) && (y0 == y1))
			break;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx) 
		{
			err += dx;
			y0 += sy;
		}
	}	
}

double ds_between_two_points(double x, double y, double x1, double y1)
{
	return(sqrt(((x1-x) * (x1-x)) + ((y1-y) * (y1 - y))));
}	

float	ft_find_hr(t_data *data, float rotation)
{
	float	a_x = 0;
	float	a_y = 0;
	int c = 0;

	if (rotation >= 0 && rotation <= M_PI)
	{
		a_y = floor(data->p_y / TILE_SIZE) * TILE_SIZE + TILE_SIZE ;
		c = 1;
	}
	else
		a_y = floor(data->p_y / TILE_SIZE) * TILE_SIZE - 0.01;
	a_x = data->p_x + ((a_y - data->p_y) / tan(rotation));
	
	while (a_x >= 0 && a_x < data->width && a_y >= 0 && a_y < data->height && !is_there_a_wall_1(a_x, a_y, data))
	{
		if (rotation >= 0 && rotation <= M_PI)
			a_y += 0.01;
		if(c)
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
	return (ds_between_two_points(data->p_x, data->p_y , a_x, a_y));
}

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
	while (a_x >= 0 && a_x < data->width && a_y >= 0 && a_y < data->height && !is_there_a_wall_1(a_x, a_y, data))
	{
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

void draw_player(t_data	*data)
{
	float dist;
	float x;
	// mlx_put_pixel(data->image ,data->p_x - 1, data->p_y, 0x00FF0000);
	// mlx_put_pixel(data->image , data->p_x , data->p_y - 1, 0x00FF0000);
	// mlx_put_pixel(data->image , data->p_x, data->p_y + 1, 0x00FF0000);
	// mlx_put_pixel(data->image , data->p_x + 1, data->p_y, 0x00FF0000);

	x = data->p_rad - (FOV / 2);
	size_t i = 0;
	while(i < data->width)
	{
		if (x < 0)
			x += M_PI * 2;
		if (x > 2 * M_PI)
			x -= M_PI * 2;
		if (ft_find_hr(data, x) < ft_find_vr(data, x))
		{
			dist = ft_find_hr(data, x) - 1;
			data->hit = 'H';
		}
		else
		{
			dist = ft_find_vr(data, x) - 1;
			data->hit = 'V';
		}
		// draw_line(data, dist, x);
		data->hit_x = data->p_x + dist * cos(x);
		data->hit_y = data->p_y + dist * sin(x);
		data->ongle = x;
		draw_wall(data, i, dist * cos(x - data->p_rad));
		x+= FOV / data->width;
		i++;
	}
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
	mlx_get_mouse_pos(data->mlx, &data->mouse_x, &data->mouse_y);
	if (data->mouse_x == data->mouse_x_old)
		data->p_rad = data->p_rad;
	else if (data->mouse_x > data->mouse_x_old)
		data->p_rad += 0.05;
	else
		data->p_rad -= 0.05;
	if (!is_there_a_wall(data->p_x + 3 * cos(data->p_rad), data->p_y + 3 * sin(data->p_rad), data) && (mlx_is_key_down(data->mlx, MLX_KEY_UP) || mlx_is_key_down(data->mlx, MLX_KEY_W)))
	{
		//up arrow
		data->p_y += 3 * sin(data->p_rad);
		data->p_x += 3 * cos(data->p_rad);
	}
	if (!is_there_a_wall(data->p_x - 3 * cos(data->p_rad), data->p_y - 3 * sin(data->p_rad), data) && (mlx_is_key_down(data->mlx, MLX_KEY_DOWN) || mlx_is_key_down(data->mlx, MLX_KEY_S)))
	{
		//down arrow
		data->p_y -= 3 * sin(data->p_rad);
		data->p_x -= 3 * cos(data->p_rad);
	}
	if (!is_there_a_wall(data->p_x + 3 * cos(data->p_rad - M_PI /2), data->p_y + 3 * sin(data->p_rad - M_PI /2), data) && (mlx_is_key_down(data->mlx, MLX_KEY_A)))
	{
		//up arrow
		data->p_y += 3 * sin(data->p_rad - M_PI /2);
		data->p_x += 3 * cos(data->p_rad - M_PI /2);
	}
	if (!is_there_a_wall(data->p_x + 3 * cos(data->p_rad + M_PI /2), data->p_y + 3 * sin(data->p_rad + M_PI /2), data) && (mlx_is_key_down(data->mlx, MLX_KEY_D)))
	{
		//down arrow
		data->p_y += 3 * sin(data->p_rad + M_PI / 2);
		data->p_x += 3 * cos(data->p_rad + M_PI / 2);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		//right arrow
		data->p_rad += M_PI / 180;
		if (data->p_rad >= 2 * M_PI)
			data->p_rad = 0;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->p_rad -= M_PI / 180;
	if (data->p_rad == 2 * M_PI)
		data->p_rad = 0;
	else if (data->p_rad < 0)
		data->p_rad +=2 * M_PI;
	mlx_delete_image(data->mlx, data->image);
	mlx_delete_image(data->mlx, data->map);
	data->image = mlx_new_image(data->mlx, data->width,data->height);
	// data->image = mlx_new_image(data->mlx, 250,250);
	// mlx_put_pixel(data->map , 25, 25, 0x00FF0000);
	mlx_set_mouse_pos(data->mlx, data->width / 2, data->height / 2);
   	// ft_draw(data);
   	draw_player(data);
   	// draw_rays(data);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	// mlx_image_to_window(data->mlx, data->map, 0, 0);
	// return 1;
}

//----------------------------------------------------------------------------//