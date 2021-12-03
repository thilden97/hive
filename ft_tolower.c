
#include <ctype.h>

int     ft_tolower(int c)
{       
        if (c >= 'A' && c <= 'Z')
                return (c + 32);
        else
                return (c);
}  

#include <stdio.h>
#include <ctype.h>

int     ft_tolower(int c);

int     main()
{       
        char k = 'a';
        char c = 'z';
        char x = 'A';
        char p = 'Z';

        int a = 1;


        printf("My k Result is = %d\n", ft_tolower(k));
        printf("Real k Result is = %d\n", tolower(k));

        printf("My c Result is = %d\n", ft_tolower(c));
        printf("Real c Result is = %d\n", tolower(c));

        printf("My x Result is = %d\n", ft_tolower(x));
        printf("Real x Result is = %d\n", tolower(x));

        printf("My p Result is = %d\n", ft_tolower(p));
        printf("Real p Result is = %d\n", tolower(p));
        return (0);
}
