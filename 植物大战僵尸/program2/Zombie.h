#pragma once 
#ifndef  ASJ_ZOMBI
#define  ASJ_ZOMBI

#include <Windows.h>
#include <string>
#include <tchar.h>
#include <time.h>
#include<vector>
#include <iostream>
#include <conio.h>
#include "Tool.h"
#include "UI.h"
using namespace std;

class Zombies
{
public:
	Zombies(){}
	virtual ~Zombies(){}
	virtual void clear() = 0;
	virtual void set_tool_type(const int &i) = 0;
	virtual void set_pos(const vector<int> & where) = 0;
	//virtual void set_solo_cd(const vector<int> & a) = 0;
	virtual void set_move_cd(const vector<int> & a) = 0;
	virtual void set_data(const vector<double> &a) = 0;
	virtual void create(const vector<int> & where) = 0;
	virtual void del_one_object(const size_t &i) = 0;
	
	virtual void Cannot_attack() = 0;
	virtual void Cannot_move() = 0;
	//获取
	virtual int get_bullet_type() = 0;
	virtual Tool* get_tools() = 0;
	virtual size_t get_num() = 0;
	virtual Zombies *get_one_object(const size_t &i) = 0;
	virtual one_uint get_who() = 0;
	virtual vector<bool> get_is_can() = 0;
	virtual string get_name() = 0;
	//表现
	virtual void print() = 0;
	virtual void attack() = 0;
	//virtual void bite() = 0;
	virtual void solo() = 0;
	virtual void defance() = 0;
	virtual int move() = 0;
	virtual void move_up ()= 0;
	virtual void move_down() = 0;


protected:
	string name;
	one_uint who;
	//vector<int> pos;    //0 row    1  col   2  x   3  y 
	//vector<double>data;	//0 MAX_XL  1  MAX_AT   2  MAX_DF  3 XL   4 AT  5  DF
	vector<int>bite_CD;	// 0  bite_CD   1  bite_CD_begin
	vector<int>solo_CD;	// 0  solo_CD   1  solo_CD_begin
	vector<int>move_CD;	// 0  move_CD   1  move_CD_begin
	bool    is_alive;
	bool    is_can_attack;
	bool    is_can_solo;
	bool    is_can_move;
	virtual void push() = 0;

};

//普通防御型僵尸
class Ordinary :public Zombies
{
	static vector<Ordinary> all;
	Tool *my_Tools;
	int what_tool;

public:
	Ordinary()
	{
		name = "僵尸";
		who.id = "普通僵尸";
		who.type = 1;
		who.data = { 900, 100, 600, 900, 100, 600 };
		solo_CD = { 10, 0 };
		move_CD = { 2, 0 };
		is_alive = 1;
		is_can_attack = 0;
		is_can_solo = 0;	
		is_can_move = 1;
		what_tool = 0;
		my_Tools = NULL;
	}
	~Ordinary(){}
	void clear()
	{
		for (size_t i = 0; i < all.size(); i++)
			all[i].my_Tools->clear();
		all.clear();
	}

	void set_tool_type(const int &i)
	{
		what_tool = i;
	}
	Tool *get_tools()
	{
		return my_Tools;
	}
	void set_pos(const vector<int> & where)
	{
		who.pos = create_pos(where[0], where[1]);
	}
	void set_solo_cd(const vector<int> & a)
	{
		solo_CD = a;
	}
	void set_move_cd(const vector<int> & a)
	{
		move_CD = a;
	}

	void set_data(const vector<double> &a)
	{
		who.data = a;
	}
	void create(const vector<int> & where);
	void del_one_object(const size_t &i)
	{
		size_t k = 0;
		vector<Ordinary>::iterator it;
		for (it = all.begin(); it != all.end(); it++, k++)
		{
			if (k == i)
			{
				it = all.erase(it);
				break;
			}
		}
	}
	
	void Cannot_attack()
	{
		is_can_attack = 0;
	}
	void Cannot_move()
	{
		is_can_move = 0;
	}

