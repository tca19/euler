CC = gcc
CFLAGS = -std=c11 -Ofast -march=native -funroll-loops -Wall -Wextra

1: problem_001-025/problem_001.c
	$(CC) problem_001-025/problem_001.c -o bin_001 $(CFLAGS)
2: problem_001-025/problem_002.c
	$(CC) problem_001-025/problem_002.c -o bin_002 $(CFLAGS)
3: problem_001-025/problem_003.c
	$(CC) problem_001-025/problem_003.c -o bin_003 $(CFLAGS)
4: problem_001-025/problem_004.c
	$(CC) problem_001-025/problem_004.c -o bin_004 $(CFLAGS)
5: problem_001-025/problem_005.c
	$(CC) problem_001-025/problem_005.c -o bin_005 $(CFLAGS)
6: problem_001-025/problem_006.c
	$(CC) problem_001-025/problem_006.c -o bin_006 $(CFLAGS)
7: problem_001-025/problem_007.c
	$(CC) problem_001-025/problem_007.c -o bin_007 $(CFLAGS)
8: problem_001-025/problem_008.c
	$(CC) problem_001-025/problem_008.c -o bin_008 $(CFLAGS)
9: problem_001-025/problem_009.c
	$(CC) problem_001-025/problem_009.c -o bin_009 $(CFLAGS)
10: problem_001-025/problem_010.c
	$(CC) problem_001-025/problem_010.c -o bin_010 $(CFLAGS)
11: problem_001-025/problem_011.c
	$(CC) problem_001-025/problem_011.c -o bin_011 $(CFLAGS)
12: problem_001-025/problem_012.c
	$(CC) problem_001-025/problem_012.c -o bin_012 $(CFLAGS)
13: problem_001-025/problem_013.c
	$(CC) problem_001-025/problem_013.c -o bin_013 $(CFLAGS)
14: problem_001-025/problem_014.c
	$(CC) problem_001-025/problem_014.c -o bin_014 $(CFLAGS)
15: problem_001-025/problem_015.c
	$(CC) problem_001-025/problem_015.c -o bin_015 $(CFLAGS)
16: problem_001-025/problem_016.c
	$(CC) problem_001-025/problem_016.c -o bin_016 $(CFLAGS)
17: problem_001-025/problem_017.c
	$(CC) problem_001-025/problem_017.c -o bin_017 $(CFLAGS)
18: problem_001-025/problem_018.c
	$(CC) problem_001-025/problem_018.c -o bin_018 $(CFLAGS)
19: problem_001-025/problem_019.c
	$(CC) problem_001-025/problem_019.c -o bin_019 $(CFLAGS)
20: problem_001-025/problem_020.c
	$(CC) problem_001-025/problem_020.c -o bin_020 $(CFLAGS)
21: problem_001-025/problem_021.c
	$(CC) problem_001-025/problem_021.c -o bin_021 $(CFLAGS)
22: problem_001-025/problem_022.c
	$(CC) problem_001-025/problem_022.c -o bin_022 $(CFLAGS)
23: problem_001-025/problem_023.c
	$(CC) problem_001-025/problem_023.c -o bin_023 $(CFLAGS)
24: problem_001-025/problem_024.c
	$(CC) problem_001-025/problem_024.c -o bin_024 $(CFLAGS)
25: problem_001-025/problem_025.c
	$(CC) problem_001-025/problem_025.c -o bin_025 $(CFLAGS)
26: problem_026-050/problem_026.c
	$(CC) problem_026-050/problem_026.c -o bin_026 $(CFLAGS)
27: problem_026-050/problem_027.c
	$(CC) problem_026-050/problem_027.c -o bin_027 $(CFLAGS)
28: problem_026-050/problem_028.c
	$(CC) problem_026-050/problem_028.c -o bin_028 $(CFLAGS)
29: problem_026-050/problem_029.c
	$(CC) problem_026-050/problem_029.c -o bin_029 $(CFLAGS)
30: problem_026-050/problem_030.c
	$(CC) problem_026-050/problem_030.c -o bin_030 $(CFLAGS)
31: problem_026-050/problem_031.c
	$(CC) problem_026-050/problem_031.c -o bin_031 $(CFLAGS)
32: problem_026-050/problem_032.c
	$(CC) problem_026-050/problem_032.c -o bin_032 $(CFLAGS)
33: problem_026-050/problem_033.c
	$(CC) problem_026-050/problem_033.c -o bin_033 $(CFLAGS)
34: problem_026-050/problem_034.c
	$(CC) problem_026-050/problem_034.c -o bin_034 $(CFLAGS)
35: problem_026-050/problem_035.c
	$(CC) problem_026-050/problem_035.c -o bin_035 $(CFLAGS)
36: problem_026-050/problem_036.c
	$(CC) problem_026-050/problem_036.c -o bin_036 $(CFLAGS)
40: problem_026-050/problem_040.c
	$(CC) problem_026-050/problem_040.c -o bin_040 $(CFLAGS)
45: problem_026-050/problem_045.c
	$(CC) problem_026-050/problem_045.c -o bin_045 $(CFLAGS)

clean:
	rm bin_*
