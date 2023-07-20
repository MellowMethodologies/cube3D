/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:40:19 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/20 10:36:29 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

//----------------------------------------------------------------------------//

char	ft_get_dir2(t_data *data)
{
	if (data->ongle >= M_PI && data->ongle < ((3 * M_PI) / 2))
	{
		if (data->hit == 'V')
			return ('W');
		else
			return ('N');
	}
	else if (data->ongle >= ((3 * M_PI) / 2) && data->ongle < (2 * M_PI))
	{
		if (data->hit == 'V')
			return ('E');
		else
			return ('N');
	}
	return (0);
}

//----------------------------------------------------------------------------//

char	ft_get_dir(t_data *data)
{
	if (data->ongle >= 0 && data->ongle < (M_PI / 2))
	{
		if (data->hit == 'V')
			return ('E');
		else
			return ('S');
	}
	else if (data->ongle >= (M_PI / 2) && data->ongle < M_PI)
	{
		if (data->hit == 'V')
			return ('W');
		else
			return ('S');
	}
	else
		return (ft_get_dir2(data));

}

//----------------------------------------------------------------------------//

void	ft_get_cord(t_data *data, int i, double dist, uint32_t	width)
{
	int	j;

	j = 0;
	data->cord.wall_hight = 160000 / dist;
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
			mlx_put_pixel(data->image, i, j++, data->vars->C);
	}
	if (data->hit == 'V')
		data->cord.offsetx = (int)(data->hit_y * (width / TILE_SIZE)) % width;
	else if (data->hit == 'H')
		data->cord.offsetx = (int)(data->hit_x * (width / TILE_SIZE)) % width;
}

//----------------------------------------------------------------------------//

void	draw_wall(t_data *data, int x, double dist)
{
	char	c;

	c = ft_get_dir(data);
	if (c == 'N')
	{
		ft_get_cord(data, x, dist, data->vars->NO->width);
		ft_draw_wall_no(data, x, 0);
	}
	else if (c == 'S')
	{
		ft_get_cord(data, x, dist, data->vars->SO->width);
		ft_draw_wall_so(data, x, 0);
	}
	else if (c == 'E')
	{
		ft_get_cord(data, x, dist, data->vars->EA->width);
		ft_draw_wall_ea(data, x, 0);
	}
	else if (c == 'W')
	{
		ft_get_cord(data, x, dist, data->vars->WE->width);
		ft_draw_wall_we(data, x, 0);
	}
	if (data->cord.wall_bottom < data->height)
	{
		while (data->cord.y < data->height)
			mlx_put_pixel(data->image, x, data->cord.y++, data->vars->F);
	}
}