	//获取函数
	int get_bullet_type()
	{
		return what_tool;
	}
	Tool *get_bullets()
	{
		return my_Tools;
	}
	
	size_t get_num()
	{
		return all.size();
	}
	Zombies *get_one_object(const size_t &i)
	{
		return &all[i];
	}
	one_uint get_who()
	{
		return who;
	}
	vector<bool> get_is_can()
	{
		vector<bool> b;
		b.push_back(is_alive);
		b.push_back(is_can_attack);
		b.push_back(is_can_solo);
		b.push_back(is_can_move);
		return b;
	}
	string get_name()
	{
		return name;
	}


	//表现
	void print();
	void attack();
	void solo()
	{

	}
	void defance();

	void move_up();
	void move_down();
	int move();
private:
	void bite();
protected:
	void push()
	{
		all.push_back(*this);
	}

};

//远程僵尸
class Z_shooter :public Zombies
{
	static vector<Z_shooter> all;
	Tool *my_Tools;
	int what_tool;
	vector<int>shoot_CD;

public:
	Z_shooter()
	{
		name = "僵尸";
		who.id = "远程僵尸";
		who.type = 1;
		who.data = { 900, 100, 600, 900, 100, 600 };
		shoot_CD = { 10, 0 };
		solo_CD = { 10, 0 };
		move_CD = { 2, 0 };
		is_alive = 1;
		is_can_attack = 0;
		is_can_solo = 0;
		is_can_move = 1;
		what_tool = 0;
		my_Tools = NULL;
	}
	~Z_shooter(){}

	void clear()
	{
		for (size_t i = 0; i < all.size(); i++)
			all[i].my_Tools->clear();
		all.clear();
	}
	void set_tool_type(const int &i)
	{
		what_tool = i;
	}
	Tool *get_tools()
	{
		return my_Tools;
	}
	void set_pos(const vector<int> & where)
	{
		who.pos = create_pos(where[0], where[1]);
	}
	void set_solo_cd(const vector<int> & a)
	{
		solo_CD = a;
	}
	void set_move_cd(const vector<int> & a)
	{
		move_CD = a;
	}

	void set_data(const vector<double> &a)
	{
		who.data = a;
	}
	void create(const vector<int> & where);
	void del_one_object(const size_t &i)
	{
		size_t k = 0;
		vector<Z_shooter>::iterator it;
		for (it = all.begin(); it != all.end(); it++, k++)
		{
			if (k == i)
			{
				it = all.erase(it);
				break;
			}
		}
	}

	void Cannot_attack()
	{
		is_can_attack = 0;
	}
	void Cannot_move()
	{
		is_can_move = 0;
	}

	//获取函数
	int get_bullet_type()
	{
		return what_tool;
	}
	Tool *get_bullets()
	{
		return my_Tools;
	}

	size_t get_num()
	{
		return all.size();
	}
	Zombies *get_one_object(const size_t &i)
	{
		return &all[i];
	}
	one_uint get_who()
	{
		return who;
	}
	vector<bool> get_is_can()
	{
		vector<bool> b;
		b.push_back(is_alive);
		b.push_back(is_can_attack);
		b.push_back(is_can_solo);
		b.push_back(is_can_move);
		return b;
	}
	string get_name()
	{
		return name;
	}


	//表现
	void print();
	void attack();
	void solo()
	{

	}
	void defance();

	void move_up();
	void move_down();
	int move();
private:
	void shoot();
protected:
	void push()
	{
		all.push_back(*this);
	}

};





