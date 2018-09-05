#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<cstdio>
using namespace std;

vector<string> red_order = { "iceman","lion","wolf","ninja","dragon" };
vector<string> blue_order = { "lion","dragon","ninja","iceman","wolf" };
map<string, int> waste, nums, nums_red, nums_blue;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Case:" << i + 1 << endl;
		int m, a, b, c, d, e;
		cin >> m >> a >> b >> c >> d >> e;
		int red ,blue ;
		red = blue = m;
		waste["dragon"] = a;
		waste["ninja"] = b;	
		waste["iceman"] = c;
		waste["lion"] = d;
		waste["wolf"] = e;
		nums["dragon"] = 0;
		nums["ninja"] = 0;
		nums["iceman"] = 0;
		nums["lion"] = 0;
		nums["wolf"] = 0;
		nums_red["dragon"] = 0;
		nums_red["ninja"] = 0;
		nums_red["iceman"] = 0;
		nums_red["lion"] = 0;
		nums_red["wolf"] = 0;
		nums_blue["dragon"] = 0;
		nums_blue["ninja"] = 0;
		nums_blue["iceman"] = 0;
		nums_blue["lion"] = 0;
		nums_blue["wolf"] = 0;

		int j_r = 0, j_b = 0, mark_r = 0, mark_b = 0;

		for (int time = 0;mark_r==0||mark_b==0 ; time++)
		{
			for (int j=0;j<5&&mark_r==0;j++,j_r=(j_r+1)%5 )
			{
				if (waste[red_order[j_r]] <= red)
				{
					red -= waste[red_order[j_r]];
					printf("%03d ", time);
					cout << "red " << red_order[j_r] << " " << time+1 << " born with strength " << waste[red_order[j_r]] << "," << ++nums_red[red_order[j_r]] << " " << red_order[j_r] << " in red headquarter" << endl;
					j_r = (j_r + 1 )% 5;
					break;
				}
				if (j == 4)
				{
					mark_r = 1;
					printf("%03d ", time);
					cout << "red headquarter stops making warriors" << endl;
				}
			}
			for (int j = 0; j<5 && mark_b== 0; j++, j_b = (j_b + 1) % 5)
			{
				if (waste[blue_order[j_b]] <= blue)
				{
					blue -= waste[blue_order[j_b]];
					printf("%03d ", time);
					cout << "blue " << blue_order[j_b] << " " << time+1 << " born with strength " << waste[blue_order[j_b]] << "," << ++nums_blue[blue_order[j_b]] << " " << blue_order[j_b] << " in blue headquarter" << endl;
					j_b = (j_b + 1) % 5;
					break;
				}
				if (j == 4)
				{
					mark_b = 1;
					printf("%03d ", time);
					cout << "blue headquarter stops making warriors" << endl;
				}
			}
		}
	}
}