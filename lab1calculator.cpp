// lab1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Token_stream.h"
#include<iostream>
using namespace std;
double ans=0.0;

void error(string s) {             //error 实现
	throw runtime_error(s);
}
void keep_window_open() {
	char ch;
	cin >> ch;
}

 Token_stream::Token_stream() :             //构建函数初始状态
		full(false), buffer(0) {}

	void Token_stream::putback(Token t) {       
		if (full) error("error");          //若缓存区已有则error
		buffer = t;
		full = true;
	}

	Token_stream ts;
	const char number = '8';         //常量引用
	const char print = ';';
	const char quit = 'q';
	const char prompt = '<';
	const char result = '=';

	Token Token_stream::get() {       
		if (full) {
			full = false;
			return buffer;
		}
		char ch;
		cin >> ch;
		switch (ch) {
		case print:
		case quit:
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '!':
		case'A':
		{return Token(ch); }
		case'.':
		case'0':case'1':case'2':case'3':case'4':
		case'5':case'6':case'7':case'8':case'9':
		{cin.putback(ch);
		double val;
		cin >> val;
		return Token(number, val); }



		default:
			error("error");
		}


	}
	void Token_stream::ignore(char c) {
		if (full&&c == buffer.kind) {
			full = false;
			return;
		}
		full = false;
		char ch = 0;
		while (cin >> ch)
			if (ch == c)return;
	}
	double expression();   //declaration
	double primary() {
		Token t = ts.get();
		switch (t.kind) {
		case'(':
		{double d = expression();
		t = ts.get();
		if (t.kind != ')') error("error");
		return d; }
		case 'A':
			return ans;
		case number:
			return t.value;
		case'-':                     //负数的实现
			return -primary();
		case'+':
			return primary();
		default:
			error("error");
		}
	}

	int jiecheng(int x) {
		int ans = 1;
		for (int i = 1; i <= x; i++)ans *= i;
		return ans;
	}

	double term() {
		double left = primary();
		Token t = ts.get();
		while (true) {
			double d = 0.0;
			int i1 = 0;
			int i2 = 0;
			switch (t.kind) {
			case'!':
				i1 = int(left);
				cout << i1 <<endl;
				cout << left<< endl;
				if (i1 != left) {              
					error("error");
				};
				if (left < 0) { error("error"); }
				else if (left == 0) {  left = 1; }
				else {
					left = jiecheng(left);
				}
				t = ts.get();
				break;

			case'*':
				left *= primary();
				t = ts.get();
				break;
			case'/':
				d = primary();
				if (d == 0) error("error");
				left =(int)left/ (int)d;
				t = ts.get();
				break;
			case'%':
				d = primary();
				i1 = int(left);
				if (i1 != left) {                //防止浮点数取模
					error("error");
				};
				i2 = int(d);
				if (i2 != d) error("error");
				if (i2 == 0) error("error");
				left = i1%i2;
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
			}
		}
	}

	double expression() {
		double left = term();
		Token t = ts.get();
		while (true) {
			switch (t.kind) {
			case'+':
				left += term();
				t = ts.get();
				break;
			case'-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
			}
		}
	}

void calculate(){ 
		while (cin) 
			try {
			cout << prompt;
			Token t = ts.get();
			while (t.kind == print)
				t = ts.get();
			if (t.kind == quit)
				return;
			ts.putback(t);
			cout << result << expression() << endl;
		}
		 catch (exception&e) {
			cerr << e.what() << endl;
			ts.ignore(print);
   }
	}

int main() 
  try{
	    calculate();
		keep_window_open();
		return 0;
	}
catch (runtime_error&e) {
	cerr << e.what() << endl;
	cout << "please enter the ~ to close the window\n";
	char ch;
	while (cin >> ch)
		if (ch == '~')return 1;
	return 1;

  }
