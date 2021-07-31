#include "Control.h"
#include "UI.h"
#include"Lawn.h"
#include<ctime>
#include"User.h"



//产生随机数
int Random(const int &a, const int &b)
{
	int r = rand() % (b - a + 1) + a;
	return r;
}

//全局变量
int max_row = get_chicun()[0];
int max_col = get_chicun()[1];
//int current_row = 1;//这两个用来显示屏幕上当前位置，用来种植植物
//int current_col = 1;


//总阳光
int Sunlight = 500;
//游戏速度
int game_speed = 100;



void put_little_zombie()
{
	Lawn L;
	Zombies *p;
	
	srand((int)time(0));  // 产生随机种子  把0换成NULL也行
	int Zom_type=Random(1, 1);
	switch (Zom_type)
	{
	case 1:
	{
		p = new Ordinary;
		int Zom_tool = Random(0, 2);
		p->set_tool_type(Zom_tool);
		break;
	}
	case 2:
	{
		p = new Z_shooter;
		int Zom_tool = Random(1, 1);
		p->set_tool_type(Zom_tool);
		break;
	}
	default:
	{
		p = new Ordinary;
		int Zom_tool = Random(0, 2);
		p->set_tool_type(Zom_tool);
		break;
	}
	}
	vector<int> w;
	w = create_pos(Random(1, 5), Random(max_col + 2, max_col + 2));
	p->create(w);
	//将该僵尸加到所欲僵尸集合中
	L.add_one_zombie(p);
}

void put_plant(int plant_type,vector<int>postion,int bullet_type)
{
	Lawn L;
	Plants *p;

	switch (plant_type)
	{
	case 1:
	{
		p = new P_shooter;
		p->create(postion,bullet_type);
		break;
	}
	case 2:
	{
		p = new Sunflower;
		p->create(postion, bullet_type);
		break;
	}
	case 60:
	{
		p = new Garlic;
		p->create(postion, bullet_type);
		break;
	}
	
	default:
		break;
	}
	//将该植物加到所欲植物集合中
	L.add_one_plant(p);
}

int  is_can_settle(vector<int>&my_pos)
{
	MoveTo(2, 34);
	cout << "请选择位置：            ";
	
	MoveTo(14, 34);
	int x, y;
	cin >> x >> y;
	my_pos[0] = x;
	my_pos[1] = y;

	if (x < 0 || x>5 || y < 0 || y>9)
		return 0;
	Lawn L;
	int flg = 1;
	for (size_t i = 0; i < L.get_num(); i++)
	{
		for (size_t j = 0; j < L.all[i].what_P_AT.size(); j++)
		{
			if (L.all[i].what_P_AT[j].pos[0] == x&&L.all[i].what_P_AT[j].pos[1] == y&&L.all[i].what_P_AT[j].type < 50)
			{
				flg = 0;
				return 0;
			}
		}
	}
	return 1;

}

