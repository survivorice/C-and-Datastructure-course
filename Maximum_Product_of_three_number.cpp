// Maximum Product of three number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	vector<int>v;
	int n=0;
	int product = 0;
	int c1 = 0;
	int c2 = 0;
	while (cin >> n) {
		v.push_back(n);
}
	sort(v.begin(), v.end());
	if (v[v.size()-1] > 0 & v[v.size()-2] > 0 & v[v.size()-3] > 0) { c1 = v[v.size()-1] * v[v.size()-2] * v[v.size()-3]; }
	if (v[v.size()-1] > 0 & v[0] < 0 & v[1] < 0) { c2 = v[v.size()-1] * v[0] * v[1]; }
	product = max(c1, c2);
	cout << product << endl;
	system("pause");
    return 0;
}

