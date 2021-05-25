#include "pch.h"
#include <iostream>
#include "Mass_word.h"

using namespace std;
using namespace  OOP_LAB_12;

int main()
{
	setlocale(LC_ALL, "");
	Mass_word m;
	char str[LENGTH];
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
			cin >> str;
			try // проверка на ввод длинного слова > 15
			{
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
			char mass[SIZE][LENGTH] = { "Nice", "good", "new", "try", "OK" , "normal" , "ABC" , "ok" , "abc" , "trouble" };
			//m = Mass_word(SIZE, mass);
			break;
		}
		case 3:
			m = Mass_word();
			try
			{
				cin >> m;
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
			}
			break;
		case 4:
			try
			{
				cout << m;
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
			}
			break;
		case 5:
		{
			cout << "Введите слово." << endl;
			cin >> str;
			try
			{
				Mass_word b = Mass_word(str);
				m += b;
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
			}
			break;

		}
		case 6:
			cout << "Введите слово:" << endl;
			cin >> str;
			try
			{
				Mass_word b = Mass_word(str);
				int k = m.search(b);
				if (k < 0)
					cout << "Слова " << b[0] << " в массиве нет." << endl;
				else
					cout << "Слово " << b[0] << " есть в массиве. Его индекс: " << k << endl;
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
			}
			break;
		case 7:
			int index;
			cout << "Введите индекс для вывода слова на экран." << endl;
			cin >> index;
			try
			{
				cout << m[index];
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
			}
			break;
		case 8:
			cout << "Введите символ." << endl;
			try // проверка на ввод > 1 символа
			{
				string symb;
				cin >> symb;
				if (symb.length() > 1)
					throw exception("Вы ввели больше одного символа. Повторите ввод.");
				m(symb[0]);
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
			}
			break;
		case 9:
			try 
			{
				m.sort();
				cout << "Массив упорядочен." << endl;
			}
			catch (exception &ex)
			{
				cout << ex.what() << endl;
			}
			break;
		case 10:
			m = Mass_word();
			cout << "Пустой экземпляр класса создан." << endl;
			break;
		case 11:
			break;
		default:
			cout << "Ошибка выбора операции. Введите целое число!" << endl;
			menu = -1;
			break;
		}
		system("pause");
		system("cls");
	}

}

