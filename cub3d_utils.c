/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:22:05 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/14 20:58:38 by sbadr            ###   ########.fr       */
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

// int check_pl(float x, float y)
// {
// 	if (){}
// }

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

void draw_player(t_data	*data)
{
	mlx_put_pixel(data->image ,data->p_x - 1, data->p_y, 0x00FF0000);
	mlx_put_pixel(data->image , data->p_x , data->p_y - 1, 0x00FF0000);
	mlx_put_pixel(data->image , data->p_x, data->p_y + 1, 0x00FF0000);
	mlx_put_pixel(data->image , data->p_x + 1, data->p_y, 0x00FF0000);
	double x;
	double y;
	double x1;
	double y1;
	// double x2;
	// double y2;
	// double dist;
	double dist1 = 0;
	// double dist2;
	int i;
	
	x = data->p_rad - (FOV / 2);
	y = data->p_rad + (FOV / 2);
	i = 0;
	//       draw a line
			
			
	// while(x <= y)
	// {
		// x1 = (data->p_x + ((data->p_y - y1) / tan(data->p_rad)));
		// y1 = fabs(data->p_y / 50) * 50;
		// 	x2 = 0;
		if (data->p_rad < -M_PI || data->p_rad > M_PI)
			i = 50;
		y1 = ((floor(data->p_y / 50)) * 50) + i;
		x1 = (data->p_x + ((data->p_y - y1) / tan(data->p_rad)) );
		// y1 = floor(data->p_y / 50) * 50 + i;
		// x1 = (data->p_x + ((data->p_y - y1) / tan(data->p_rad))) / 50 ;
		if(data->p_rad == 0 || data->p_rad == M_PI)
		{
			x1 = data->p_x;
			y1 = data->p_y;
		}
		printf("playerx = %f playery = %f x1  = %f y1=%f\n",data->p_x/50, data->p_y/50, x1/50,  y1/50);
		// y2 = (int)(data->p_y / 50) * 50;
		// x2 = (int)(data->p_x + ((data->p_y) / tan(data->p_rad))) / 50 * 50;
		while (1)
		{
		    if (is_there_a_wall(fabs(x1), fabs(y1), data))
		    {
		        dist1 = ds_between_two_points(fabs(x1), fabs(y1), data->p_x, data->p_y);
				printf("dist 1 ==%f\n",dist1);
		        break;
		    }
		    // else if (is_there_a_wall(fabs(x2), fabs(y2), data))
		    // {
		    //     dist1 = ds_between_two_points(fabs(x2), fabs(y2), data->p_x, data->p_y);
		    //     break;
		    // }
		    x1 += fabs(50 / tan(data->p_rad));
		    y1 += 50;
		    // x2 -= fabs(50 / tan(data->p_rad));
		    // y2 += 50;
		}
		mlx_put_pixel(data->image, x1, y1, 0x00FFFF00F);
		// draw_line(data, dist1, data->p_rad);
		// x += M_PI / 180;
	// }
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
		data->p_rad += M_PI / 180;
		if (data->p_rad == 2 * M_PI)
			data->p_rad = 0;
		//rotation angle 15degree to the left
		data->a_x = data->p_x + dx;
		data->a_y = data->p_y + dy;
	}
	
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
	   // left arrow
		data->p_rad -= M_PI  / 180;

		if (data->p_rad == 2 * M_PI)
			data->p_rad = 0;
		data->a_x = data->p_x + dx;
		data->a_y = data->p_y + dy;
	}
	mlx_delete_image(data->mlx, data->image);
	data->image = mlx_new_image(data->mlx, data->width,data->height);
   	ft_draw(data);
   	draw_player(data);
   	// draw_rays(data);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	// return 1;
}

//----------------------------------------------------------------------------//