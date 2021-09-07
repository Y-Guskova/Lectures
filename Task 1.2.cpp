#include <iostream> 
#include <string>
using namespace std;

int main()
{
	char c;
	int a, b;
	cout << "Enter first letter of your name: ";
	cin >> c;
	a = c - '0';
	b = a % 2 + 1;
	cout << "Your option is: " << b;
	return 0;
}
