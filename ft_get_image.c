/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:33:04 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/11 11:44:24 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_get_image(t_data *data)
{
	uint8_t *tmp;
	int count = 0;
	unsigned int *tmp2;

	data->png = mlx_load_png("./textures/Background.png");
	if (!data->png)
		ft_abort(3);
	// 	printf("%d\n", data->png->bytes_per_pixel);
	// exit (0);
	tmp = data->png->pixels;
	while (*data->png->pixels)
	{
		count ++;
		data->png->pixels += 4;
	}
	data->img = (unsigned int *)malloc(sizeof(unsigned int) * count + 1);
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