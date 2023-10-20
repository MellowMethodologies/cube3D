/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:33:04 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/26 16:08:06 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

int	get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

unsigned int	*ft_get_pixels(uint8_t *pxl, uint32_t count)
{
	unsigned int	*texture;
	unsigned int	*tmp;
	uint32_t		i;

	i = 0;
	texture = (unsigned int *)malloc(sizeof(unsigned int) * count);
	if (!texture)
		ft_abort(1);
	tmp = texture;
	while (i < count)
	{
		tmp[i++] = get_rgba(*pxl, *(pxl + 1), *(pxl + 2), *(pxl + 3));
		pxl += 4;
	}
	return (texture);
}

void	ft_get_image(t_data *data, t_vars *vars)
{
	data->no = ft_get_pixels(vars->no->pixels, vars->no->height
			* vars->no->width);
	data->so = ft_get_pixels(vars->so->pixels, vars->so->height
			* vars->so->width);
	data->we = ft_get_pixels(vars->we->pixels, vars->we->height
			* vars->we->width);
	data->ea = ft_get_pixels(vars->ea->pixels, vars->ea->height
			* vars->ea->width);
}
