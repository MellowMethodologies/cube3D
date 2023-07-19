/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:33:04 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/19 08:09:02 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

unsigned int	*ft_get_pixels(uint8_t *pxl, uint32_t count)
{
	unsigned int	*texture;
	unsigned int	*tmp;
	int				i;

	i = 0;
	texture = (unsigned int *)malloc(sizeof(unsigned int) * count);
	if (!texture)
		ft_abort(1);
	tmp = texture;
	while (i < (int)count)
	{
		tmp[i++] = get_rgba(*pxl, *(pxl + 1), *(pxl + 2), *(pxl + 3));
		pxl += 4;
	}
	return (texture);
}

void	ft_get_image(t_data *data, t_vars *vars)
{
	data->no = ft_get_pixels(vars->NO->pixels, vars->NO->height
			* vars->NO->width);
	data->so = ft_get_pixels(vars->SO->pixels, vars->SO->height
			* vars->SO->width);
	data->we = ft_get_pixels(vars->WE->pixels, vars->WE->height
			* vars->WE->width);
	data->ea = ft_get_pixels(vars->EA->pixels, vars->EA->height
			* vars->EA->width);
}
