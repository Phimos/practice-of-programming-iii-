#include<iostream>
#include<set>
#include<string>
using namespace std;


int main()
{
	int n;
	cin >> n;
	multiset<int> s;
	set<int> s0;

	while (n--)
	{
		string order;
		int k;
		cin >> order;
		cin >> k;

		if (order == "add")
		{
			s.insert(k);
			s0.insert(k);
			cout << s.count(k) << endl;
		}
		else if (order == "ask")
		{
			if (s0.count(k))
				cout << 1;
			else
				cout << 0;
			cout << ' ' << s.count(k) << endl;
		}
		else if (order == "del")
		{
			cout << s.count(k) << endl;
			s.erase(k);
		}
	}
}