#pragma once 

#ifndef  ASJ_TOOL
#define  ASJ_TOOL


#include <Windows.h>
#include <string>
#include <tchar.h>
#include <time.h>
#include<vector>
#include <iostream>
#include <conio.h>
#include "Lawn.h"
using namespace std;


class Tool
{
public:
	Tool(){}
	virtual ~Tool(){}
	virtual void clear() = 0;
	virtual void set_pos(const vector<int> & where) = 0;
	virtual void set_shoot_cd(const vector<int> & a) = 0;
	virtual void set_data(const vector<double> &a) = 0;
	virtual void create(const vector<int> & where) = 0;
	virtual void del_one_object(const size_t &i) = 0;

	//获取
	virtual vector<int> get_cd() = 0;
	virtual size_t get_num() = 0;
	virtual Tool *get_one_object(const size_t &i) = 0;
	virtual one_uint get_who() = 0;
	virtual string get_name() = 0;
	virtual vector<bool>get_is_can() = 0;
	//表现
	virtual void print() = 0;
	virtual void move() = 0;
protected:
	string	name;
	string  shap;
	one_uint who;
	//vector<int> pos;    //0 row    1  col   2  x   3  y 
	//vector<double>data;	//0 MAX_XL  1  MAX_AT   2  MAX_DF  3 XL   4 AT  5  DF
	vector<int>shoot_CD;	// 0  shoot_CD  发射频率  1  SP  移动速度   2  SP_begin
	bool    is_alive;
	bool is_can_move;
	virtual void push() = 0;
};

//读报
class Newspaper :public Tool
{
	vector<Newspaper> all;
public:
	Newspaper()
	{
		name = "读报";
		shap = "";
		who.type = 51;
		who.data = { 900, 100, 600, 900, 100, 600 };
		shoot_CD = { 4, 5, 0 };
		is_alive = 1;
		is_can_move = 1;
	}
	~Newspaper(){}
	void clear()
	{
		all.clear();
	}
	void set_pos(const vector<int> & where)
	{
		who.pos = where;
	}
	void set_shoot_cd(const vector<int> & a)
	{
		shoot_CD = a;
	}
	void set_data(const vector<double> &a)
	{
		who.data = a;
	}
	void create(const vector<int> & where)
	{
		this->who.pos = where;
		this->who.pos[3] += 1;
		this->push();
	}
	void del_one_object(const size_t &i)
	{
		size_t k = 0;
		vector<Newspaper>::iterator it;
		for (it = all.begin(); it != all.end(); it++, k++)
		{
			if (k == i)
			{
				it = all.erase(it);
				break;
			}
		}
	}
	
	//获取函数

	
	vector<int> get_cd()
	{
		return shoot_CD;
	}
	size_t get_num()
	{
		return all.size();
	}
	Tool *get_one_object(const size_t &i)
	{
		return &all[i];
	}
	one_uint get_who()
	{
		return who;
	}
	string get_name()
	{
		return name;
	}
	vector<bool>get_is_can()
	{
		vector<bool> b;
		b.push_back(is_alive);
		b.push_back(is_can_move);
		return b;
	}
	//表现
	void print();
	void move();
protected:
	void push()
	{
		all.push_back(*this);
	}
};

//铁桶
class Bucket :public Tool
{
	vector<Bucket> all;
public:
	Bucket()
	{
		name = "铁桶";
		shap = "";
		who.type = 52;
		who.data = { 1300, 100, 600, 1300, 100, 600 };
		shoot_CD = { 4, 10, 0 };
		is_alive = 1;
		is_can_move = 1;
	}
	~Bucket(){}

	void clear()
	{
		all.clear();
	}
	void set_pos(const vector<int> & where)
	{
		who.pos = where;
	}
	void set_shoot_cd(const vector<int> & a)
	{
		shoot_CD = a;
	}
	void set_data(const vector<double> &a)
	{
		who.data = a;
	}
	void create(const vector<int> & where)
	{
		this->who.pos = where;
		this->who.pos[3] += 1;
		this->push();
	}
	void del_one_object(const size_t &i)
	{
		size_t k = 0;
		vector<Bucket>::iterator it;
		for (it = all.begin(); it != all.end(); it++, k++)
		{
			if (k == i)
			{
				it = all.erase(it);
				break;
			}
		}
	}

	//获取函数


	vector<int> get_cd()
	{
		return shoot_CD;
	}
	size_t get_num()
	{
		return all.size();
	}
	Tool *get_one_object(const size_t &i)
	{
		return &all[i];
	}
	one_uint get_who()
	{
		return who;
	}
	string get_name()
	{
		return name;
	}
	vector<bool>get_is_can()
	{
		vector<bool> b;
		b.push_back(is_alive);
		b.push_back(is_can_move);
		return b;
	}
	//表现
	void print();
	void move();
protected:
	void push()
	{
		all.push_back(*this);
	}
};

