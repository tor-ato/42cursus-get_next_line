# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 17:54:34 by tkitahar          #+#    #+#              #
#    Updated: 2024/05/24 18:27:12 by tkitahar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

WWWFLAGS = -Wall -Wextra -Werror
BUFFER_SIZEFLAGS = -D BUFFER_SIZE=42
DEBUGFLAGS = -g -fsanitize=address
CFILESE =  get_next_line.c get_next_line_utils.c

tst :
	$(CC) $(WWWFLAGS) $(BUFFER_SIZEFLAGS) $(DEBUGFLAGS) $(CFILESE)
	a.out
