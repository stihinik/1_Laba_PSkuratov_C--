// Laba_1_Sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

//Записываем поток данных с консоли
void Read_withConsol(std::vector<double> &mas)
{
	std::cout << "Ввeдите цифры, если хотите закончить ввод, введите любую букву и нажмите Enter" << std::endl;
	double what = 0;
	bool flag = true;
	while (flag)
	{
		std::cin >> what;
		if (std::cin.good()) { mas.push_back(what); }
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			flag = false;
		}
	}
}
//Функция для чтения из файла и вывода содержимого файла в консоль
void Read_File(std::string from, std::vector<double> &to)
{
	std::ifstream file(from);
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
void Write_File(std::string to, std::vector<double> &mas)
{
	std::ofstream out(to, std::ios::app);
	for (size_t i = 0; i < mas.size(); i++)
	{
		if (out.is_open())
		{
			out << mas[i]<< std::endl;
		}
	}
	out.close();
}
//Очищаем файл
void Clear_File(std::string to)
{
	std::ofstream out(to);
	out.close();
}

// Выводим содержимое файла на консоль
void Print_Massive(std::vector<double> mas)
{
	for (auto element : mas)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl << std::endl;
}

// Сортировка выбором по возростанию
void Sort_Massiv_Increase(std::vector<double> &mas)
{
	int j = 0;
	int tmp = 0;
	for (size_t i = 0; i < mas.size(); i++) {
		j = i;
		for (size_t k = i; k < mas.size(); k++) {
			if (mas[j] > mas[k]) {
				j = k;
			}
		}
		tmp = mas[i];
		mas[i] = mas[j];
		mas[j] = tmp;
	}
}
// Сортировка выбором по убыванию
void Sort_Massiv_Decrease(std::vector<double> &mas)
{
	int j = 0;
	int tmp = 0;
	for (size_t i = 0; i < mas.size(); i++) {
		j = i;
		for (size_t k = i; k < mas.size(); k++) {
			if (mas[j] < mas[k]) {
				j = k;
			}
		}
		tmp = mas[i];
		mas[i] = mas[j];
		mas[j] = tmp;
	}
}

void Test_Sort_Increase(std::string to, std::vector<double> &mas)
{
	Clear_File(to);
	// 1 тест на рандомные числа
	std::vector<double> check_mas;
	std::cout << "1 тест на запись рандомным значений и отсортировка их по возростанию" << std::endl;
	for (int i = 0; i < 20; i++)
	{
		double rand = std::rand() % 1000;
		mas.push_back(rand);
		check_mas.push_back(rand);
	}
	Sort_Massiv_Increase(mas);
	std::sort(check_mas.begin(), check_mas.end());
	bool flag = true;
	for (int i = 0; i < 20; i++)
	{
		if (check_mas[i] != mas[i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		std::cout << "Первый тест пройден успешно"<< std::endl;
	}
	else
	{
		std::cout << "первый тест не пройден, программа работает некоректно" << std::endl;
	}
}
void Test_Sort_Decrease(std::string to, std::vector<double> &mas)
{
	//2 тест 
	Clear_File(to);
	mas.clear();
	std::vector<double> check_mas;
	std::cout << "2 тест на запись рандомным значений и отсортировка их по убыванию" << std::endl;
	for (int i = 0; i < 20; i++)
	{
		double rand = std::rand() % 1000;
		mas.push_back(rand);
		check_mas.push_back(rand);
	}
	Sort_Massiv_Decrease(mas);
	std::sort(check_mas.rbegin(), check_mas.rend());
	bool flag = true;
	for (int i = 0; i < 20; i++)
	{
		if (check_mas[i] != mas[i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		std::cout << "Второй тест пройден успешно" << std::endl;
	}
	else
	{
		std::cout << "Второй тест не пройден, программа работает некоректно" << std::endl;
	}
}
void Test_Sorting_Sequence_Increase(std::string to, std::vector<double> &mas)
{
	//3 тест 
	Clear_File(to);
	mas.clear();
	std::cout << "3 тест на запись последовательных по возростанию и отсортировка их по возростанию" << std::endl;
	for (int i = 0; i < 20; i++)
	{
		mas.push_back(i);
	}
	Sort_Massiv_Increase(mas);
	bool flag = true;
	for (double i = 0; i < 20; i++)
	{
		if (i != mas[i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		std::cout << "Третий тест пройден успешно" << std::endl;
	}
	else
	{
		std::cout << "Третий тест не пройден, программа работает некоректно" << std::endl;
	}
}
void Test_Sorting_Sequence_Decrease(std::string to, std::vector<double> &mas)
{
	//4 тест 
	Clear_File(to);
	mas.clear();
	std::cout << "4 тест на запись последовательных по убыванию, отсортировка их по убыванию и запись в файл" << std::endl;
	for (int i = 20; i > 0; i--)
	{
		mas.push_back(i);
	}
	Sort_Massiv_Decrease(mas);
	bool flag = true;
	double k = 20;
	for (int i = 0; i < 20; i++)
	{
		if (k != mas[i])
		{
			flag = false;
			break;
		}
		k--;
	}
	if (flag)
	{
		std::cout << "Четвертый тест пройден успешно" << std::endl;
	}
	else
	{
		std::cout << "Четвертый тест не пройден, программа работает некоректно" << std::endl;
	}
}

void Test_Void_Massiv(std::string to,std::vector<double> &mas)
{
	//5 тест 
	Clear_File(to);
	mas.clear();
	std::cout << "5 тест на запись пустого массиваи запись в файл" << std::endl;
	Sort_Massiv_Decrease(mas);
	Write_File(to, mas);
	mas.clear();
	Read_File(to, mas);
	if (mas.size() == 0)
	{
		std::cout << "Пятый тест пройден успешно" << std::endl;
	}
	else
	{
		std::cout << "Пятый тест не пройден, программа работает некоректно" << std::endl;
	}
	Clear_File(to);
}


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "russian_russia");
	// путь к файлу
	const std::string way_file = "C:\\Users\\Пользователь\\Desktop\\магистр\\С++\\1_Laba_PSkuratov_C++\\1_Laba_PSkuratov_C--\\Файл_Для_Сортировки.txt";
	//число для выбора функционала 
	int number_choose = 10;
	//вектор для хранения данных из файла
	std::vector<double> massiv;
	//проверка раьтоспособности программы 
	Test_Sort_Increase(way_file, massiv);
	Test_Sort_Decrease(way_file, massiv);
	Test_Sorting_Sequence_Increase(way_file, massiv);
	Test_Sorting_Sequence_Decrease(way_file, massiv);
	Test_Void_Massiv(way_file, massiv);
	std::cout << "Все работает" << std::endl << std::endl;
	while (1)
	{
		//функционал программы
		std::cout << "Выберете что сделать с файлом" << std::endl;
		std::cout << "1 - Вывести содержимое файла на консоль" << std::endl;
		std::cout << "2 - Записать новые данные в файл" << std::endl;
		std::cout << "3 - Отсортировать файл по возростанию, записать и вывести содержимое на экран" << std::endl;
		std::cout << "4 - Отсортировать файл по убыванию, записать и вывести содержимое на экран" << std::endl;
		std::cout << "5 - Перезаписать файл" << std::endl;
		std::cout << "0 - Закрыть программу" << std::endl;
		std::cin >> number_choose;
		system("cls");
		if (number_choose == 1)
		{
			massiv.clear();
			Read_File(way_file, massiv);
			system("cls");
			Print_Massive(massiv);
		}
		else if (number_choose == 2)
		{
			system("cls");
			massiv.clear();
			Read_withConsol(massiv);
			Write_File(way_file, massiv);
			system("cls");
		}
		else if (number_choose == 3)
		{
			massiv.clear();
			Read_File(way_file, massiv);
			Clear_File(way_file);
			Sort_Massiv_Increase(massiv);
			Write_File(way_file, massiv);
			system("cls");
			Print_Massive(massiv);
		}
		else if (number_choose == 4)
		{
			massiv.clear();
			Read_File(way_file, massiv);
			Clear_File(way_file);
			Sort_Massiv_Decrease(massiv);
			Write_File(way_file, massiv);
			system("cls");
			Print_Massive(massiv);
		}
		else if (number_choose == 5)
		{
			system("cls");
			Clear_File(way_file);
			massiv.clear();
			Read_withConsol(massiv);
			Write_File(way_file, massiv);
			system("cls");
		}
		else if (number_choose == 0){break;}
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
