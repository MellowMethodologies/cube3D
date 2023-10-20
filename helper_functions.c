/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:20:51 by sbadr             #+#    #+#             */
/*   Updated: 2023/07/26 16:16:06 by sbadr            ###   ########.fr       */
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

int	check_help(int c)
{
	if (c == '1' || c == '0' || c == 'W' || c == 'N' || c == 'E' || c == 'S')
		return (1); 
	return (0);
}

int	check_player(int c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
		return (1);
	return (0);
}

void	check_path(t_vars *vars)
{
	if (!vars->ea || !vars->no || !vars->so || !vars->we)
		error();
}
