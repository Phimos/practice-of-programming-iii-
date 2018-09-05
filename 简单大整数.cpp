#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110;
class CHugeInt {
	// 在此处补充你的代码
	char num[210];
	int len;
public:
	CHugeInt(char *s)
	{
		int l = strlen(s);
		for (int i = 0; i < l; i++)
			num[i] = s[l - i - 1];
		num[l] = 0;
		len = l;
	}
	CHugeInt()
	{
		memset(num, 0, sizeof(num));
		len = 0;
	}
	CHugeInt(int n)
	{
		int i;
		for (i = 0; n != 0; i++, n /= 10)
		{
			num[i] = n % 10 + '0';
		}
		num[i] = 0;
		len = i;
	}
	CHugeInt  operator+(const CHugeInt & b)
	{
		CHugeInt tmp;
		int i, k, an, bn;
		for (i = 0, k = 0; i<len || i<b.len || k; i++)
		{
			an = i<len ? num[i] - '0' : 0;
			bn = i<b.len ? b.num[i] - '0' : 0;
			tmp.num[i] = (k + an + bn) % 10 + '0';
			k = (k + an + bn) / 10;
		}
		tmp.len = i;
		return tmp;
	}
	CHugeInt operator+=(int n)
	{
		*this = *this + CHugeInt(n);
		return *this;
	}
	CHugeInt & operator++()
	{
		*this += 1;
		return *this;
	}
	CHugeInt operator++(int)
	{
		CHugeInt tmp;
		tmp = *this;
		*this += 1;
		return tmp;
	}
	friend ostream & operator<<(ostream & os,const CHugeInt & a)
	{
		for (int i = a.len - 1; i >= 0; --i)
		{
			os << a.num[i];
		}
		return os;
	}
	friend CHugeInt  operator+(int n, const CHugeInt & b)
	{
		return CHugeInt(n)+b;
	}
};
int  main()
{
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);
		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout << ++b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}