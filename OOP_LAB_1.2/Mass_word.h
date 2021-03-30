#ifndef _MASS_WORD_
#define _MASS_WORD_

#include <iostream>
#include <string.h>

using namespace std;
namespace  OOP_LAB_12
{
	class Mass_word
	{
	private:
		static const int LENGTH = 15; // ������������ ����� ����� � �������
		static const int SIZE = 10;   // ������ ������� ��-���������
		int size;
		char **mass;
	public:
		Mass_word() : size(SIZE), mass(new char*[size])
		{
			for (int i = 0; i < size; i++)
			{
				mass[i] = new char[LENGTH];
				for (int j = 0; j < LENGTH; j++)
				{
					mass[i][j] = ' ';
				}
			}
		}

		Mass_word(const char *word) : size(1), mass(new char*[size])
		{
			for (int i = 0; i < size; i++)
			{
				mass[i] = new char[LENGTH];
				
				for (int j = 0; j < LENGTH; j++)
				{
					if (j < sizeof(word))
						mass[i][j] = word[j];
					else
						mass[i][j] = ' ';
				}
			}
		}

		Mass_word(int size_1, char **word) : size(size_1), mass(new char*[size])
		{
			for (int i = 0; i < size; i++)
			{
				mass[i] = new char[LENGTH];
				
				for (int j = 0; j < LENGTH; j++)
				{
					if (j < strlen(word[i]))
						mass[i][j] = word[i][j];
					else
						mass[i][j] = ' ';
				}
			}

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
		Mass_word & operator +=(const char *word); // ����������� ������ �� ������ ������� � ������	
		Mass_word &operator =(const Mass_word &); // ����������� ������ �� ������ ������� � ������

		//Mass_word &operator =(Mass_word &&);		// ������������ �������� ������������
		Mass_word & operator() (char c); // ���������� ��������� ()
		Mass_word & sort(); // ����������
		const Mass_word & search(const char *m); //����� �����
		// ������� �������
		int getSize() const { return size; }		// �������
		int getMaxSize() const { return SIZE; }	// ������������
		friend std::ostream & operator <<(std::ostream &, const Mass_word &);
		friend std::istream & operator >>(std::istream &, const Mass_word &);
		char* operator[] (const int index); // ���������� ��������� []
	};
}
#endif