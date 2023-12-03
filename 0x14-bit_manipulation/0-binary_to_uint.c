#include "main.h"
#include <string.h>


unsigned int binary_to_uint(const char *b)
{
	int i, n = strlen(b);
	unsigned int prev = 0, ans;

	if (b == NULL)
		return (0);

	for (i = 0; i < n; i++)
	{
		if (b[i] != 48 && b[i] != 49)
			return (0);

		ans = prev * 2 + (b[i] - 48);
		prev = ans;
	}

	return (ans);


}
