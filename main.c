/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelehov <dmelehov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 22:34:59 by dmelehov          #+#    #+#             */
/*   Updated: 2017/06/11 18:08:03 by dmelehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_burnship(t_fractol *drugs, double pr, double pi, int iter)
{
	drugs->iter = iter;
	drugs->new_re = drugs->old_re * drugs->old_re -
		drugs->old_im * drugs->old_im;
	drugs->new_im = 2 * fabs(drugs->old_re * drugs->old_im);
	drugs->old_re = drugs->new_re + pr;
	drugs->old_im = drugs->new_im + pi;
}

void	burnship(t_fractol *drugs)
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
				calc_burnship(drugs, pr, pi, iter++);
			if (iter < drugs->max_iter)
				img_ppx(drugs, drugs->x, drugs->y);
			(drugs->x)++;
		}
		(drugs->y)++;
	}
}

void	error_manager(int error_num)
{
	if (error_num == 1)
	{
		write(1, "usage: ./fractol [number]\n", 26);
		write(1, "1 - mandelbrot\n2 - julia\n3 - burnship\n", 38);
	}
	else if (error_num == 2)
		write(1, "error: invalid file\n", 20);
	exit(-1);
}

void	fractal_manager(int type, t_fractol *drugs)
{
	if (type == 1)
		mandelbrot(drugs);
	else if (type == 2)
		julia(drugs);
	else if (type == 3)
		burnship(drugs);
	else
		exit(0);
}

int		main(int argc, char **argv)
{
	t_fractol	drugs;

	if (argc != 2)
		error_manager(1);
	drugs.type = ft_atoi(argv[1]);
	if (drugs.type < 1 && drugs.type > 3)
		error_manager(2);
	get_struct_data(&drugs);
	create_image(&drugs);
	fractal_manager(drugs.type, &drugs);
	start_drawing(&drugs);
	return (0);
}