int  choose_plant(Plants *&p,vector<int> &pos)
{
	int result = 0;
	MoveTo(2, 33);
	cout << "请选择植物：         ";
	
	MoveTo(14, 33);
	int k;
	cin >> k;
	switch (k)
	{
	case 1:
	{
		p = new Sunflower;
		pos.push_back(1);
		pos.push_back(1);
		p->create_tmp(pos,0);//临时建立，不放入容器
		if (Sunlight - p->get_price() < 0)
		{
			MoveTo(14, 33);
			cout << "阳光不够！！！";
			Sleep(1000);
			MoveTo(14, 33);
			cout << "                  ";
			result = -1;
		}
		else
		{
			if (is_can_settle(pos) == 1)
			{
				result = 1;
			}
			else
			{
				MoveTo(14, 34);
				cout << "该位置不可用";
				Sleep(1000);
				MoveTo(14, 34);
				cout << "                ";
				result = 0;
			}
		}
		break;
	}
	case 2:
	{
		p = new P_shooter;
		pos.push_back(1);
		pos.push_back(1);
		p->create_tmp(pos, 51);//临时建立，不放入容器
		if (Sunlight - p->get_price() < 0)
		{
			MoveTo(14, 33);
			cout << "阳光不够！！！";
			Sleep(1000);
			MoveTo(14, 33);
			cout << "                  ";
			result = -1;
		}
		else
		{
			if (is_can_settle(pos) == 1)
			{
				result = 1;
			}
			else
			{
				MoveTo(14, 34);
				cout << "该位置不可用";
				Sleep(1000);
				MoveTo(14, 34);
				cout << "                ";
				result = 0;
			}
		}
		break;
	}
	case 3:
	{
		p = new P_shooter;
		pos.push_back(1);
		pos.push_back(1);
		p->create_tmp(pos, 52);//临时建立，不放入容器
		if (Sunlight - p->get_price() < 0)
		{
			MoveTo(14, 33);
			cout << "阳光不够！！！";
			Sleep(1000);
			MoveTo(14, 33);
			cout << "                  ";
			result = -1;
		}
		else
		{
			if (is_can_settle(pos) == 1)
			{
				result = 1;
			}
			else
			{
				MoveTo(14, 34);
				cout << "该位置不可用";
				Sleep(1000);
				MoveTo(14, 34);
				cout << "                ";
				result = 0;
			}
		}
		break;
	}
	case 4:
	{
		p = new P_shooter;
		pos.push_back(1);
		pos.push_back(1);
		p->create_tmp(pos, 53);//临时建立，不放入容器
		if (Sunlight - p->get_price() < 0)
		{
			MoveTo(14, 33);
			cout << "阳光不够！！！";
			Sleep(1000);
			MoveTo(14, 33);
			cout << "                  ";
			result = -1;
		}
		else
		{
			if (is_can_settle(pos) == 1)
			{
				result = 1;
			}
			else
			{
				MoveTo(14, 34);
				cout << "该位置不可用";
				Sleep(1000);
				MoveTo(14, 34);
				cout << "                ";
				result = 0;
			}
		}
		break;
	}
	case 5:
	{
		p = new Garlic;
		pos.push_back(1);
		pos.push_back(1);
		p->create_tmp(pos, 60);//临时建立，不放入容器
		if (Sunlight - p->get_price() < 0)
		{
			MoveTo(14, 33);
			cout << "阳光不够！！！";
			Sleep(1000);
			MoveTo(14, 33);
			cout << "                  ";
			result = -1;
		}
		else
		{
			if (is_can_settle(pos) == 1)
			{
				result = 1;
			}
			else
			{
				MoveTo(14, 34);
				cout << "该位置不可用";
				Sleep(1000);
				MoveTo(14, 34);
				cout << "                ";
				result = 0;
			}
		}
		break;
	}


	default:
		break;
	}
	return result;
}




//键盘事件处理
int get_order()
{
	int r = 0;
	vector<int> jianpanma1 = { 87, 119, 83, 115, 65, 97, 68, 100, 112, 80, 32, 61, 45, 13, 27 };
	vector<int>  zhiling   = { 2,   2,   3,    3, 4,  4, 5,   5,   6,   6, 7,  19, 20,  9, 10 };
	vector<int> jianpanma2 = { 72, 80, 75, 77,83, 73 , 81,134,133,68,67,66,65 };
	vector<int> zhiling2   = { 2 , 3 , 4 , 5 , 8, 11 , 12 ,13,14 ,15,16,17,18};
	int key1 = _getch();
	for (size_t i = 0; i < jianpanma1.size(); i++)
	{
		if (jianpanma1[i] == key1)
		{
			r = zhiling[i];
		}
	}
	if (key1==0||key1==224)
	{
		int key2 = _getch();
		for (size_t i = 0; i < jianpanma2.size(); i++)
		{
			if (jianpanma2[i] == key2)
			{
				r = zhiling2[i];
			}
		}
	}
	return r;
}

