#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s)
{
	int i = 0;
	for (; s[i]; ++i);
	return i;
}
void strcpy(char * d, const char * s)
{
	int i = 0;
	for (i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
}
int strcmp(const char * s1, const char * s2)
{
	for (int i = 0; s1[i] && s2[i]; ++i) {
		if (s1[i] < s2[i])
			return -1;
		else if (s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d, const char * s)
{
	int len = strlen(d);
	strcpy(d + len, s);
}
class MyString
{
	// 在此处补充你的代码
	char *p;
public:
	MyString(void)
	{
		p =(char*) malloc(sizeof(char));
		p[0] = 0;
	}
	MyString(const char *s)
	{
		p = (char *)malloc((strlen(s) + 1) * sizeof(char));
		strcpy(p, s);
	}
	MyString operator()(int a, int b)
	{
		char *q = (char *)malloc(sizeof(char)*(b + 1));
		for (int i = 0; i < b; i++)
			q[i] = p[a + i];
		q[b] = 0;
		return MyString(q);
	}
	char & operator[](char a)
	{
		return p[a];
	}
	friend ostream& operator<<(ostream& os, MyString s)
	{
		os << s.p;
		return os;
	}
	bool operator<(MyString b)
	{
		if (strcmp(p, b.p) < 0)
			return true;
		else
			return false;
	}
	bool operator==(MyString b)
	{
		if (strcmp(p, b.p) == 0)
			return true;
		else
			return false;
	}
	bool operator>(MyString b)
	{
		if (strcmp(p, b.p) > 0)
			return true;
		else
			return false;
	}
	MyString operator+(MyString b)
	{
		char * k = (char *)malloc((strlen(p) + strlen(b.p) + 1) * sizeof(char));
		strcpy(k, p);
		strcat(k, b.p);
		return MyString(k);
	}
	MyString operator+=(MyString b)
	{
		*this = *this + b;
		return *this;
	}
	friend MyString operator+(const char * s, MyString a)
	{
		char * k = (char *)malloc((strlen(s) + strlen(a.p) + 1) * sizeof(char));
		strcpy(k, s);
		strcat(k, a.p);
		return MyString(k);
	}
};


int CompareString(const void * e1, const void * e2)
{
	MyString * s1 = (MyString *)e1;
	MyString * s2 = (MyString *)e2;
	if (*s1 < *s2)
		return -1;
	else if (*s1 == *s2)
		return 0;
	else if (*s1 > *s2)
		return 1;
}
int main()
{
	MyString s1("abcd-"), s2, s3("efgh-"), s4(s1);
	MyString SArray[4] = { "big","me","about","take" };
	cout << "1. " << s1 << s2 << s3 << s4 << endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A';
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray, 4, sizeof(MyString), CompareString);
	for (int i = 0; i < 4; i++)
		cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0, 4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5, 10) << endl;
	return 0;
}