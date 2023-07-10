/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:37:29 by sbadr             #+#    #+#             */
/*   Updated: 2023/07/10 10:50:53 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

void	remplisage(char **str, t_collectives *col)
{
	col->i = 6;
	col->t = 0;
	col->len = ft_strlen(str[0]);
	col->p = 0;
}

void	all_in(char **str, t_collectives *col)
{
	remplisage(str, col);
	while (str[col->i])
	{
		col->j = 0;
		while (str[col->i][col->j])
		{
			if (str[col->i][col->j] == 'N' || str[col->i][col->j] == 'W' \
			|| str[col->i][col->j] == 'E' || str[col->i][col->j] == 'S' )
				col->p += 1;
			col->j++;
		}
		col->i++;
	}
	if (col->p != 1)
	{
		ft_putstr_fd("Error!\nchars invalid remember : 1P\n", 2);
		exit(1);
	}
}

int		check_help(int c)
{
	if (c == '1' || c == '0' || c == 'W' || c == 'N' || c == 'E' || c == 'S')
		return 1;
	return 0;
}

int		check_player(int c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
		return 1;
	return 0;
}

void	map_check(t_vars *vars)
{
	vars->i = 6;
	while (vars->map[vars->i])
	{
		vars->j = 0;
		while (vars->map[vars->i][vars->j])
		{
			if (vars->map[vars->i][vars->j] == '1' || vars->map[vars->i][vars->j] == ' ' || check_player(vars->map[vars->i][vars->j]))
			{	
				vars->j++;
				continue;
			}
			else if (vars->map[vars->i][vars->j] == '0' && (vars->i - 1 >= 0 && vars->j - 1 >= 0 && (check_help(vars->map[vars->i + 1][vars->j]) \
			&& check_help(vars->map[vars->i - 1][vars->j]) && check_help(vars->map[vars->i][vars->j + 1])\
			&& check_help(vars->map[vars->i][vars->j - 1]))))
			{
				vars->j++;
				continue;
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

void	parser(char *par, t_vars *vars)
{
	t_collectives	col;

	vars->fd = open(par, O_RDONLY);
	if (vars->fd < 0)
	{
		ft_putstr_fd("Error!\ncan't open file", 2);
		exit(1);
	}
	vars->s = get_next_line(vars->fd);
	vars->map = ft_split(vars->s, '\n');
	map_check(vars);
	all_in(vars->map, &col);
}
