/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 22:43:54 by dmelehov          #+#    #+#             */
/*   Updated: 2017/06/11 18:03:24 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/includes/libft.h"
# include <math.h>
# include <mlx.h>

# define WIN_X 720
# define WIN_Y 720
# define COLOR 0xffffff

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			type;
	int			bpp;
	int			size_line;
	int			endian;
	int			x;
	int			y;
	int			max_iter;
	int			iter;
	int			color;
	int			r;
	int			g;
	int			b;
	double		min_cx;
	double		min_cy;
	double		max_cx;
	double		max_cy;
	double		zoom;
	double		move_x;
	double		move_y;
	double		zxp;
	double		zyp;
	double		old_re;
	double		old_im;
	double		new_re;
	double		new_im;
}				t_fractol;

void			move(t_fractol *drugs, double shift, int i);
int				key_manager(int key, void *param);
int				mouse_manager(int key, int x, int y, t_fractol *drugs);
void			zoom(t_fractol *drugs, double z);
int				julia_scroll(int x, int y, t_fractol *drugs);
void			get_zoom_scale(t_fractol *drugs);
void			calc_julia(t_fractol *drugs, int iter);
void			julia(t_fractol *drugs);
void			calc_mandelbrot(t_fractol *drugs, double pr,
		double pi, int iter);
void			mandelbrot(t_fractol *drugs);
void			start_drawing(t_fractol *drugs);
void			get_struct_data(t_fractol *drugs);
void			fractal_manager(int type, t_fractol *drugs);
void			error_manager(int error_num);
void			create_image(t_fractol *drugs);
void			burnship(t_fractol *drugs);
void			calc_burnship(t_fractol *drugs, double pr, double pi, int iter);
void			img_ppx(t_fractol *drugs, int x, int y);
double			modify_value(double x, int win_max,
		double to_min, double to_max);

#endif
