#include <iostream>

using namespace std;

template <typename T>
T minimum(const T& a, const T& b)
{
	return a < b ? a : b;
}

int main()
{
	cout << "template  demo." << endl;
	int a = 3;
	int b = 6;
	cout << "��С����Ϊ��" << minimum<int>(a, b) << endl;
	return 0;
}
