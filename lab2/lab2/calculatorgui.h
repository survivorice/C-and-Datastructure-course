#pragma once
#include"Graph.h"
#include"GUI.h"
#include"Simple_window.h"
#include"Point.h"
#include<string>
#include<iostream>
#include"Tokenstream.h"

string s="";
struct Calculate_window:Window {
	Calculate_window(Point xy, int w, int h, const string& title);
private:
	Button b0;
	Button b1;
	Button b2;
	Button b3;
	Button b4;
	Button b5;
	Button b6;
	Button b7;
	Button b8;
	Button b9;
	Button bdian;
	Button bjia;
	Button bjian;
	Button bcheng;
	Button bchu;
	Button bcalculate;
	Button bclean;
	Out_box input;
	Out_box output;

	static void cb_0(Address, Address);
	void put_0();
	static void cb_1(Address, Address);
	void put_1();
	static void cb_2(Address, Address);
	void put_2();
	static void cb_3(Address, Address);
	void put_3();
	static void cb_4(Address, Address);
	void put_4();
	static void cb_5(Address, Address);
	void put_5();
	static void cb_6(Address, Address);
	void put_6();
	static void cb_7(Address, Address);
	void put_7();
	static void cb_8(Address, Address);
	void put_8();
	static void cb_9(Address, Address);
	void put_9();
	static void cb_dian(Address, Address);
	void put_dian();
	static void cb_jia(Address, Address);
	void put_jia();
	static void cb_jian(Address, Address);
	void put_jian();
	static void cb_cheng(Address, Address);
	void put_cheng();
	static void cb_chu(Address, Address);
	void put_chu();
	static void cb_calculate(Address, Address);
	void put_calculate();
	static void cb_clean(Address, Address);
	void clean();
};

Calculate_window::Calculate_window(Point xy, int w, int h, const string& title):
	Window(xy, w, h, title),
	b0(Point(50,320), 50, 50, "0", cb_0),
	b1(Point(50, 260), 50, 50, "1", cb_1),
	b2(Point(110, 260), 50, 50, "2", cb_2),
	b3(Point(170, 260), 50, 50, "3", cb_3),
	b4(Point(50, 200), 50, 50, "4", cb_4),
	b5(Point(110, 200), 50, 50, "5", cb_5),
	b6(Point(170, 200), 50, 50, "6", cb_6),
	b7(Point(50, 140), 50, 50, "7", cb_7),
	b8(Point(110, 140), 50, 50, "8", cb_8),
	b9(Point(170, 140), 50, 50, "9", cb_9),
	bdian(Point(110,320),50,50,".",cb_dian),
	bjia(Point(230,260),50,50,"+",cb_jia),
	bjian(Point(290,260),50,50,"-",cb_jian),
	bcheng(Point(230,200),50,50,"*",cb_cheng),
	bchu(Point(290,200),50,50,"/",cb_chu),
	bcalculate(Point(290,320),50,50,"=",cb_calculate),
	bclean(Point(290,140),50,50,"AC",cb_clean),
	input(Point(80, 40), 300, 30, "expression:"),
	output(Point(80, 80), 300, 30, "result:") 
{
	attach(b0);
	attach(b1);
	attach(b2);
	attach(b3);
	attach(b4);
	attach(b5);
	attach(b6);
	attach(b7);
	attach(b8);
	attach(b9);
	attach(input);
	attach(output);
	attach(bdian);
	attach(bjia);
	attach(bjian);
	attach(bcheng);
	attach(bchu);
	attach(bcalculate);
	attach(bclean);
}


void Calculate_window::cb_0(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_0();
}
void Calculate_window::put_0() {
	s = s + "0";
	input.put(s);
}
void Calculate_window::cb_1(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_1();
}
void Calculate_window::put_1() {
	s = s + "1";
	input.put(s);
}

void Calculate_window::cb_2(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_2();
}
void Calculate_window::put_2() {
	s = s + "2";
	input.put(s);
}

void Calculate_window::cb_3(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_3();
}
void Calculate_window::put_3() {
	s = s + "3";
	input.put(s);
}

void Calculate_window::cb_4(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_4();
}
void Calculate_window::put_4() {
	s = s + "4";
	input.put(s);
}

void Calculate_window::cb_5(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_5();
}
void Calculate_window::put_5() {
	s = s + "5";
	input.put(s);
}

void Calculate_window::cb_6(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_6();
}
void Calculate_window::put_6() {
	s = s + "6";
	input.put(s);
}

void Calculate_window::cb_7(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_7();
}
void Calculate_window::put_7() {
	s = s + "7";
	input.put(s);
}

void Calculate_window::cb_8(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_8();
}
void Calculate_window::put_8() {
	s = s + "8";
	input.put(s);
}

void Calculate_window::cb_9(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_9();
}
void Calculate_window::put_9() {
	s = s + "9";
	input.put(s);
}

void Calculate_window::cb_dian(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_dian();
}
void Calculate_window::put_dian() {
	s = s + ".";
	input.put(s);
}

void Calculate_window::cb_jia(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_jia();
}
void Calculate_window::put_jia() {
	s = s + "+";
	input.put(s);
}

void Calculate_window::cb_jian(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_jian();
}
void Calculate_window::put_jian() {
	s = s + "-";
	input.put(s);
}

void Calculate_window::cb_cheng(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_cheng();
}
void Calculate_window::put_cheng() {
	s = s + "*";
	input.put(s);
}

void Calculate_window::cb_chu(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_chu();
}
void Calculate_window::put_chu() {
	s = s + "/";
	input.put(s);
}

void Calculate_window::cb_calculate(Address, Address pw) {
	reference_to<Calculate_window>(pw).put_calculate();
}
void Calculate_window::put_calculate() {
	s = s + ";";
	ii.str(s);
	calculate();
	output.put(oo.str());
}
void Calculate_window::cb_clean(Address, Address pw) {
	reference_to<Calculate_window>(pw).clean();
}
void Calculate_window::clean() {
	s = "";
	ii.str(s);
	oo.str("");
	output.put("");
	input.put(s);
}


