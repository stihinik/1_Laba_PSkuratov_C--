// Laba_1_Sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Функция для чтения из файла и вывода содержимого файла в консоль
void Read_File(string from, vector<double> &to)
{
	ifstream file(from);
	if (file.is_open())
	{
		double nom;
		while (file >> nom)
		{
			to.push_back(nom);
		}
	}
	file.close();
}

//Записываем новые данные в файл
void Write_File(string to)
{

	cout << "Ввeдите цифры, если хотите закончить ввод, введите любую букву и нажмите Enter" << endl;
	double what = 0;
	bool flag = true;
	while (flag)
	{
		cin >> what;
		if (cin.good())
		{
			ofstream out(to, ios::app);
			if (out.is_open())
			{
				out << what << endl;
			}
			out.close();
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			flag = false;
		}
	}

}
//Очищаем файл и записываем новые данные 
void Write_File_All(string to)
{
	ofstream out(to);
	out.close();
	Write_File(to);
}
//Перезаписывем файл, после сортировки
void Write_File_After_Sort(string to, vector<double> from)
{
	// Очищаем файл 
	ofstream out(to);
	out.close();
	// Записываем отсортированные данные
	ofstream out_1(to, ios::app);
	for (auto element : from)
	{	
		if (out_1.is_open())
		{
			out_1 << element << endl;
		}
	}
	out_1.close();
}
// Выводим содержимое файла на консоль
void Print_Mas(vector<double> mas)
{
	system("cls");
	for (auto element : mas)
	{
		cout << element << " ";
	}
	cout << endl << endl;
}


int main()
{
	setlocale(LC_ALL, "russian_russia");
	// путь к файлу
	string puth = "C:\\Users\\Пользователь\\Desktop\\магистр\\С++\\1_Laba_PSkuratov_C++\\1_Laba_PSkuratov_C--\\Файл_Для_Сортировки.txt";
	//число для выбора функционала 
	int Nomer = 10;
	//вектор для хранения данных из файла
	vector<double> massiv;
	
	while (1)
	{
		//функционал программы
		cout << "Выберете что сделать с файлом" << endl;
		cout << "1 - Вывести содержимое файла на консоль" << endl;
		cout << "2 - Записать новые данные в файл" << endl;
		cout << "3 - Отсортировать файл по возростанию, записать и вывести содержимое на экран" << endl;
		cout << "4 - Отсортировать файл по убыванию, записать и вывести содержимое на экран" << endl;
		cout << "5 - Перезаписать файл" << endl;
		cout << "0 - Закрыть программу" << endl;
		cin >> Nomer;
		system("cls");
		if (Nomer == 1)
		{
			massiv.clear();
			Read_File(puth, massiv);
			Print_Mas(massiv);
		}
		else if (Nomer == 2)
		{
			system("cls");
			Write_File(puth);
			system("cls");
		}
		else if (Nomer == 3)
		{
			sort(massiv.begin(), massiv.end());
			Write_File_After_Sort(puth, massiv);
			Print_Mas(massiv);

		}
		else if (Nomer == 4)
		{
			sort(massiv.rbegin(), massiv.rend());
			Write_File_After_Sort(puth, massiv);
			Print_Mas(massiv);
		}
		else if (Nomer == 5)
		{
			system("cls");
			Write_File_All(puth);
			system("cls");
		}
		else if (Nomer == 0){break;}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
