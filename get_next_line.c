/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:51:28 by tkitahar          #+#    #+#             */
/*   Updated: 2024/05/26 23:11:03 by tkitahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned char	ft_getc(int fd)
{
	static unsigned char	buf[BUFFER_SIZE];
	static unsigned char	*bufp;
	static int				n = 0;

	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		bufp = buf;
	}
	if (--n > -1)
		return ((unsigned char)*bufp++);
	else
		return (EOF);
}

void	ft_putc(t_line *gnl, char c)
{
	gnl->string[gnl->length++] = c;
	return ;
}

char	*get_next_line(int fd)
{
	char	c;
	t_line	gnl;

	gnl.length = 0;
	gnl.capacity = BUFFER_SIZE;
	gnl.string = (char *)malloc(sizeof(char) * gnl->capacity);
	if (!gnl.string)
		return (NULL);
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF || c == '\n')
			break ;
		ft_putc(&gnl, c);
	}
	if (gnl.length == 0 && c == EOF)
		return (NULL);
	gnl.string[gnl.length] = 0;
	return (gnl.string);
}

/////////////
////main/////
/////////////

// int	main(void)
// {
// 	int	fd;

// 	fd = open("./text.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// char *line;
// while(42)
// {
//     line = get_next_line(fd);
//     if (!line)
//         return (0);
//     printf("%s\n", line);
//     free(line);
// }
// 	close(fd);
// 	return (0);
// }

// int	main(void)
// {
// 	int fd = open("./text.txt", O_RDONLY);
// 	printf("%c", ft_getc(fd));
// }

// int	main(void)
// {
// 	t_line	gnl;
// 	// #  define BUFFER_SIZE 6
// 	gnl.length = 0;
// 	gnl.capacity = BUFFER_SIZE;
// 	gnl.string = (char *)malloc(BUFFER_SIZE * sizeof(char));
// 	ft_putc(&gnl, 'H');
// 	ft_putc(&gnl, 'e');
// 	ft_putc(&gnl, 'l');
// 	ft_putc(&gnl, 'l');
// 	ft_putc(&gnl, 'o');
// 	ft_putc(&gnl, 0);
// 	printf("Resulting string: %s\n", gnl.string);
// 	free(gnl.string);
// 	return (0);
// }
