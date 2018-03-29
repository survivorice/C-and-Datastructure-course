#pragma once
#include<iostream>
#include<string>
using namespace std;

class Electromobile {
    public:
      enum Campus {SJTU=1,Fudan,Tongji,ECUST,ECNU};
	  Electromobile(string i, int q, string rd, bool bs, bool rs, string p, Campus c); //��ʼ��
	  string get_ID() { return i; }; //���ص�ƿ�����
	  int get_q() { return q; };//���ص�ƿ��������ʾ0-100�İٷֱ�
	  string get_repair_date() { return rd; };//�����ϴ�ά��ʱ�䣬��2018/03/05
	  bool borrow_status() { return bs; };//�����Ƿ��ѱ����ã�1��ʾ������
	  bool repair_status() { return rs; };//�����Ƿ���Ҫά�ޣ�1��ʾ��Ҫά��
	  string get_place() { return p; };//���ص�ƿ���ص�
	  string campus() ;//���ص�ƿ������У԰
	  void borrow_bike();//�⳵
	  void return_bike();//����
	  void repair_bike();//�޳�
	  bool operator==(Electromobile&b);
	  bool operator!=(Electromobile&b);
    private:
		string i;
		int q;
		string rd;
		bool bs;
		bool rs;
		string p;
		Campus c;

};
ostream&operator<<(ostream&os, Electromobile&b);