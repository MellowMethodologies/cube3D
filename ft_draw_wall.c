/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:40:19 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/13 11:55:30 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

//----------------------------------------------------------------------------//

unsigned int	*ft_get_dir2(t_data *data)
{
	if (data->ongle >= M_PI && data->ongle < ((3 * M_PI) / 2))
	{
		if (data->hit == 'V')
			return (data->we);
		else
			return (data->no);
	}
	else if (data->ongle >= ((3 * M_PI) / 2) && data->ongle < (2 * M_PI))
	{
		if (data->hit == 'V')
			return (data->ea);
		else
			return (data->no);
	}
	return (0);
}

//----------------------------------------------------------------------------//

unsigned int	*ft_get_dir(t_data *data)
{
	if (data->ongle >= 0 && data->ongle < (M_PI / 2))
	{
		if (data->hit == 'V')
			return (data->ea);
		else
			return (data->so);
	}
	else if (data->ongle >= (M_PI / 2) && data->ongle < M_PI)
	{
		if (data->hit == 'V')
			return (data->we);
		else
			return (data->so);
	}
	else
		return (ft_get_dir2(data));
}

//----------------------------------------------------------------------------//

void	ft_get_cord(t_data *data, int i, double dist)
{
	size_t	j;

	j = 0;
	data->cord.wall_hight = 50000 / dist;
	data->cord.wall_top = data->height / 2 - data->cord.wall_hight / 2;
	if (data->cord.wall_top < 0)
		data->cord.wall_top = 0;
	data->cord.wall_bottom = data->height / 2 + data->cord.wall_hight / 2;
	if (data->cord.wall_bottom > data->height)
		data->cord.wall_bottom = data->height;
	data->cord.y = data->cord.wall_top;
	if (data->cord.wall_top > 0)
	{
		while (j < data->cord.wall_top)
			mlx_put_pixel(data->image, i, j++, 0x000099FFFF);
	}
	if (data->hit == 'V')
		data->cord.offsetx = (int)data->hit_y + 1 % data->vars->NO->width;
	
	else if (data->hit == 'H')
		data->cord.offsetx = (int)data->hit_x + 1 % data->vars->NO->width;
}

//----------------------------------------------------------------------------//

void	draw_wall(t_data *data, int i, double dist)
{
	size_t			j;
	unsigned int	color;
	unsigned int	*buffer;

	j = 0;
	ft_get_cord(data, i, dist);
	buffer = ft_get_dir(data);
	while (data->cord.y < data->cord.wall_bottom)
	{
		j = (data->cord.y + (data->cord.wall_hight / 2) - (data->height / 2));
		data->cord.offsety = j * ((double)(data->vars->NO->height / data->cord.wall_hight));
		color = buffer[(data->vars->NO->height * data->cord.offsety) + (data->cord.offsetx)];
		mlx_put_pixel(data->image, i, data->cord.y++, color);
	}
	if (data->cord.wall_bottom < data->height)
	{
		while (data->cord.y < data->height)
			mlx_put_pixel(data->image, i, data->cord.y++, 0x606060FF);
	}
}

//----------------------------------------------------------------------------//