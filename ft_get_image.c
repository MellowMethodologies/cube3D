/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:33:04 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/10 10:50:53 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_get_image(t_data *data)
{
	mlx_texture_t*	png;
	uint8_t *tmp;
	int count = 0;
	unsigned int *tmp2;

	png = mlx_load_png("./textures/Background.png");
	if (!png)
		ft_abort(3);
	tmp = png->pixels;
	while (*png->pixels)
	{
		count ++;
		png->pixels += 4;
	}
	data->img = malloc(sizeof(unsigned int) * count + 1);
	tmp2 = data->img;
	while(*tmp)
	{
		*tmp2 = get_rgba(*tmp, *(tmp + 1), *(tmp + 2), *(tmp + 3));
		tmp2++;
		tmp += 4;
	}
	*tmp2 = 0;
	// exit (0);
	// printf("%hhu\n", *(png->pixels + 1));
	// printf("%hhu\n", *(png->pixels + 2));
	// printf("%hhu\n", *(png->pixels + 3));
	// printf("%X\n", get_rgba(*png->pixels, (*(png->pixels + 1)), (*(png->pixels + 2)), (*(png->pixels + 3))));

}
