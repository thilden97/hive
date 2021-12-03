#include <ctype.h>

int     ft_isalnum(int c)
{
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                return (1);
        else
                return (0);
}

#include <ctype.h>
#include <stdio.h>

int     ft_isalnum(int c);

int     main()
{
        char k = 'a';
        char c = 'a';
        char x = ' ';
        char p = '.';

        char a = '1';


        printf("My c Result is = %d\n", ft_isalnum(k));
        printf("Real c Result is = %d\n", isalnum(c));

        printf("My x Result is = %d\n", ft_isalnum(x));
        printf("Real x Result is = %d\n", isalnum(x));

        printf("My p Result is = %d\n", ft_isalnum(p));
        printf("Real p Result is = %d\n", isalnum(p));

        printf("My a Result is = %d\n", ft_isalnum(a));
        printf("Real a Result is = %d\n", isalnum(a));
        return (0);
}

