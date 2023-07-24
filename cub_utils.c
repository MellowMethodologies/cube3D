/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:40:31 by sbadr             #+#    #+#             */
/*   Updated: 2023/07/25 00:24:08 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

int	check_it(int c)
{
	if (c == '1' || check_player(c) || c == ' ')
		return (1);
	return (0);
}

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

void	circled(double *x)
{
	if (*x < 0)
		*x += M_PI * 2;
	if (*x > 2 * M_PI)
		*x -= M_PI * 2;
}

double	find_hr(t_data *data, double a_x, double a_y, double rotation)
{
	while (1)
	{
		if (((rotation >= 0 && rotation <= M_PI)
				&& is_there_a_wall_1(a_x, a_y + 0.0001, data))
			|| is_there_a_wall_1(a_x, a_y, data))
		{
			break ;
		}
		if (rotation > 0 && rotation < M_PI)
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

double	find_vr(t_data *data, double a_x, double a_y, double rotation)
{
	while (1)
	{
		if (((rotation > 3 * M_PI / 2 || rotation < M_PI / 2)
				&& is_there_a_wall_1(a_x + 0.0001, a_y, data))
			|| is_there_a_wall_1(a_x, a_y, data))
		{
			break ;
		}
		if (rotation > 3 * M_PI / 2 || rotation < M_PI / 2)
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
