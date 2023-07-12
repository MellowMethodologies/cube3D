/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:33:04 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/12 11:11:00 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

unsigned int	*ft_get_pixels(uint8_t *pixels)
{
	unsigned int *texture;
	uint8_t *tmp;
	unsigned int *tmp2;
	int count = 0;

	tmp = pixels;
	texture = (unsigned int *)malloc(sizeof(unsigned int) * TILE_SIZE * TILE_SIZE + 1);
	if (!texture)
		ft_abort(1);
	tmp2 = texture;
	while (count < TILE_SIZE * TILE_SIZE)
	{
		*tmp2 = get_rgba(*tmp, *(tmp + 1), *(tmp + 2), *(tmp + 3));
		tmp2++;
		tmp += 4;
		count++;
	}
	return (texture);
}

void	ft_get_image(t_data *data, t_vars *vars)
{
	data->no = ft_get_pixels(vars->NO->pixels);
	data->so = ft_get_pixels(vars->SO->pixels);
	data->we = ft_get_pixels(vars->WE->pixels);
	data->ea = ft_get_pixels(vars->EA->pixels);
}
