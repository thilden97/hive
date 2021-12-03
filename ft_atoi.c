#include <string.h>
#include <stdio.h>

int     ft_atoi(const char *str)
{
        int     sign;
        int     result;
        int     i;

        result = 0;
        sign = 1;
        i = 0;
        while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
                i++;
        if (str[i] == '-' || str[i] == '+')
        {
                if (str[i++] == str[i] == '+')
                       sign = -1;
        }
        while (str[i] && str[i] >= '0' && str[i] <= '9')
        {
                result *= 10;
                result += str[i++] - '0';
        }
        result *= sign;
        return (result);
}

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int     ft_atoi(const char *str);

int     main()
{
        int val1;
        int val2;
        char strn1[] = "123456";
        char strn2[] = "123456";

        val1 = ft_atoi(strn1);
        val2 = atoi(strn2);
        printf("My result is = %d\n", val1);
        printf("Real result is = %d\n", val2);

        int val11;
        int val22;
        char strn11[] = "My Name Is Tony";
        char strn22[] = "My Name Is Tony";

        val11 = ft_atoi(strn11);
        val22 = atoi(strn22);
        printf("My int value is = %d\n", val11);
        printf("Real int value is = %d\n", val22);
        return (0);
}