//铁扇门
class Iron_gate :public Tool
{
	vector<Iron_gate> all;
public:
	Iron_gate()
	{
		name = "铁扇门";
		shap = "";
		who.type = 52;
		who.data = { 1600, 100, 600, 1600, 100, 600 };
		shoot_CD = { 4, 10, 0 };
		is_alive = 1;
		is_can_move = 1;
	}
	~Iron_gate(){}
	void clear()
	{
		all.clear();
	}
	void set_pos(const vector<int> & where)
	{
		who.pos = where;
	}
	void set_shoot_cd(const vector<int> & a)
	{
		shoot_CD = a;
	}
	void set_data(const vector<double> &a)
	{
		who.data = a;
	}
	void create(const vector<int> & where)
	{
		this->who.pos = where;
		this->who.pos[3] += 1;
		this->push();
	}
	void del_one_object(const size_t &i)
	{
		size_t k = 0;
		vector<Iron_gate>::iterator it;
		for (it = all.begin(); it != all.end(); it++, k++)
		{
			if (k == i)
			{
				it = all.erase(it);
				break;
			}
		}
	}

	//获取函数


	vector<int> get_cd()
	{
		return shoot_CD;
	}
	size_t get_num()
	{
		return all.size();
	}
	Tool *get_one_object(const size_t &i)
	{
		return &all[i];
	}
	one_uint get_who()
	{
		return who;
	}
	string get_name()
	{
		return name;
	}
	vector<bool>get_is_can()
	{
		vector<bool> b;
		b.push_back(is_alive);
		b.push_back(is_can_move);
		return b;
	}
	//表现
	void print();
	void move();
protected:
	void push()
	{
		all.push_back(*this);
	}
};


//
//class Rugby :public Tool
//{
//	static vector<Rugby> all;
//public:
//	Rugby()
//	{
//		name = "橄榄球服";
//		shap = "";
//		data = { 100, 100, 0, 100, 100, 0 };
//		shoot_CD = { 4, 20, 0 };
//	}
//	~Rugby(){}
//	void set_pos(const vector<int> & where)
//	{
//		pos = where;
//	}
//	void set_shoot_cd(const vector<int> & a)
//	{
//		shoot_CD = a;
//	}
//	void set_data(const vector<double> &a)
//	{
//		data = a;
//	}
//	void create(const vector<int> & where)
//	{
//		this->set_pos(where);
//		this->push();
//	}
//	void del_one_object(const size_t &i)
//	{
//		size_t k = 0;
//		vector<Rugby>::iterator it;
//		for (it = all.begin(); it != all.end(); it++, k++)
//		{
//			if (k == i)
//			{
//				it = all.erase(it);
//				break;
//			}
//		}
//	}
//	void push()
//	{
//		all.push_back(*this);
//	}
//	//获取函数
//
//	vector<int> get_pos()
//	{
//		return pos;
//	}
//	vector<double>get_data()
//	{
//		return data;
//	}
//	vector<int> get_cd()
//	{
//		return shoot_CD;
//	}
//	size_t get_num()
//	{
//		return all.size();
//	}
//	Tool *get_one_object(const size_t &i)
//	{
//		return &all[i];
//	}
//	string get_ID()
//	{
//		return ID;
//	}
//	string get_name()
//	{
//		return name;
//	}
//	//表现
//	void print();
//
//	void move();
//};
//
////Pole_Vaulting
//class Pole_Vaulting :public Tool
//{
//	static vector<Pole_Vaulting> all;
//public:
//	Pole_Vaulting()
//	{
//		name = "撑杆";
//		shap = "";
//		data = { 100, 100, 0, 100, 100, 0 };
//		shoot_CD = { 4, 20, 0 };
//	}
//	~Pole_Vaulting(){}
//	void set_pos(const vector<int> & where)
//	{
//		pos = where;
//	}
//	void set_shoot_cd(const vector<int> & a)
//	{
//		shoot_CD = a;
//	}
//	void set_data(const vector<double> &a)
//	{
//		data = a;
//	}
//	void create(const vector<int> & where)
//	{
//		this->set_pos(where);
//		this->push();
//	}
//	void del_one_object(const size_t &i)
//	{
//		size_t k = 0;
//		vector<Pole_Vaulting>::iterator it;
//		for (it = all.begin(); it != all.end(); it++, k++)
//		{
//			if (k == i)
//			{
//				it = all.erase(it);
//				break;
//			}
//		}
//	}
//	void push()
//	{
//		all.push_back(*this);
//	}
//	//获取函数
//
//	vector<int> get_pos()
//	{
//		return pos;
//	}
//	vector<double>get_data()
//	{
//		return data;
//	}
//	vector<int> get_cd()
//	{
//		return shoot_CD;
//	}
//	size_t get_num()
//	{
//		return all.size();
//	}
//	Tool *get_one_object(const size_t &i)
//	{
//		return &all[i];
//	}
//	string get_ID()
//	{
//		return ID;
//	}
//	string get_name()
//	{
//		return name;
//	}
//	//表现
//	void print();
//
//	void move();
//
//};
//
//


