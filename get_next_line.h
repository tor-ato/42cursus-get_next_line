/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:51:34 by tkitahar          #+#    #+#             */
/*   Updated: 2024/05/24 18:16:34 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef GRT_NEXT_LINE_H
# define GRT_NEXT_LINE_H

# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

char *get_next_line(int fd);

#endif
