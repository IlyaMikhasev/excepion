// Персональный шаблон
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = begin + rand() % (end);
}
template <typename T>
void show_arr(T arr[], const int length) {
	if (length <= 0)
		throw std::invalid_argument("Обнаружена отрицательная длинна массива");

	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
double devide(double num1, double num2);

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	//классическкая проверка(if else)
	
	std::cout << "Введите начала диапазона -> ";
	std::cin >> n;
	std::cout << "Введите конец диапазона -> ";
	std::cin >> m;
	if (n < m)
		std::cout << "ввод коректен\n";
	else
		std::cout << "ошибка ввода!\n";
	
	//обработка исключений
	
	try {
		std::cout << "Введите начала диапазона -> ";
		std::cin >> n;
		std::cout << "Введите конец диапазона -> ";
		std::cin >> m;
		if (n > m)
			throw 1;
		if (n == m)
			throw "границы диапазона равны";
		std::cout << "все отлчно\n";
	} 
	catch (const int& e) {
		if (e == 1)
			std::cout << "Начала диапазона больше конца диапазона\n";
	}
	catch (const char* e) {//константный указатель на символьный массив
		std::cout << "Ошибка: " << e << std::endl;
	}
	
	//обработка деления на ноль
	
	try {
		std::cout << "Введите два числа: ";
		std::cin >> n >> m;
		std::cout << n << " / " << m << " = " << devide(n, m) << '\n';
	}
	catch (const char* e) {
		std::cout << "Ошибка: " << e << '\n';
	}
	catch (const std::exception& ex) {
		std::cout << "Ошибка: " << ex.what() << '\n';
	}
	
	//обработка открытия файла
	
	std::string path = "file.txt/ds";
	std::ofstream out;
	out.exceptions(std::ios::badbit | std::ios::failbit | std::ios::eofbit);	
	try	{
		out.open(path);
		std::cout << "Файл открыт для записи.\n";

		out.close(); //при испсользование try надо закрытие файла указвать внутри блока 
	}
	catch (const std::ios::failure& ex)	{// failure предназначен для работы с файлами
		std::cout << "Ошибка открытия фала : " << ex.what() << '\n';
		std::cout << "Код ошибки: " << ex.code().value() << '\n'; //ex.code() возвращает оишбку .value() возвращает инт код ошибки для дальнейшей обработки
	}
	
	//задача 1 
	std::cout << "Задача 1.\nМассив:\n";
	const int size = 10;
	int arr[size];
	try {
		fill_arr(arr, size, 1, 10);
		show_arr(arr, size);
	}
	catch (const std::exception& ex) {
		std::cout<< "Ошибка: "<< ex.what() << std::endl;
	}


	return 0;
}
double devide(double num1, double num2) {
	if (num2 == 0)
		//	throw "обнаруженно деление на ноль";
		//throw std::exception("обнаруженно деление на ноль");
		throw std::invalid_argument("Делить на ноль нельзя");
	return num1 / num2;
}