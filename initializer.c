/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 16:01:49 by idabligi          #+#    #+#             */
<<<<<<< HEAD:initializer.c
/*   Updated: 2023/07/25 16:16:32 by sbadr            ###   ########.fr       */
=======
/*   Updated: 2023/07/25 12:29:32 by idabligi         ###   ########.fr       */
>>>>>>> 52dda7b753de3327a909f938ccb9921e75196206:ft_textures.c
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

<<<<<<< HEAD:initializer.c
void	find_player(t_data *vars)
=======
void	find_player(t_vars *vars)
>>>>>>> 52dda7b753de3327a909f938ccb9921e75196206:ft_textures.c
{
	int	i;
	int	j;

	i = 0;
<<<<<<< HEAD:initializer.c
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
=======
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (check_player(vars->map[i][j]))
			{
				vars->pl[0] = i;
				vars->pl[1] = j;
				vars->pl[2] = vars->map[i][j];
>>>>>>> 52dda7b753de3327a909f938ccb9921e75196206:ft_textures.c
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
	else if (c == 'S')
		return (M_PI / 2);
	else
		return (-1);
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

char	*find_map(t_vars *vars)
{
<<<<<<< HEAD:initializer.c
	data->str = vars->map + 6;
	find_player(data);
	counter(data);
	data->p_rad = check_rotation(data->pl[2]);
	data->p_x = data->pl[1] * TILE_SIZE + TILE_SIZE / 2;
	data->p_y = data->pl[0] * TILE_SIZE + TILE_SIZE / 2;
=======
	int		i;

	i = 0;
	while (vars->map[i])
	{
		if(vars->map[i][0] == '1')
			return
		i++;
	}
	return NULL;
}

void	ft_textures(t_data *data, t_vars *vars)
{
	data->str = find_map();
	find_player(vars);
	counter(data);
	if (check_rotation(vars->pl[2])	>= 0)
		data->p_rad = check_rotation(vars->pl[2]);
	else
	{
		ft_putstr_fd("error finding player!\n", 2);
		exit(1);
	}
	data->p_x = vars->pl[1] * TILE_SIZE + TILE_SIZE / 2;
	data->p_y = vars->pl[0] * TILE_SIZE + TILE_SIZE / 2;
	printf("x=%d, y=%d\n", vars->pl[1], vars->pl[0]);
>>>>>>> 52dda7b753de3327a909f938ccb9921e75196206:ft_textures.c
	data->dist = 1;
	data->mouse_x_old = WIDTH / 2;
	ft_get_image(data, vars);
}
