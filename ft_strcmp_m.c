#include "./includes/cube.h"

int	ft_strcmp_m(char *s1, char *s2)
{
	int i;
    int a;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
        i++;
    a = s1[i] - s2[i];
    // free(s1);
	return (a);
}
