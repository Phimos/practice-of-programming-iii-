#include <iostream>
using namespace std;
class MyCin
{

	// �ڴ˴�������Ĵ���
private:
	bool mark = true;
public:
	MyCin & operator>>(int & n)
	{
		cin >> n;
		if (n == -1)
			mark = false;
		return *this;
	}
	operator bool()
	{
		return mark;
	}
};
int main()
{
	MyCin m;
	int n1, n2;
	while (m >> n1 >> n2)
		cout << n1 << " " << n2 << endl;
	return 0;
}