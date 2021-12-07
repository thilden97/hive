
#include "libft.h"
#include <stdlib.h>

void    *ft_memalloc(size_t size)
{       
        unsigned char *mem;
        
        mem = NULL;
        if(!(mem = (unsigned char *)malloc(size)))
                return (NULL);
        ft_bzero(mem, size);
        return (mem);
}   