//棒球
class Baseball :public Tool
{
	vector<Baseball> all;
public:
	Baseball()
	{
		name = "棒球";
		shap = "#";
		who.type = 52;
		who.data = { 900, 100, 600, 900, 100, 600 };
		shoot_CD = { 40, 2, 0 };
		is_alive = 1;
		is_can_move = 1;
	}
	~Baseball(){}
	void clear()
	{
		all.clear();
	}
	void set_pos(const vector<int> & where)
	{
		who.pos = where;
	}
	void set_shoot_cd(const vector<int> & a)
	{
		shoot_CD = a;
	}
	void set_data(const vector<double> &a)
	{
		who.data = a;
	}
	void create(const vector<int> & where)
	{
		this->who.pos = where;
		this->who.pos[3] += 1;
		this->push();
	}
	void del_one_object(const size_t &i)
	{
		size_t k = 0;
		vector<Baseball>::iterator it;
		for (it = all.begin(); it != all.end(); it++, k++)
		{
			if (k == i)
			{
				it = all.erase(it);
				break;
			}
		}
	}

	//获取函数


	vector<int> get_cd()
	{
		return shoot_CD;
	}
	size_t get_num()
	{
		return all.size();
	}
	Tool *get_one_object(const size_t &i)
	{
		return &all[i];
	}
	one_uint get_who()
	{
		return who;
	}
	string get_name()
	{
		return name;
	}
	vector<bool>get_is_can()
	{
		vector<bool> b;
		b.push_back(is_alive);
		b.push_back(is_can_move);
		return b;
	}
	//表现
	void print();
	void move();
protected:
	void push()
	{
		all.push_back(*this);
	}
};


////Baseball
//class Baseball :public Tool
//{
//	static vector<Baseball> all;
//public:
//	Baseball()
//	{
//		name = "棒球";
//		shap = "";
//		data = { 100, 100, 0, 100, 100, 0 };
//		shoot_CD = { 4, 20, 0 };
//	}
//	~Baseball(){}
//	void set_pos(const vector<int> & where)
//	{
//		pos = where;
//	}
//	void set_shoot_cd(const vector<int> & a)
//	{
//		shoot_CD = a;
//	}
//	void set_data(const vector<double> &a)
//	{
//		data = a;
//	}
//	void create(const vector<int> & where)
//	{
//		this->set_pos(where);
//		this->push();
//	}
//	void del_one_object(const size_t &i)
//	{
//		size_t k = 0;
//		vector<Baseball>::iterator it;
//		for (it = all.begin(); it != all.end(); it++, k++)
//		{
//			if (k == i)
//			{
//				it = all.erase(it);
//				break;
//			}
//		}
//	}
//	void push()
//	{
//		all.push_back(*this);
//	}
//	//获取函数
//
//	vector<int> get_pos()
//	{
//		return pos;
//	}
//	vector<double>get_data()
//	{
//		return data;
//	}
//	vector<int> get_cd()
//	{
//		return shoot_CD;
//	}
//	size_t get_num()
//	{
//		return all.size();
//	}
//	Tool *get_one_object(const size_t &i)
//	{
//		return &all[i];
//	}
//	string get_ID()
//	{
//		return ID;
//	}
//	string get_name()
//	{
//		return name;
//	}
//	//表现
//	void print();
//
//	void move();
//};
//
////Chemist
//class Chemist :public Tool
//{
//	static vector<Chemist> all;
//public:
//	Chemist()
//	{
//		name = "炸药";
//		shap = "";
//		data = { 100, 100, 0, 100, 100, 0 };
//		shoot_CD = { 4, 20, 0 };
//	}
//	~Chemist(){}
//	void set_pos(const vector<int> & where)
//	{
//		pos = where;
//	}
//	void set_shoot_cd(const vector<int> & a)
//	{
//		shoot_CD = a;
//	}
//	void set_data(const vector<double> &a)
//	{
//		data = a;
//	}
//	void create(const vector<int> & where)
//	{
//		this->set_pos(where);
//		this->push();
//	}
//	void del_one_object(const size_t &i)
//	{
//		size_t k = 0;
//		vector<Chemist>::iterator it;
//		for (it = all.begin(); it != all.end(); it++, k++)
//		{
//			if (k == i)
//			{
//				it = all.erase(it);
//				break;
//			}
//		}
//	}
//	void push()
//	{
//		all.push_back(*this);
//	}
//	//获取函数
//
//	vector<int> get_pos()
//	{
//		return pos;
//	}
//	vector<double>get_data()
//	{
//		return data;
//	}
//	vector<int> get_cd()
//	{
//		return shoot_CD;
//	}
//	size_t get_num()
//	{
//		return all.size();
//	}
//	Tool *get_one_object(const size_t &i)
//	{
//		return &all[i];
//	}
//	string get_ID()
//	{
//		return ID;
//	}
//	string get_name()
//	{
//		return name;
//	}
//	//表现
//	void print();
//
//	void move();
//
//};
//


#endif 





