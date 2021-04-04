#include "pch.h"
#include "Mass_word.h"
#include <boost/algorithm/string.hpp>    

using namespace boost::algorithm;

namespace  OOP_LAB_12
{
	// копирующий конструктор
	Mass_word::Mass_word(const Mass_word &m) :size(m.size)
	{
		mass = new char*[size];
		for (int i = 0; i < size; i++)
			mass[i] = strdup(m.mass[i]);
	}
	
	Mass_word & Mass_word::operator =(const Mass_word &m)
	{
		if (this != &m)
		{
			for (int i = 0; i < size; i++)
				delete[](mass[i]);
			delete[](mass);

			size = m.size;
			mass = new char*[size];
			for (int i = 0; i < size; i++)
				mass[i] = strdup(m.mass[i]);
		}
		return *this;
	}
	
	ostream & operator <<(ostream &out, const Mass_word &m)
	{
		if (m.size == 0)
			out << "Массив пуст." << endl;
		else
		{
			out << "Слова: " << endl;
			for (int i = 0; i < m.size; i++)
				out << i + 1 << ") " << m.mass[i] << endl;
		}
		return out;
	}

	istream & operator >>(istream &in, Mass_word &m) 
	{
		cout << "Введите количество слов:" << endl;
		cin >> m.size;
		if (m.size > SIZE || m.size < 0)
			throw exception("Введено некорректное число слов: > 10 или < 0.");
		char str[LENGTH];
		
		Mass_word temp = Mass_word(str);
		int size_tmp = 0;

		for (int i = 0; i < m.size; i++)
		{
			in >> str;
			strcpy_s(temp.mass[0], strlen(str) + 1, str);
			size_tmp = m.size;
			m.size = i;
			m += temp;
			m.size = size_tmp;
		}
		return in;
	}

	// перегруженный оператор присваивания
	Mass_word & Mass_word::operator +=(const Mass_word &m)
	{
		char str[LENGTH];
		if (strlen(m.mass[0]) > LENGTH)
			throw exception("Введенное слово превышает максимальное значение длинны слова в массиве. Допустимая длинна 15 символов.");
		if (size == SIZE)
			throw exception("Невозможно добавить слово. Массив переполнен.");
		for (int i = 0; i < size; i++)
		{
			if (!strcmp(m.mass[0], mass[i]))
				throw exception("Невозможно добавить слово. Оно уже есть в массиве.");
		}

		char **tmp = mass;
		size += 1;
		mass = new char*[size];
		for (int i = 0; i < size - 1; i++)
			mass[i] = strdup(tmp[i]);
		mass[size - 1] = strdup(m.mass[0]);

		delete[](tmp);

		return *this;
	}

	Mass_word & Mass_word::operator() (char c) // перегрузка оператора ()
	{
		char **mass_tmp = new char*[size];

		
		int k = 0;
		for (int i = 0; i < size; i++)
			if (toupper(mass[i][0]) == toupper(c))
			{
				mass_tmp[k] = strdup(mass[i]);
				k++;
			}
		
		size = k;
		delete[] mass;
		mass = new char*[size];
		for (int i = 0; i < size; i++)
			mass[i] = strdup(mass_tmp[i]);
		delete[](mass_tmp);

		return *this;
	}

	Mass_word & Mass_word::sort() // Метод сортировка
	{
		if (size == 0)
			throw exception("Массив пуст. Сортировка невозможна.");
		if (size == 1)
			throw exception("Массив содержит 1 элемент. Сортировка невозможна.");
	
		char mass_tmp[SIZE][LENGTH];
		for (int i = 0; i < size; i++)
			strcpy_s(mass_tmp[i], mass[i]);
		
		char tmp[LENGTH];
		char tmp_mass_1[LENGTH];
		char tmp_mass_2[LENGTH];

		for (int j = 1; j < size; j++)
			for (int i = 0; i < size - j; i++)
			{
				strcpy_s(tmp_mass_1, mass_tmp[i + 1]);
				to_lower(tmp_mass_1);
				strcpy_s(tmp_mass_2, mass_tmp[i]);
				to_lower(tmp_mass_2);

				if (strcmp(tmp_mass_1, tmp_mass_2) < 0)
				{
					for (int k = 0; k < LENGTH; k++)
						tmp[k] = mass_tmp[i][k];
					for (int k = 0; k < LENGTH; k++)
						mass_tmp[i][k] = mass_tmp[i + 1][k];
					for (int k = 0; k < LENGTH; k++)
						mass_tmp[i + 1][k] = tmp[k];
				}
			}
		
		delete[] mass;
		
		mass = new char*[size];
		for (int i = 0; i < size; i++)
			mass[i] = strdup(mass_tmp[i]);

		return *this;
	}

	const int & Mass_word::search(const Mass_word &m) //поиск слова
	{
		int i, check = -1;
		for (i = 0; i < size; i++)
			if (!strcmp(mass[i], m.mass[0])) //strcmp
			{
				check = 1;
				break;
			}
		if (check != 1)
			i = -1;
		return i;
	}

	const char* Mass_word::operator[] (const int index) const // перегрузка оператора []
	{
		if (index < 0 || index >= SIZE)
			throw exception("Введено некорректное значение индекса. < 0 или > 10");
		return mass[index];
	}
}