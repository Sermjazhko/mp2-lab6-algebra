﻿#include "Interface.h"

void printTableList(const string& str)
{
	cout << str << endl;
	cout << " 1 - Линейная таблица на массиве" << endl;
	cout << " 2 - Линейная таблица на списке" << endl;
	cout << " 3 - Упорядоченная таблица на массиве" << endl;
	cout << " 4 - Авл-дерево" << endl;
	cout << " 5 - Хеш-таблица на массиве" << endl;
	cout << " 6 - Хеш-таблица на списке" << endl;
}

void printMenuList(const string& str)
{
	cout << str << endl;
	cout << " 1 - Добавить полином" << endl;
	cout << " 2 - Найти по имени полином и поиздеваться над ним" << endl;
	cout << " 3 - Ввести арифметическое выражение" << endl;
	cout << " 4 - Вывести все полиномы" << endl;
	cout << " 5 - Удалить полином" << endl;
	cout << " 6 - Выход" << endl;
}

void printPolynomOperation(const string& str)
{
	cout << str << endl;
	cout << " 1 - Изменить полином" << endl;
	cout << " 2 - Посчитать полином в точке" << endl;
	cout << " 3 - Проинтегрировать по X" << endl;
	cout << " 4 - Проинтегрировать по Y" << endl;
	cout << " 5 - Проинтегрировать по Z" << endl;
	cout << " 6 - Выход" << endl;
}

void printExit(const string& str)
{
	cout << str << endl;
	cout << " 0 - Нет" << endl;
	cout << " 1 - Да" << endl;
}

void printCalculate(const string& str)
{
	cout << str << endl;
	cout << " 1 - Посчитать полином" << endl;
	cout << " 2 - Посчитать полином по выражению в точке" << endl;
	cout << " 3 - Выход" << endl;
}

void keyRules()
{
	cout << " 1. Вводить имя(ключ) можно только маленькими буквами" << endl;
	cout << " 2. Без использования всяких непристойных знаков (например, _*/!\.,)" << endl;
	cout << " 3. Без цифр" << endl;
}

void polynomRules()
{
	cout << " 1. Правила по вводу полиномов я не помню, так что на свой страх и риск вводите" << endl;
}

void panika(int k)
{
	if (k == 10)
	{
		cout << "НЕ ПАНИКУЙ" << endl;
		cout << "Может, стоит прочитать правила повнимательней?" << endl;
		cout << "Надеюсь, в следующий раз все получится" << endl;
	}
	if (k == 20)
	{
		cout << "Меня терзают смутные сомнения." << endl;
		cout << "Правила выводятся каждый раз, неужели так сложно ввести правильно?" << endl;
	}
	if (k == 30)
	{
		cout << "А вы, часом, не тупенький?" << endl;
		cout << "Ну, что вы, это не оскорбление, а констатация факта" << endl;
		cout << "Разработчики почти приносят извинения за дерзость компьютера" << endl;
	}
	if (k == 40)
	{
		cout << "Кто-нибудь, остановите его!" << endl;
		cout << "Введи хотя бы х!" << endl;
		cout << "Без восклицательного знака. Это так, предосторожность" << endl;
	}
	if (k == 41)
	{
		cout << "Господи, я же дал подсказку, что можно ввести!" << endl;
		cout << "Неужели можно быть таким ..." << endl;
		cout << "Пожалуйста, кто-нибудь, введите правильно уже!" << endl;
	}
	if (k == 42)
	{
		cout << "Так и быть, дам ответ на главный вопрос жизни, вселенной и всего такого..." << endl;
		cout << "____" << endl;
		cout << "|42|" << endl;
		cout << "|__|" << endl;
	}
	if (k == 50)
	{
		cout << "Это уже 50 попытка ... " << endl;
	}
	if (k > 50)
	{
		cout << "ПОМОГИТЕ!!!" << endl;
	}
	
}

void Interface::exceptionHandling(int code)
{
	switch (code)
	{
	case 1: cout << "В таблице пусто" << endl; break;
	case 2: cout << "Нет такого ключа" << endl; break;
	case 3: cout << "Уже есть объект с таким ключом" << endl; break;
	case 4: cout << "Неверный ключ" << endl; break;
	case 5: cout << "Нет места" << endl; break;
	case 6: cout << "Неверная степень" << endl; break;
	case 7: cout << "Несовпадение степеней мономов" << endl; break;
	case 8: cout << "Полином введен некорректно" << endl; break;
	case 9: cout << "Имя должно быть одним словом" << endl; break;
	case 10: cout << "Имя только из латинских строчных букв" << endl; break;
	}
}

