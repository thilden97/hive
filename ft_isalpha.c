#include <ctype.h>
#include <stdio.h>

int     ft_isalpha(int c)
{
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                return (1);
        else
                return (0);
}       

#include <ctype.h>
#include <stdio.h>

int     ft_isalpha(int c);

int     main()
{       
        char k = 'a';
        char c = 'a';
        char x = ' ';
        char p = '.';

        int a = 1;


        printf("My c Result is = %d\n", ft_isalpha(k));
        printf("Real c Result is = %d\n", isalpha(c));

        printf("My x Result is = %d\n", ft_isalpha(x));
        printf("Real x Result is = %d\n", isalpha(x));

        printf("My p Result is = %d\n", ft_isalpha(p));
        printf("Real p Result is = %d\n", isalpha(p));

        printf("My a Result is = %d\n", ft_isalpha(a));
        printf("Real a Result is = %d\n", isalpha(a));
        return (0);
}       
~         
