/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:01:49 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/25 16:16:32 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

void	find_player(t_data *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->str[i])
	{
		j = 0;
		while (vars->str[i][j])
		{
			if (check_player(vars->str[i][j]))
			{
				vars->pl[0] = i;
				vars->pl[1] = j;
				vars->pl[2] = vars->str[i][j];
			}
			j++;
		}
		i++;
	}
}

double	check_rotation(int c)
{
	if (c == 'E')
		return (0);
	else if (c == 'W')
		return (M_PI);
	else if (c == 'N')
		return (-M_PI / 2);
	else
		return (M_PI / 2);
}

void	counter(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->str[i])
	{
		j = 0;
		while (data->str[i][j])
			j++;
		i++;
	}
	data->count = i;
}

void	ft_textures(t_data *data, t_vars *vars)
{
	data->str = vars->map + 6;
	find_player(data);
	counter(data);
	data->p_rad = check_rotation(data->pl[2]);
	data->p_x = data->pl[1] * TILE_SIZE + TILE_SIZE / 2;
	data->p_y = data->pl[0] * TILE_SIZE + TILE_SIZE / 2;
	data->dist = 1;
	data->mouse_x_old = WIDTH / 2;
	ft_get_image(data, vars);
}
