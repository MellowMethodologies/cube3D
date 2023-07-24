/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:01:49 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/24 23:26:40 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

int	*find_player(char **map)
{
	int	i;
	int	j;
	int	*pl;

	i = 0;
	pl = malloc(sizeof(int) * 3);
	if (!pl)
		return (NULL);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_player(map[i][j]))
			{
				pl[0] = i;
				pl[1] = j;
				pl[2] = map[i][j];
			}
			j++;
		}
		i++;
	}
	return (pl);
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
	int	*pl;

	pl = malloc(sizeof(int) * 3);
	if (!pl)
		return ;
	data->str = vars->map + 6;
	pl = find_player(data->str);
	counter(data);
	data->p_rad = check_rotation(pl[2]);
	data->p_x = pl[1] * TILE_SIZE + TILE_SIZE / 2;
	data->p_y = pl[0] * TILE_SIZE + TILE_SIZE / 2;
	data->dist = 1;
	data->mouse_x_old = WIDTH / 2;
	ft_get_image(data, vars);
}
