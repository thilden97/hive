#include <ctype.h>
#include <stdio.h>

int     ft_isascii(int c)
{       
        if (c >= 0 && c <= 127)
                return (1);
        else            
                return (0);
}  

#include <stdio.h>
#include <ctype.h>

int     ft_isascii(int c);

int     main()
{       
        char k = 'a';
        char c = 'a';
        char x = ' ';
        char p = '.';

        int a = 1;


        printf("My c Result is = %d\n", ft_isascii(k));
        printf("Real c Result is = %d\n", isascii(c));

        printf("My x Result is = %d\n", ft_isascii(x));
        printf("Real x Result is = %d\n", isascii(x));

        printf("My p Result is = %d\n", ft_isascii(p));
        printf("Real p Result is = %d\n", isascii(p));

        printf("My a Result is = %d\n", ft_isascii(a));
        printf("Real a Result is = %d\n", isascii(a));
        return (0);
}

