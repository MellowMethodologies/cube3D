/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:01:49 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/09 19:47:20 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
	
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
			if (map[i][j] != '0' && !ft_isspace(map[i][j]) && map[i][j] != '1')
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
	int	i;
	int	j;
	int *pl;

	i = 6;
	j = 0;
	j = ft_strlen(vars->map[i]);
	pl = malloc(sizeof(int) * 3);
	if (!pl)
		return ;
	data->width = j * 50;
	while (vars->map[i])
	{
		if (j < ft_strlen(vars->map[i]))
			data->width = ft_strlen(vars->map[i]) * 50;
		i++;
	}
	data->height = (i - 6) * 50;
	data->str = vars->map + 6;
	pl = find_player(data->str);
	data->p_rad = check_rotation(pl[2]);
	data->p_x = pl[1] * 50 + 25;
	data->p_y = pl[0] * 50 + 25;
	data->a_x = data->p_x + 22 * cos(data->p_rad);
	data->a_y = data->p_y + 22 * sin(data->p_rad);
	data->num_rays = data->width / WALL_THICKNESS /50;
	data->dis_bt_a_p = 22;
	// ft_get_image(data);
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
			mlx_put_pixel(data->image, x, y, 0x00FFFFFF);
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
				ft_color(data, x * 50, y * 50);
			x++;
		}
		y++;
	}
}
