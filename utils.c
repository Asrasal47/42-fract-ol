/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:50:16 by arasal            #+#    #+#             */
/*   Updated: 2022/08/03 01:19:57 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	select_image(t_help *help)
{
	mlx_delete_image(help->mlx, help->img);
	if (help->fractol == 1)
		create_image(help);
	else if (help->fractol == 2)
		create_image2(help);
	else if (help->fractol == 3)
		create_image3(help);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	init(t_help *help, mlx_t *mlx)
{
	help->mlx = mlx;
	help->zoom = 1;
	help->i = 0;
	help->j = 0;
	help->cx = W / 4;
	help->cy = H / 4;
	help->root = 0;
	help->trgb1 = 10;
	help->trgb2 = 10;
	help->centrx = (double)(W / 2);
	help->centry = (double)(H / 2);
	if (help->fractol == 1)
		help->it = 105;
	else
		help->it = 200;
}

void	ft_put(t_help *help)
{
	if (help->x != 1)
	{
		ft_putstr_fd("Please enter a valid parameter\n", 1);
		ft_putstr_fd("Here are a few available parameters:\n", 1);
		ft_putstr_fd("A : -0.6+0.6i\n", 1);
		ft_putstr_fd("B : -0.8+0.4i\n", 1);
		ft_putstr_fd("C : -0.8+0.2i\n", 1);
		ft_putstr_fd("D : 0.39+0.6i\n", 1);
		help->x = 1;
	}
}
