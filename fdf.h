/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:19:32 by stde-la-          #+#    #+#             */
/*   Updated: 2023/01/30 21:19:33 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH				1400
# define HEIGHT				800
# define RAD_ANGLE			0.46365
# define HEXA_BASE			"0123456789ABCDEF"
# define LOADING_SYMBOLS	"\\|/-"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include <libft.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

enum {
	// ROTATE_Z_LEFT = 49,
	// ROTATE_Z_RIGHT = 50,
	// ROTATE_X_LEFT = 51,
	// ROTATE_X_RIGHT = 52,
	// ROTATE_Y_LEFT = 53,
	// ROTATE_Y_RIGHT = 54,
	// UP = 65362, 
	// DOWN = 65364, 
	// RIGHT = 65363, 
	// LEFT = 65361, 
	// ZOOM_IN = 61,
	// ZOOM_OUT = 45,
	// SCROLL_UP = 4,
	// SCROLL_DOWN = 5,
	// INCREASE_ALTITUDE = 119,
	// DECREASE_ALTITUDE = 115,
	// RESET = 114,
	// ESC = 65307,
	// PERSPECTIVE_TOGGLE = 112

	ROTATE_Z_LEFT = 18,
    ROTATE_Z_RIGHT = 19,
    ROTATE_X_LEFT = 20,
    ROTATE_X_RIGHT = 21,
    ROTATE_Y_LEFT = 22,
    ROTATE_Y_RIGHT = 23,
    UP = 126,
    DOWN = 125,
    RIGHT = 124,
    LEFT = 123,
    ZOOM_IN = 24,
    ZOOM_OUT = 27,
    SCROLL_UP = 4,
    SCROLL_DOWN = 5,
    INCREASE_ALTITUDE = 13,
    DECREASE_ALTITUDE = 1,
    RESET = 15,
    ESC = 53,
    PERSPECTIVE_TOGGLE = 112
};

enum {
	ZOOM = 1,
	TRANSLATION = 2,
	ROTATE_X = 4,
	ROTATE_Y = 5,
	ROTATE_Z = 6,
	ROTATION = 7,
	ALTITUDE = 8
};

typedef struct	s_rgb {
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}				t_rgb;

typedef struct	s_point {
	double	x;
	double	y;
	t_rgb	rgb;
	int		hexa;
}				t_point;

typedef struct	s_line {
	t_point	start;
	t_point	end;
}				t_line;

typedef struct	s_map {
	double	x;
	double	y;
	double	z;
	t_rgb	rgb;
	int		hexa;
}				t_map;

typedef struct	s_camera {
	double	zoom;
	double	x_offset;
	double	y_offset;
	double	x_rotate;
	double	y_rotate;
	double	z_rotate;
	double	altitude_sensibility;
	int		iso_projection;
}				t_camera;

typedef struct	s_img{
	void	*p;	
	char	*img_addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_data {
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		**map;
	int			map_height;
	int			map_width;
	t_camera	camera;
}				t_data;

void	init_camera(t_data *data);

int		handle_key(int key, t_data *data);

void	draw_line(t_data *data, t_point *a, t_point *b);
double	abs_double(double nb);

void	draw_menu(t_data *data);

int		pixel_color(t_point *curr, t_point *a, t_point *b);

void	loader(void);

t_map	**get_map(char *file_path, t_data *data);

int		get_map_width(char *map_line);
void	skip_spaces(char **map_line, int *index);

void	get_point_color(char *file, t_map *point, int *index);
int		rgb_to_hexa(t_rgb *rgb);

void	zoom(int key, double *zoom);
void	translate(int key, t_camera *camera);
void	adjust_altitude(int key, double *altitude_sensibility);
void	rotate(int key, t_camera *camera);

void	display_map(t_data *data);
int		is_point_inside_screen(double x, double y);

int		close_program(t_data *data);
void	free_map(t_data *data, int up_to);

void	rotate_x_axis(double rotation, t_map *point);
void	rotate_z_axis(double rotation, t_map *point);
void	rotate_y_axis(double rotation, t_map *point);
double	project_y(t_camera *camera, t_map *point);
double	project_x(t_camera *camera, t_map *point);

#endif
