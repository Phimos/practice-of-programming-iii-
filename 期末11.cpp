#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>

using namespace std;
class MyQueue
{

	// 在此处补充你的代码
public:
	int k;
	MyQueue(int k):k(k) {};
	vector<int> s;
	friend istream& operator>>(istream& in, MyQueue &p)
	{
		int this_one;
		in >> this_one;
		if (this_one % 2 == 0)
		{
			p.s.push_back(this_one);
		}
		return in;
	}
	friend ostream& operator<<(ostream & out, MyQueue &p)
	{
		sort(p.s.begin(), p.s.end());
		for (int i = p.s.size() - 1; i >= p.s.size()-p.k; --i)
			out << p.s[i]<<' ';
		return out;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		MyQueue q(k);
		for (int i = 0; i < n; ++i)
			cin >> q;
		cout << q;
		cout << endl;
	}
	return 0;
}