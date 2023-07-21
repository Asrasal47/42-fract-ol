/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:47:27 by arasal            #+#    #+#             */
/*   Updated: 2022/08/03 01:24:18 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_help	*help;

	help = (t_help *)param;
	if (ydelta > 0)
	{
		help->zoom *= 2;
		mlx_get_mouse_pos(help->mlx, &help->i, &help->j);
		help->centrx = (double)(W / 2) + 2 * (help->centrx - help->i);
		help->centry = (double)(H / 2) + 2 * (help->centry - help->j);
		select_image(help);
	}
	if (ydelta < 0)
	{
		help->zoom *= 0.5;
		mlx_get_mouse_pos(help->mlx, &help->i, &help->j);
		help->centrx = (double)(W / 2) + 0.5 * (help->centrx - help->i);
		help->centry = (double)(H / 2) + 0.5 * (help->centry - help->j);
		select_image(help);
	}
	if (xdelta < 0)
		ft_putstr_fd("Sliiiide to the left!", 1);
	else if (xdelta > 0)
		ft_putstr_fd("Sliiiide to the right!", 1);
}

void	hook3(void *param)
{
	t_help	*help;

	help = (t_help *)param;
	if (mlx_is_mouse_down(help->mlx, MLX_MOUSE_BUTTON_MIDDLE))
	{
		mlx_get_mouse_pos(help->mlx, &help->trgb1, &help->trgb2);
		select_image(help);
	}
}

void	hook2(void *param)
{
	t_help	*help;

	help = (t_help *)param;
	if (mlx_is_mouse_down(help->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		help->c = 0;
		help->d = 0;
		mlx_get_mouse_pos(help->mlx, &help->cx, &help->cy);
		help->c = ((double)help->cx - (W / 2)) / (W / 4);
		help->d = ((H / 2) - (double)help->cy) / (H / 4);
		select_image(help);
	}
}

void	hook(void *param)
{
	t_help	*help;

	help = (t_help *)param;
	if (mlx_is_key_down(help->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(help->mlx);
	if (mlx_is_key_down(help->mlx, MLX_KEY_UP))
	{
		help->centry = help->centry + 100;
		select_image(help);
	}
	if (mlx_is_key_down(help->mlx, MLX_KEY_DOWN))
	{
		help->centry = help->centry - 100;
		select_image(help);
	}
	if (mlx_is_key_down(help->mlx, MLX_KEY_LEFT))
	{
		help->centrx = help->centrx + 100;
		select_image(help);
	}
	if (mlx_is_key_down(help->mlx, MLX_KEY_RIGHT))
	{
		help->centrx = help->centrx - 100;
		select_image(help);
	}
}

void	hook4(void *param)
{
	t_help	*help;

	help = (t_help *)param;
	if (mlx_is_key_down(help->mlx, MLX_KEY_KP_ADD))
	{	
		help->it += 50;
		select_image(help);
	}
	if (mlx_is_key_down(help->mlx, MLX_KEY_KP_SUBTRACT) && help->it > 150)
	{	
		help->it -= 50;
		select_image(help);
	}
}
