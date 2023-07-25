/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:09:40 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/25 16:53:29 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

void	ft_draw_wall_no(t_data *data, int x, int dis)
{
	unsigned int	color;

	while (data->cord.y < data->cord.wall_bottom)
	{
		dis = (data->cord.y + (data->cord.wall_hight / 2) - (HEIGHT / 2));
		data->cord.offsety = dis * ((double)(data->vars->no->height
					/ data->cord.wall_hight));
		color = data->no[(data->vars->no->height * data->cord.offsety)
			+ (data->cord.offsetx)];
		mlx_put_pixel(data->image, x, data->cord.y++, color);
	}
}

//----------------------------------------------------------------------------//

void	ft_draw_wall_so(t_data *data, int x, int dis)
{
	unsigned int	color;

	while (data->cord.y < data->cord.wall_bottom)
	{
		dis = (data->cord.y + (data->cord.wall_hight / 2) - (HEIGHT / 2));
		data->cord.offsety = dis * ((double)(data->vars->so->height
					/ data->cord.wall_hight));
		color = data->so[(data->vars->so->height * data->cord.offsety)
			+ (data->cord.offsetx)];
		mlx_put_pixel(data->image, x, data->cord.y++, color);
	}
}

//----------------------------------------------------------------------------//

void	ft_draw_wall_we(t_data *data, int x, int dis)
{
	unsigned int	color;

	while (data->cord.y < data->cord.wall_bottom)
	{
		dis = (data->cord.y + (data->cord.wall_hight / 2) - (HEIGHT / 2));
		data->cord.offsety = dis * ((double)(data->vars->we->height
					/ data->cord.wall_hight));
		color = data->we[(data->vars->we->height * data->cord.offsety)
			+ (data->cord.offsetx)];
		mlx_put_pixel(data->image, x, data->cord.y++, color);
	}
}

//----------------------------------------------------------------------------//

void	ft_draw_wall_ea(t_data *data, int x, int dis)
{
	unsigned int	color;

	while (data->cord.y < data->cord.wall_bottom)
	{
		dis = (data->cord.y + (data->cord.wall_hight / 2) - (HEIGHT / 2));
		data->cord.offsety = dis * ((double)(data->vars->ea->height
					/ data->cord.wall_hight));
		color = data->ea[(data->vars->ea->height * data->cord.offsety)
			+ (data->cord.offsetx)];
		mlx_put_pixel(data->image, x, data->cord.y++, color);
	}
}
//----------------------------------------------------------------------------//