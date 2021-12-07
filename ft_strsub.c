#include "libft.h"

char    *ft_strsub(char const *s, unsigned int start, size_t len)
{       
        size_t  i;
        char    *tmp;
        
        i = 0;
        if (!s || !(tmp = (char *)malloc(sizeof(char) * len + 1)))
                return (NULL);
        while (i < len)
        {       
                tmp[i] = s[i + start];
                i += 1;
        }       
        tmp[i] = '\0';
        return (tmp);
}       
~         