string Interface::controlKey(const string& key)
{
	string res;
	int count = 0;
	int length = key.length();
	for (int k = 0; k < length; k++)
	{
		if (key[k] != ' ')
		{
			if (key[k + 1] == ' ')
				count++;
			res += key[k];
			if ((key[k] < 'a') || (key[k] > 'z'))
				throw 10;
		}
	}
	if (count != 1)
		throw 9;
	return res;
	//здесь что-то будет
}

string Interface::controlPolynom(const string& str)
{
	string res;
	int length = str.length();
	for (int i = 0; i < length; i++)
	{
		if (str[i] != ' ')
			res += str[i];
	}
	if (!isCorrect(res))
		throw 8;
	return res;
}

bool Interface::isCorrect(string str)
{
	int length = str.length();
	if (length == 0)
		return false;
	int k[3] = { 0,0,0 };
	int flag = 0;
	int point = 0;
	int simbol = 0;
	str = str + "+";
	string acceptable = "xyz-+0123456789.,^";
	if ((str[0] == '.') || (str[0] == ','))
		return false;
	for (int i = 0; i < length; i++)
	{
		if (acceptable.find(str[i]) == string::npos)
			return false;
		for (int j = 0; j < 3; j++)
		{
			if ((str[i] == acceptable[j]) && (flag == 0))
			{
				if (k[j] == 1)
					return false;
				k[j]++;
				string temp = "xyz+-";
				if (temp.find(str[i + 1]) != string::npos)
					flag = 0;
				else
					flag = 1;
				point = 0;
				simbol = 0;
				break;
			}
			if (flag == 1)
			{
				if (str[i] == '^')
				{
					flag = 2;
					break;
				}
				else
				{
					return false;
				}
			}
			if (flag == 2)
			{
				if ((str[i] < '0') || (str[i] > '9'))
					return false;
				else
				{
					string temp = "xyz+-";
					if (temp.find(str[i + 1]) != string::npos)
						flag = 0;
					else
						return false;
				}
			}
		}
		if ((str[i] == '-') || (str[i] == '+'))
		{
			if (simbol > 0)
				return false;
			else
			{
				k[0] = k[1] = k[2] = 0;
				simbol++;
			}
		}
		if ((str[i] >= '0') && (str[i] <= '9'))
			simbol = 0;
		if ((str[i] == '.') || (str[i] == ','))
		{
			if (point > 0)
				return false;
			else
			{
				if ((str[i - 1] < '0') || (str[i - 1] > '9'))
					return false;
				else
					point++;
			}
		}
	}
	if ((str[length - 1] == '-') || (str[length - 1] == '+'))
		return false;
	//str.erase(length);
	return true;
}

int Interface::inputControl(string left_board, string right_board, void (*print)(const string&), const string& str)
{
	string number;
	bool flag;
	do
	{
		flag = false;
		print(str);
		//cin >> number;
		getline(cin, number);
		system("cls");
		if ((number > right_board) || (number < left_board) || (number.length() != 1))
		{
			cout << "ОШИБКА ВВОДА! ВВЕДИТЕ ЕЩЕ РАЗ!" << endl;
			flag = true;
		}
	} while (flag);
	return stoi(number);
}

void Interface::tableSelection()
{
	int code = inputControl("1", "6", printTableList, " ");
	switch (code)
	{
	case 1: Base = new LineTable; break;
	case 2: Base = new LinTabList; break;
	case 3: Base = new ordered_line_table; break;
	case 4: Base = new TableTree; break;
	case 5: Base = new hash_table_on_lists; break;
	case 6: Base = new HashTabLin; break;
	}
}

void Interface::Menu()
{
	cout << "Выберите таблицу, которой хотите пользоваться" << endl;
	tableSelection();
	int code;
	do
	{
		//cout << "----------------------Меню----------------------" << endl;
		//cout << "  Для выбора, введите соответствующую клавишу." << endl;
		code = inputControl("1", "6", printMenuList, "---------------------------Меню---------------------------\n  Для выбора введите соответствующую клавишу.\n");
		switch (code)
		{
		case 1: Add(); break;
		case 2: Search(); break;
		case 3: Calculate(); break;
		case 4: Print(); break;
		case 5: Delete(); break;
		}
	} while (code != 6);
}

