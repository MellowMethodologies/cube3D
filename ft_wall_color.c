/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:09:40 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/19 10:14:35 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

void	ft_draw_wall_no(t_data *data, int x, int j)
{
	unsigned int	color;

	while (data->cord.y < data->cord.wall_bottom)
	{
		j = (data->cord.y + (data->cord.wall_hight / 2) - (data->height / 2));
		data->cord.offsety = j * ((double)(data->vars->NO->height
				/ data->cord.wall_hight));
		color = data->no[(data->vars->NO->height * data->cord.offsety)
			+ (data->cord.offsetx)];
		mlx_put_pixel(data->image, x, data->cord.y++, color);
	}
}

//----------------------------------------------------------------------------//

void	ft_draw_wall_so(t_data *data, int x, int j)
{
	unsigned int	color;

	while (data->cord.y < data->cord.wall_bottom)
	{
		j = (data->cord.y + (data->cord.wall_hight / 2) - (data->height / 2));
		data->cord.offsety = j * ((double)(data->vars->NO->height
				/ data->cord.wall_hight));
		color = data->so[(data->vars->NO->height * data->cord.offsety)
			+ (data->cord.offsetx)];
		mlx_put_pixel(data->image, x, data->cord.y++, color);
	}
}

//----------------------------------------------------------------------------//

void	ft_draw_wall_we(t_data *data, int x, int j)
{
	unsigned int	color;

	while (data->cord.y < data->cord.wall_bottom)
	{
		j = (data->cord.y + (data->cord.wall_hight / 2) - (data->height / 2));
		data->cord.offsety = j * ((double)(data->vars->NO->height
				/ data->cord.wall_hight));
		color = data->we[(data->vars->NO->height * data->cord.offsety)
			+ (data->cord.offsetx)];
		mlx_put_pixel(data->image, x, data->cord.y++, color);
	}
}

//----------------------------------------------------------------------------//

void	ft_draw_wall_ea(t_data *data, int x, int j)
{
	unsigned int	color;

	while (data->cord.y < data->cord.wall_bottom)
	{
		j = (data->cord.y + (data->cord.wall_hight / 2) - (data->height / 2));
		data->cord.offsety = j * ((double)(data->vars->NO->height
				/ data->cord.wall_hight));
		color = data->ea[(data->vars->NO->height * data->cord.offsety)
			+ (data->cord.offsetx)];
		mlx_put_pixel(data->image, x, data->cord.y++, color);
	}
}

//----------------------------------------------------------------------------//

