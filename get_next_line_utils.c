/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:51:31 by tkitahar          #+#    #+#             */
/*   Updated: 2024/05/27 16:00:57 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*char_dest;
	const char	*char_src;

	if (!dest && !src)
		return (NULL);
	char_dest = (char *)dest;
	char_src = (const char *)src;
	while (n--)
		*char_dest++ = *char_src++;
	return (dest);
}
