#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void Create(int** C, const int HIGH, const int LOW, const int ROW_COUNT, const int COL_COUNT, 
																				int i, int j);
void Print(int** C, const int ROW_COUNT, const int COL_COUNT, int i, int j);
void Replace(int** C, const int ROW_COUNT, const int COL_COUNT, int& jmin, int& imin, 
															int j, int i, int min, bool a);
int Min(int** mas, const int ROW_COUNT, const int COL_COUNT, int& minmin, int& imin_1, int& jmin_1, int i, int j);
void Change(int** C, int& imin, int& jmin, int& i, int& j, const int COL_COUNT);

int main()
{
	srand(time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int HIGH = 50;
	const int LOW = 10;
	int ROW_COUNT;
	int COL_COUNT;
	cout << "¬вед≥ть розм≥р квадратноњ матриц≥: "; cin >> ROW_COUNT;
	COL_COUNT = ROW_COUNT;

	int** C = new int* [ROW_COUNT];
	for (int i = 0; i < ROW_COUNT; i++)
		C[i] = new int[COL_COUNT];

	cout << "«генерована матриц€ у заданому д≥апазон≥: " << "\n";
	int i = 0; 
	int j = 0;
	Create(C, HIGH, LOW, ROW_COUNT, COL_COUNT, i, j);
	Print(C, ROW_COUNT, COL_COUNT, i, j);
	int imin = 0;
	int jmin = 0;
	int min = C[i][0];
	bool a = false;
	Replace(C, ROW_COUNT, COL_COUNT, jmin, imin, j, i, min, a);
	Print(C, ROW_COUNT, COL_COUNT, i, j);

	for (int i = 0; i < ROW_COUNT; i++)
		delete[] C[i];
	delete[]C;

	system("pause");
	return 0;
}
void Create(int** C, const int HIGH, const int LOW, const int ROW_COUNT, const int COL_COUNT, 
																				int i, int j)
{
	C[i][j] = LOW + rand() % (HIGH - LOW + 1);
	if (j < COL_COUNT - 1)
		Create(C, HIGH, LOW, ROW_COUNT, COL_COUNT, i, j + 1);
	else 
		if (i < ROW_COUNT - 1)
			Create(C, HIGH, LOW, ROW_COUNT, COL_COUNT, i + 1, 0);
}
void Print(int** C, const int ROW_COUNT, const int COL_COUNT, int i, int j)
{
	cout << C[i][j] << "\t";
	if (j < COL_COUNT - 1)
		Print(C, ROW_COUNT, COL_COUNT, i, j + 1);
	else
		if (i < ROW_COUNT - 1)
		{
			cout << "\n";
			Print(C, ROW_COUNT, COL_COUNT, i + 1, 0);
		}
		else 
		cout << "\n" << "\n" << "\n";
}
void Replace(int** C, const int ROW_COUNT, const int COL_COUNT, int& jmin, int& imin, int j, int i, int min, bool a)
{
	if (i < ROW_COUNT)
	{
		if (a)
		{
			min = C[i][0];
			a = false;
		}
		if (i < ROW_COUNT)
		{
			if (j < COL_COUNT)
			{
				if (C[i][j] <= min)
				{
					min = C[i][j];
					jmin = j;
					imin = i;
				}
				if (j == (COL_COUNT - 1))
				{
					cout << "C[" << imin << "][" << jmin << "] = " << min << "\t" << "\n";
					if (C[i][COL_COUNT - 1 - i] != C[imin][jmin])
					{
						Change(C, imin, jmin, i, j, COL_COUNT);
					}
				}
				Replace(C, ROW_COUNT, COL_COUNT, jmin, imin, j + 1, i, min, a);
			}
			else
			{
				bool a = true;
				Replace(C, ROW_COUNT, COL_COUNT, jmin, imin, 0, i + 1, min, a);
			}
		}
	}
	else return;
}


int Min(int** mas, const int ROW_COUNT, const int COL_COUNT, int& minmin, int& imin_1, int& jmin_1, int i, int j)
{
	if (mas[i][j] <= minmin)
	{
		minmin = mas[i][j];
		jmin_1 = j;
		imin_1 = i;
	}
	if (j < COL_COUNT - 1)
		Min(mas, ROW_COUNT, COL_COUNT, minmin, imin_1, jmin_1, i, j + 1);
	else
		if (i < ROW_COUNT - 1)
			Min(mas, ROW_COUNT, COL_COUNT, minmin, imin_1, jmin_1, i + 1, 0);
		else
			return minmin;
}
void Change(int** C, int& imin, int& jmin, int& i, int& j, const int COL_COUNT)
{
	int tmp = 0;
	tmp = C[i][COL_COUNT - 1 - i];
	C[i][COL_COUNT - 1 - i] = C[imin][jmin];
	C[imin][jmin] = tmp;
}
