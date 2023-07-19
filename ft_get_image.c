/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:33:04 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/19 11:23:48 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_get_pixels(unsigned int *dir, uint8_t *pxl, uint32_t count)
{
	long		i;

	i = 0;
	// texture = (unsigned int *)malloc(sizeof(unsigned int) * count);
	// if (!texture)
	// 	ft_abort(1);
	while (i < (int)count)
	{
		dir[i++] = get_rgba(*pxl, *(pxl + 1), *(pxl + 2), *(pxl + 3));
		pxl += 4;
	}
}

void	ft_get_image(t_data *data, t_vars *vars)
{
	ft_get_pixels(data->no, vars->NO->pixels, vars->NO->height
			* vars->NO->width);
	ft_get_pixels(data->so, vars->SO->pixels, vars->SO->height
			* vars->SO->width);
	ft_get_pixels(data->we, vars->WE->pixels, vars->WE->height
			* vars->WE->width);
	ft_get_pixels(data->ea, vars->EA->pixels, vars->EA->height
			* vars->EA->width);
}
