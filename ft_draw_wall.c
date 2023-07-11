/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:40:19 by idabligi          #+#    #+#             */
/*   Updated: 2023/07/11 15:16:23 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

unsigned int	*ft_get_dir(t_data *data)
{
	if (data->ongle >= 0 && data->ongle < (M_PI / 2))
	{
		if (data->hit == 'V')
			return data->ea;
		else
			return data->so;
	}
	else if (data->ongle >= (M_PI / 2) && data->ongle < M_PI)
	{
		if (data->hit == 'V')
			return data->we;
		else
			return data->so;
	}
	else if (data->ongle >= M_PI && data->ongle < ((3 * M_PI) / 2))
	{
		if (data->hit == 'V')
			return data->we;
		else
			return data->no;
	}
	else if (data->ongle >= ((3 * M_PI) / 2) && data->ongle < (2 * M_PI))
	{
		if (data->hit == 'V')
			return data->ea;
		else
			return data->no;
	}
	return 0;
}
