#pragma once
#ifndef PORT_H_
#define PORT_H_
#include <iostream>
using namespace std;

class Port {
private:
	char *brand;
	char style[20];
	int bottles;
public:
	Port(const char *br = "none", const char *st = "none", int b = 0);
	Port(const Port &p);//copy constructor.
	virtual ~Port() { delete[] brand; }
	Port &operator=(const Port &p);
	Port &operator+=(int b);
	Port &operator-=(int b);
	int BottleCount() const { return bottles; }
	virtual void Show() const;
};

class VintagePort : public Port {
private:
	char *nickname;
	int year;
public:
	VintagePort() : Port("none", "vintage", 0), year(0) {
		nickname = new char[sizeof("none") + 1];
		strcpy(nickname, "none");
	};
	VintagePort(const char *br, int b, const char *nn, int y)
		: Port(br, "vintage", b), year(y) {
		nickname = new char[sizeof(nn) + 1];
		strcpy(nickname, nn);
	};
	VintagePort(const VintagePort &vp);
	~VintagePort() { delete[] nickname; }
	VintagePort &operator=(const VintagePort &vp);
	void Show() const;
	friend ostream &operator<<(ostream &os, const VintagePort &vp);
};
#endif