void Interface::Add()
{
	cout << "-----------------------1.Добавление-----------------------" << endl;
	Data d;
	cout << "Правила ввода! Просьба их соблюдать! НАДЕЮСЬ, Я ПОНЯТНО ОБЪЯСНЯЮ" << endl;
	cout << "Великий свод правил:"<< endl;
	//cout << " 1. Вводить имя(ключ) можно только используя маленькие буквы" << endl;
	//cout << " 2. Без использования цифр и всяких непристойных знаков (например, _*/!\.,)" << endl;
	//cout << " 3. Без цифр" << endl;
	keyRules();
	//cout << " 4. Правила по вводу полиномов я не помню, так что на свой страх и риск вводите" << endl;
	polynomRules();
	cout << "Если что-то введено неправильно, будет выдана ошибка (я не позволю испортить труд 3 человек)" << endl;
	cout << "Удачи :) " << endl;
	try
	{
		//string temp;
		cout << "Введите имя полинома: ";
		//cin >> d.key;
		getline(cin, d.key);
		//cout << d.key << "!" << endl;
		d.key = controlKey(d.key + " ");
		cout << "Введите сам полином: ";
		//cin >> d.PolyString;
		getline(cin, d.PolyString);
		d.PolyString = controlPolynom(d.PolyString);
		//cout << d.PolyString << "!" << endl;
		Polynom p(d.PolyString);
		//d.Poly.CreatePolynom(d.PolyString);
		d.Poly = p;
		Base->Insert(d);
	}
	catch (int code)
	{
		exceptionHandling(code);
	}
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls");
}

void Interface::Print()
{
	cout << "-------------------------4.Вывод--------------------------" << endl;
	Base->Print();
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls");
}

void Interface::changePolynom(Data* d)
{
	bool flag = false;
	int count = 0;
	string poly;
	do
	{
		cout << "Свод правил:" << endl;
		polynomRules();
		flag = false;
		panika(count);
		try 
		{
			cout << "Введите новый полином: ";
			getline(cin, poly);
			poly = controlPolynom(poly);
		}
		catch (int code)
		{
			exceptionHandling(code);
			flag = true;
			cout << "\nОШИБКА!!!!!!!! Попробуйте ввести заново" << endl;
		}
		count++;
	} 
	while (flag);
	d->PolyString = poly;
	Polynom temp(poly);
	d->Poly = temp;
	cout << "Изменения прошли успешно" << endl;
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls");
}

void Interface::countPolynom(Data* d)
{
	cout << "Имя полинома: " << d->key << endl;
	cout << "Полином: " << d->PolyString << endl;
	cout << "Просьба вводить цифры. Если что-то сломается, значит таков путь. " << endl;
	double x, y, z;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	cout << "z: ";
	cin >> z;
	double res = d->Poly.ValuePoint(x, y, z);
	cout << "Результат вычислений: " << res << endl;
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls");
}

void Interface::Integral(Data* d, int code)
{
	Polynom temp = d->Poly;
	Polynom temp2;
	string varity;
	switch (code)
	{
	case 1: temp2 = d->Poly.IntegrateDX(); d->Poly = temp; temp = temp2; break; //temp = d->Poly.IntegrateDX(); varity = "x"; break;
	case 2: temp2 = d->Poly.IntegrateDY(); d->Poly = temp; temp = temp2; break; //temp = d->Poly.IntegrateDY(); varity = "y"; break;
	case 3: temp2 = d->Poly.IntegrateDZ(); d->Poly = temp; temp = temp2; break; //temp = d->Poly.IntegrateDZ(); varity = "z"; break;
	}
	string str;
	str = "Исходный полином: " + d->PolyString;
	str = str + "\nИнтеграл от этого полинома по переменной " + varity + ": " + temp.CreateString();
	varity = str + "\n";
	str = str + "\nЖелаете сохранить этот полином в таблице?\n";
	//cout << "Исходный полином: " << d->Poly << endl;
	//cout << "Интеграл от этого полинома по переменной" << varity << ": " << temp << endl;
	//cout << "Желаете сохранить этот полином в таблице? " << endl << endl;
	int k = inputControl("0", "1", printExit, str);
	if (k == 1)
	{
		cout << varity;
		bool flag = false;
		Data element;
		do
		{
			flag = false;
			try 
			{
				keyRules();
				cout << "Введите имя полинома: ";
				getline(cin, element.key);
				element.key = controlKey(element.key + " ");
			}
			catch (int i)
			{
				exceptionHandling(i);
				cout << "ОШИБКА!!!!!!!! Попробуйте ввести заново!";
				flag = true;
			}
			if (Base->Find(element.key) != nullptr)
				flag = true;
		} 
		while (flag);
		element.Poly = temp;
		element.PolyString = element.Poly.CreateString();
		Base->Insert(element);
		cout << "Для выхода нажмите любую клавишу" << endl;
		_getch();
	}
	system("cls");
}

