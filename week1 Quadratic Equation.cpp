// week1 Quadratic Equation.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"math.h"
#include<iomanip>
#include<typeinfo>
using namespace std;

int main()
{
		double a = 0.0;
		double b = 0.0;
		double c = 0.0;
		double root1 = 0.0;
		double root2 = 0.0;
		cin >> a >> b >> c;
		if (cin.fail()) { cout << "error" << endl; 
		        exit(0);
		}
		if (b*b - 4 * a*c < 0) {
			cout << "invalid" << endl;
		}
		else if (b*b - 4 * a*c == 0) {
			root1 = -(b / 2 * a);
			cout << setiosflags(ios::fixed) << setprecision(2) << root1 << endl;
		}
		else {
			root1 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a);
			root2 = (-b - sqrt(b*b - 4 * a*c)) / (2 * a);
			if (root1 > root2) {
				cout << setiosflags(ios::fixed) << setprecision(2) << root1 << " " << root2 << endl;
			}
			else {
				cout << setiosflags(ios::fixed) << setprecision(2) << root2 << " " << root1 << endl;
			}
		}
		system("pause");
    return 0;
}

