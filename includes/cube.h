/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:19:21 by sbadr             #+#    #+#             */
/*   Updated: 2023/07/28 10:52:13 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "./libft.h"
# include <limits.h>

# define FOV 0.5235987756
# define HEIGHT 1080
# define WIDTH 1920
# define TILE_SIZE 64
# define ROTATION_SPEED 1
# define ACC 1

typedef struct vars
{
	int				i;
	int				j;
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	int				f;
	int				c;
	int				len;	
	int				fd;
	char			*s;
	char			**map;
}	t_vars;

typedef struct s_ray
{
	double	angle;
	double	xwall;
	double	ywall;
	double	distance;
}t_ray;

typedef struct collections{
	int	j;
	int	i;
	int	len;
	int	t;
	int	p;	
}	t_collectives;

typedef struct coordinates{
	int				offsetx;
	int				offsety;
	double			wall_hight;
	double			wall_top;
	double			wall_bottom;
	size_t			y;

}	t_coordinates;

typedef struct s_data
{
	int				i;
	int				j;
	int				*a;
	int				pl[3];
	unsigned int	*no;
	unsigned int	*so;
	unsigned int	*we;
	unsigned int	*ea;
	double			dist;
	double			ongle;
	char			hit;
	size_t			count;
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	mlx_image_t		*map;
	mlx_texture_t	png;
	t_vars			*vars;
	double			hit_x;
	double			hit_y;
	int32_t			mouse_x;
	int32_t			mouse_y;
	int32_t			mouse_x_old;
	int32_t			mouse_y_old;
	size_t			height;
	size_t			width;
	int				num_rays;
	double			p_x;
	double			p_y;
	double			p_rad;
	double			dis_bt_a_p;
	char			**str;
	void			*mlx;
	void			*window;
	t_coordinates	cord;
}	t_data;

int				is_there_a_wall(double x, double y, t_data *data);
int				check_it(int c);
void			remplisage(char **str, t_collectives *col);
void			all_in(char **str, t_collectives *col);
int				check_help(int c);
int				check_player(int c);
void			check_path(t_vars *vars);
double			ds_between_two_points(double x, double y, double x1, double y1);
void			circled(double *x);
double			find_hr(t_data *data, double a_x, double a_y, double rotation);
double			find_vr(t_data *data, double a_x, double a_y, double rotation);
void			error(void);
int				get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
int				is_there_a_wall_1(double x, double y, t_data *data);
void			draw_player(t_data	*data);
void			ft_textures(t_data *data, t_vars *vars);
void			ft_event(void *dat);
void			ft_abort(int id);
char			*get_next_line(int fd);
size_t			ft_strlen_b(char *str);
char			*ft_strdup_b(char *src);
char			*ft_strjoin_b(char *s1, char *s2);
void			ft_putchar_fd(char c, int fd);
char			*get_next_line(int fd);
void			ft_putstr_fd(char *s, int fd);
void			parser(char *par, t_vars *vars);
void			map_check(t_vars *vars);
int				check_player(int c);
void			ft_get_image(t_data *data, t_vars *vars);
void			draw_wall(t_data *data, int i, double dist);
void			draw_mini_map(t_data *data);
void			ft_hooks(t_data *data);
void			ft_hooks_(t_data *data);
void			norme_it(t_data *data);
void			ft_event(void *dat);
double			ds_between_two_points(double x, double y, double x1, double y1);
void			ft_draw_wall_no(t_data *data, int x, int j);
void			ft_draw_wall_so(t_data *data, int x, int j);
void			ft_draw_wall_we(t_data *data, int x, int j);
void			ft_draw_wall_ea(t_data *data, int x, int j);

#endif