#include "pch.h"
#include <iostream>
#include "Mass_word.h"
#include "constants.h"

using namespace constants;
using namespace std;
using namespace  OOP_LAB_12;

int main()
{
	setlocale(LC_ALL, "");
	//Mass_word m = Mass_word();

	cout << "Введите количество слов:" << endl;
	int size;
	try
	{
		cin >> size;
	}
	catch (exception &ex)
	{
		cout << ex.what() << std::endl;
	}

	cout << "Введите " << size << " слов: " << endl;

	char **mass;
	mass = new char*[size];
	for (int k = 0; k < size; k++)
		mass[k] = new char[LENGTH];

	for (int i = 0; i < size; i++)
	{
		cin >> mass[i];
		for (int j = 0; j < i; j++)
		{
			try // проверка на ввод повторяющихся слов
			{
				if (!strcmp(mass[i], mass[j]))
					throw exception("Такое слово уже есть в массиве. Введите другое слово.");
				if (strlen(mass[i]) > LENGTH)
					throw exception("Введенное слово превышает максимальное значение длинны слова в массиве. Допустимая длинна 15 символов.");
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
				i--;
			}
		}
	}
	
	Mass_word m(size, mass);

	char str_1[LENGTH];
	int check;
	check = 0; // переменная для повторного ввода слова, в случае повторения
	do
	{
		cout << "Введите слово:" << endl;
		try // проверка на ввод длинного слова > 15
		{
			cin >> str_1;
			if (strlen(str_1) > LENGTH)
				throw exception("Введенное слово превышает максимальное значение длинны слова в массиве. Допустимая длинна 15 символов.");
			for (int i = 0; i < m.getSize(); i++)
			{
				try // проверка на ввод повторяющихся слов
				{
					if (!strcmp(str_1, m[i]))
					{
						check = 1;
						throw exception(" Такое слово уже есть в массиве. Попробуйте добавить другое слово.");
					}
					check = 0;
				}
				catch (exception &ex)
				{
					cout << ex.what() << endl;
					break;
				}
			}
		}
		catch (exception &ex)
		{
			cout << ex.what() << endl;
			break;
		}
	} while (check);
	if (!(strlen(str_1) >= LENGTH))
		m += str_1;

	int menu = 1;

	while (menu != 11)
	{
		cout << "Введите:" << endl;
		cout << "1. Для создания экземпляра класса с инициализацией одним словом, т.е. строкой символов" << endl;
		cout << "2. Для создания экземпляров класса с инициализацией количеством слов и словами из массива строковых констант" << endl;
		cout << "3. Для ввода экземпляров класса из входного потока" << endl;
		cout << "4. Для вывода экземпляров класса в выходной поток" << endl;
		cout << "5. Для добавления слова к массиву слов" << endl;
		cout << "6. Для поиска слова в массиве" << endl;
		cout << "7. Для выделения слова по его номеру в массиве" << endl;
		cout << "8. Для формирования массива слов, начинающихся на заданный символ без учета регистра" << endl;
		cout << "9. Для упорядочивания слов в массиве по алфавиту" << endl;
		cout << "10. Для создания пустого экземпляра класса" << endl;
		cout << "11. Для выхода." << endl;
		cin >> menu;
		system("cls");

		switch (menu)
		{
		case 1:
		{
			cout << "Введите строку:" << endl;
			char str[LENGTH];
			try // проверка на ввод повторяющихся слов
			{
				cin >> str;
				if (strlen(str) > LENGTH)
					throw exception("Введенное слово превышает максимальное значение длинны слова в массиве. Допустимая длинна 15 символов.");
				m = Mass_word(str);
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
			}
			break;
		}
		case 2:
		{
			cout << "Введите количество слов:" << endl;
			int size;
			try
			{
				cin >> size;
			}
			catch (exception &ex)
			{
				cout << ex.what() << std::endl;
			}
			
			cout << "Введите " << size << " слов: " << endl;
			
			char **mass;
			mass = new char*[size];
			for (int k = 0; k < size; k++)
				mass[k] = new char[LENGTH];

			for (int i = 0; i < size; i++)
			{
				cin >> mass[i];
				for (int j = 0; j < i; j++)
				{
					try // проверка на ввод повторяющихся слов
					{
						if (!strcmp(mass[i], mass[j]))
							throw exception("Такое слово уже есть в массиве. Введите другое слово.");
						if (strlen(mass[i]) > LENGTH)
							throw exception("Введенное слово превышает максимальное значение длинны слова в массиве. Допустимая длинна 15 символов.");
					}
					catch (exception &ex)
					{
						cout << ex.what() << endl;
						i--;
					}
				}
			}
			Mass_word w(size, mass);
			m = w;
			cout << w;
			system("pause");
			
			break;
		}
		case 3:
		{
			m = Mass_word();
			cout << "Введите " << SIZE << " слов:" << endl;
			try // проверка на ввод повторяющихся слов
			{
				cin >> m;
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
			}
			break;
		}
		case 4:
		{
			try // проверка на вывод пустого массива
			{
				cout << m;
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
			}
			break;
		}
		case 5:
		{
			char str_1[LENGTH];
			int check;
			check = 0; // переменная для повторного ввода слова, в случае повторения
			do
			{
				cout << "Введите слово:" << endl;
				try // проверка на ввод длинного слова > 15
				{
					cin >> str_1;
					if (strlen(str_1) > LENGTH)
						throw exception("Введенное слово превышает максимальное значение длинны слова в массиве. Допустимая длинна 15 символов.");
					for (int i = 0; i < m.getSize(); i++)
					{
						try // проверка на ввод повторяющихся слов
						{
							if (!strcmp(str_1, m[i]))
							{
								check = 1;
								throw exception(" Такое слово уже есть в массиве. Попробуйте добавить другое слово.");
							}
							check = 0;
						}
						catch (exception &ex)
						{
							cout << ex.what() << endl;
							break;
						}
					}
				}
				catch (exception &ex)
				{
					cout << ex.what() << endl;
					break;
				}
			} while (check);
			if (!(strlen(str_1) >= LENGTH))
				m += str_1;
			break;
		}
		case 6:
		{
			char str_1[LENGTH];
			cout << "Введите слово:" << endl;
			cin >> str_1;
			try // проверка на ввод длинного символа
			{
				m.search(str_1);
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
			}
			break;
		}
		case 7:
		{
			int index;
			cin >> index;
			cout << "Введите индекс слова для вывода этого слова на экран." << endl;
			try // проверка на ввод большого индекса
			{
				cout << m[index];
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
			}
			break;
		}
		case 8:
		{
			//cout << "Введите символ." << endl;
			//char *symb;
			//cin >> symb;
			//try // проверка на ввод > 1 символа
			//{
			//	if (symb.length() > 1)
			//		throw exception("Вы ввели больше одного символа. Повторите ввод.");
			//	m(symb[0]);
			//}
			//catch (exception &ex)
			//{
			//	cout << ex.what() << endl;
			//}
			break;
		}
		case 9:
		{
			try // проверка на сортировку пустого массива или массива из 1го элемента
			{
				m.sort();
				cout << "Массив упорядочен." << endl;
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
			}
			break;
		}
		case 10:
		{
			m = Mass_word();
			cout << "Пустой экземпляр класса создан." << endl;
			break;
		}
		case 11:
		{
			break;
		}
		default:
		{
			cout << "Ошибка выбора операции. Введите целое число!" << endl;
			menu = -1;
			break;
		}
		}
		system("pause");
		system("cls");
	}

}

