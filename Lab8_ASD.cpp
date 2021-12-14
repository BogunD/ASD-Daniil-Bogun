#include <iomanip>
#include <iostream>
#include <windows.h>
#include <ctime>
void matrix(double m[6][5], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			m[i][j] = ((double)rand()) / RAND_MAX * 20 - 1 + 1 + (-10);
			std::cout << std::setw(12)<< m[i][j];
		}
		std::cout << "\n";
	}
}

double SumRowEl(double m[6][5], int row, int col, int i) {
	double Sum = 0;
	for (int j = 0; j < col; j++) {
		Sum += m[i][j];
	}
	return Sum;
}

double SerArifm(double m[6][5], int row, int col, int i) {
	double Sum = SumRowEl(m, row, col, i);
	double sr = Sum / col;
	return sr;
}

double srArr(double m[1][5], int row, int col, int i) {
		double* m1 = &m[0][0];
		m1[i] = SerArifm(m, row, col, i);
		return m1[i];
	}

void SortObmin(double arr[], int row) {
	int i, j;
	double tmp;
	for (i = 0; i < row; i++) {
		for (j = 0; j < row - i - 1; j++)
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		std::cout << arr[j] << std::setw(14);
		}
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int R = 6;
	const int ST = 5;
	int counter = 0;
	double arr1[R];
	srand(time(NULL));
	double arr[R][ST] ;
	std::cout << "Двомірний масив 6 х 5: " << "\n\n";
	matrix(arr, R, ST);
	std::cout << "\n";
	for (int i = 0; i < R; i++) {
		double Sum = SumRowEl(arr, R, ST, i);
		counter++;
		std::cout << "\n" << " Сума елементів " << counter << " рядка = " << Sum;
		SerArifm(arr, R, ST, i);
	}
	std::cout << "\n\n";
	
	std::cout <<"\n\n"<< "Результат :" << "\n";
	for (int i = 0; i < R; i++) {
		arr1[i] = srArr(arr, R, ST, i);
	}
	SortObmin(arr1, R);
	std::cout << "\n";
}


