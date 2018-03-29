#include "stdafx.h"
#include"Electromobile.h"

int main() {
	Electromobile e1("ss-9304", 100, "2018/03/03", 1, 1, "Central Park", Electromobile::SJTU);
	Electromobile e2("ss-9304", 80, "2017/10/29", 0, 0, "Canteen", Electromobile::ECUST);
	Electromobile e3("ss-8394", 20, "2015/04/01", 0, 1, "Domitory", Electromobile::Fudan);
	cout << e1.get_ID() <<endl;
	cout << e1.get_q() << endl;
	cout << e1.get_repair_date() << endl;
	cout << e1.borrow_status() << endl;
	cout << e1.repair_status() <<endl;
	cout << e1.get_place() << endl;
	cout << e1.campus() << endl;
	if (e1 == e2) { cout << "same ID" << endl; };
	if (e1 != e3) { cout << "different ID" << endl; };
	cout << e1;
	e1.return_bike();
	e1.borrow_bike();
	e1.repair_bike();
	cout << e1;
	system("pause");
}