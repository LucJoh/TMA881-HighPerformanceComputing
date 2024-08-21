#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]) {

	clock_t start, end;
	double time;
	double avg;

	int size = 1000;
	double sums[size];
	double *matrix = (double*) malloc(sizeof(double) * size*size);
	double **row = (double**) malloc(sizeof(double*) * size);
	for (size_t i = 0, j = 0; i < size; ++i, j+=size)
		row[i] = matrix + j;

	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
			row[i][j] = 1.0;

	start = clock();
	for (int k = 0; k < 5000; k++) {
		for ( size_t i = 0; i < size; i++ ) {
			double sum0 = 0.;
			double sum1 = 0.;
			double sum2 = 0.;
			double sum3 = 0.;
			double sum4 = 0.;
			double sum5 = 0.;
			double sum6 = 0.;
			double sum7 = 0.;
			for ( size_t j = 0; j < size; j += 8 ) {
				sum0 += row[i][j];
				sum1 += row[i][j+1];
				sum2 += row[i][j+2];
				sum3 += row[i][j+3];
				sum4 += row[i][j+4];
				sum5 += row[i][j+5];
				sum6 += row[i][j+6];
				sum7 += row[i][j+7];
			}
			sums[i] = sum0 + sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7;
		}
	}
	end = clock();
	time = ((double) (end - start)) / (CLOCKS_PER_SEC);

	printf("sums[0] = %f\n", sums[0]);
	printf("unrolled8 : %f seconds\n", time);

	free(matrix);
	free(row);

	return 0;

}
