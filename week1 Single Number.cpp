// week1 Single Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v;
	int size = 0;
	int single_number = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		int u = 0;
		cin >> u;
		v.push_back(u);
	}
	sort(v.begin(), v.end());
	int i = 0;
	while (i <= size - 1) {
		if (i == size - 1) { 
			single_number = v[i];
		    break;
		}
		else if (v[i] != v[i + 1]) {
			single_number = v[i];
			break;
		}
		else { i = i + 2; }
	}
	cout << single_number<<endl;
	system("pause");
    return 0;
}

