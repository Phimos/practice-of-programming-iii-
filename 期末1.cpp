#include <iostream>
#include <string>
using namespace std;
string dec2bin(int x) {
	// 在此处补充你的代码
	string b;
	for (int i = 0; i < 31; i++)
		if (x&(1 << i))
			b.insert(b.begin(), '1');
		else
			b.insert(b.begin(), '0');
	return b;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		cout << dec2bin(x) << endl;
	}
	return 0;
}