
#include "stdafx.h"
#include <map> //ассоциативный массив (является отсортированным по ключу)
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <windows.h>
#include <stdio.h>



using namespace std;
//содержит связку символ/значение Морзе //Morse.insert(pair<char, string>('a',".-"));

//перевод строки на азбуку Морзе 
string ConverToMorse (string str) 
{
	map <char, string> Morse;
		 
	Morse['а'] = ".-";	    Morse['a'] = ".-";
	Morse['б'] = "-...";	Morse['b'] = "-...";
    Morse['в'] = ".--";	    Morse['w'] = ".--";
    Morse['г'] = "--.";	    Morse['g'] = "--.";
    Morse['д'] = "-..";	    Morse['d'] = "-..";
    Morse['е'] = ".";		Morse['e'] = ".";
    Morse['ж'] = "...-";	Morse['v'] = "...-";
    Morse['з'] = "--..";	Morse['z'] = "--..";
    Morse['и'] = "..";		Morse['i'] = "..";
    Morse['й'] = ".---";	Morse['j'] = ".---";
    Morse['к'] = "-.-";		Morse['k'] = "-.-";
    Morse['л'] = ".-..";	Morse['l'] = ".-..";
    Morse['м'] = "--";		Morse['m'] = "--";
    Morse['н'] = "-.";		Morse['n'] = "-.";
    Morse['о'] = "---";		Morse['o'] = "---";
    Morse['п'] = ".--.";	Morse['p'] = ".--.";
	Morse['р'] = ".-.";		Morse['r'] = ".-.";
    Morse['с'] = "...";		Morse['s'] = "...";
    Morse['т'] = "-";		Morse['t'] = "-";
    Morse['у'] =  "..-";	Morse['u'] = "..-";
    Morse['ф'] = "..-.";	Morse['f'] = "..-.";
    Morse['х'] = "....";	Morse['h'] = "....";
    Morse['ц'] = "-.-.";	Morse['c'] = "-.-.";
    Morse['ч'] = "--.-";	
    Morse['ш'] = "-.--";	
    Morse['щ'] = "-..-";	Morse['q'] = "--.-";
	Morse['ъ'] = "--.--";
	Morse['ы'] = "-.--";	Morse['y'] = "-.--";
	Morse['ь'] = "-..-";	Morse['x'] = "-..-";
	Morse['э'] = "..-..";
	Morse['ю'] = "..--";
	Morse['я'] = ".-.-";

    	Morse['1'] = ".----";
    	Morse['2'] = "..---";
		Morse['3'] = "...--";
    	Morse['4'] = "....-";
    	Morse['5'] = ".....";
    	Morse['6'] = "-....";
    	Morse['7'] = "--...";
    	Morse['8'] = "---..";
    	Morse['9'] = "----.";
    	Morse['0'] = "-----";

   	Morse['.'] = "......"; 
   	Morse[','] = ".-.-.-";   Morse['.'] = ".-.-.-";
	Morse['!'] = "--..--";   Morse[','] = "--..--";
				             Morse['!'] = "-.-.--";
    	Morse[':'] = "---...";
    	Morse[';'] = "-.-.-.";
		Morse['?'] = "..--..";
		Morse['"'] = ".-..-.";
		Morse['-'] = "-....-";
		Morse['/'] = "-..-.";
        Morse['='] = "-...-";
	    Morse['_'] = "..--.-";
		Morse[' '] = "-...-";
    	Morse['@'] = ".--.-.";

    	Morse['('] = "-.--.-";   Morse['('] = "-.--.";
    	Morse[')'] = "-.--.-";   Morse[')'] = "-.--.-";
	
		string  MorStr = "";
		int len = str.length();
	    for (int i = 0; i < len; i++) 
		{
	    	str[i] = tolower(str[i]); //перевод заглавных букв в строчные
	        MorStr += Morse.find(str[i]) -> second + "  ";
		}

		return MorStr;
	}


bool Answer(string txt)
{
	char ans; //переменная, содержащая ответ на вопрос
	cout << txt << endl;
	do {
		cin >> ans;
		if ((ans != 'N') && (ans != 'n') && (ans != 'Y') && (ans != 'y')  && (ans != 'Д') && (ans != 'д')  && (ans != 'н') && (ans != 'Н'))
			cout << "Введеное некорректное значение. Повторите ввод.\n";
	} while ((ans != 'N') && (ans != 'n') && (ans != 'Y') && (ans != 'y')  && (ans != 'Д') && (ans != 'д')  && (ans != 'н') && (ans != 'Н'));
	getchar();
	if ((ans == 'Y') || (ans == 'y') || (ans == 'д') || (ans == 'Д'))
		return true; //если ответ положительный, то вернуть функции true
	else
		return false;
}
/*========================================================================считывание текста из консоли============================================================================*/