////远程僵尸
//class Z_01 :public Zombies
//{
//	static vector<Z_01> all;
//	Tool *my_Tools;
//	int what_tool;
//public:
//	Z_01()
//	{
//		name = "远程僵尸";
//		type = "远程僵尸";
//		MAX_XL = 100;
//		XL = 100;
//		AT = 30;
//		SP = 20;
//		SP_begin = 0;
//		is_alive = 1;
//		//初始化一个工具
//		what_tool = 0;
//		my_Tools = new Baseball;
//		
//	}
//	~Z_01(){}
//	void set_pos(const int &a, const int &b);
//	void select_tool(int i)
//	{
//		what_tool = i;
//	}
//	void create(const int &a, const int &b);
//	void print();
//	void attak()
//	{
//		bite();
//	}
//	void move();
//	void push()
//	{
//		all.push_back(*this);
//	}
//	size_t get_num()
//	{
//		return all.size();
//	}
//	void bite()
//	{
//
//	}
//	Zombies* get_one_object(size_t i)
//	{
//		return &all[i];
//	}
//	void hit_one_object(size_t i, double at)
//	{
//		all[i].XL -= at;
//	}
//	int get_row()
//	{
//		return row;
//	}
//	int get_col()
//	{
//		return col;
//	}
//	string get_type()
//	{
//		return type;
//	}
//	Tool * get_tool()
//	{
//		return my_Tools;
//	}
//	int get_tool_type()
//	{
//		return what_tool;
//	}
//
//};
//
////近程僵尸
//class Z_02 :public Zombies
//{
//	static vector<Z_02> all;
//	Tool *my_Tools;
//	int what_tool;
//public:
//	Z_02()
//	{
//		name = "近程僵尸";
//		type = "近程僵尸";
//		MAX_XL = 100;
//		XL = 100;
//		AT = 30;
//		SP = 20;
//		SP_begin = 0;
//		is_alive = 1;
//		//初始化一个工具
//		what_tool = 0;
//		my_Tools = new Pole_Vaulting;
//		
//	}
//	~Z_02(){}
//	void set_pos(const int &a, const int &b);
//	void select_tool(int i)
//	{
//		what_tool = i;
//	}
//	void create(const int &a, const int &b);
//	void print();
//	void attak()
//	{
//		bite();
//	}
//	void move();
//	void push()
//	{
//		all.push_back(*this);
//	}
//	size_t get_num()
//	{
//		return all.size();
//	}
//	void bite()
//	{
//
//	}
//	Zombies* get_one_object(size_t i)
//	{
//		return &all[i];
//	}
//	void hit_one_object(size_t i, double at)
//	{
//		all[i].XL -= at;
//	}
//	int get_row()
//	{
//		return row;
//	}
//	int get_col()
//	{
//		return col;
//	}
//	string get_type()
//	{
//		return type;
//	}
//	Tool * get_tool()
//	{
//		return my_Tools;
//	}
//	int get_tool_type()
//	{
//		return what_tool;
//	}
//};
//
//
//
//
//
////Kunkun
//class Kunkun :public Zombies
//{
//	static vector<Kunkun> all;
//	Tool *my_Tools;
//	int what_tool;
//	int is_about_to_die;
//public:
//	Kunkun()
//	{
//		name = "坤坤僵尸";
//		type = "坤坤僵尸";
//		MAX_XL = 100;
//		XL = 100;
//		AT = 30;
//		SP = 50;
//		SP_begin = 0;
//		is_alive = 1;
//		is_about_to_die = 0;
//		//初始化一个工具
//		what_tool = 0;
//		my_Tools = NULL;
//		
//	}
//	~Kunkun(){}
//	void set_pos(const int &a, const int &b);
//	void select_tool(int i)
//	{
//		what_tool = i;
//	}
//	void create(const int &a, const int &b);
//	void print();
//	void attak()
//	{
//		bite();
//	}
//	void move();
//	void push()
//	{
//		all.push_back(*this);
//	}
//	size_t get_num()
//	{
//		return all.size();
//	}
//	void bite()
//	{
//
//	}
//	Zombies* get_one_object(size_t i)
//	{
//		return &all[i];
//	}
//	void hit_one_object(size_t i, double at)
//	{
//		all[i].XL -= at;
//	}
//	int get_row()
//	{
//		return row;
//	}
//	int get_col()
//	{
//		return col;
//	}
//	string get_type()
//	{
//		return type;
//	}
//	Tool * get_tool()
//	{
//		return my_Tools;
//	}
//	int get_tool_type()
//	{
//		return what_tool;
//	}
//};
//


#endif 





