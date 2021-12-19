#include <iostream>
#include <iomanip>
#include <windows.h>


double SumAboveDiag(int a, int b, double** matrix);
double** Matrixx(int a, int b);
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int row, col;
	std::cout << "The matrix (n x n) \n n = " ; std::cin >> row;
	col = row;
	double** matrix;
	matrix = Matrixx(row, col);
	double Sum = SumAboveDiag(row, col, matrix);
	std::cout << "\n\n" << " Сума елементів, розташованих над головною діагоналлю = " << Sum <<"\n";
}	

double** Matrixx(int a, int b) {
	double** arr = new double* [a];
	for (int i = 0; i < a; i++)
		arr[i] = new double[b];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			arr[i][j] = ((double)rand()) / RAND_MAX * 20 - 1 + 1 + (-10);
			std::cout << arr[i][j] << std::setw(12);
		}
		std::cout << "\n";
	}
	return arr;
}


double SumAboveDiag(int a, int b, double** arr) {
	double sum = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (i < j)
				sum += arr[i][j];
			else
				continue;
		}
		
	}
	return sum;
}