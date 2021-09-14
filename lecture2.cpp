//  Написать класс для работы со строками
// Вариант 3  - true – если строки равны    bool compare(char* str)

#include <iostream>
#include <cstring>
using namespace std;

class FooString 
{
	int size;
	char* buf;
public:
	FooString(char* tbuf)
	{
		size = strlen(tbuf) + 1;
		buf = new char[size];
		for (size_t i = 0; i < size; i++)
		{
			buf[i] = tbuf[i];
		}
	}

	FooString::~FooString()
	{
		delete[] buf;
	}

	void FooString::show()
	{
		cout << buf;
	}


	bool FooString::compare(char* str)
	{
		int i = 0;
		while (str[i] != '\0' || buf[i] != '\0') 
		{
			if (str[i] != buf[i])
				return false;
			i++;
		}
		return true;
	}
}

int main()
{
	char fst[] = "TestString";
	char scnd[] = "TestString";
	FooString fstOb(fst);
	FooString scndOb(scnd);
	if (fstOb.compare(scndOb) == true)
	{
		cout << "test is done";
	}
	else
	{
		cout << "test failed";
	}
	return 0;
}