//сохраняем только введенный текст в файл newf (потом можно открыть его при вводе текста из файла)
void SaveOnlyText ()
{
	string str, s;
	string out_fname;
	cout << "Введите имя нового файла:" << endl;
	cin >> out_fname;
	out_fname = out_fname + ".txt";
	ofstream newf;
	newf.open(out_fname);		
	if (!newf.is_open())
		cout << "Неудалось создать файл" << endl;
	else 
		{ 
	cout << "Файл создан и открыт для записи\n" << endl;
	cout << "Введите текст:" << endl;
	(getline(cin, str, '.'));
	cout << "Результат перевода:\n";
	cout << "Буквы отделяются одним пробелом, слова - тремя." << endl;
	int len = str.length();
	newf << str;
	newf.close();
	cout << "Текст сохранен в файл " <<  out_fname;
	for (int i = 0; i < len; i++)
	{
		while ((i < len) && (str[i] != '\n'))
		{
			s += str[i];
			i++;
		}
		cout << ConverToMorse(s) << endl;
		s = "";
	}
	getchar();
		}
}

//сохраняем введенный текст и результат в новый файл newf-------------------------------------------------------
void SaveResult ()
{
	string str, s, res;
	string out_fname;
	cout << "Введите имя нового файла:" << endl;
	cin >> out_fname;
	out_fname = out_fname + ".txt";
	ofstream newf;
	newf.open(out_fname);
				
	if (!newf.is_open())
		cout << "Неудалось создать файл" << endl;
	else 
		{ 
			cout << "Файл создан и открыт для записи\n" << endl;
			cout << "Введите текст:" << endl;
			newf << "Результат перевода:\n"; //запись строки в файл
			newf << "Буквы отделяются одним пробелом, слова - тремя." << endl;
			(getline(cin, str, '.'));
			newf << str << endl;
			cout << "Результат перевода:\n";
			cout << "Буквы отделяются одним пробелом, слова - тремя." << endl;
			int len = str.length();
			for (int i = 0; i < len; i++)
			{
				while ((i < len) && (str[i] != '\n'))
				{
					s += str[i];
					i++;
				}
				res = ConverToMorse(s);
				cout << res << endl;
				newf << res << endl;
				s = "";
			}
			newf.close();
			cout << "Результат сохранен в файл " <<  out_fname;
			getchar();
		}
}
//печать результата в консоли------------------------------------------------------------------------------------------
void PrintConsol ()
{
	string str, s;
	cout << "Введите текст:" << endl;
	(getline(cin, str, '.'));
	cout << "Результат перевода:\n";
	cout << "Буквы отделяются одним пробелом, слова - тремя.\n" << endl;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		while ((i < len) && (str[i] != '\n'))
		{
			s += str[i];
			i++;
		}
		cout << ConverToMorse(s) << endl;
		s = "";
	}
	getchar();
}

//меню при выборе " 1 - Ввести текст в консоли"-----------------------------------------------------------------------------------------------------
void ReadConsole() 
{
	cout << "  Выберите следующее действие: " << endl;
	cout << "  1 - Сохранить в файл только введенный текст " << endl;
	cout << "  2 - Сохранить в файл текст и результат перевода " << endl;
	cout << "  3 - Показать результат в консоли " << endl;
	int num;
	do {
		cin >> num;
		if ((num != 1) && (num != 2) && (num != 3))
			cout << "Ведено некорректное значение. Повторите ввод.\n";
	   } while ((num != 1) && (num != 2) && (num != 3));

	switch (num) 
	{
		case 1: SaveOnlyText ();
			break;
		case 2: SaveResult ();
			break;
		case 3: PrintConsol ();
			break;
	}
}
	


/*========================================================================считывание текста из файла============================================================================*/

