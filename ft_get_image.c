/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:33:04 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/11 14:21:39 by idabligi         ###   ########.fr       */
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
	int count = 0;
	unsigned int *tmp2;

	tmp = pixels;
	while(*pixels)
	{
		count++;
		pixels += 4;
	}
	texture = (unsigned int *)malloc(sizeof(unsigned int) * count + 1);
	if (!texture)
		ft_abort(1);
	tmp2 = texture;
	while (*tmp)
	{
		*tmp2 = get_rgba(*tmp, *(tmp + 1), *(tmp + 2), *(tmp + 3));
		tmp2++;
		tmp += 4;
	}
	*tmp2 = 0;
	return (texture);
}

void	ft_get_image(t_data *data, t_vars *vars)
{
	data->no = ft_get_pixels(vars->NO->pixels);
	// ft_get_pixels(data->so, vars->SO->pixels);
	// ft_get_pixels(data->we, vars->WE->pixels);
	// ft_get_pixels(data->ea, vars->EA->pixels);
}

// void	ft_get_image(t_data *data, t_vars *vars)
// {
// 	uint8_t *tmp;
// 	int count = 0;
// 	unsigned int *tmp2;

// 	tmp = vars->NO->pixels;
// 	while (*vars->NO->pixels)
// 	{
// 		count ++;
// 		vars->NO->pixels += 4;
// 	}
// 	data->no = (unsigned int *)malloc(sizeof(unsigned int) * count + 1);
// 	tmp2 = data->no;
// 	while(*tmp)
// 	{
// 		*tmp2 = get_rgba(*tmp, *(tmp + 1), *(tmp + 2), *(tmp + 3));
// 		tmp2++;
// 		tmp += 4;
// 	}
// 	*tmp2 = 0;
// 	// exit (0);
// 	// printf("%hhu\n", *(png->pixels + 1));
// 	// printf("%hhu\n", *(png->pixels + 2));
// 	// printf("%hhu\n", *(png->pixels + 3));
// 	// printf("%X\n", get_rgba(*png->pixels, (*(png->pixels + 1)), (*(png->pixels + 2)), (*(png->pixels + 3))));

// }