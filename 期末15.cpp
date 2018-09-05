#include <iostream>
#include <set>
using namespace std;

// 在此处补充你的代码
class Rectangle
{
public:
	int row, col;
	int s, l;
	Rectangle(int _row, int _col) :row(_row), col(_col) {
		s = row * col;
		l = 2 * (row + col);
	};
	bool operator<(const Rectangle b)const
	{
		if (s != b.s)
			return s > b.s;
		else
			return l > b.l;
	}
	friend ostream&operator<<(ostream& out, Rectangle p)
	{
		out << p.s << ' ' << p.l;
		return out;
	}
};
class Comp
{
public:
	bool operator()(Rectangle a, Rectangle b)
	{
		if (a.l != b.l)
			return a.l < b.l;
		else
			return a.s < b.s;
	}
};

int main() {
	multiset<Rectangle> m1;
	multiset<Rectangle, Comp> m2;
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		m1.insert(Rectangle(a, b));
		m2.insert(Rectangle(a, b));
	}
	for (multiset<Rectangle>::iterator it = m1.begin(); it != m1.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;
	for (multiset<Rectangle>::iterator it = m2.begin(); it != m2.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}