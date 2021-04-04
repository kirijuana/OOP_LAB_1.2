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
		//static const int LENGTH = 15; // ������������ ����� ����� � �������
		//static const int SIZE = 10;   // ������ ������� ��-���������
		int size;
		char **mass;
	public:
		Mass_word() : size(SIZE), mass(new char*[size])
		{
			for (int i = 0; i < size; i++)
				mass[i] = new char[LENGTH];
		}

		Mass_word(char *word) : size(1), mass(new char*[size])
		{
			for (int i = 0; i < size; i++)
				mass[i] = strdup(word);
		}

		Mass_word(int size_1, char word[SIZE][LENGTH]) : size(size_1), mass(new char*[size])
		{
			for (int i = 0; i < size; i++)
				mass[i] = strdup(word[i]);
		}
		~Mass_word()
		{
 			for (int i = 0; i < size; i++)
			{
				delete[] mass[i];
			}
 			delete[] mass;
			mass = nullptr;
		}
		Mass_word(const Mass_word&); // ���������� �����������


		//Mass_word(Mass_word&&); // ������������ �����������
		// ������������� �������� ������������
		Mass_word & operator +=(const Mass_word &m); // ����������� ������ �� ������ ������� � ������	
		Mass_word &operator =(const Mass_word &); // ����������� ������ �� ������ ������� � ������

		//Mass_word &operator =(Mass_word &&);		// ������������ �������� ������������
		Mass_word & operator() (char c); // ���������� ��������� ()
		Mass_word & sort(); // ����������
		const int & search(const Mass_word &m); //����� �����
		// ������� �������
		int getSize() const { return size; }		// �������
		int getMaxSize() const { return SIZE; }	// ������������
		friend std::ostream & operator <<(std::ostream &, const Mass_word &);
		friend std::istream & operator >>(std::istream &, Mass_word &);
		const char* operator[] (const int index) const; // ���������� ��������� []
		char* strdup(char *s)
		{
			char *p = new char[strlen(s) + 1];

			strcpy_s(p, strlen(s)+1, s);
			return p;
		}
	};
}
#endif

