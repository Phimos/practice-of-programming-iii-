#include <iostream>
using namespace std;
class CMyClassA {
	int val;
public:
	CMyClassA(int);
	void virtual print();
};
CMyClassA::CMyClassA(int arg) {
	val = arg;
	printf("A:%d\n", val);
}
void CMyClassA::print() {
	printf("%d\n", val);
	return;
}

// 在此处补充你的代码
class CMyClassB:public CMyClassA
{
public:
	int val_b;
	CMyClassB(int k) :CMyClassA(3 * k), val_b(k) 
	{
		printf("B:%d\n", val_b);
	};
	void print()
	{
		printf("%d\n", val_b);
	}
};

int main(int argc, char** argv) {
	CMyClassA a(3), *ptr;
	CMyClassB b(5);
	ptr = &a; ptr->print();
	a = b;
	a.print();
	ptr = &b; ptr->print();
	return 0;
}