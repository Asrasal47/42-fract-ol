/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:49:38 by arasal            #+#    #+#             */
/*   Updated: 2022/07/21 00:35:39 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parameters1(t_help *help)
{
	char	*str;

	ft_putstr_fd("Select a parameter by entering the \
corrosponding number:\n1 :- Julia\n2 :- Mandelbrot\n3 :- Newton\n", 1);
	str = get_next_line(0);
	if (ft_strncmp(str, "1\n", 2) == 0)
	{
		help->fractol = 1;
		parameters2(help);
	}
	else if (ft_strncmp(str, "2\n", 2) == 0)
		help->fractol = 2;
	else if (ft_strncmp(str, "3\n", 2) == 0)
		help->fractol = 3;
	else
	{
		ft_putstr_fd("Please enter a valid parameter\n", 1);
		parameters1(help);
	}
	free(str);
}

void	parameters2(t_help *help)
{
	char	*str;

	ft_putstr_fd("Would you like to enter x and y \
parameters for Julia set?  Y/N\n", 1);
	str = get_next_line(0);
	while (ft_strncmp(str, "Y\n", 2) != 0 && ft_strncmp(str, "N\n", 2) != 0)
	{
		free(str);
		ft_putstr_fd("Please answer with Y or N followed by enter \
Y/N\n", 1);
		str = get_next_line(0);
	}
	if (ft_strncmp(str, "Y\n", 2) == 0)
		parameters_julia(help);
	else if (ft_strncmp(str, "N\n", 2) == 0)
		ft_putstr_fd("Alright, have fun with Julia!!\n", 1);
	free (str);
}

void	parameters_julia(t_help *help)
{
	char	*x;
	char	*y;

	help->x = 0;
	ft_putstr_fd("Please enter real value\n", 1);
	x = get_next_line(0);
	ft_putstr_fd("Please enter imaginary value\n", 1);
	y = get_next_line(0);
	help->c = ft_atof(x, help);
	help->d = ft_atof(y, help);
	if (help->x == 1)
		parameters_julia(help);
	free (x);
	free (y);
}

double	ft_atof(char *str, t_help *help)
{
	double	i;
	double	j;
	int		k;
	char	*l;

	k = 0;
	l = str;
	i = ft_atoi(str);
	if (*l == '-')
		l++;
	while (ft_isdigit(*l) != 0)
		l++;
	if (*l == '.')
		l++;
	else if (*l != '\n')
		ft_put(help);
	j = ft_atoi(l);
	while (ft_isdigit(*l++) != 0)
		k++;
	if (*(--l) != '\n')
		ft_put(help);
	while (k-- > 0)
		j /= 10;
	ft_sign(*str, &i, &j);
	return (i);
}

void	ft_sign(char l, double *i, double *j)
{
	if (l == '-')
		(*i) = (*i) - (*j);
	else
		(*i) = (*i) + (*j);
}
