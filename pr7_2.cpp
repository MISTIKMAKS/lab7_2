#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCout, const int colCout, const int Low, const int High);
void Print(int** a, const int rowCout, const int colCout);
int MinFromMax(int** a, const int rowCount, const int colCount);

int main() {
	srand((unsigned)time(NULL));

	int Low = -21;
	int High = 24;

	int k;
	int n;

	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int rowCount = k;
	int colCount = n;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++) {
		a[i] = new int[colCount];
	}
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	int MFM = MinFromMax(a, rowCount, colCount);
	if (MFM) {
		cout << "Min From Max = " << MFM << endl;
	}
	else {
		cout << "Помилка" << endl;
	}
	for (int i = 0; i < rowCount; i++) {
		delete[] a[i];
	}
	delete[] a;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			a[i][j] = Low + rand() % (High - Low + 1);
		}
	}
}
void Print(int** a, const int rowCount, const int colCount) {
	cout << endl;
	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
int MinFromMax(int** a, const int rowCount, const int colCount) {
	int remixColCount = 0;
	int l = 0;
	int minFromMax = 0;
	if (colCount % 2 == 0) {
		remixColCount = colCount / 2;
	}
	else {
		remixColCount = (colCount / 2) + 1;
	}
	cout << remixColCount << std::endl;
	cout << endl;
	int* b = new int[remixColCount];
	for (int j = 0; j < colCount; j = j + 2) {
		//if (j % 2 == 0) {
			int max = a[0][j];
			for (int i = 1; i < rowCount; i++) {
				if (a[i][j] > max) {
					max = a[i][j];
				}
			}
			b[l] = max;
			l++;
		//}
	}
	for (int i = 0; i < remixColCount; i++) {
		std::cout << b[i] << std::endl;
	}
	cout << endl;
	minFromMax = b[0];
	for (int i = 1; i < remixColCount; i++) {
		if (minFromMax > b[i]) {
			minFromMax = b[i];
		}
	}
	return minFromMax;
}