#pragma once
#include<iostream>
#include<string>
using namespace std;

class Electromobile {
    public:
      enum Campus {SJTU=1,Fudan,Tongji,ECUST,ECNU};
	  Electromobile(string i, int q, string rd, bool bs, bool rs, string p, Campus c); //初始化
	  string get_ID() { return i; }; //返回电瓶车编号
	  int get_q() { return q; };//返回电瓶电量，表示0-100的百分比
	  string get_repair_date() { return rd; };//返回上次维修时间，如2018/03/05
	  bool borrow_status() { return bs; };//返回是否已被租用，1表示被租用
	  bool repair_status() { return rs; };//返回是否需要维修，1表示需要维修
	  string get_place() { return p; };//返回电瓶车地点
	  string campus() ;//返回电瓶车所在校园
	  void borrow_bike();//租车
	  void return_bike();//还车
	  void repair_bike();//修车
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