#include <iostream>
#include <cstring> 
#include <vector>
#include <cstdio> 
using namespace std;

// 在此处补充你的代码
template<class T>
class CMyClass
{
public:
	T a[100];
	CMyClass(T * _a, int k)
	{
		for (int i = 0; i < k; i++)
			a[i] = _a[i];
	}
	T operator[](int k)
	{
		return a[k];
	}
};

int  a[40];
int main(int argc, char** argv) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; ++i)
			scanf("%d", a + i);
		char s[100];
		scanf("%s", s);
		CMyClass<int> b(a, m);
		CMyClass<char> c(s, strlen(s));
		printf("%d %c\n", b[5], c[7]);
	}
	return 0;
}