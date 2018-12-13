#include "libft.h"
/*
** @Function: Copies src to string dst of size size. At most size - 1
** characters will be copied. Always NULL terminates (unless size == 0)
** if retval >= size, the string will be truncated.
** @Param 1: the destination string
** @Param 2: the constant source string
** @Param 3: the size of dst
** @Return: strlen(src);
*/

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    char        *d;
    const char  *s;
    size_t      n;

    d = dst;
    s = src;
    n = size;
    if (n != 0 && --n != 0)
    {
        do
        {
            if ((*d++ = *s++) == 0)
                break;
        }while (--n != 0);
    }
    if (n == 0)
    {
        if (size != 0)
            *d = '\0';
        while (*s++)
            ;
    }
    return (s - src - 1);
}
