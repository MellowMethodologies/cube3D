/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:01:49 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/15 10:48:52 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"
	
int		*find_player(char **map)
{
	int i = 0;
	int j;
	int *pl;

	pl = malloc(sizeof(int) *3);
	if (!pl)
		return (NULL);
	while(map[i])
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

void	ft_textures(t_data *data, t_vars *vars)
{
	int i = 0;
	int j;
	int *pl;

	pl = malloc(sizeof(int) * 3);
	if (!pl)
		return ;
	data->width = WIDTH;
	data->height = HEIGHT;
	data->str = vars->map + 6;
	pl = find_player(data->str);
	while (data->str[i])
	{
		j = 0;
		while (data->str[i][j++]);
		i++;
	}
	data->count = i;
	data->p_rad = check_rotation(pl[2]);
	data->p_x = pl[1] * TILE_SIZE + TILE_SIZE / 2;
	data->p_y = pl[0] * TILE_SIZE + TILE_SIZE / 2;
	data->mouse_x_old = data->width / 2;
	data->dis_bt_a_p = 22;
	ft_get_image(data, vars);
}

//----------------------------------------------------------------------------//

void    ft_color(t_data *data, int x, int y, unsigned int color)
{
	int i;
	int j;
	int s;

	i = 0;
	j = 0;
	s = x;
	while (j < TILE_SIZE - 1)
	{
		i = 0;
		x = s;
		while (i < TILE_SIZE - 1)
		{
			if (color)
				mlx_put_pixel(data->image, x, y, color);
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
	while (data->str[y])
	{
		x = 0;
		while (data->str[y][x])
		{
			if (!check_player(data->str[y][x]) && data->str[y][x] == '1')
				ft_color(data, x * TILE_SIZE, y * TILE_SIZE, 0x00FFFFFF);
			x++;
		}
		y++;
	}
}
