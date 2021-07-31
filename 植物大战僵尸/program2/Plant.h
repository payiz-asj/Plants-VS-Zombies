#pragma once 
#ifndef  ASJ_PLANT
#define  ASJ_PLANT

#include <Windows.h>
#include <string>
#include <tchar.h>
#include <time.h>
#include<vector>
#include <iostream>
#include <conio.h>
#include "Bullet.h"
#include "UI.h"
using namespace std;



class Plants
{
public:
	Plants(){}
	virtual ~Plants(){}
	//修改
	virtual void clear() = 0;
	virtual void set_pos(const vector<int> & where) = 0;
	//virtual void set_solo_cd(const vector<int> & a) = 0;
	virtual void set_data(const vector<double> &a) = 0;
	virtual void create(const vector<int> & where, const int &b_type) = 0;
	virtual void create_tmp(const vector<int> & where, const int &b_type) = 0;
	virtual void del_one_object(const size_t &i) = 0;
	
	virtual void Cannot_attack() = 0;
	//获取
	virtual int get_bullet_type() = 0;
	virtual Bullet* get_bullets() = 0;
	virtual size_t get_num() = 0;
	virtual Plants *get_one_object(const size_t &i) = 0;
	virtual one_uint get_who() = 0;
	virtual vector<bool> get_is_can() = 0;
	virtual int get_price() = 0;
	virtual string get_name() = 0;

	//表现
	virtual void print() = 0;
	virtual void attack() = 0;
	virtual void solo() = 0;
	virtual void defance() = 0;
	virtual void move() = 0;
	virtual void write_text() = 0;

protected:
	string name;
	one_uint who;
	int  price;

	//vector<int> pos;    //0 row    1  col   2  x   3  y 
	//vector<double>data;	//0 MAX_XL  1  MAX_AT   2  MAX_DF  3 XL   4 AT  5  DF
	vector<int>solo_CD;	// 0  solo_CD   1  solo_CD_begin
	vector<int>shoot_CD;  //0   shoot_CD   1  shoot_CD_begin
	bool    is_alive;
	bool    is_can_attack;
	bool    is_can_solo;	
	bool    is_can_move;
	virtual void push() = 0;
};



