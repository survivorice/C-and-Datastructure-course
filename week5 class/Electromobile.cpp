// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Electromobile.h"

Electromobile::Electromobile(string i, int q, string rd, bool bs, bool rs, string p, Campus c)://初始化
	i(i),q(q),rd(rd),bs(bs),rs(rs),p(p),c(c){}

string Electromobile::campus() {                              //返回校园
	switch (c) {
	case 1:
		return "SJTU";
		break;
	case 2:
		return "Fudan";
		break;
	case 3:
		return "Tongji";
		break;
	case 4:
		return"ECUST";
		break;
	case 5:
		return"ECNU";
		break;
	}
}

void Electromobile::borrow_bike() {             //借车
	if (bs == 1) { cout << "error"<<endl; }
	else { bs = 1;
	cout << "borrow success" << endl;
	}
}

void Electromobile::return_bike() {              //还车
	if (bs == 0) {
		cout << "error" << endl;
	}
	else {
		bs = 0;
		cout << "return success" << endl;
	}
}

void Electromobile::repair_bike() {             //修车
	if (rs == 0) {
		cout << "error" << endl;
	}
	else {
		rs = 0;
		cout << "repair success" << endl;
	}
}

bool Electromobile::operator==(Electromobile&b) {
	return (get_ID()== b.get_ID());
}
bool Electromobile::operator!=(Electromobile&b) {
	return (get_ID() != b.get_ID());
}
ostream&operator<<(ostream&os, Electromobile&b) {
	return os << "ID: " << b.get_ID() << "\n" << "q: " << b.get_q() << "\n" << "repair date: " << b.get_repair_date() << "\n"
		<< "borrow or not: " << b.borrow_status()<< "\n" << "need repair or not: " << b.repair_status() << "\n" << "place: " << b.get_place() << endl;
}