#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define LOW 1000
#define MAX 10000
#define CYCLE_LENGTH 6

int32_t count[CYCLE_LENGTH];
int32_t *numbers[CYCLE_LENGTH];

/* compute_triangle: return the n-th triangle number */
int32_t compute_triangle(int32_t n) {return n * (n + 1) / 2;}

/* compute_square: return the n-th square number */
int32_t compute_square(int32_t n)   {return n * n;}

/* compute_penta: return the n-th pentagonal number */
int32_t compute_penta(int32_t n)    {return n * (3*n - 1) / 2;}

/* compute_hexa: return the n-th hexagonal number */
int32_t compute_hexa(int32_t n)     {return n * (2*n - 1);}

/* compute_hepta: return the n-th heptagonal number */
int32_t compute_hepta(int32_t n)    {return n * (5*n - 3) / 2;}

/* compute_octa: return the n-th octagonal number */
int32_t compute_octa(int32_t n)     {return n * (3*n - 2);}

/* generate_numbers: return an array of polygonal numbers between [LOW, MAX[
 * given the formula. The formula returns the n-th triangle/square/.../octa
 * number given n. n_numbers is set to the number of numbers generated. */
int32_t *generate_numbers(int32_t *n_numbers, int32_t (*formula)(int32_t))
{
	int32_t n, i, polygonal, *numbers;

	/* find the number of polygonal numbers that can be generated. Only
	 * count the ones between [LOW, MAX[. The solution of the problem is
	 * composed of 4 digits numbers, so last 2 digits can't start with 0. */
	*n_numbers = 0;
	for (n = 1; ; ++n) /* stop when we are outside [LOW, MAX[ */
	{
		polygonal = formula(n);
		if (polygonal >= MAX)
			break;
		if (polygonal >= LOW && polygonal%100 >= 10)
			++*n_numbers;
	}

	/* allocate enough memory to store the numbers. Generate the numbers. */
	numbers = calloc(*n_numbers, sizeof *numbers);
	for (n = 1, i = 0; ; ++n)
	{
		polygonal = formula(n);
		if (polygonal >= MAX)
			break;
		if (polygonal >= LOW && polygonal%100 >= 10)
			numbers[i++] = polygonal;
	}

	return numbers;
}

/* print_array: print all values of ar, space separated */
void print_array(int32_t *ar, int32_t size)
{
	int32_t i;

	for (i = 0; i < size; ++i)
		printf("%d%c", ar[i], i%10 == 9 ? '\n' : ' ');
	printf("\n");
}

/* next_permutation: generate the next permutation of integers in ar */
int32_t next_permutation(int32_t *ar, int32_t size)
{
	int32_t k, l, tmp;

	/* find largest index k st a[k] < a[k+1] */
	for (k = size-2; k >= 0 && ar[k] >= ar[k+1]; --k)
		;
	if (k < 0)
		return -1;

	/* find largest index l (l > k) st a[k] < a[l] */
	for (l = size-1; l > k+1 && ar[k] >= ar[l]; --l)
		;
	if (l == size)
		return -1;


/*	printf("k=%d, l=%d ", k , l); */
	/* swap a[k] and a[l] */
	tmp = ar[l];
	ar[l] = ar[k];
	ar[k] = tmp;

	/* reverse array from a[k+1] up to a[size-1] */
	for (k = k+1, l = size-1; k < l; k++, l--)
		tmp = ar[k], ar[k] = ar[l], ar[l] = tmp;

	return 1;
}


int32_t main(void)
{
	int32_t s[CYCLE_LENGTH], i, answer, found;
	int32_t n1, n2, n3, n4, n5, n6;

	/* fill s array with 0,1,2,3... */
	for (i = 0; i < CYCLE_LENGTH; ++i)
		s[i] = i;

	numbers[0] = generate_numbers(&count[0], compute_triangle);
	numbers[1] = generate_numbers(&count[1], compute_square);
	numbers[2] = generate_numbers(&count[2], compute_penta);
	numbers[3] = generate_numbers(&count[3], compute_hexa);
	numbers[4] = generate_numbers(&count[4], compute_hepta);
	numbers[5] = generate_numbers(&count[5], compute_octa);

	found = answer = 0;
	while(!found)
	{
		for (n1 = 0; n1 < count[s[0]]; ++n1)
		{
			for (n2 = 0; n2 < count[s[1]]; ++n2)
			{
				if (numbers[s[0]][n1]%100 != numbers[s[1]][n2]/100)
					continue;

				for (n3 = 0; n3 < count[s[2]]; ++n3)
				{
					if (numbers[s[1]][n2]%100 != numbers[s[2]][n3]/100)
						continue;

					for (n4 = 0; n4 < count[s[3]]; ++n4)
					{
						if (numbers[s[2]][n3]%100 != numbers[s[3]][n4]/100)
							continue;

						for (n5 = 0; n5 < count[s[4]]; ++n5)
						{
							if (numbers[s[3]][n4]%100 != numbers[s[4]][n5]/100)
								continue;

							for (n6 = 0; n6 < count[s[5]]; ++n6)
							{
								if (numbers[s[4]][n5]%100 != numbers[s[5]][n6]/100
								 || numbers[s[5]][n6]%100 != numbers[s[0]][n1]/100)
									continue;

								answer = numbers[s[0]][n1];
								answer += numbers[s[1]][n2];
								answer += numbers[s[2]][n3];
								answer += numbers[s[3]][n4];
								answer += numbers[s[4]][n5];
								answer += numbers[s[5]][n6];
								found = 1;
							}
						}
					}
				}
			}
		}

		next_permutation(s, CYCLE_LENGTH);
		++i;

	}

	printf("Problem 61: %d\n", answer);

	for (i = 0; i < CYCLE_LENGTH; ++i)
		free(numbers[i]);

	return 0;
}
