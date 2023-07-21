/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:50:52 by arasal            #+#    #+#             */
/*   Updated: 2022/05/15 19:51:07 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_lists	f;

	init_rest(&f);
	f.number = 1;
	while (f.number && f.number % 1 == 0
		&& (!(ft_strchr_gnl(f.line, '\n'))))
	{
		f.number = read(fd, f.buff, 1);
		if ((f.number == 0 && (!*f.line)) || f.number == -1)
		{
			if (f.line || f.number == -1)
				free(f.line);
			return (NULL);
		}
		f.buff[f.number] = '\0';
		f.line = ft_strjoin_gnl(f.line, f.buff);
	}
	ft_saverest(&f);
	ft_returnline(&f);
	return (f.line);
}

void	ft_saverest(t_lists *f)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (f->line == NULL)
		return ;
	while (f->line[j] != '\0')
		j++;
	while (f->line[i] != '\n' && f->line[i] != '\0')
		i++;
	if (i != j)
		f->rest = ft_substr_gnl(f->line, i + 1, j - (i + 1));
	else
		f->rest = ft_strdup_gnl("");
}

void	init_rest(t_lists *f)
{
	if (f->rest)
	{
		f->line = ft_strdup_gnl(f->rest);
		free (f->rest);
	}
	else
		f->line = ft_strdup_gnl("");
}

void	ft_returnline(t_lists *f)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (f->line == NULL)
		return ;
	while (f->line[j] != '\0')
		j++;
	while (f->line[i] != '\n' && f->line[i] != '\0')
		i++;
	if (i != j)
	{
		ret = ft_substr_gnl(f->line, 0, i + 1);
		free (f->line);
		f->line = ft_strdup_gnl(ret);
		free (ret);
	}
}
