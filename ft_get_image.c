/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:33:04 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/09 18:58:58 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_get_image(t_data *data)
{
	mlx_texture_t*	png;
	uint8_t *tmp;
	int count = 0;
	unsigned int *img;
	unsigned int *tmp2;

	png = mlx_load_png("./textures/Background.png");
	tmp = png->pixels;
	while (*png->pixels)
	{
		count ++;
		png->pixels += 4;
	}
	img = malloc(sizeof(unsigned int) * count + 1);
	tmp2 = img;
	while(*tmp)
	{
		*img = get_rgba(*tmp, *(tmp + 1), *(tmp + 2), *(tmp + 3));
		img++;
		tmp += 4;
	}
	*img = 0;
	while(*tmp2)
	{
		printf("%X\n", *tmp2);
		tmp2++;		
	}
		printf("%X\n", *tmp2);
	write(1, "ENDE\n", 5);
	// exit (0);
	// printf("%hhu\n", *(png->pixels + 1));
	// printf("%hhu\n", *(png->pixels + 2));
	// printf("%hhu\n", *(png->pixels + 3));
	// printf("%X\n", get_rgba(*png->pixels, (*(png->pixels + 1)), (*(png->pixels + 2)), (*(png->pixels + 3))));

}
