#pragma once
#include<iostream>
using namespace std;
istringstream ii;
ostringstream oo;   
class Token {                  //make a token
public:
	char kind;
	double value;
	Token(char ch) :                 //token no value
		kind(ch), value(0) {}
	Token(char ch, double val) :     //token with value
		kind(ch), value(val) {}
};


class Token_stream {
public:
	Token_stream();                 //构建函数
	Token get();                    //取token函数
	void putback(Token t);          //将token放回流中
	void ignore(char c);
private:
	bool full;                      //流中的缓存状态
	Token buffer;                   //缓存区
};

void keep_window_open() {
	char ch;
	ii>> ch;
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
	ii >> ch;
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
	{return Token(ch); }
	case'.':
	case'0':case'1':case'2':case'3':case'4':
	case'5':case'6':case'7':case'8':case'9':
	{ii.putback(ch);
	double val;
	ii>> val;
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
	while (ii >> ch)
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

double term() {
	double left = primary();
	Token t = ts.get();
	while (true) {
		double d = 0.0;
		int i1 = 0;
		int i2 = 0;
		switch (t.kind) {
		case'*':
			left *= primary();
			t = ts.get();
			break;
		case'/':
			d = primary();
			if (d == 0) error("error");
			left=int(left)/int(d);
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

void calculate() {
	while (ii)
		try {
		Token t = ts.get();
		if (t.kind == print)
		{
			break;
		}
		ts.putback(t);
		oo << expression();
	}
	catch (exception&e) {
		cerr << e.what() << endl;
		ts.ignore(print);
	}
}

