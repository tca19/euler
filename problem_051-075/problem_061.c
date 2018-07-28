#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define LOW 1000
#define MAX 10000

/* generate_triangle: return an array of triangle numbers between [low, high[ */
int32_t *generate_triangle(int32_t *n_triangles, int32_t low, int32_t high)
{
	int32_t n, i, triangle, *numbers;

	*n_triangles = 0;
	for (n = 1; ; ++n)
	{
		triangle = n * (n + 1) / 2;
		if (triangle >= high)
			break;
		if (triangle >= low && triangle%100 >= 10)
			++*n_triangles;
	}

	numbers = calloc(*n_triangles, sizeof *numbers);
	for (n = 1, i = 0; ; ++n)
	{
		triangle = n * (n + 1) / 2;
		if (triangle >= high)
			break;
		if (triangle >= low && triangle%100 >= 10)
			numbers[i++] = triangle;
	}

	return numbers;
}

/* generate_square: return an array of square numbers between [low, high[ */
int32_t *generate_square(int32_t *n_squares, int32_t low, int32_t high)
{
	int32_t n, i, square, *numbers;

	*n_squares = 0;
	for (n = 1; ; ++n)
	{
		square = n * n;
		if (square >= high)
			break;
		if (square >= low && square%100 >= 10)
			++*n_squares;
	}

	numbers = calloc(*n_squares, sizeof *numbers);
	for (n = 1, i = 0; ; ++n)
	{
		square = n * n;
		if (square >= high)
			break;
		if (square >= low && square%100 >= 10)
			numbers[i++] = square;
	}

	return numbers;
}

/* generate_penta: return an array of pentagonal numbers between [low, high[ */
int32_t *generate_penta(int32_t *n_pentas, int32_t low, int32_t high)
{
	int32_t n, i, penta, *numbers;

	*n_pentas = 0;
	for (n = 1; ; ++n)
	{
		penta = n * (3*n - 1) / 2;
		if (penta >= high)
			break;
		if (penta >= low && penta%100 >= 10)
			++*n_pentas;
	}

	numbers = calloc(*n_pentas, sizeof *numbers);
	for (n = 1, i = 0; ; ++n)
	{
		penta = n * (3*n - 1) / 2;
		if (penta >= high)
			break;
		if (penta >= low && penta%100 >= 10)
			numbers[i++] = penta;
	}

	return numbers;
}

/* generate_hexa: return an array of hexagonal numbers between [low, high[ */
int32_t *generate_hexa(int32_t *n_hexas, int32_t low, int32_t high)
{
	int32_t n, i, hexa, *numbers;

	*n_hexas = 0;
	for (n = 1; ; ++n)
	{
		hexa = n * (2*n - 1);
		if (hexa >= high)
			break;
		if (hexa >= low && hexa%100 >= 10)
			++*n_hexas;
	}

	numbers = calloc(*n_hexas, sizeof *numbers);
	for (n = 1, i = 0; ; ++n)
	{
		hexa = n * (2*n - 1);
		if (hexa >= high)
			break;
		if (hexa >= low && hexa%100 >= 10)
			numbers[i++] = hexa;
	}

	return numbers;
}

/* generate_hepta: return an array of heptagonal numbers between [low, high[ */
int32_t *generate_hepta(int32_t *n_heptas, int32_t low, int32_t high)
{
	int32_t n, i, hepta, *numbers;

	*n_heptas = 0;
	for (n = 1; ; ++n)
	{
		hepta = n * (5*n - 3) / 2;
		if (hepta >= high)
			break;
		if (hepta >= low && hepta%100 >= 10)
			++*n_heptas;
	}

	numbers = calloc(*n_heptas, sizeof *numbers);
	for (n = 1, i = 0; ; ++n)
	{
		hepta = n * (5*n - 3) / 2;
		if (hepta >= high)
			break;
		if (hepta >= low && hepta%100 >= 10)
			numbers[i++] = hepta;
	}

	return numbers;
}

/* generate_octa: return an array of octagonal numbers between [low, high[ */
int32_t *generate_octa(int32_t *n_octas, int32_t low, int32_t high)
{
	int32_t n, i, octa, *numbers;

	*n_octas = 0;
	for (n = 1; ; ++n)
	{
		octa = n * (3*n - 2);
		if (octa >= high)
			break;
		if (octa >= low && octa%100 >= 10)
			++*n_octas;
	}

	numbers = calloc(*n_octas, sizeof *numbers);
	for (n = 1, i = 0; ; ++n)
	{
		octa = n * (3*n - 2);
		if (octa >= high)
			break;
		if (octa >= low && octa%100 >= 10)
			numbers[i++] = octa;
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

	triangles = generate_triangle(&n_triangles, LOW, MAX);
	printf("T R I A N G L E S (%d)\n", n_triangles);
	print_array(triangles, n_triangles);

	squares = generate_square(&n_squares, LOW, MAX);
	printf("S Q U A R E S (%d)\n", n_squares);
	print_array(squares, n_squares);

	pentas = generate_penta(&n_pentas, LOW, MAX);
	printf("P E N T A G O N A L S (%d)\n", n_pentas);
	print_array(pentas, n_pentas);

	hexas = generate_hexa(&n_hexas, LOW, MAX);
	printf("H E X A G O N A L S (%d)\n", n_hexas);
	print_array(hexas, n_hexas);

	heptas = generate_hepta(&n_heptas, LOW, MAX);
	printf("H E P T A G O N A L S (%d)\n", n_heptas);
	print_array(heptas, n_heptas);

	octas = generate_octa(&n_octas, LOW, MAX);
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
