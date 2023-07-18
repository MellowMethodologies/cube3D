/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:40:31 by sbadr             #+#    #+#             */
/*   Updated: 2023/07/16 17:05:32 by sbadr            ###   ########.fr       */
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

void	circled(float *x)
{
	if (*x < 0)
		*x += M_PI * 2;
	if (*x > 2 * M_PI)
		*x -= M_PI * 2;
}

float	find_hr(t_data *data, float a_x, float a_y, float rotation)
{
	while (1)
	{
		if (is_there_a_wall_1(a_x, a_y, data))
		{
			if (rotation >= 0 && rotation <= M_PI)
				a_y += 0.01;
			break ;
		}
		if (rotation >= 0 && rotation <= M_PI)
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

float	find_vr(t_data *data, float a_x, float a_y, float rotation)
{
	while (1)
	{
		if (is_there_a_wall_1(a_x, a_y, data))
		{
			if (rotation >= 3 * M_PI / 2 || rotation <= M_PI / 2)
				a_x += 0.01;
			break ;
		}
		if (rotation >= 3 * M_PI / 2 || rotation <= M_PI / 2)
		{
			a_y += TILE_SIZE * tan(rotation);
			a_x += TILE_SIZE;
		}
		else
		{
			a_y -= TILE_SIZE * tan(rotation);
			a_x -= TILE_SIZE;
		}
	}
	return (ds_between_two_points(data->p_x, data->p_y, a_x, a_y));
}
