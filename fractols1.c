/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 17:38:39 by dmelehov          #+#    #+#             */
/*   Updated: 2017/06/11 18:08:30 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_scroll(int x, int y, t_fractol *drugs)
{
	mlx_destroy_image(drugs->mlx, drugs->img);
	drugs->x = 0;
	drugs->y = 0;
	drugs->zxp = x;
	drugs->zyp = y;
	create_image(drugs);
	if (drugs->type == 2)
		julia(drugs);
	mlx_put_image_to_window(drugs->mlx, drugs->win, drugs->img, 0, 0);
	return (0);
}

void	calc_julia(t_fractol *drugs, int iter)
{
	double	pr;
	double	pi;

	drugs->iter = iter;
	pr = modify_value(drugs->zxp, WIN_X, drugs->min_cx, drugs->max_cx);
	pi = modify_value(drugs->zyp, WIN_Y, drugs->min_cy, drugs->max_cy);
	drugs->new_re = drugs->old_re * drugs->old_re -
		drugs->old_im * drugs->old_im;
	drugs->new_im = 2 * drugs->old_re * drugs->old_im;
	drugs->old_re = drugs->new_re + pr;
	drugs->old_im = drugs->new_im + pi;
}

void	julia(t_fractol *drugs)
{
	int	iter;

	while (drugs->y < WIN_Y)
	{
		drugs->x = 0;
		while (drugs->x < WIN_X)
		{
			drugs->old_re = modify_value(drugs->x, WIN_X,
				drugs->min_cx, drugs->max_cx);
			drugs->old_im = modify_value(drugs->y, WIN_Y,
				drugs->min_cy, drugs->max_cy);
			iter = 0;
			while (drugs->old_re * drugs->old_re +
				drugs->old_im * drugs->old_im <= 4 && iter < drugs->max_iter)
			{
				calc_julia(drugs, iter);
				iter++;
			}
			if (iter < drugs->max_iter)
				img_ppx(drugs, drugs->x, drugs->y);
			(drugs->x)++;
		}
		(drugs->y)++;
	}
}

void	calc_mandelbrot(t_fractol *drugs, double pr, double pi, int iter)
{
	drugs->iter = iter;
	drugs->new_re = drugs->old_re * drugs->old_re -
		drugs->old_im * drugs->old_im;
	drugs->new_im = 2 * drugs->old_re * drugs->old_im;
	drugs->old_re = drugs->new_re + pr;
	drugs->old_im = drugs->new_im + pi;
}

void	mandelbrot(t_fractol *drugs)
{
	double	pr;
	double	pi;
	int		iter;

	while (drugs->y < WIN_Y)
	{
		drugs->x = 0;
		while (drugs->x < WIN_X)
		{
			drugs->old_re = modify_value(drugs->x, WIN_X,
				drugs->min_cx, drugs->max_cx);
			drugs->old_im = modify_value(drugs->y, WIN_Y,
				drugs->min_cy, drugs->max_cy);
			iter = 0;
			pr = drugs->old_re;
			pi = drugs->old_im;
			while (drugs->old_re * drugs->old_re +
				drugs->old_im * drugs->old_im <= 4 && iter < drugs->max_iter)
				calc_mandelbrot(drugs, pr, pi, iter++);
			if (iter < drugs->max_iter)
				img_ppx(drugs, drugs->x, drugs->y);
			(drugs->x)++;
		}
		(drugs->y)++;
	}
}
