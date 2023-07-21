/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:32:33 by arasal            #+#    #+#             */
/*   Updated: 2022/08/03 01:18:04 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "MLX42/MLX42.h"
# include "Libft/libft.h"
# include "get_next_line_bonus.h"
# include <math.h>
# define W 500
# define H 500

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_help
{
	int				i;
	int				j;
	int				ju;
	int				ma;
	int				ne;
	double			centrx;
	double			centry;
	int				xpos;
	int				ypos;
	int				cx;
	int				cy;
	int				trgb1;
	int				trgb2;
	double			zoom;
	int				fractol;
	double			c;
	double			d;
	double			z;
	double			x;
	double			root;
	double			it;
	mlx_t			*mlx;
	mlx_image_t		*img;
}			t_help;

int			julia(t_help *help);
void		create_image(t_help *help);
int			mandelbrot(t_help *help);
void		create_image2(t_help *help);
t_complex	add(t_complex z, t_complex c);
t_complex	square(t_complex z);
t_complex	cube(t_complex z);
int			create_trgb(int t, int r, int g, int b);
void		parameters1(t_help *help);
void		parameters2(t_help *help);
void		parameters_julia(t_help *help);
void		select_image(t_help *help);
void		hook(void *param);
void		hook2(void *param);
void		hook3(void *param);
void		hook4(void *param);
void		my_scrollhook(double xdelta, double ydelta, void *param);
void		init(t_help *help, mlx_t *mlx);
double		ft_atof(char *str, t_help *help);
void		ft_put(t_help *help);
void		ft_sign(char l, double *i, double *j);
int			newton(t_help *help);
void		create_image3(t_help *help);
t_complex	divide(t_complex z1, t_complex z2);
t_complex	multiply(t_complex z, double c);

#endif