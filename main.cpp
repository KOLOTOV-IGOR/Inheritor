#include "Port.h"

int main() {
	/*char *a = new char[20];
	cin.getline(a, 20);
	cout << a << endl;
	cout << sizeof(a) << endl;*/
	VintagePort g;
	g.Show();
	VintagePort q("new", 4, "new", 5);
	//q.Show();
	q = g; cout << endl;
	q.Show();
	q += 5;
	//cout << q.BottleCount() << endl;
	cout << q << endl;

	return 0;
}