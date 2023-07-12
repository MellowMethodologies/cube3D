/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:33:04 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/12 11:07:42 by idabligi         ###   ########.fr       */
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
	int i = 0;

	tmp = pixels;
	while(*tmp)
	{
		count++;
		tmp += 4;
	}
	texture = (unsigned int *)malloc(sizeof(unsigned int) * count + 1);
	if (!texture)
		ft_abort(1);
	tmp2 = texture;
	while (i < count)
	{
		tmp2[i++] = get_rgba(*pixels, *(pixels + 1), *(pixels + 2), *(pixels + 3));
		pixels += 4;
	}
	tmp2[i] = 0;
	return (texture);
}

void	ft_get_image(t_data *data, t_vars *vars)
{
	data->no = ft_get_pixels(vars->NO->pixels);
	data->so = ft_get_pixels(vars->SO->pixels);
	data->we = ft_get_pixels(vars->WE->pixels);
	data->ea = ft_get_pixels(vars->EA->pixels);
}
