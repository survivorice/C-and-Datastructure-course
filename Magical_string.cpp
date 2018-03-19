// Magical string.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;


int main()
{
	int n = 0;
	int n1 = 0;
	cin >> n;
	string s = "122";
	if (n <= 0) { n1 = 0; }
	else if (n <= 3) { n1 = 1; }
	else {
		int position = 2;
		while (s.length() < n) {
			if (s.at(position) == '1') {
				if (s.at(s.length() - 1) == '1') { s = s + "2"; }
				else { s = s + "1"; }
			}
			else {
				if (s.at(s.length() - 1) == '1') { s = s + "22"; }
				else { s = s + "11"; }
			}
			position++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (s.at(i) == '1') { n1++; }
	}
	    cout << n1 << endl;
		system("pause");
		return 0;
	}

