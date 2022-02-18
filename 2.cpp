#include <iostream>
#include <algorithm>
#include <vector>
#include<string>  
using namespace std;
const int nmax = 5;
//Дана квадратная матрица. Найти минимальное значение среди элементов, расположенных под главной диагональю.

void v(int** mas,int &m) {
	cout << "Матрица:\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
void minEl(int** mas, int& m, int &tempint) {
	for (int i = 1; i < m; i++) {
		for (int j = 0; j <= i - 1; j++)
			tempint=min(tempint,mas[i][j]);
	}
}
//void func3d(int*& mas, int& n, int i, int newelem) { //Добавление элемента
//	mas = (int*)realloc(mas, (n + 1) * sizeof(int));
//	for (int j = n; j > i; j--)
//		mas[j] = mas[j - 1];
//	mas[i + 1] = newelem;
//	n++;
//}
void vm(int** mas, int& m) {
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mas[i][j];
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int menu, ns, nd, nv, min_;
	vector<int>masv;
	int** mass = new int* [nmax];
	for (int i = 0; i < nmax; ++i)
	{
		mass[i] = new int[nmax];
	}
	cout << "Лабораторная работа №2 'Двумерный массив'. Галиханова Эмилия" << endl;
	do {
		cout << "Выберете тип матрицы, ввод которой Вы будете осуществлять: ";
		cout << "1:static  2:dynamic  3:vector \n";
		cin >> menu;
		switch (menu) {
		case 1: //static
			cout << "Какого размера будет ваша матрица nxn?(максимум n = 5): ";
			ns = 0;
			do
			{
				cin >> ns;
				if (ns > 10)
					cout << "Вы ввели значение, которое больше максимального размера статического массива! Попробуйте еще раз.\nСколько ввести элементов(максимум = 10): ";
			} while (ns > nmax);
			vm(mass, ns);
			min_ = mass[1][0];
			v(mass, ns);
			minEl(mass, ns, min_);
			cout <<"MINel = "<< min_ << endl;
			break;
		case 2:
			int** masd;
			cout << "Какого размера будет ваша матрица nxn?: ";
			nd = 0;
			do {
				cin >> nd;
				if (nd<=0)
					cout<<"Попробуйте,пожауйста, снова! Введите натуральное число!\nКакого размера будет ваша матрица nxn ? :";
			} while (nd <= 0);
			masd = new int* [nd];
			for (int i = 0; i < nd; ++i)
			{
				masd[i] = new int[nd];
			}
			vm(masd, nd);
			min_ = masd[1][0];
			v(masd, nd);
			minEl(masd, nd, min_);
			cout << "MINel = " << min_ << endl;
			break;
		case 3:

			break;

		}
		}while (menu != 0);
	}