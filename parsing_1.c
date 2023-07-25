/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:37:29 by sbadr             #+#    #+#             */
/*   Updated: 2023/07/25 16:21:40 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

void	map_check(t_vars *vars)
{
	while (vars->map[vars->i])
	{
		vars->j = 0;
		while (vars->map[vars->i][vars->j])
		{
			if (check_player(vars->map[vars->i][vars->j])
			&& (!check_help(vars->map[vars->i + 1][vars->j])
				|| !check_help(vars->map[vars->i - 1][vars->j])
				|| !check_help(vars->map[vars->i][vars->j + 1])
					|| !check_help(vars->map[vars->i][vars->j - 1])))
			{
				ft_putstr_fd("Player not in map !\n", 2);
				exit (1);
			}
			else if (vars->map[vars->i][vars->j] == '1'
				|| vars->map[vars->i][vars->j] == ' '
				|| check_player(vars->map[vars->i][vars->j]))
			{
				vars->j++;
				continue ;
			}
			vars->j++;
		}
		vars->i++;
	}
}

void	map_check_1(t_vars *vars)
{
	while (vars->map[vars->i])
	{
		vars->j = 0;
		while (vars->map[vars->i][vars->j])
		{
			if ((vars->map[vars->i][vars->j] == '0'
				&& (vars->i - 1 >= 0 && vars->j - 1 >= 0
					&& (check_help(vars->map[vars->i + 1][vars->j])
					&& check_help(vars->map[vars->i - 1][vars->j])
				&& check_help(vars->map[vars->i][vars->j + 1])
				&& check_help(vars->map[vars->i][vars->j - 1]))))
				|| check_it(vars->map[vars->i][vars->j]))
			{
				vars->j++;
				continue ;
			}
			else
			{
				ft_putstr_fd("map not surrounded by walls !\n", 2);
				exit (1);
			}
			vars->j++;
		}
		vars->i++;
	}
}

void	check_files(t_vars *vars)
{
	int		i;

	i = 0;
	while (vars->map[i])
	{
		if (!ft_strncmp(vars->map[i], "NO", 2))
			vars->no = mlx_load_png(vars->map[i] + 3);
		else if (!ft_strncmp(vars->map[i],  "SO", 2))
			vars->so = mlx_load_png(vars->map[i] + 3);
		else if (!ft_strncmp(vars->map[i],  "WE", 2))
			vars->we = mlx_load_png(vars->map[i] + 3);
		else if (!ft_strncmp(vars->map[i],  "EA", 2))
			vars->ea = mlx_load_png(vars->map[i] + 3);
		i++;
	}
}

void	check_colors(t_vars *vars)
{
	int		i;
	char	**tmp;
	char	*tmp1;

	i = 0;
	while (vars->map[i])
	{
		tmp1 = ft_substr(vars->map[i], 0, 2);
		if (!ft_strncmp(tmp1, "F ", 2))
		{
			tmp = ft_split(vars->map[i] + 2, ',');
			vars->F = get_rgba(ft_atoi(tmp[0]), ft_atoi(tmp[1]),
					ft_atoi(tmp[2]), 255);
			ft_freeall(tmp, ft_count(vars->map[i], ','));
		}
		else if (!ft_strncmp(tmp1, "C ", 2))
		{
			tmp = ft_split(vars->map[i] + 2, ',');
			vars->C = get_rgba(ft_atoi(tmp[0]), ft_atoi(tmp[1]),
					ft_atoi(tmp[2]), 255);
			ft_freeall(tmp, ft_count(vars->map[i], ','));
		}
		free(tmp1);
		i++;
	}
}

void	parser(char *par, t_vars *vars)
{
	t_collectives	col;

	vars->fd = open(par, O_RDONLY);
	if (vars->fd < 0)
	{
		ft_putstr_fd("Error!\ncan't open file", 2);
		exit(1);
	}
	vars->F = -1;
	vars->C = -1;
	vars->s = get_next_line(vars->fd);
	vars->map = ft_split(vars->s, '\n');
	check_files(vars);
	check_colors(vars);
	check_path(vars);
	vars->i = 6;
	map_check(vars);
	vars->i = 6;
	map_check_1(vars);
	all_in(vars->map, &col);
}
