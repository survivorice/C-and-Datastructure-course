
#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

void cutpipe(vector<int>&requests, int stocklength, int & pipe_rest, int & pipe_number) {
	if (requests.size() == 1) {
		if (requests[0] > pipe_rest) { pipe_number++; pipe_rest = stocklength - requests[0]; return; }
		else { pipe_rest = pipe_rest - requests[0]; return; }
	}
	else {
		vector<int> temp;
		int check = 0;
		for (int i = 0; i < requests.size(); i++) {
			if (requests[i] < pipe_rest) { check = i; }
		}
		temp.push_back(requests[check]);
		requests.erase(requests.begin()+check);
		cutpipe(temp, stocklength, pipe_rest, pipe_number);
		cutpipe(requests, stocklength, pipe_rest, pipe_number);
		return;


	}
}

int cutstock(vector<int>&requests, int stocklength) {
	int pipe_number=0;
	int pipe_rest = 0;
	cutpipe(requests, stocklength, pipe_rest, pipe_number);
	return pipe_number;
}


int main()
{
	vector<int>requests;
	int stocklength = 0;
	int size = 0;
	cout << "enter your stocklength and pipe requests:" << endl;
	cin >> stocklength;
	cin >> size;
	for (int i = 0; i < size; i++) {
		int p = 0;
		cin >> p;
		requests.push_back(p);
	}
	cout << cutstock(requests, stocklength) << endl;
	system("pause");
    return 0;
}

