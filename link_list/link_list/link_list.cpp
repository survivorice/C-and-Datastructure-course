// link_list.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "516030910467_张啸.h"


int main()
{
	int arr[6] = { 1,2,3,4,5,6 };
	List list(arr, 6);
    cout<< list.length() << endl;
	list.print();
	cout << "-------------------------" << endl;
	cout << list.insert(4, 8) << endl;
	cout << list.insert(2, 8) << endl;
	cout << list.length() << endl;
	list.print();
	cout << "---------------------------" << endl;
	cout << list.find(2, 8) << endl;
	cout << list.find(3, 8) << endl;
	cout << list.find(6, 8) << endl;
	cout << "---------------------------" << endl;
	cout << list.remove(8) << endl;
	cout << list.length() << endl;
	list.print();
	cout << "---------------------------" << endl;
	int arr2[10] = { 0 };
	List list2(arr2, 0);
	cout << list.split(1, list2) << endl;
	cout << list.length() << endl;
	list.print();
	cout << list2.length() << endl;
	list2.print();
	cout << "---------------------------" << endl;
	list.combine(list2);
	cout << list2.length() << endl;
	list2.print();
	cout << list.length() << endl;
	list.print();
	system("pause");
	return 0;
}