#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define LOW 1000
#define MAX 10000
#define CYCLE_LENGTH 6

struct type {
	int32_t n_numbers;
	int32_t *numbers;
};

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
	int32_t permutations[CYCLE_LENGTH], i, answer, found;
	int32_t n_triangles, *triangles,
		n_squares,   *squares,
		n_pentas,    *pentas,
		n_hexas,     *hexas,
		n_heptas,    *heptas,
		n_octas,     *octas;
	struct type types[CYCLE_LENGTH];
	int32_t n1, n2, n3, n4, n5, n6;

	/* fill permutations array with 0,1,2,3... */
	for (i = 0; i < CYCLE_LENGTH; ++i)
		permutations[i] = i;

	print_array(permutations, CYCLE_LENGTH);

	triangles = generate_numbers(&n_triangles, compute_triangle);
	printf("T R I A N G L E S (%d)\n", n_triangles);
	print_array(triangles, n_triangles);
	types[0].n_numbers = n_triangles;
	types[0].numbers   = triangles;

	squares = generate_numbers(&n_squares, compute_square);
	printf("S Q U A R E S (%d)\n", n_squares);
	print_array(squares, n_squares);
	types[1].n_numbers = n_squares;
	types[1].numbers = squares;

	pentas = generate_numbers(&n_pentas, compute_penta);
	printf("P E N T A G O N A L S (%d)\n", n_pentas);
	print_array(pentas, n_pentas);
	types[2].n_numbers = n_pentas;
	types[2].numbers = pentas;

	hexas = generate_numbers(&n_hexas, compute_hexa);
	printf("H E X A G O N A L S (%d)\n", n_hexas);
	print_array(hexas, n_hexas);
	types[3].n_numbers = n_hexas;
	types[3].numbers = hexas;

	heptas = generate_numbers(&n_heptas, compute_hepta);
	printf("H E P T A G O N A L S (%d)\n", n_heptas);
	print_array(heptas, n_heptas);
	types[4].n_numbers = n_heptas;
	types[4].numbers = heptas;

	octas = generate_numbers(&n_octas, compute_octa);
	printf("O C T A G O N A L S (%d)\n", n_octas);
	print_array(octas, n_octas);
	types[5].n_numbers = n_octas;
	types[5].numbers = octas;

	found = 0;
	i = 0;
	while(!found && i < 720)
	{
		answer = 0;

		printf("perm #%d:", i);
		print_array(permutations, CYCLE_LENGTH);

		for (n1 = 0; n1 < types[permutations[0]].n_numbers; ++n1)
		{
			for (n2 = 0; n2 < types[permutations[1]].n_numbers; ++n2)
			{
				if (types[permutations[0]].numbers[n1]%100 != types[permutations[1]].numbers[n2]/100)
					continue;

				for (n3 = 0; n3 < types[permutations[2]].n_numbers; ++n3)
				{
					if (types[permutations[1]].numbers[n2]%100 != types[permutations[2]].numbers[n3]/100)
						continue;

					for (n4 = 0; n4 < types[permutations[3]].n_numbers; ++n4)
					{
						if (types[permutations[2]].numbers[n3]%100 != types[permutations[3]].numbers[n4]/100)
							continue;

						for (n5 = 0; n5 < types[permutations[4]].n_numbers; ++n5)
						{
							if (types[permutations[3]].numbers[n4]%100 != types[permutations[4]].numbers[n5]/100)
								continue;

							for (n6 = 0; n6 < types[permutations[5]].n_numbers; ++n6)
							{
								if (types[permutations[4]].numbers[n5]%100 != types[permutations[5]].numbers[n6]/100
								 || types[permutations[5]].numbers[n6]%100 != types[permutations[0]].numbers[n1]/100)
									continue;

								/*printf("it matches %d %d %d %d %d %d\n",
									types[permutations[0]].numbers[n1],
									types[permutations[1]].numbers[n2],
									types[permutations[2]].numbers[n3],
									types[permutations[3]].numbers[n4],
									types[permutations[4]].numbers[n5],
									types[permutations[5]].numbers[n6]);*/
								answer = types[permutations[0]].numbers[n1];
								answer += types[permutations[1]].numbers[n2];
								answer += types[permutations[2]].numbers[n3];
								answer += types[permutations[3]].numbers[n4];
								answer += types[permutations[4]].numbers[n5];
								answer += types[permutations[5]].numbers[n6];
								found = 1;
							}
						}
					}
				}
			}
		}

		next_permutation(permutations, CYCLE_LENGTH);
		++i;

	}

	print_array(types[0].numbers, types[0].n_numbers);
	printf("Problem 61: %d\n", answer);

	free(triangles);
	free(squares);
	free(pentas);
	free(hexas);
	free(heptas);
	free(octas);
	return 0;
}
