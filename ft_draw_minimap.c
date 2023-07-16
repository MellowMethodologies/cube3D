/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:08:25 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/16 16:20:29 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

//----------------------------------------------------------------------------//

void    ft_draw_mm_walls(t_data *data, int x, int y)
{
	int i;
	int j;
	int s;
	int	l;

	i = 0;
	j = 0;
	s = x;
	l = TILE_SIZE / 6 ;
	while (j <= l)
	{
		i = 0;
		x = s;
		while (i <= l)
		{
			mlx_put_pixel(data->image, x, y, 0x00CCFFFFFF);
			x++;
			i++;
		}
		y++;
		j++;
	}
}

//----------------------------------------------------------------------------//

void	ft_draw_mm_background(t_data *data, int x, int y, size_t i)
{
	if (data->str[y])
		i = ft_strlen(data->str[y]);
	while (data->str[y])
	{
		if (i < ft_strlen(data->str[y]))
			i = ft_strlen(data->str[y]);
		y++;
	}
	x = (i * TILE_SIZE) / 6;
	i = y;
	while (x >= 0)
	{ 
		y = (i * TILE_SIZE) / 6;
		while (y >= 0)
		{
			mlx_put_pixel(data->image, x, y, 0x00000000);
			y--;
		}
		x--;
	}
}

//----------------------------------------------------------------------------//

void	ft_draw_mm_line(t_data *data)
{
	float	x;
	float	y;
	int		count = 50;
	while (count > 2)
	{
		x = data->p_x + cos(data->p_rad) * count;
		y = data->p_y + sin(data->p_rad) * count;
		mlx_put_pixel(data->image, x / 6, y / 6, 0xFF3333FF);
		count--;
	}
}

//----------------------------------------------------------------------------//

void draw_mini_map(t_data *data, int x, int y)
{

	ft_draw_mm_background(data, 0, 0, 0);
	while (data->str[y])
	{
		x = 0;
		while (data->str[y][x])
		{
			if (data->str[y][x] == '1')
				ft_draw_mm_walls(data, (x * TILE_SIZE / 6), (y * TILE_SIZE / 6));
			x++;
		}
		y++;
	}
	ft_draw_mm_line(data);
	// mlx_put_pixel(data->image ,data->p_x/6, data->p_y/6, 0x00CCFFFFFF);
	// mlx_put_pixel(data->image ,(data->p_x - 1)/6, data->p_y/6, 0x00CCFFFFFF);
	// mlx_put_pixel(data->image , data->p_x/6 , (data->p_y - 1/6), 0x00CCFFFFFF);
	// mlx_put_pixel(data->image , data->p_x/6, (data->p_y + 1)/6, 0x00CCFFFFFF);
	// mlx_put_pixel(data->image , (data->p_x + 1)/6, data->p_y/6, 0x00CCFFFFFF);
}