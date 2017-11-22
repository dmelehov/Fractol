/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 17:52:37 by dmelehov          #+#    #+#             */
/*   Updated: 2017/06/11 17:54:34 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_struct_data(t_fractol *drugs)
{
	drugs->mlx = mlx_init();
	drugs->win = mlx_new_window(drugs->mlx, WIN_X, WIN_Y, "SRAV");
	drugs->x = 0;
	drugs->y = 0;
	drugs->max_iter = 50;
	drugs->color = 0xffffff;
	drugs->r = 30;
	drugs->g = 20;
	drugs->b = 25;
	drugs->min_cx = -2;
	drugs->min_cy = -1;
	drugs->max_cx = 1;
	drugs->max_cy = 2;
	drugs->zxp = WIN_X / 2;
	drugs->zyp = WIN_Y / 2;
}

void	start_drawing(t_fractol *drugs)
{
	mlx_put_image_to_window(drugs->mlx, drugs->win, drugs->img, 0, 0);
	mlx_mouse_hook(drugs->win, mouse_manager, drugs);
	mlx_hook(drugs->win, 2, 5, key_manager, drugs);
	mlx_loop(drugs->mlx);
}

void	create_image(t_fractol *drugs)
{
	drugs->img = mlx_new_image(drugs->mlx, WIN_X, WIN_Y);
	drugs->bpp = 32;
	drugs->endian = 0;
	drugs->data = mlx_get_data_addr(drugs->img, &drugs->bpp,
		&drugs->size_line, &drugs->endian);
}

double	modify_value(double x, int win_max, double to_min, double to_max)
{
	return (x * ((to_max - to_min) / win_max) + to_min);
}

void	img_ppx(t_fractol *drugs, int x, int y)
{
	drugs->iter *= drugs->iter;
	drugs->data[((y * drugs->size_line) + (x * 4))] = (drugs->iter + drugs->b);
	drugs->data[((y * drugs->size_line) + (x * 4)) + 1] =
		(drugs->iter + drugs->g);
	drugs->data[((y * drugs->size_line) + (x * 4)) + 2] =
		(drugs->iter + drugs->r);
}