//сохраняем результат в исходный файл file 
void SaveResultThisFile (string in_fname)
{
	string str,  res;
	int cnt = 0;
	fstream file(in_fname, ios_base::app |  ios_base::in |  ios_base::out);

	//проходим по файлу и получаем количество строк cnt
	while (getline(file, str))
		cnt++;
	//создаем массив строк и инициализируем пустыми строками 
	string* strbuff = new string[cnt];
	for (int i = 0; i < cnt; i++)
		strbuff[i] = "";

	file.clear();//ощчищаем поток 
	file.seekg(0, ios_base::beg);//ставим указатель потока считывания на начало файла

	//заполняем массив строками из файла
	for (int i = 0; i < cnt; i++)
		getline(file, strbuff[i]);

	if ((Answer("Показать содержимое файла?")))
	{
		//печать массива
		for (int i = 0; i < cnt; i++)
		cout << strbuff[i] << endl;

		cout << "Результат перевода:\n";
		cout << "Буквы отделяются одним пробелом, слова - тремя.\n" << endl;
		
		//переводим строки массива в азбуку Морзе и печатаем их
		for (int i = 0; i < cnt; i++)
		{
			strbuff[i] = ConverToMorse(strbuff[i]);
			cout << strbuff[i] << endl;
		}
	}
		
	else 
	{
		cout << "Результат перевода:\n";
		cout << "Буквы отделяются одним пробелом, слова - тремя.\n" << endl;
		for (int i = 0; i < cnt; i++)
		{
			strbuff[i] = ConverToMorse(strbuff[i]);
			cout << strbuff[i] << endl;
		}
	}

	file.clear();
	file << "\nРезультат перевода:" << endl;
	file << "Буквы отделяются одним пробелом, слова - тремя." << endl;
	//записыванм в файл полученный массив
	for (int i = 0; i < cnt; i++)
	file << strbuff[i] << endl;

	//удаляем массив
	delete [] strbuff;
		
	file.close();
}


//сохраняем текст и результат в новый файл newf-------------------------------------------------------------------------------- 
void SaveResultNewFile(string in_fname) 
{
	string str, s, res;
	string out_fname;
	//создание и открытие нового файла
	cout << "Введите имя нового файла:" << endl;
	cin >> out_fname;
	out_fname = out_fname + ".txt";
	ofstream newf;
	newf.open(out_fname);
	//открытие исходного файла
	ifstream file;
	file.open(in_fname);
	newf << "Результат перевода:\n"; //запись строки в файл
	newf << "Буквы отделяются одним пробелом, слова - тремя." << endl;
	if (!(Answer("Показать содержимое файла?")))
	{
		while (getline(file, str))
			newf << str << endl;

		file.seekg(0);
		cout << "Результат перевода:\n";
		cout << "Буквы отделяются одним пробелом, слова - тремя.\n" << endl;
		while (getline(file, str))
		{
			res = ConverToMorse(str);
			newf << res << endl;
			cout << res << endl;
		}
	}
	else 
	{
		while (getline(file, str))
		{
			newf << str << endl;
			cout << str << endl;
		}
		file.clear();
		file.seekg(0, ios_base::beg);

		str = "";
		cout << "Результат перевода:\n";
		cout << "Буквы отделяются одним пробелом, слова - тремя.\n" << endl;
		
		while (getline(file, str))
		{
			res = ConverToMorse(str);
			newf << res << endl;
			cout << res << endl;
		}
	}
	newf.close();
	file.close();
	getchar();
}
//меня при выборе  "2 - Загрузить текст из файла"------------------------------------------------------------------------------ 
void Read_File ()
{
	string in_fname, res, str;
	cout << "Введите имя файла: " << endl;
	cin >> in_fname;
	in_fname = in_fname + ".txt";
	//открытие введенного пользователем файла
	fstream file(in_fname);
	//проверяем, можно ли открыть файл
	if (!file.is_open())
		 cout << "Неудалось открыть или найти файл" << endl;
	else 
	{  
		cout << "Файл  <" << in_fname << "> открыт" << endl;
		file.close();
		cout << "  Выберите следующее действие: " << endl;
		cout << "  1 - Сохранить результат перевода в этот же файл " << endl;
		cout << "  2 - Сохранить текст и результат перевода в новый файл" << endl;
		int num;
		do {
			cin >> num;
			if ((num != 1) && (num != 2))
				cout << "Ведено некорректное значение. Повторите ввод.\n";
		   } while ((num != 1) && (num != 2) );

		switch (num) 
		{
			case 1: SaveResultThisFile (in_fname);
				break;
			case 2: SaveResultNewFile (in_fname);
				break;
		}
	}
}

	





int Menu()
{
	cout << "****************************************************\n";
	cout << "*                      МЕНЮ						*\n";
	cout << "****************************************************\n";
	cout << "*  1 - Ввести текст в консоли                      *\n";
	cout << "*--------------------------------------------------*\n";
	cout << "*  2 - Загрузить текст из файла                    *\n";
	cout << "****************************************************\n";
	int num;
	do {
		cin >> num;
		if ((num != 1) && (num != 2))
			cout << "Ведено некорректное значение. Повторите ввод.\n";
	} while ((num != 1) && (num != 2));

	switch (num) 
	{
		case 1: ReadConsole();
			break;
		case 2: Read_File();
			break;
	}

	getchar();
	cout << "\n";
	return 0;
}


int main()
{
	string stroka; 

	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu();
	
	return 0;
}

