#ifndef _MASS_WORD_
#define _MASS_WORD_

#include <iostream>
#include <string>
#include "constants.h"

using namespace std;
using namespace constants;

namespace  OOP_LAB_12
{
	class Mass_word
	{
	private:
		int size;
		char **mass;
	public:
		Mass_word() : size(0), mass(nullptr)
		{
		}

		Mass_word(const char *word) : size(1), mass(new char*[size])
		{	
			for (int i = 0; i < size; i++)
				mass[i] = strdup_(word);
		}

		Mass_word(const int size_1, char **word) : size(size_1), mass(new char*[size]) // char **word
		{
			for (int i = 0; i < size; i++)
				mass[i] = strdup_(word[i]);
		}
		~Mass_word()
		{
 			for (int i = 0; i < size; i++)
			{
 				delete[] mass[i];
			}
 			delete[] mass;		
		}

		Mass_word(const Mass_word&); // копирующий конструктор
		Mass_word(Mass_word&&);			// перемещающий конструктор 
		Mass_word &operator =(const Mass_word &); // копирование данных из одного массива в другой
		// перемещающий оператор присваивания
		Mass_word &operator =(Mass_word &&);
		Mass_word & operator() (char c); // перегрузка оператора ()
		Mass_word & operator +=(const Mass_word &m);
		Mass_word & sort(); // сортировка
		const int & search(const Mass_word &m); //поиск слова

		friend std::ostream & operator <<(std::ostream &, const Mass_word &);
		friend std::istream & operator >>(std::istream &, Mass_word &);
		const char* operator[] (const int index) const; // перегрузка оператора []
	
		char* strdup_(const char *s)
		{
			try
			{
				char *p = new char[strlen(s) + 1];
				strcpy_s(p, strlen(s) + 1, s);
				return p;
			}
			catch(exception &ex)
			{
				cout << ex.what() << endl;
			}		
		}
	};
}
#endif

