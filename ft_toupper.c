#include <ctype.h>

int     ft_toupper(int c)
{       
        if (c >= 'a' && c <= 'z')
                return (c - 32);
        else
                return (c);
}      

#include <ctype.h>

int     ft_toupper(int c);

int     main()
{       
        char k = 'a';
        char c = 'z';
        char x = 'A';
        char p = 'Z';

        int a = 1;


        printf("My k Result is = %d\n", ft_toupper(k));
        printf("Real k Result is = %d\n", toupper(k));

        printf("My c Result is = %d\n", ft_toupper(c));
        printf("Real c Result is = %d\n", toupper(c));

        printf("My x Result is = %d\n", ft_toupper(x));
        printf("Real x Result is = %d\n", toupper(x));

        printf("My p Result is = %d\n", ft_toupper(p));
        printf("Real p Result is = %d\n", toupper(p));
        return (0);
}
