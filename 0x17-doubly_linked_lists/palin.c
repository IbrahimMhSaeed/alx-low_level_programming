#include "lists.h"
#include <string.h>

char *convert(int ans)
{
	char *num;

	num = malloc(sizeof(char) * 7);

	for (int i = 0; i < 6; i++)
	{
		if (ans == 0)
		{
			num[i] = '\0';
			return (num);
		}
		num[i] = (ans % 10) + '0';
		ans /= 10;
	}
	num[6] = '\0';
	return (num);
}

int check(int ans)
{
	int len, i;
	char *num;

	len = 0;
	i = 0;
	num = convert(ans);
	while (num[len] != '\0')
		len++;
	len--;
	while (i < len)
	{
		if (num[i] != num[len])
			return (-1);
		i++;
		len--;
	}
	return (1);

}

int main(void)
{
	int i, j, ans, max;

	max = -1;
	for (i = 999; i > 0; i--)
	{
		for (j = i; j > 0; j--)
		{
			ans = i * j;
			if (check(ans) == 1 && ans > max)
			{
				max = ans;
			}
		}

	}

	printf("number = %d\n", max);
	return (0);
}