//实现命令
int manipulate_order()
{
	int what=get_order();
	int status = 0;
	switch (what)
	{
	case 0:
	{

		break;
	}
	case 1:
	{

		break;
	}
	case 2:
	{

		break;
	}
	case 3:
	{

		break;
	}
	case 4:
	{

		break;
	}
	case 5:
	{

		break;
	}
	case 6:
	{
		//游戏暂停
		while (1)
		{
			if (get_order() == 6)
				break;
		}
		break;
	}
	case 7:
	{
		//进入商店
		while (1)
		{
			MoveTo(2, 32);
			cout << "按“Enter键”开始购买，按“Esc键”退出商店：";
			while (1)
			{
				if (_kbhit())
					break;
			}
			int k = get_order();
			MoveTo(2, 32);
			cout << "                                             ";
			//开始判断
			if (k == 10)
				break;
			else if (k == 9)
			{
				Plants *p = new P_shooter;
				vector<int>pos;
				if (choose_plant(p, pos) == 1)
				{
					Sunlight -= p->get_price();
					put_plant(p->get_who().type, pos, p->get_bullet_type());
					MoveTo(14, 34);
					cout << "种植成功！";
					Sleep(1000);
					MoveTo(14, 34);
					cout << "                 ";
					//清除选择植物
					MoveTo(2, 33);
					cout << "                                ";
					//清除选择位置
					MoveTo(2, 34);
					cout << "                                ";
				}
			}		
		}
		break;
	}
	case 8:
	{

		break;
	}
	case 9:
	{

		break;
	}
	case 10:
	{

		break;
	}
	case 11:
	{

		break;
	}
	case 12:
	{

		break;
	}
	case 13:
	{

		break;
	}
	case 14:
	{

		break;
	}
	case 15:
	{

		break;
	}
	case 16:
	{

		break;
	}
	case 17:
	{

		break;
	}
	case 18:
	{

		break;
	}
	case 19:
	{
		//游戏加延迟
		if (game_speed < 500)
			game_speed += 50;
		break;
		
	}
	case 20:
	{
		//游戏减延迟
		if (game_speed > 100)
			game_speed -= 50;
		break;
	}
	default:
		break;
	}
	return status;
}

void play()
{
	//初始化，添加5*9个草坪
	Lawn my_lawn;
	my_lawn.init_lawn();

	//定义随机出现僵尸的间隔
	int Zom_CD = 70;
	int Zom_count = 0;
	//定义随机产生阳光的间隔
	int Sun_CD = 150;
	int Sun_CD_count = 0;

	//导入玩家信息
	User me;
	me = me.get_me();
	Day my_day;
	my_day.read_day();
	my_day = my_day.get_today(me.what_day);

	//判断游戏结束条件
	int is_game_over = 0;
	//开始循环进行游戏
	while (1)
	{
		//界面维护
		//标题、关卡及玩家信息界面
		MoveTo(55, 1);
		cout << "植物大战僵尸（ASJ版1.1.0）";
		MoveTo(0, 2);
		cout << "第 "<<my_day.num<<" 天："<<"\t"<<my_day.name;
		MoveTo(0, 3);
		cout << "难度：" << my_day.level << "    " <<"\t"<<"基础奖励:" << my_day.basic_reward;
		MoveTo(40, 3);
		cout << "游戏速度延迟：" << game_speed;

		MoveTo(148, 1);
		cout << me.name;
		MoveTo(148, 2);
		cout << me.money;
		//商店界面
		//获取阳光
		Sunflower s;
		Sunlight += s.get_sun();
		if (Sun_CD_count == Sun_CD)
		{
			Sunlight += 100;
		}
		Sun_CD_count++;
		MoveTo(80, 32);
		cout << "阳光总量："<< Sunlight;
		MoveTo(5, 36);
		cout <<" 1.向日葵     2.豌豆射手      3.寒冰射手     4.西瓜    5.大蒜";
		MoveTo(5, 37);
		cout << "   100           125              50           200       50";
		
		//游戏结束检测
		if (is_game_over == 1)
		{
			game_over();
			me.save_users();
			break;
		}

		//交互
		if (_kbhit())
		{
			manipulate_order();
		}
		//随机产生僵尸
		if (Zom_count == Zom_CD)
		{
			put_little_zombie();
			Zom_count = 0;
		}
		Zom_count++;


		//------打架--------
		my_lawn.p_attack_Z();
		//my_lawn.update_lawn();
		my_lawn.print_lawn();

		my_lawn.z_attack_p();
		//my_lawn.update_lawn();
		my_lawn.print_lawn();

		is_game_over=my_lawn.all_move();

		//更新，打印
		my_lawn.update_lawn();
		my_lawn.print_lawn();

		//游戏速度体现
		Sleep(game_speed);	
	}


	//cout << "欢迎下次再来！" << endl;

}


void game_over()
{
	vector<string>over;
	read_pic("./pic/over.txt", over);
	for (size_t j = 10; j < 15+over.size(); j++)
	{
		MoveTo(30, j); 
		cout << "                                                                           ";
	}
	print_letter(30,10,over);
}