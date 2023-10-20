/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:37:29 by sbadr             #+#    #+#             */
/*   Updated: 2023/07/27 15:18:47 by sbadr            ###   ########.fr       */
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
	char	*tmp;

	i = 0;
	while (vars->map[i])
	{
		tmp = ft_substr(vars->map[i], 0, 3);
		if (!ft_strncmp(tmp, "NO ", 3))
			vars->no = mlx_load_png(vars->map[i] + 3);
		else if (!ft_strncmp(tmp, "SO ", 3))
			vars->so = mlx_load_png(vars->map[i] + 3);
		else if (!ft_strncmp(tmp, "WE ", 3))
			vars->we = mlx_load_png(vars->map[i] + 3);
		else if (!ft_strncmp(tmp, "EA ", 3))
			vars->ea = mlx_load_png(vars->map[i] + 3);
		free(tmp);
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
			vars->f = get_rgba(ft_atoi(tmp[0]), ft_atoi(tmp[1]),
					ft_atoi(tmp[2]), 255);
			ft_freeall(tmp, ft_count(vars->map[i], ','));
		}
		else if (!ft_strncmp(tmp1, "C ", 2))
		{
			tmp = ft_split(vars->map[i] + 2, ',');
			vars->c = get_rgba(ft_atoi(tmp[0]), ft_atoi(tmp[1]),
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
	vars->no = NULL;
	vars->we = NULL;
	vars->so = NULL;
	vars->ea = NULL;
	vars->f = -1;
	vars->c = -1;
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
