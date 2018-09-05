#include<iostream>
#include<list>
#include<string>
using namespace std;

list<int> lst[10005];

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string order;
		cin >> order;
		if (order == "new")
		{
			int a;
			cin>>a;
		}
		else if (order == "add")
		{
			int id, num;
			cin >> id >> num;
			lst[id].push_back(num);
		}
		else if (order == "merge")
		{
			int a, b;
			cin >> a >> b;
			lst[a].merge(lst[b]);
		}
		else if (order == "unique")
		{
			int a;
			cin >> a;
			lst[a].sort();
			lst[a].unique();
		}
		else if (order == "out")
		{
			int a;
			cin >> a;
			lst[a].sort();
			for (list<int>::iterator i = lst[a].begin(); i != lst[a].end(); ++i)
				cout << *i << ' ';
			cout << endl;
		}
	}
}