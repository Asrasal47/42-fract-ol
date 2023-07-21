/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:38:34 by arasal            #+#    #+#             */
/*   Updated: 2022/08/03 03:55:46 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_help *help)
{
	t_complex	z;
	t_complex	c;
	int			n;

	c.x = ((double)help->xpos - help->centrx) / (help->zoom * W / 4);
	c.y = (help->centry - (double)help->ypos) / (help->zoom * H / 4);
	z.x = 0;
	z.y = 0;
	n = 0;
	while (n <= help->it)
	{
		z = add(square(z), c);
		if (z.x * z.x + z.y * z.y > 4)
			break ;
		n++;
	}
	return (n);
}

void	create_image2(t_help *help)
{
	help->xpos = -1;
	help->img = mlx_new_image(help->mlx, W, H);
	while (++help->xpos < W)
	{
		help->ypos = -1;
		while (++help->ypos < H)
		{
			help->ju = mandelbrot(help);
			if (help->ju > help->it)
				mlx_put_pixel(help->img, help->xpos, help->ypos, create_trgb
					((log2(help->ju) * 255 / 7) + log2(help->trgb2),
						help->trgb1 / -2, (log2(help->ju) * 255 / 5), 255));
			else if (help->ju > help->it / 2)
				mlx_put_pixel(help->img, help->xpos, help->ypos, create_trgb
					((log2(help->ju) * 255 / 7) + log2(help->trgb2 * 100),
						help->trgb1 / -2, (log2(help->ju) * 255 / 7), 255));
			else
				mlx_put_pixel(help->img, help->xpos, help->ypos, create_trgb
					((log2(help->ju) * 255 / 7) + log2(help->trgb2),
						help->trgb1 / 2, help->xpos / 10, 255));
		}
	}
	mlx_image_to_window(help->mlx, help->img, 0, 0);
}
