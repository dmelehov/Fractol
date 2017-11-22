/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 17:33:17 by dmelehov          #+#    #+#             */
/*   Updated: 2017/06/11 17:40:53 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_fractol *drugs, double shift, int i)
{
	mlx_destroy_image(drugs->mlx, drugs->img);
	drugs->x = 0;
	drugs->y = 0;
	if (i == 0)
	{
		drugs->min_cx += shift;
		drugs->max_cx += shift;
	}
	else if (i == 1)
	{
		drugs->min_cy += shift;
		drugs->max_cy += shift;
	}
	create_image(drugs);
	if (drugs->type == 1)
		mandelbrot(drugs);
	else if (drugs->type == 2)
		julia(drugs);
	else if (drugs->type == 3)
		burnship(drugs);
	mlx_put_image_to_window(drugs->mlx, drugs->win, drugs->img, 0, 0);
}

int		key_manager(int key, void *param)
{
	if (key == 53)
		exit(0);
	if (key == 24)
		zoom(param, 1.1);
	if (key == 27)
		zoom(param, 0.9);
	if (key == 123)
		move(param, 0.05, 0);
	if (key == 124)
		move(param, -0.05, 0);
	if (key == 126)
		move(param, 0.05, 1);
	if (key == 125)
		move(param, -0.05, 1);
	return (0);
}

int		mouse_manager(int key, int x, int y, t_fractol *drugs)
{
	drugs->zxp = x;
	drugs->zyp = y;
	if (key == 5)
		zoom(drugs, 1.1);
	if (key == 4)
		zoom(drugs, 0.9);
	if (drugs->type == 2)
		mlx_hook(drugs->win, 6, 0, julia_scroll, drugs);
	return (0);
}

void	zoom(t_fractol *drugs, double z)
{
	mlx_destroy_image(drugs->mlx, drugs->img);
	drugs->x = 0;
	drugs->y = 0;
	drugs->zoom = z;
	get_zoom_scale(drugs);
	create_image(drugs);
	if (drugs->type == 1)
		mandelbrot(drugs);
	else if (drugs->type == 2)
		julia(drugs);
	else if (drugs->type == 3)
		burnship(drugs);
	mlx_put_image_to_window(drugs->mlx, drugs->win, drugs->img, 0, 0);
}

void	get_zoom_scale(t_fractol *drugs)
{
	drugs->move_x = modify_value(drugs->zxp, WIN_X,
		drugs->min_cx, drugs->max_cx);
	drugs->move_y = modify_value(drugs->zyp, WIN_Y,
		drugs->min_cy, drugs->max_cy);
	drugs->min_cx = (drugs->min_cx * drugs->zoom) +
		(drugs->move_x * (1 - drugs->zoom));
	drugs->max_cx = (drugs->max_cx * drugs->zoom) +
		(drugs->move_x * (1 - drugs->zoom));
	drugs->min_cy = (drugs->min_cy * drugs->zoom) +
		(drugs->move_y * (1 - drugs->zoom));
	drugs->max_cy = (drugs->max_cy * drugs->zoom) +
		(drugs->move_y * (1 - drugs->zoom));
}
