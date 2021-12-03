#include <ctype.h>
#include <stdio.h>

int     ft_isdigit(int c)
{       
        if (c >= '0' && c <= '9')
                return (1);
        else    
                return (0);
}   

#include <ctype.h>
#include <stdio.h>

int     ft_isdigit(int c);

int     main()
{       
        char x = ' ';
        char p = '.';

        char a = '1';
        int b = 22;


        printf("My c Result is = %d\n", ft_isdigit(a));
        printf("Real c Result is = %d\n", isdigit(a));

        printf("My x Result is = %d\n", ft_isdigit(x));
        printf("Real x Result is = %d\n", isdigit(x));

        printf("My p Result is = %d\n", ft_isdigit(p));
        printf("Real p Result is = %d\n", isdigit(p));

