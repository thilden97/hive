int     ft_isprint(int c)
{       
        if (c >= 32 && c <= 126)
                return (1);
        else
                return (0);
}       

#include <ctype.h>
#include <stdio.h>

int     ft_isprint(int c);

int     main()
{
        char k = 'a';
        char c = 'a';
        char x = ' ';
        char p = '.';

        int a = 1;


        printf("My c Result is = %d\n", ft_isprint(k));
        printf("Real c Result is = %d\n", isprint(c));

        printf("My x Result is = %d\n", ft_isprint(x));
        printf("Real x Result is = %d\n", isprint(x));

        printf("My p Result is = %d\n", ft_isprint(p));
        printf("Real p Result is = %d\n", isprint(p));

        printf("My a Result is = %d\n", ft_isprint(a));
        printf("Real a Result is = %d\n", isprint(a));
        return (0);
}