void Interface::Search()
{
	string key;
	string head = "--------------------2.Поиск и операции--------------------";
	Data* d;
	while (1 > 0) 
	{
		cout << head << endl;
		cout << "Введите имя: ";
		getline(cin, key);
		d = Base->Find(key);
		system("cls");
		if (d == nullptr)
		{
			cout << head << endl;
			cout << "Такого полинома нет" << endl;
		}
		else
		{
			int cod;
			do
			{
				string temp = head;
				temp += "\nИмя полинома: " + d->key + "\nНайденный полином: " + d->PolyString;
				cod = inputControl("0", "6", printPolynomOperation, temp);
				switch (cod)
				{
				case 1: changePolynom(d); break;
				case 2: countPolynom(d); break;
				case 3: Integral(d, 1); break;
				case 4: Integral(d, 2); break;
				case 5: Integral(d, 3); break;
				}
			} 
			while (cod != 6);
		}
		//cout << "Раздел - Найти полином" << endl;
		cout << "Попробовать еще?" << endl;
		int code = inputControl("0", "1", printExit, "");
		if (code == 0)
			break;
		system("cls");
	}
}

void Interface::calPol()
{
	bool flag = true;
	string str;
	string key;
	string infix;
	TPostfix post;
	while (flag)
	{
		flag = false;
		cout << "Арифметическое выражение вводить в следующем формате: " << endl;
		cout << " <имя_полинома> = <арифметическое выражение>" << endl;
		cout << "Арифметическое выражение должно содержать только следующие операции: +,-,*" << endl;
		cout << "Также допускаются скобки" << endl;
		cout << "Пример: a+b*(c+d)" << endl;
		cout << "a,b,c,d - имена полиномов, имеющихся в таблице" << endl;
		cout << "Если ты здесь по ошибке введи !" << endl;
		cout << "Введите арифметическое выражение:" << endl;
		try 
		{
			getline(cin, str);
			if (str == "!")
			{
				system("cls");
				return;
			}
			if (str.find('=') == string::npos)
				throw "Некорректный формат";
			int k;
			for (k = 0; str[k] != '='; k++)
			{
				key += str[k];
			}
			key = controlKey(key + " ");
			int length = str.length();
			k++;
			for (; k < length; k++)
				infix += str[k];
			if (infix.find('/') != string::npos)
				throw "Error";
			TPostfix p(infix);
			post = p;
			//post = TPostfix(infix);
		}
		catch (int i)
		{
			exceptionHandling(i);
			cout << "Попробуйте ввести еще раз" << endl;
			flag = true;
		}
		catch (const char* s)
		{
			cout << s << endl;
			cout << "Попробуйте ввести еще раз" << endl;
			flag = true;
		}
	}
	post.ToPostfix();
	try 
	{
		Data res;
		res.Poly = post.NewPoly(*Base);
		res.key = key;
		res.PolyString = res.Poly.CreateString();
		Base->Insert(res);
	}
	catch (int i)
	{
		exceptionHandling(i);
	}
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls");
} 

void Interface::calPolPoint()
{
	bool flag = true;
	string infix;
	TPostfix post;
	while (flag)
	{
		flag = false;
		cout << "Арифметическое выражение должно содержать только следующие операции: +,-,*" << endl;
		cout << "Также допускаются скобки" << endl;
		cout << "Пример: a+b*(c+d)" << endl;
		cout << "a,b,c,d - имена полиномов, имеющихся в таблице" << endl;
		cout << "Введите арифметическое выражение:" << endl;
		cout << "Если ты здесь по ошибке, введи !" << endl;
		try 
		{
			getline(cin, infix);
			if (infix == "!")
			{
				system("cls");
				return;
			}
			TPostfix p(infix);
			post = p;
		}
		catch (int i)
		{
			exceptionHandling(i);
			cout << "Попробуйте ввести еще раз" << endl;
			flag = true;
		}
		catch (const char* s)
		{
			cout << s << endl;
			cout << "Попробуйте ввести еще раз" << endl;
			flag = true;
		}
	}
	post.ToPostfix();
	try
	{
		cout << "Результат: " << post.Calculate(*Base) << endl;
	}
	catch (int i)
	{
		exceptionHandling(i);
	}
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls");
}

void Interface::Calculate()
{
	string str = "-----------------------3.Вычисление-----------------------\nВыберите режим\n";
	int code = 0;
	while(code != 3)
	{
		code = inputControl("1", "3", printCalculate, str);
		switch (code)
		{
		case 1: calPol(); break;
		case 2: calPolPoint(); break;
		}
	}
	system("cls");
}

void Interface::Delete()
{
	string key;
	cout << "------------------------5.Удаление------------------------" << endl;
	keyRules();
	try
	{
		cout << "Введите имя полинома: ";
		getline(cin, key);
		key = controlKey(key + " ");
		Base->Delete(key);
		cout << "Удаление прошло успешно" << endl;
	}
	catch (int code)
	{
		exceptionHandling(code);
	}
	cout << "Для выхода нажмите любую клавишу" << endl;
	_getch();
	system("cls");
}