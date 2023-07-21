/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:52:52 by arasal            #+#    #+#             */
/*   Updated: 2022/08/03 01:16:05 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	newton(t_help *help)
{
	t_complex	z;
	t_complex	c;
	t_complex	r;
	int			n;

	z.x = ((double)help->xpos - help->centrx) / (help->zoom * W / 4);
	z.y = (help->centry - (double)help->ypos) / (help->zoom * H / 4);
	c.x = -1;
	c.y = 0;
	n = 0;
	while (n <= help->it)
	{
		r = add(cube(z), c);
		if (r.x == 0 && r.y == 0)
		{
			help->root = z.y;
			break ;
		}
		z = add(z, divide(r, multiply(square(z), -3)));
		help->root = z.y;
		n++;
	}
	return (n);
}

void	create_image3(t_help *help)
{
	help->xpos = -1;
	help->img = mlx_new_image(help->mlx, W, H);
	while (++help->xpos < W)
	{
		help->ypos = -1;
		while (++help->ypos < H)
		{
			help->ne = newton(help);
			if (help->root > 0)
				mlx_put_pixel(help->img, help->xpos, help->ypos, create_trgb
					((log2(help->ne) * 255 / 7) + log2(help->trgb2),
						help->trgb1 / 10, 0, 255));
			else if (help->root < 0)
				mlx_put_pixel(help->img, help->xpos, help->ypos, create_trgb
					(help->trgb1 / 10, (log2(help->ne) * 255 / 7) + log2
						(help->trgb2 * 100), (log2(help->ne) * 255 / 7), 255));
			else if (help->root == 0)
				mlx_put_pixel(help->img, help->xpos, help->ypos, create_trgb
					((log2(help->ne) * 255 / 5), help->trgb1 / 10,
						(log2(help->ne) * 255 / 7) + log2(help->trgb2), 255));
		}
	}
	mlx_image_to_window(help->mlx, help->img, 0, 0);
}
