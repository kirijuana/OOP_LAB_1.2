#include "pch.h"
#include "Mass_word.h"
namespace  OOP_LAB_12
{
	// ���������� �����������
	Mass_word::Mass_word(const Mass_word &m) :size(m.size)
	{
		mass = new char*[size];
		for (int i = 0; i < size; i++)
		{
			mass[i] = new char[LENGTH];
			mass[i] = m.mass[i];
		}
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
			{
				mass[i] = new char[LENGTH];
				mass[i] = m.mass[i];
			}
		}
		return *this;
	}
	
	ostream & operator <<(ostream &out, const Mass_word &m)
	{
		//if (m.size == 0)
		//	throw exception("������ ����.");
		//else
		//{
		out << "�����: " << endl;
		for (int i = 0; i < m.size; i++)
		{
			out << i + 1 << ") " << m.mass[i] << endl;
		}
		//}

		return out;
	}

	istream & operator >>(istream &in, const Mass_word &m) {
		for (int i = 0; i < m.size; i++)
		{
			in >> m.mass[i];
			if (strlen(m.mass[i]) >= m.LENGTH)
				throw exception("��������� ����� ��������� ������������ �������� ������ ����� � �������. ���������� ������ 15 ��������.");
			for (int j = 0; j < i; j++)
			{
				if (!strcmp(m.mass[i], m.mass[j]))
					throw exception("������ �� ��� ��������, ��������� �� ����� ������������� �����. ��������� ������ �����.");
			}
		}
		return in;
	}

	// ������������� �������� ������������
	Mass_word & Mass_word::operator +=(const char *word)
	{
		char **tmp;
		tmp = new char*[size];
		for (int i = 0; i < size; i++)
		{ 
			tmp[i] = new char[LENGTH];
			tmp[i] = mass[i];
		}

		size += 1;
		mass = new char*[size];
		for (int i = 0; i < size - 1; i++)
		{
			mass[i] = new char[LENGTH];
			mass[i] = tmp[i];
		}
		mass[size - 1] = new char[LENGTH];

		for (int i = 0; i < size - 1; i++)
			delete[](tmp[i]);
		delete[](tmp);

		for (int i = 0; i < LENGTH; i++)
		{
			if (i < strlen(word))
				mass[size - 1][i] = word[i];
			else
				mass[size - 1][i] = ' ';
		}
		return *this;
	}



	char* Mass_word::operator[] (const int index) // ���������� ��������� []
	{
		return mass[index];
	}

	Mass_word & Mass_word::operator() (char c) // ���������� ��������� ()
	{
		char mass1[SIZE][LENGTH] = { "Hello", "Buy", "From", "Russia", "russia", "Rainbow", "Germany", "great", "Britan", "based" };
		int k = 0;
		for (int i = 0; i < SIZE; i++)
		{
			if (((int)mass1[i][0] - (int)c) % 32 == 0 || mass1[i][0] == c)
			{
				for (int j = 0; j < LENGTH; j++)
				{
					mass[k][j] = mass1[i][j];
				}
				k++;
			}
		}
		size = k;
		return *this;
	}

	Mass_word & Mass_word::sort() // ����� ����������
	{
		if (size == 0)
		{
			throw exception("������ ����. ���������� ����������.");
		}
		if (size == 1)
		{
			throw exception("������ �������� 1 �������. ���������� ����������.");
		}
		char tmp[LENGTH];
		for (int j = 1; j < size; j++)
			for (int i = 0; i < size - j; i++)
			{
				if (strcmp(mass[i + 1], mass[i]) < 0)
				{
					for (int k = 0; k < LENGTH; k++)
						tmp[k] = mass[i][k];
					for (int k = 0; k < LENGTH; k++)
						mass[i][k] = mass[i + 1][k];
					for (int k = 0; k < LENGTH; k++)
						mass[i + 1][k] = tmp[k];
				}
			}
		return *this;
	}

	const Mass_word & Mass_word::search(const char *m) //����� �����
	{
		if (strlen(m) > LENGTH)
			throw exception("��������� ����� ��������� ������������ �������� ������ ����� � �������. ���������� ������ 15 ��������.");
		int check = 0; // ���������� ��� �������� ������������ 2-� ����
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < LENGTH; j++)
			{
				if (mass[i][j] == m[j])
					check++;
				else
				{
					check = 0;
					break;
				}

				if (check == strlen(m))
				{
					cout << "�����: " << "<<" << m << ">>" << " " << "����. ��� �������: �" << i + 1 << endl;
					check = -1;
					break;
				}

			}
			if (check == -1)
				break;
			check = 0;
		}
		if (check != -1)
		{
			cout << "�����: " << m << " " << "���." << endl;
		}
		return *this;
	}

}