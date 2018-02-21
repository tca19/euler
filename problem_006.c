#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

int32_t main()
{
	/* a = 1^2 + 2^2 + 3^2 + [...] + 100^2
	 * b = (1 + 2 + 3 + [...] + 100)^2 */
	uint64_t MAX = 100, a = 0, b = 0;

	for (uint64_t i = 1; i < MAX+1; ++i)
	{
		a += i*i;
		b += i;
	}

	b *= b;

	printf("Problem 6: %" PRIu64 "\n", b-a);
	return 0;
}
