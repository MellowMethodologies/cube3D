/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:22:05 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/13 17:14:30 by sbadr            ###   ########.fr       */
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
	return(sqrt(((x-x1) * (x-x1)) + ((y-y1) * (y - y1))));
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
	double dist;
	double dist1;
	double dist2;
	int i;
	
	x = data->p_rad - (FOV / 2);
	y = data->p_rad + (FOV / 2);
	i = 0;
	x1= 0;
	//       draw a line
	while(x <= y)
	{
		while (1)
		{
		    x1 = data->p_x + i;
		    if (is_there_a_wall((x1) * cos(x), (data->p_y) * sin(data->p_rad), data))
		    {
		    	dist1 = ds_between_two_points(x1 , y1, data->p_x, data->p_y);
		        break;
		    }
		    i++;
		}
		// i = 0;
		// y1 = 0;
		// while (1)
		// {
		// 	y1 = data->p_x + i;
		// 	if (!is_there_a_wall((data->p_x) * cos(data->p_rad), (y1) * sin(x), data))
		// 	{
		// 		dist2 = ds_between_two_points(x1 , y1, data->p_x, data->p_y);
		// 		break;
		// 	}
		// 	i++;
		// }
		dist = ds_between_two_points(dist1 * cos(data->p_rad), dist2 *sin (data->p_rad), data->p_x, data->p_y);
		// printf("%f\n", dist);
		draw_line(data, dist, x);
		x += M_PI / 180;
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
		data->p_rad += M_PI * 2/ 180;
		//rotation angle 15degree to the left
		data->a_x = data->p_x + dx;
		data->a_y = data->p_y + dy;
	}
	
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
	   // left arrow
		data->p_rad -= M_PI *2 / 180;

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