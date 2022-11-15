// ������������ ������
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
		throw std::invalid_argument("���������� ������������� ������ �������");

	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
double devide(double num1, double num2);

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	//������������� ��������(if else)
	
	std::cout << "������� ������ ��������� -> ";
	std::cin >> n;
	std::cout << "������� ����� ��������� -> ";
	std::cin >> m;
	if (n < m)
		std::cout << "���� ��������\n";
	else
		std::cout << "������ �����!\n";
	
	//��������� ����������
	
	try {
		std::cout << "������� ������ ��������� -> ";
		std::cin >> n;
		std::cout << "������� ����� ��������� -> ";
		std::cin >> m;
		if (n > m)
			throw 1;
		if (n == m)
			throw "������� ��������� �����";
		std::cout << "��� ������\n";
	} 
	catch (const int& e) {
		if (e == 1)
			std::cout << "������ ��������� ������ ����� ���������\n";
	}
	catch (const char* e) {//����������� ��������� �� ���������� ������
		std::cout << "������: " << e << std::endl;
	}
	
	//��������� ������� �� ����
	
	try {
		std::cout << "������� ��� �����: ";
		std::cin >> n >> m;
		std::cout << n << " / " << m << " = " << devide(n, m) << '\n';
	}
	catch (const char* e) {
		std::cout << "������: " << e << '\n';
	}
	catch (const std::exception& ex) {
		std::cout << "������: " << ex.what() << '\n';
	}
	
	//��������� �������� �����
	
	std::string path = "file.txt/ds";
	std::ofstream out;
	out.exceptions(std::ios::badbit | std::ios::failbit | std::ios::eofbit);	
	try	{
		out.open(path);
		std::cout << "���� ������ ��� ������.\n";

		out.close(); //��� �������������� try ���� �������� ����� �������� ������ ����� 
	}
	catch (const std::ios::failure& ex)	{// failure ������������ ��� ������ � �������
		std::cout << "������ �������� ���� : " << ex.what() << '\n';
		std::cout << "��� ������: " << ex.code().value() << '\n'; //ex.code() ���������� ������ .value() ���������� ��� ��� ������ ��� ���������� ���������
	}
	
	//������ 1 
	std::cout << "������ 1.\n������:\n";
	const int size = 10;
	int arr[size];
	try {
		fill_arr(arr, size, 1, 10);
		show_arr(arr, size);
	}
	catch (const std::exception& ex) {
		std::cout<< "������: "<< ex.what() << std::endl;
	}


	return 0;
}
double devide(double num1, double num2) {
	if (num2 == 0)
		//	throw "����������� ������� �� ����";
		//throw std::exception("����������� ������� �� ����");
		throw std::invalid_argument("������ �� ���� ������");
	return num1 / num2;
}