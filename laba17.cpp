// laba17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <io.h>
using namespace System;
using namespace System::IO;
using namespace std;
namespace ConsoleApplication2
{
	public ref class Program
	{
	public:
		static void Main()
		{
			for each (String ^ entry in Directory::GetDirectories("C:\\"))
			{
				DisplayFileSystemInfoAttributes(gcnew DirectoryInfo(entry));
			}
			for each (String ^ entry in Directory::GetFiles("C:\\"))
			{
				DisplayFileSystemInfoAttributes(gcnew FileInfo(entry));
			}
		}
		static void DisplayFileSystemInfoAttributes(FileSystemInfo^ fsi)
		{
			String^ entryType = "File";
			if ((fsi->Attributes & FileAttributes::Directory) == FileAttributes::Directory)
			{
				entryType = "Directory";
			}
			Console::WriteLine("{0} entry {1} was created on {2:D}", entryType, fsi->FullName, fsi -> CreationTime);
		}
		property FileAttributes Attributes 
		{
			FileAttributes get();
			void set(FileAttributes value);
		}
	};
};
int main()
{
	ConsoleApplication2::Program::Main();
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
