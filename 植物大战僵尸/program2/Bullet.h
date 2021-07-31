#pragma once 
#ifndef  ASJ_BULLET
#define  ASJ_BULLET

#include <Windows.h>
#include <string>
#include <tchar.h>
#include <time.h>
#include<vector>
#include <iostream>
#include <conio.h>

#include "Lawn.h"
using namespace std;


class Bullet
{
public:
	Bullet(){}
	virtual ~Bullet(){}
	//修改
	virtual void clear() = 0;
	virtual void set_pos(const vector<int> & where) = 0;
	virtual void set_shoot_cd(const vector<int> & a) = 0;
	virtual void set_data(const vector<double> &a) = 0;
	virtual void create(const vector<int> & where) = 0;
	virtual void del_one_object(const size_t &i) = 0;
	
	//获取
	virtual vector<int> get_cd() = 0;
	virtual size_t get_num() = 0;
	virtual Bullet *get_one_object(const size_t &i) = 0;
	virtual one_uint get_who() = 0;
	virtual string get_name() = 0;
	virtual int get_price() = 0;
	virtual vector<bool>get_is_can() = 0;
	//表现
	virtual void print() = 0;
	virtual void move() = 0;
protected:
	string	name;
	string  shap;
	one_uint who;
	int price;
	bool is_can_move;
	//vector<int> pos;    //0 row    1  col   2  x   3  y 
	//vector<double>data;	//0 MAX_XL  1  MAX_AT   2  MAX_DF  3 XL   4 AT  5  DF
	vector<int>shoot_CD;	// 0  shoot_CD  发射频率  1  SP  移动速度   2  SP_begin

	virtual void push() = 0;


};

//Org_pea
class Org_pea :public Bullet
{
	vector<Org_pea> all;
public:
	Org_pea()
	{
		name = "普通豌豆";
		shap = "O";
		price = 100;
		who.type = 51;
		who.data = { 500, 200, 300, 500, 200, 300 };
		shoot_CD = { 20,5, 0 };
		is_can_move = 1;

	}
	~Org_pea(){}
	void clear()
	{
		all.clear();
	}
	void set_pos(const vector<int> & where)
	{
		who.pos = create_pos(where[0], where[1]);
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
		this->set_pos(where);
		this->push();
	}
	void del_one_object(const size_t &i)
	{
		size_t k = 0;
		vector<Org_pea>::iterator it;
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
	Bullet *get_one_object(const size_t &i)
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
	int get_price()
	{
		return price;
	}
	vector<bool>get_is_can()
	{
		vector<bool> b;
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

//Snow_pea
class Snow_pea :public Bullet
{
	vector<Snow_pea> all;
public:
	Snow_pea()
	{
		name = "雪花豌豆";
		shap = "*";
		price = 100;
		who.type = 52;
		who.data = { 1500, 100, 500, 1500, 100, 500 };
		shoot_CD = { 30, 5, 0 };
		is_can_move = 1;

	}
	~Snow_pea(){}
	void clear()
	{
		all.clear();
	}
	void set_pos(const vector<int> & where)
	{
		who.pos = create_pos(where[0], where[1]);
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
		this->set_pos(where);
		this->push();
	}
	void del_one_object(const size_t &i)
	{
		size_t k = 0;
		vector<Snow_pea>::iterator it;
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
	Bullet *get_one_object(const size_t &i)
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
	int get_price()
	{
		return price;
	}
	vector<bool>get_is_can()
	{
		vector<bool> b;
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
//Melon
class Melon :public Bullet
{
	vector<Melon> all;
public:
	Melon()
	{
		name = "西瓜";
		shap = "∞";
		price = 200;
		who.type = 53;
		who.data = { 500, 200, 300, 500, 200, 300 };
		shoot_CD = { 40, 10, 0 };
		is_can_move = 1;

	}
	~Melon(){}
	void clear()
	{
		all.clear();
	}
	void set_pos(const vector<int> & where)
	{
		who.pos = create_pos(where[0], where[1]);
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
		this->set_pos(where);
		this->push();
	}
	void del_one_object(const size_t &i)
	{
		size_t k = 0;
		vector<Melon>::iterator it;
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
	Bullet *get_one_object(const size_t &i)
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
	int get_price()
	{
		return price;
	}
	vector<bool>get_is_can()
	{
		vector<bool> b;
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




#endif 

