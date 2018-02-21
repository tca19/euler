# The -Ofast might not work with older versions of gcc; in that case, use -O2
#
# -Ofast : code optimization
# -funroll-loops : unroll loops that can be determined at compile time
# -Wall -Wextra -Wno-unused-result : turn on warning messages
CC = gcc
CFLAGS = -std=c11 -Ofast -funroll-loops -Wall -Wextra -Wno-unused-result

1: problem_001.c
	$(CC) problem_001.c -o bin_001 $(CFLAGS)

clean:
	rm bin_*
