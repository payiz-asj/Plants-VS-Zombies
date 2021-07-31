
#ifndef  ASJ_LAWN
#define  ASJ_LAWN

#include "UI.h"

#include <Windows.h>
#include <string>
#include <tchar.h>
#include <time.h>
#include<vector>
#include <iostream>
#include <conio.h>
#include<fstream>
using namespace std;

class Zombies;
class Plants;


struct one_uint
{
	string id;
	vector<int>pos;
	int    type;
	vector<double> data;
};






class Lawn
{
public:
	static vector<Lawn> all;
	vector<int>pos;     //0  row    1    col
	//一块草坪所包含的植物、僵尸
	vector<one_uint>what_P_AT;    
	vector<one_uint>what_Z_AT;

	
	//颜色，待考虑

	Lawn()
	{

	}
	~Lawn()
	{

	}
	//初始化所有草坪
	void init_lawn();
	//添加一个植物、僵尸
	void add_one_zombie(Zombies *p);
	void add_one_plant(Plants *p);
	//1：植物打僵尸,僵尸承受
	void p_attack_Z();
	//2：僵尸打植物，植物承受
	void z_attack_p();
	//3：植物和僵尸移动
	int all_move();
	//4: 更新草坪
	void update_lawn();
	void plant_attack(one_uint who);
	void zombie_attack(one_uint who);
	//5: 打印草坪
	void print_lawn();

	

	void chage_plant_text(vector<Plants *>all_P);
	void chage_zombie_text(vector<Zombies *> all_Z);
	void set_pos(const vector<int> & where)
	{
		pos = where;
	}
	void push()
	{
		all.push_back(*this);
	}

	
	void del_zombie_attack(const int &a, const double&b);
	void del_plant_attack(const int &a, const double&b);
	Lawn get_one_object(const size_t &i);
	void del_one_object(const size_t &i);
	void del_one_plant(const size_t &i);
	void del_one_zombie(const size_t &i);


	size_t get_num()
	{
		return all.size();
	}
	vector<int> get_pos()
	{
		return pos;
	}



};




#endif 