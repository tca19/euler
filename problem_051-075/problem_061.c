#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define LOW 1000
#define MAX 10000

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
 * number given n. */
int32_t *generate_numbers(int32_t *n_numbers, int32_t (*formula)(int32_t))
{
	int32_t n, i, polygonal, *numbers;

	*n_numbers = 0;
	for (n = 1; ; ++n)
	{
		polygonal = formula(n);
		if (polygonal >= MAX)
			break;
		if (polygonal >= LOW && polygonal%100 >= 10)
			++*n_numbers;
	}

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

int32_t main(void)
{
	int32_t n_triangles, *triangles,
		n_squares,   *squares,
		n_pentas,    *pentas,
		n_hexas,     *hexas,
		n_heptas,    *heptas,
		n_octas,     *octas;

	triangles = generate_numbers(&n_triangles, compute_triangle);
	printf("T R I A N G L E S (%d)\n", n_triangles);
	print_array(triangles, n_triangles);

	squares = generate_numbers(&n_squares, compute_square);
	printf("S Q U A R E S (%d)\n", n_squares);
	print_array(squares, n_squares);

	pentas = generate_numbers(&n_pentas, compute_penta);
	printf("P E N T A G O N A L S (%d)\n", n_pentas);
	print_array(pentas, n_pentas);

	hexas = generate_numbers(&n_hexas, compute_hexa);
	printf("H E X A G O N A L S (%d)\n", n_hexas);
	print_array(hexas, n_hexas);

	heptas = generate_numbers(&n_heptas, compute_hepta);
	printf("H E P T A G O N A L S (%d)\n", n_heptas);
	print_array(heptas, n_heptas);

	octas = generate_numbers(&n_octas, compute_octa);
	printf("O C T A G O N A L S (%d)\n", n_octas);
	print_array(octas, n_octas);

	free(triangles);
	free(squares);
	free(pentas);
	free(hexas);
	free(heptas);
	free(octas);
	return 0;
}
