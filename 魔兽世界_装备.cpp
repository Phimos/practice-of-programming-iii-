#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<iomanip>
using namespace std;

string warrior_weapon[3] = { "sword","bomb","arrow" };
string group[2] = {"red" ,"blue" };
map<string, int> init_strength;
int order[2][5] = {2,3,4,1,0,3,0,1,2,4};//0-red 1-blue
string warrior_name[5] = { "dragon" ,"ninja","iceman","lion","wolf" };
int num_of_group[2], num_warriors[2][5];

class warrior
{
public:
	int time, id, strength, life_element, type, is_blue;
	string name;
	warrior(int time_, int type_, int life_element_, int is_blue_)
	{
		time = time_;
		id = time_ + 1;
		type = type_;
		life_element = life_element_;
		is_blue = is_blue_;
		name = warrior_name[type];
		strength = init_strength[name];
		num_of_group[is_blue]++;
		num_warriors[is_blue][type]++;
		cout << setiosflags(ios::right) << setfill('0') << setw(3)<< time << " " << group[is_blue] << " " << name << " " << id << " born with strength " << init_strength[name] << "," << num_warriors[is_blue][type] << " "<< name<<" in " << group[is_blue] << " headquarter" << endl;
	}
};

class dragon :public warrior
{
	double morale;
	int weapon;
public:
	dragon(int time_, int type_, int life_element_, int is_blue_) :warrior(time_, type_, life_element_, is_blue_)
	{
		weapon = warrior::id % 3;
		morale = double(life_element) / init_strength[name];
		cout << "It has a " << warrior_weapon[weapon] << ",and it's morale is " << fixed<<setprecision(2)<<  morale << endl;
	}
};

class ninja :public warrior
{
	int weapon_1, weapon_2;
public:
	ninja(int time_, int type_, int life_element_, int is_blue_) :warrior(time_, type_, life_element_, is_blue_)
	{
		weapon_1 = id % 3;
		weapon_2 = (id + 1) % 3;
		cout << "It has a " << warrior_weapon[weapon_1] << " and a " << warrior_weapon[weapon_2] << endl;
	}
};

class iceman :public warrior
{
	int weapon;
public:
	iceman(int time_, int type_, int life_element_, int is_blue_) :warrior(time_, type_, life_element_, is_blue_)
	{
		weapon = id % 3;
		cout << "It has a " << warrior_weapon[weapon] << endl;
	}
};

class lion :public warrior
{
	int loyalty;
public:
	lion(int time_, int type_, int life_element_, int is_blue_) :warrior(time_, type_, life_element_, is_blue_)
	{
		loyalty = life_element;
		cout << "It's loyalty is " << loyalty << endl;
	}
};

class wolf :public warrior
{
public:
	wolf(int time_, int type_, int life_element_, int is_blue_) :warrior(time_, type_, life_element_, is_blue_)
	{

	}
};

void init_num()
{
	for (int i = 0; i <= 1; i++)
	{
		num_of_group[i] = 0;
		for (int j = 0; j < 5; j++)
			num_warriors[i][j] = 0;
	}
}

void make_warrior(int time_, int type_, int life_element_, int is_blue_)
{
	switch (type_)
	{
	case 0:dragon(time_, type_, life_element_, is_blue_);
		break;
	case 1:ninja(time_, type_, life_element_, is_blue_);
		break;
	case 2:iceman(time_, type_, life_element_, is_blue_);
		break;
	case 3:lion(time_, type_, life_element_, is_blue_);
		break;
	case 4:wolf(time_, type_, life_element_, is_blue_);
		break;
	}
	return;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int m;
		cin >> m;
		cin >> init_strength["dragon"] >> init_strength["ninja"] >> init_strength["iceman"] >> init_strength["lion"] >> init_strength["wolf"];
		cout << "Case:" << i << endl;
		int time_point = 0, warrior_type_now[2] = { -1,-1 };
		int group_life_element[2] = { m,m };
		bool end_point[2] = { false,false };
		init_num();
		while (!end_point[0]||!end_point[1])
		{
			for (int i = 0; i <= 1; i++)
			{
				int j;
				for (j = 1; j <= 5; j++)
				{
					if (group_life_element[i] >=init_strength[warrior_name[order[i][(warrior_type_now[i] + j) % 5]]])
					{
						group_life_element[i] -= init_strength[warrior_name[order[i][(warrior_type_now[i] + j) % 5]]];
						warrior_type_now[i] = (warrior_type_now[i] + j) % 5;
						make_warrior(time_point, order[i][warrior_type_now[i]], group_life_element[i], i);
						break;
					}
				}
				if (j > 5 && end_point[i] == false)
				{
					end_point[i] = true;
					cout << setiosflags(ios::right)<<setfill('0') << setw(3) <<time_point<<" "<<group[i] <<" headquarter stops making warriors" << endl;
				}
			}
			time_point++;
		}
	}
}