class P_shooter :public Plants
{
	static vector<P_shooter> all;
	Bullet *my_Bullets;
	int    what_bullet;
public:
	P_shooter(){
		name    = "";
		who.id  = "远程植物";
		who.type = 1;
		who.data = { 1500, 100, 500, 1500, 100, 500 };
		price  = 0;
		solo_CD = { 0, 0 };
		shoot_CD = { 0, 0 };
		is_alive = 1;
		is_can_attack=0;
		is_can_solo = 0;
		is_can_move = 0;
		what_bullet = 0;
		my_Bullets = new Org_pea;
	
	}
	~P_shooter(){
		/*delete my_Bullets;
		my_Bullets = NULL;*/
	}
	void clear()
	{
		for (size_t i = 0; i < all.size(); i++)
			all[i].my_Bullets->clear();
		all.clear();
	}
	void set_pos(const vector<int> & where)
	{
		who.pos = create_pos(where[0],where[1]);
		who.pos[3] += 2;
	}
	void set_shoot_cd(const vector<int> & a)
	{
		shoot_CD = a;
	}
	void set_data(const vector<double> &a)
	{
		who.data = a;
	}
	void create(const vector<int> & where, const int &b_type );
	void create_tmp(const vector<int> & where, const int &b_type);
	void del_one_object(const size_t &i)
	{
		size_t k = 0;
		vector<P_shooter>::iterator it;
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
	//获取函数
	int get_bullet_type()
	{
		return what_bullet;
	}
	Bullet *get_bullets()
	{
		return my_Bullets;
	}
	
	
	size_t get_num()
	{
		return all.size();
	}
	Plants *get_one_object(const size_t &i)
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
	int get_price()
	{
		return price;
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

	void move();
	void write_text();
private:
	void shoot();
protected:
	void push()
	{
		all.push_back(*this);
	}
};


////进程攻击
//class p_02 :public Plants
//{
//	static vector<p_02> all;
//	Bullet *my_Bullets;
//	int what_bullet;
//public:
//	p_02()
//	{
//		name = "窝瓜";
//		type = "近程植物";
//		price = 100;
//		MAX_XL = 100;
//		XL = 100;
//		AT = 200;
//		CD = 20;
//		CD_begin = 0;
//		is_alive = 1;
//		shine = 0;
//		CD_begin = 0;
//		what_bullet = 0;
//		my_Bullets = NULL;
//	
//	}
//	void select_tool(int i);
//	void set_cd(int mcd);
//	vector<int> set_pos(const vector<int> & where)
//	{
//		row = where[0];
//		col = where[1];
//		x = where[2];
//		y = where[3];
//	}
//	vector<int> get_pos()
//	{
//		vector<int> r;
//		r.push_back(row);
//		r.push_back(col);
//		r.push_back(x);
//		r.push_back(y);
//		return r;
//	}
//	void create(const int &a, const int &b);
//
//	void print();
//	void move()
//	{
//		//暂时不考虑植物移动
//	}
//	void attak()
//	{
//		shoot();
//	}
//	double get_AT()
//	{
//		return AT;
//	}
//	void shoot()
//	{
//		CD_begin++;
//		if (CD_begin == CD)
//		{
//			//发动攻击
//			
//			shine = 1;
//			CD_begin = 0;
//		}
//	}
//	void push()
//	{
//		all.push_back(*this);
//	}
//	size_t get_num()
//	{
//		return all.size();
//	}
//	Plants* get_one_object(size_t i)
//	{
//		return &all[i];
//	}
//	void del_one_object(size_t i)
//	{
//		size_t k = 0;
//		vector<p_02>::iterator it;
//		for (it = all.begin(); it != all.end(); it++, k++)
//		{
//			if (k == i)
//			{
//				it = all.erase(it);
//			}
//		}
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
//	Bullet* get_bullet()
//	{
//		return my_Bullets;
//	}
//	int get_bullet_type()
//	{
//		return what_bullet;
//	}
//};
//
//效果性
//向日葵
class Sunflower :public Plants
{
	static vector<Sunflower> all;
	static int all_sun;
	Bullet *my_Bullets;
	int    what_bullet;
public:
	Sunflower()
	{
		name = "向日葵";
		who.id = "经济性植物";
		who.type = 2;
		who.data = { 3500, 100, 500, 3500, 100, 500 };
		price = 50;
		solo_CD = { 30, 0 };
		shoot_CD = { 30, 0 };
		is_alive = 1;
		is_can_attack = 1;
		is_can_solo = 0;
		is_can_move = 0;
		what_bullet = 0;
		my_Bullets = NULL;

	}
	~Sunflower(){
		/*delete my_Bullets;
		my_Bullets = NULL;*/
	}

	void clear()
	{
		for (size_t i = 0; i < all.size(); i++)
			all[i].my_Bullets=NULL;
		all.clear();
	}

	void set_pos(const vector<int> & where)
	{
		who.pos = create_pos(where[0], where[1]);
		who.pos[3] += 2;
	}
	void set_shoot_cd(const vector<int> & a)
	{
		shoot_CD = a;
	}
	void set_data(const vector<double> &a)
	{
		who.data = a;
	}
	void create(const vector<int> & where, const int &b_type );
	void create_tmp(const vector<int> & where, const int &b_type );
	void del_one_object(const size_t &i)
	{
		size_t k = 0;
		vector<Sunflower>::iterator it;
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
	//获取函数
	int get_bullet_type()
	{
		return what_bullet;
	}
	Bullet *get_bullets()
	{
		return my_Bullets;
	}
	int get_sun()
	{
		int s=0;
		for (size_t s1 = 0; s1 < get_num(); s1++)
		{
			s += all[s1].all_sun;
		}
		return s;
	}

	size_t get_num()
	{
		return all.size();
	}
	Plants *get_one_object(const size_t &i)
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
	int get_price()
	{
		return price;
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

	void move();
	void write_text();

private:
	void shoot();
protected:
	void push()
	{
		all.push_back(*this);
	}
};


//大蒜
class Garlic :public Plants
{
	static vector<Garlic> all;
	Bullet *my_Bullets;
	int    what_bullet;
public:
	Garlic()
	{
		name = "大蒜";
		who.id = "攻击型";
		who.type = 60;
		who.data = { 3500, 100, 500, 3500, 100, 500 };
		price = 50;
		solo_CD = { 30, 0 };
		shoot_CD = { 30, 0 };
		is_alive = 1;
		is_can_attack = 1;
		is_can_solo = 0;
		is_can_move = 0;
		what_bullet = 0;
		my_Bullets = NULL;

	}
	~Garlic(){
		/*delete my_Bullets;
		my_Bullets = NULL;*/
	}
	void clear()
	{
		for (size_t i = 0; i < all.size(); i++)
			all[i].my_Bullets=NULL;
		all.clear();
	}
	void set_pos(const vector<int> & where)
	{
		who.pos = create_pos(where[0], where[1]);
		who.pos[3] += 2;
	}
	void set_shoot_cd(const vector<int> & a)
	{
		shoot_CD = a;
	}
	void set_data(const vector<double> &a)
	{
		who.data = a;
	}
	void create(const vector<int> & where, const int &b_type);
	void create_tmp(const vector<int> & where, const int &b_type);
	void del_one_object(const size_t &i)
	{
		size_t k = 0;
		vector<Garlic>::iterator it;
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
	//获取函数
	int get_bullet_type()
	{
		return what_bullet;
	}
	Bullet *get_bullets()
	{
		return my_Bullets;
	}
	

	size_t get_num()
	{
		return all.size();
	}
	Plants *get_one_object(const size_t &i)
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
	int get_price()
	{
		return price;
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

	void move();
	void write_text();

private:
	void shoot();
protected:
	void push()
	{
		all.push_back(*this);
	}
};







#endif 





