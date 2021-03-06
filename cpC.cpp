// cpC.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <errno.h>
#include <clocale>
#include <locale.h>
#define BUF_SIZE 256
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, ".1251");
	FILE* in_file, * out_file; char rec
		[BUF_SIZE]; size_t bytes_in,
		bytes_out;
	if (argc != 3)
	{
		printf("Использование: Cрc file1 File2\n");
		return 1;
	}
	in_file = fopen(argv[1], "rb");
	if (in_file == NULL)
	{
		perror(argv[1]);
		return 2;
	}
	out_file = fopen(argv[2], "wb");
	if (out_file == NULL)
	{
		perror(argv[2]);
		return 3;
	}
	while ((bytes_in = fread(rec, 1, BUF_SIZE, in_file)) > 0)
	{
		bytes_out = fwrite(rec, 1, bytes_in, out_file);
		if (bytes_out != bytes_in)
		{
			perror("Неисправимая ошибка записи.");
			return 4;
		}
	}
	fclose(in_file);
	fclose(out_file);
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
