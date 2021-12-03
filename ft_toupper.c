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


        printf("My k Result is = %d\n", ft_isalpha(k));
        printf("Real k Result is = %d\n", isalpha(k));

        printf("My c Result is = %d\n", ft_isalpha(c));
        printf("Real c Result is = %d\n", isalpha(c));

        printf("My x Result is = %d\n", ft_isalpha(x));
        printf("Real x Result is = %d\n", isalpha(x));

        printf("My p Result is = %d\n", ft_isalpha(p));
        printf("Real p Result is = %d\n", isalpha(p));
        return (0);
}
