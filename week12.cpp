// week12.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

int sum(int n) {
	if (n == 1) { return 1; }
	else { return n+sum(n - 1); }
}

int vabonacci_number(int n) {
	if (n == 1) { return 1; }
	if (n == 2) { return 1; }
	else { return vabonacci_number(n - 1) + vabonacci_number(n - 2); }
}
void vabonacci(int n) {
	for (int i = 1; i <= n; i++) {
		cout << vabonacci_number(i) << " ";
	}
	cout << endl;
}

int findsum(int num[] ,int size) {
	if (size >0) { return findsum(num, size - 1) + num[size - 1]; }
	else { return 0; }
}

int findmin(int num[], int size) {
	if (size == 1) { return num[0];}
	else { return min(findmin(num, size - 1), num[size - 1]); }
}

int main()
{
	cout << sum(100) << endl;
	vabonacci(10);
	int a[] = { 2,1,3,4,5 };
	cout<<findsum(a, 5)<<endl;
	cout << findmin(a, 5) << endl;
	system("pause");
    return 0;
}

