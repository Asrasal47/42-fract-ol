/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:53:59 by arasal            #+#    #+#             */
/*   Updated: 2023/05/23 18:38:10 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	main(void)
{
	mlx_t		*mlx;
	t_help		help;

	parameters1(&help);
	mlx = mlx_init(W, H, "fract-ol", true);
	if (!mlx)
		return (EXIT_FAILURE);
	init(&help, mlx);
	select_image(&help);
	mlx_scroll_hook(mlx, &my_scrollhook, (void *)&help);
	if (help.fractol == 1)
		mlx_loop_hook(mlx, &hook2, (void *)&help);
	mlx_loop_hook(mlx, &hook, (void *)&help);
	mlx_loop_hook(mlx, &hook3, (void *)&help);
	mlx_loop_hook(mlx, &hook4, (void *)&help);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
