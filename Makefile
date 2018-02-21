# The -Ofast might not work with older versions of gcc; in that case, use -O2
#
# -Ofast : code optimization
# -funroll-loops : unroll loops that can be determined at compile time
# -Wall -Wextra -Wno-unused-result : turn on warning messages
CC = gcc
CFLAGS = -std=c11 -Ofast -funroll-loops -Wall -Wextra -Wno-unused-result

1: problem_001.c
	$(CC) problem_001.c -o bin_001 $(CFLAGS)
2: problem_002.c
	$(CC) problem_002.c -o bin_002 $(CFLAGS)
3: problem_003.c
	$(CC) problem_003.c -o bin_003 $(CFLAGS)
4: problem_004.c
	$(CC) problem_004.c -o bin_004 $(CFLAGS)

clean:
	rm bin_*
