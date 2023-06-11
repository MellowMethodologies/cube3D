/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:01:49 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/11 13:52:05 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_textures(t_data *data, t_vars *vars)
{
	int	i;
	int	j;
	
	i = 6;
	j = 0;
	while(vars->map[i])
	{
		j = ft_strlen(vars->map[i]);
		if (j > ft_strlen(vars->map[i + 1]))
			data->width = j * 50;
		i++;
	}
	data->height = (i - 6) * 50;
	data->str = vars->map + 6;
	data->p_rad = M_PI/2;
	data->p_x = data->width / 2;
	data->p_y = data->height / 2;
	data->a_x = data->width / 2;
	data->a_y = data->height / 2 + 22;
	data->dis_bt_a_p = 22;
}

//----------------------------------------------------------------------------//

void    ft_color(t_data *data, int x, int y)
{
	int i;
	int j;
	int s;

	i = 0;
	j = 0;
	s = x;
	while (j < 49)
	{
		i = 0;
		x = s;
		while (i < 49)
		{
			mlx_pixel_put(data->mlx, data->window, x, y, 0x00FFFFFF);
			x++;
			i++;
		}
		y++;
		j++;
	}
}

//----------------------------------------------------------------------------//

void	ft_draw(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_clear_window(data->mlx, data->window);
	while (data->str[y])
	{
		x = 0;
		while (data->str[y][x])
		{
			if (data->str[y][x] == '0')
				ft_color(data, x * 50, y * 50);
			x++;
		}
		y++;
	}
}
