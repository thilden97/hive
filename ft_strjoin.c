#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
        int     i;
        int     len1;
        int     len2;
        char    *tmp;

        if (s1 && s2)
        {
                len1 = ft_strlen(s1);
                len2 = ft_strlen(s2);
                if (!(tmp = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
                        return (NULL);
                i = -1;
                while (s1[++i])
                        tmp[i] = s1[i];
                i = -1;
                while (s2[++i])
                {
                        tmp[len1] = s2[i];
                        len1++;
                }
                tmp[len1] = '\0';
                return (tmp);
        }
        return (NULL);
}
