#ifndef CUBE_H
# define CUBE_H

// # include <mlx.h>
# include "/Users/sbadr/Desktop/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

# define FOV 60 * (M_PI / 180)

typedef struct vars
{
	int		i;
	int		j;
	int		len;	
	int		fd;
	char	*s;
	char	**map;
}	t_vars;

typedef struct collections{
	int	j;
	int	i;
	int	len;
	int	t;
	int	p;	
}	t_collectives;

typedef struct s_data
{

	int				height;
	int				width;
	mlx_image_t		*image;
	double			p_x;
	double			p_y;
	double			a_x;
	double			a_y;
	double			p_rad;
	double			dis_bt_a_p;
	char			**str;
	void			*mlx;
	void			*window;
}   t_data;

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
void 	draw_player(t_data	*data);
void	ft_putnbr_fd(int nb, int fd);
void	p_fill(t_vars *vars);
char	*get_next_line(int fd);
int		ft_strlen(const char *str);
int		ft_count(char const *s, char c);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s1);
void	parser(char *par, t_vars *vars);
int		is_there_a_wall(double x, double y, t_data *data);
void	map_check(t_vars *vars);
int		check_player(int c);

#endif