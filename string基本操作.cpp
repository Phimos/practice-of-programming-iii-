#include<iostream>
#include<string>
using namespace std;
int main()
{
	string http = "www.runoob.com";
	cout << http.length() << endl;
	http.append("/C++");
	cout << http << endl;
	int pos = http.find("/C++");
	cout << pos << endl;
	http.replace(pos, 4, "");//pos开始4个字符替换为空
	cout << http << endl;
	int first = http.find_first_of(".");
	int last = http.find_last_of(".");
	cout << http.substr(first + 1, last - first - 1) << endl;
	return 0;
}