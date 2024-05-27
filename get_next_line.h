/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:51:34 by tkitahar          #+#    #+#             */
/*   Updated: 2024/05/27 17:11:49 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define READ_ERROR -42

typedef struct s_gnl
{
	char	*str;
	size_t	len;
	size_t	capa;
}			t_gnl;

char		*get_next_line(int fd);
void		*ft_memcpy(void *dst, const void *src, size_t n);

#endif
