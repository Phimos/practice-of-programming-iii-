#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	map<int, int> namelist;
	namelist[1000000000] = 1;
	cin >> n;
	while (n--)
	{
		int id, power, fighter;
		cin >> id >> power;
		map<int, int>::iterator i = namelist.upper_bound(power);
		if (i == namelist.begin())
			fighter= i->second;
		else
		{
			map<int, int>::iterator j = i;
			--j;
			if (abs(j->first - power) <= abs(i->first - power))
				fighter = j->second;
			else
				fighter = i->second;
		}
		namelist[power] = id;
		cout << id << ' ' << fighter << endl;
	}
}