#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	map<int, int> namelist;
	namelist.insert(pair<int, int>(1000000000, 1));
	cin >> n;
	while (n--)
	{
		int id, power, fighter;
		cin >> id >> power;
		if (namelist.count(power))
		{
			fighter = namelist[power];
			if (namelist[power] > id)
				namelist[power] = id;
		}
		else
		{
			map<int, int>::iterator j = namelist.upper_bound(power);
			if (j == namelist.begin())
				fighter = j->second;
			else
			{	
				map<int, int>::iterator i =j;
				--j;
				if (abs(j->first - power) < abs(i->first - power))
					fighter = j->second;
				else if (abs(j->first - power) > abs(i->first - power))
					fighter = i->second;
				else
					fighter = min(j->second, i->second);
			}
			namelist.insert(pair<int, int>(power, id));
		}
		cout << id << ' ' << fighter << endl;
	}
}