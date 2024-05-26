#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 42

typedef struct s_line
{
    char *string;
    size_t length;
    size_t capacity;
} t_line;

typedef struct s_buffinfo
{
    char buff[BUFFER_SIZE];
    char *buffptr;
    int read_byte;
} t_buffinfo;

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*memo_dst;
	const char	*memo_src;
	size_t		i;

	memo_dst = (char *)dst;
	memo_src = (const char *)src;
	if (dst == src)
		return (dst);
	i = 0;
	while (n--)
	{
		memo_dst[i] = memo_src[i];
		i++;
	}
	return ((void *)memo_dst);
}

char ft_getc(int fd)
{
    static t_buffinfo buffinfo;

    if (buffinfo.read_byte == 0)
    {
        buffinfo.read_byte = read(fd, buffinfo.buff, sizeof buffinfo.buff);
        buffinfo.buffptr = buffinfo.buff;
    }

    if (--buffinfo.read_byte >= 0)// n = 1でstop
        return(*buffinfo.buffptr++);
    return(EOF);
}

void ft_putc(t_line *line, char c)
{
    char *new_string;

    if (line->length + 1 > line->capacity)
    {
        line->capacity = (line->length + 1) * 2;
        new_string = (char *)malloc(sizeof(char) * line->capacity);
        if (!new_string)
            return ;
        ft_memcpy(new_string, line->string, line->length);
        free(line->string);
        line->string = new_string;
    }
    line->string[line->length++] = c;
}

char *get_next_line(int fd)
{
    char c;
    t_line line;


    line.length = 0;
    line.capacity = BUFFER_SIZE;
    line.string = (char *)malloc(BUFFER_SIZE * sizeof(char) * line.capacity);//これはreviewerがfreeする前提で
    if(!line.string)
        return(NULL);
    while (1)
    {
        c = ft_getc(fd);
        if (c == EOF || c == '\n')
            break;
        ft_putc(&line, c);
    }
    if (line.length == 0 && c == EOF)
        return (NULL);
    line.string[line.length] = '\0';
    return (line.string);
}

// #include <stdio.h>

// int main()//->ft_getc
// {
//     int fd = open("./text.txt", O_RDONLY);
//     printf("%c", ft_getc(fd));
// }

// int main()//->ft_putc
// {
//     t_line line;
//     line.length = 0;
//     line.capacity = BUFFER_SIZE;
//     line.string = (char *)malloc(BUFFER_SIZE * sizeof(char) * line.capacity);//これはreviewerがfreeする前提で

//     ft_putc(&line, 'H');
//     ft_putc(&line, 'e');
//     ft_putc(&line, 'l');
//     ft_putc(&line, 'l');
//     ft_putc(&line, 'o');

//     // 結果を表示
//     printf("Resulting string: %s\n", line.string);

//     // メモリの解放
//     free(line.string);

//     return 0;
// }


int main()//->get_next_line
{
    int fd = open("./text.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    char *line;
    while(42)
    {
        line = get_next_line(fd);
        if (!line)
            return (0);
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}