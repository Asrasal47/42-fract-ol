/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:04:01 by arasal            #+#    #+#             */
/*   Updated: 2022/07/08 18:01:26 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define BUFFER_SIZE = 4
# include "Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lists
{
	char		buff[4];
	char		*rest;
	char		*line;
	long long	number;
}					t_lists;

char	*get_next_line(int fd);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strdup_gnl(const char *s1);
size_t	ft_strlen_gnl(const char *s);
void	ft_returnline(t_lists *f);
void	ft_saverest(t_lists *f);
void	init_rest(t_lists *f);
#endif