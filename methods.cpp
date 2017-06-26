#include "Port.h"

Port::Port(const char *br, const char *st, int b) {
	brand = new char[sizeof(br) + 1];//plus zero byte.
	strcpy(brand, br);
	strcpy(style, st);
	bottles = b;
}

Port::Port(const Port &p) {
	brand = new char[sizeof(p.brand) + 1];//plus zero byte.
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

void Port::Show() const {
	cout << "Accounts of bottles: " << bottles << endl;
	cout << "The style: " << style << endl;
	cout << "The brand: " << brand << endl;
}

Port &Port::operator=(const Port &p) {
	Port::Port(p);
	return *this;
}

Port &Port::operator+=(int b) {
	bottles += b;
	return *this;
}

Port &Port::operator-=(int b) {
	bottles -= b;
	return *this;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VintagePort::VintagePort(const VintagePort &vp) {
	Port::Port(vp);
	nickname = new char[sizeof(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

void VintagePort::Show() const {
	Port::Show();
	cout << "The nickname: " << nickname << endl;
	cout << "The year of gathering: " << year << endl;
}

VintagePort &VintagePort::operator=(const VintagePort &vp) {
	VintagePort::VintagePort(vp);
	return *this;
}

ostream &operator<<(ostream &os, const VintagePort &vp) {
	vp.Show();
	return os;
}