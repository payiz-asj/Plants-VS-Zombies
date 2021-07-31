#pragma once 
#ifndef  ASJ_USER
#define  ASJ_USER

#include <string>
#include <time.h>
#include<vector>
#include <iostream>
#include <conio.h>
using namespace std;


class Day
{
public:
	Day()
	{
		num = 0;
		level = 0;
		basic_reward = 0;
		name = "нч";
	}
	static vector<Day>all_days;
	int num;
	int level;
	double basic_reward;
	string name;

	void read_day();
	Day get_today(size_t num);



};


class User
{
public:
	User();
	~User(){}
	static vector<User>all_user;
	static vector<User>present_user;
	string name;
	string pass_word;
	double money;
	size_t    what_day;
	void read_data();
	int sign_up();
	int  log_in();
	void push()
	{
		all_user.push_back(*this);
	}
	User get_me()
	{
		if (present_user.size() > 0)
			return present_user[0];
		else
			return *this;
	}
	void save_users();
};












#endif