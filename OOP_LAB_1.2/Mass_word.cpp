#include "pch.h"
#include "Mass_word.h"
#include <boost/algorithm/string.hpp>    

using namespace boost::algorithm;

namespace  OOP_LAB_12
{
	// копирующий конструктор
	Mass_word::Mass_word(const Mass_word &m) :size(m.size)
	{
		try 
		{
			mass = new char*[size];
			for (int i = 0; i < size; i++)
				mass[i] = strdup_(m.mass[i]);
		}
		catch (exception &ex)
		{
			cout << ex.what() << endl;
		}		
	}
	
	// перемещающий конструктор
	Mass_word::Mass_word(Mass_word &&m) :size(m.size), mass(m.mass)
	{
		m.mass = nullptr;
	}
	
	// оператор присваивания
	Mass_word & Mass_word::operator =(const Mass_word &m)
	{
		if (this != &m)
		{ // переделать чз временный объект
		
			int tmp_size = size;
			char **tmp_mas = mass;

			for (int i = 0; i < size; i++)
				delete[](mass[i]);
			delete[](mass);

			try 
			{
				size = m.size;
				mass = new char*[size];
				for (int i = 0; i < size; i++)
					mass[i] = strdup_(m.mass[i]);
			}
			catch (exception &ex)
			{
				for (int i = 0; i < size; i++)
					delete[](mass[i]);
				delete[](mass);

				size = tmp_size;
				mass = new char*[size];
				for (int i = 0; i < size; i++)
					mass[i] = strdup_(tmp_mas[i]);
				
				cout << ex.what() << endl;
				return *this;
			}
		}
		return *this;
	}
	
	 //перемещающий оператор присваивания
	Mass_word & Mass_word::operator =(Mass_word &&m)
	{
		int tmp_size = size;
		size = m.size;
		m.size = tmp_size;
		char **ptr = mass;
		mass = m.mass;
		m.mass = ptr;
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
		int size_tmp = 0;
		in >> size_tmp;
		
		if (m.size < 0)
		{
			in.setstate(ios_base::failbit);
			return in;
		}

		char str[LENGTH] = " ";
		
		char **mass_tmp;
		mass_tmp = new char*[size_tmp];
			
		for (int i = 0; i < size_tmp; i++)
		{
			in >> str;
			mass_tmp[i] = new char[strlen(str) + 1];
			strcpy_s(mass_tmp[i], strlen(str) + 1, str);
		}
		Mass_word temp(size_tmp, mass_tmp);
		m = temp;
		return in;
	}

	
	Mass_word & Mass_word::operator +=(const Mass_word &m)
	{
		char str;

		for (int i = 0; i < size; i++)
		{
			if (!strcmp(m.mass[0], mass[i]))
				throw exception("Невозможно добавить слово. Оно уже есть в массиве.");
		}

		char **tmp = mass;
		size += 1;
		mass = new char*[size];
		for (int i = 0; i < size - 1; i++)
			mass[i] = strdup_(tmp[i]);
		mass[size - 1] = strdup_(m.mass[0]);

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
				mass_tmp[k] = strdup_(mass[i]);
				k++;
			}
		
		size = k;
		delete[] mass;
		mass = new char*[size];
		for (int i = 0; i < size; i++)
			mass[i] = strdup_(mass_tmp[i]);
		delete[](mass_tmp);

		return *this;
	}

	Mass_word & Mass_word::sort() // Метод сортировка
	{
	
		char mass_tmp[SIZE][LENGTH]; // char **
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
			mass[i] = strdup_(mass_tmp[i]);

		return *this;
	}

	const int & Mass_word::search(const Mass_word &m) //поиск слова
	{
		int i, check = -1;
		for (i = 0; i < size; i++)
			if (!strcmp(mass[i], m.mass[0])) 
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
		if (index < 0)
			throw exception("Введено некорректное значение индекса. < 0 ");
		return mass[index];
	}
}