#include "User.h"
#include <fstream>
#include<time.h>
#include <Windows.h>


vector<Day> Day::all_days;
vector<User> User::all_user;
vector<User> User::present_user;





void Day::read_day()
{
	all_days.clear();
	ifstream in;
	in.open("./user_info/day.txt", ios::in);
	if (!in)
	{
		cout << "Can not create file \" login \" !" << endl;
		//exit(-1);
	}
	else
	{
		while (!in.eof())
		{
			Day d;
			in >> d.num >> d.level >> d.basic_reward >>d.name;
			all_days.push_back(d);
		}
	}
}

Day Day::get_today(size_t num)
{
	for (size_t i = 0; i < all_days.size(); i++)
	{
		if (all_days[i].num == num)
			return all_days[i];
	}
	return *this;
}



User::User()
{
	name = "无";
	pass_word = "";
	what_day = 0;
	money = 0;
}

void User::read_data()
{
	ifstream in;
	in.open("./user_info/data.txt", ios::in);
	if (!in)
	{
		cout << "Can not create file \" login \" !" << endl;
		//exit(-1);
	}
	else
	{
		while (!in.eof())
		{
			User u;
			in >> u.name >> u.pass_word >> u.what_day >> u.money;
			u.push();
		}
	}
}

int User::sign_up()
{
	system("cls");
	cout << "\t\t* * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "\t\t*                  注册                 *" << endl;
	cout << "\t\t* * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "\t\t* * * * * * * * * * * * * * * * * * * * *" << endl << endl << endl;

	ofstream f;
	f.open("./user_info/data.txt", ios::app);
	if (!f.is_open())
	{
		cout << "Can not create file \" login \" !" << endl;
		//exit(-1);
		return 0;
	}
	f << this->name<< " " << this->pass_word << " " << this->what_day << " " << this->money << endl;
	f.close();
	cout << endl << "注册成功!" << endl;
	
	cout << endl << "正在登录!" << endl;
	cout << endl << "正在进入游戏!" << endl;
	Sleep(2000);
	present_user.push_back(*this);
	return 1;
}



int User::log_in()
{
	system("cls");
	this->read_data();
	if (all_user.size() == 0)
	{
		cout << endl << endl << endl;
		cout << "\t\t★---------------------------------------------★" << endl;
		cout << "\t\t       当前没有已注册信息，请尝试注册！         " << endl;
		cout << "\t\t★---------------------------------------------★" << endl;
		cout << endl << "正在返回..." << endl;
		Sleep(3000);
		return 0;
	}
	vector<User> ::iterator it;
	for (it = all_user.begin(); it != all_user.end(); it++)
	{
		if (it->name == name&&it->pass_word== pass_word)
		{
			cout << endl << endl << endl;
			cout << "\t\t★---------------------------------------------★" << endl;
			cout << "\t\t\t            登陆成功 !!!         " << endl;
			cout << "\t\t★---------------------------------------------★" << endl;

			cout << endl << "正在进入游戏!" << endl;
			Sleep(2000);
			present_user.push_back(*this);
			return 1;
		}
	}
	cout << endl << endl << endl;
	cout << "\t\t★---------------------------------------------★" << endl;
	cout << "\t\t\t            玩家名或密码错误 !!!         " << endl;
	cout << "\t\t★---------------------------------------------★" << endl;

	cout << endl << "正在返回..." << endl;
	Sleep(2000);
	return 0;
}

void User::save_users()
{
	ofstream f;
	f.open("./user_info/data.txt", ios::out);
	if (!f.is_open())
	{
		cout << "Can not create file \" login \" !" << endl;
		//exit(-1);
		//return 0;
	}
	else
	{
		for (size_t i = 0; i < all_user.size(); i++)
		{
			f << all_user[i].name << " " << all_user[i].pass_word << " " << all_user[i].what_day << " " << all_user[i].money << endl;
		}	
	}
	
	f.close();
}

