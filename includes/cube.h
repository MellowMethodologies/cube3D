#ifndef CUBE_H
# define CUBE_H

// # include <mlx.h>
# include "MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
#include "../libft/libft.h"

# define FOV 60 * (M_PI / 180)
# define WALL_THICKNESS 4
# define HEIGHT 1080
# define WIDTH 1920
# define TILE_SIZE 50


typedef struct vars
{
	int		i;
	int		j;
	mlx_texture_t 	*NO;
	mlx_texture_t	*SO;
	mlx_texture_t 	*WE;
	mlx_texture_t	*EA;
	int 	F;
	int		C;
	int		len;	
	int		fd;
	char	*s;
	char	**map;
}	t_vars;

typedef struct s_ray
{
	float angle;
	float xwall;
	float ywall;
	float distance;
}t_ray;

typedef struct collections{
	int	j;
	int	i;
	int	len;
	int	t;
	int	p;	
}	t_collectives;

typedef struct s_data
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	mlx_texture_t*	png;
	double			hit_x;
	double			hit_y;
	int32_t			mouse_x;
	int32_t			mouse_y;
	int32_t			mouse_x_old;
	int32_t			mouse_y_old;
	size_t				height;
	size_t				width;
	unsigned int 	*img;
	int				num_rays;
	double			p_x;
	double			p_y;
	double			p_rad;
	double			dis_bt_a_p;
	char			**str;
	void			*mlx;
	void			*window;
}   t_data;

void	 error(void);
int 	get_rgba(int r, int g, int b, int a);
int		is_there_a_wall_1(double x, double y, t_data *data);
void	draw_player(t_data	*data);
int		ft_isspace(int i);
void	ft_textures(t_data *data, t_vars *vars);
int		ft_destroy(t_data *data);
void	ft_event(void *dat);
void	ft_end(int sig);
void	ft_draw(t_data *data);
void	ft_abort(int id);
char	*ft_strdup(const char *src);
char	*ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
size_t	ft_strlen_b(char *str);
char	*ft_strdup_b(char *src);
char	*ft_strjoin_b(char *s1, char *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	p_fill(t_vars *vars);
char	*get_next_line(int fd);

void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
void	parser(char *par, t_vars *vars);
int		is_there_a_wall(double x, double y, t_data *data);
void	map_check(t_vars *vars);
int		check_player(int c);
void	ft_get_image(t_data *data);

#endif