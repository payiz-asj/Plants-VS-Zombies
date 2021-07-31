#include "Plant.h"
#include "UI.h"
#include"Lawn.h"

//静态变量初始化区
vector<P_shooter> P_shooter::all;
//vector<p_02> p_02::all;
vector<Sunflower> Sunflower::all;
vector<Garlic> Garlic::all;
int Sunflower::all_sun = 0;





//所有工具类的实现区
//远程
void P_shooter::create(const vector<int> & where, const int &b_type)
{
	what_bullet = b_type;
	switch (what_bullet)
	{
	case 51:
	{
		my_Bullets = new Org_pea;
		break;
	}
	case 52:
	{
		my_Bullets = new Snow_pea;
		break;
	}
	case 53:
	{
		my_Bullets = new Melon;
		break;
	}
	default:
	{
		my_Bullets = new Org_pea;
		break;
	}
	}

	this->set_pos(where);
	this->shoot_CD[0] = my_Bullets->get_cd()[0];
	name = my_Bullets->get_name() + name;
	price = my_Bullets->get_price();
	this->set_data(my_Bullets->get_who().data);
	this->push();
}

void P_shooter::create_tmp(const vector<int> & where, const int &b_type)
{
	//这里只是假装种植一下，不放入容器，目的是看一下配备该子弹后的总价钱
	what_bullet = b_type;
	switch (what_bullet)
	{
	case 0:
	{
		my_Bullets = new Org_pea;
		break;
	}
	/*case 1:
	{
	my_Bullets = new Snow_pea;
	my_Bullets->create(w);
	break;
	}
	case 2:
	{
	my_Bullets = new Melon;
	my_Bullets->create(w);
	break;
	}*/
	default:
	{
		my_Bullets = new Org_pea;
		break;
	}
	}

	this->set_pos(where);
	this->shoot_CD[0] = my_Bullets->get_cd()[0];
	name = my_Bullets->get_name() + name;
	price = my_Bullets->get_price();
}

void P_shooter::print()
{
	MoveTo(get_who().pos[2], get_who().pos[3]);
	cout << name;
	Bullet *b;
	for (size_t i = 0; i < my_Bullets->get_num(); i++)
	{
		b = my_Bullets->get_one_object(i);
		if (b->get_is_can()[0] == 0)
		{
			MoveTo(b->get_who().pos[2], b->get_who().pos[3]);
			string kongge = "";
			for (size_t k = 0; k < b->get_name().size(); k++)
				kongge += " ";
			cout << kongge;
			b->del_one_object(i);
		}
		else
			b->print();
	}
}

void P_shooter::attack()
{
	//这类植物的攻击是发射子弹
	Lawn L;
	is_can_attack = 0;
	for (size_t j = 0; j < L.get_num(); j++)
	{
		//查看所在一行有无僵尸
		if (L.all[j].pos[0] == get_who().pos[0])
		{
			for (size_t k = 0; k < L.all[j].what_Z_AT.size(); k++)
			{
				if (L.all[j].what_Z_AT[k].type < 50)
					is_can_attack = 1;
			}
		}
	}
	if (is_can_attack == 1)
	{
		shoot();
	}

	
}

void P_shooter::shoot()
{
	shoot_CD[1]++;
	if (shoot_CD[1] == shoot_CD[0])
	{
		vector<int> w;
		w = create_pos(who.pos[0], who.pos[1] + 1);
		my_Bullets->create(w);
		shoot_CD[0] = my_Bullets->get_cd()[0];
		shoot_CD[1] = 0;
	}
}

void P_shooter::defance()
{
	Lawn L;
	for (size_t j = 0; j < L.get_num(); j++)
	{
		//找到该植物当前
		if (L.all[j].pos[0] == get_who().pos[0] && L.all[j].pos[1] == get_who().pos[1])
		{
			for (size_t k = 0; k < L.all[j].what_Z_AT.size(); k++)
			{
				//如果是僵尸的攻击（子弹或其他）
				if (L.all[j].what_Z_AT[k].type >50 && L.all[j].what_P_AT[k].type < 60)
				{
					//这是子弹的直接伤害
					vector<double>my_data = get_who().data;
					if (L.all[j].what_Z_AT[k].type < 60)
					{
						if (my_data[5] > L.all[j].what_Z_AT[k].data[4])
						{
							my_data[5] -= L.all[j].what_Z_AT[k].data[4];
						}
						else
						{
							my_data[5] = 0;
							my_data[3] -= L.all[j].what_Z_AT[k].data[4] - my_data[5];
						}
						set_data(my_data);
					}
					else if (L.all[j].what_P_AT[k].type == 60)
					{
						//这是压扁,直接死
					}
					else
					{
						//这里可能有眩晕
					}
				}
				else
				{
					//僵尸本尊
					vector<double>my_data = get_who().data;
					if (my_data[5] > L.all[j].what_Z_AT[k].data[4])
					{
						my_data[5] -= L.all[j].what_Z_AT[k].data[4];
					}
					else
					{
						my_data[5] = 0;
						my_data[3] -= L.all[j].what_Z_AT[k].data[4] - my_data[5];
					}
					set_data(my_data);
				}
			}
			if (get_who().data[3] < 0)
				is_alive = 0;
		}
	}

	
}

void P_shooter::move()
{
	Bullet *b;
	for (size_t i = 0; i < my_Bullets->get_num(); i++)
	{
		b = my_Bullets->get_one_object(i);
		if (b->get_is_can()[0] == 0)
		{
			MoveTo(b->get_who().pos[2], b->get_who().pos[3]);
			string kongge = "";
			for (size_t k = 0; k < b->get_name().size(); k++)
				kongge += " ";
			cout << kongge;
			b->del_one_object(i);
		}
		else
			b->move();
	}
}

void P_shooter::write_text()
{
	/*Lawn L;
	string name = "./Law/";
	int i = (pos[0] - 1)*get_screen_data()[2] + pos[1];
	string n1 = name + to_string(i) + "- plants.txt";
	ofstream out1;
	out1.open(n1, ios::app);
	if (!out1.is_open())
	{
	cout << "系统文件写入失败，无法加载游戏！";
	exit(-1);
	}
	out1 << ID << data[0] << " " << data[1] << " " << data[2] << " " << data[3] << " " << data[4] << " " << data[5] << endl;
	*/
	//my_Bullets->write_text();
}

//向日葵
void Sunflower::create(const vector<int> & where, const int &b_type)
{
	this->set_pos(where);
	this->push();
}

void Sunflower::create_tmp(const vector<int> & where, const int &b_type)
{
	//这里只是假装种植一下，不放入容器，目的是看一下配备该子弹后的总价钱
	this->set_pos(where);
}

void Sunflower::print()
{
	MoveTo(get_who().pos[2], get_who().pos[3]);
	cout << name;
}

void Sunflower::attack()
{
	//这个植物的攻击是产生阳光
	if (is_can_attack == 1)
	{
		shoot();
	}
}

void Sunflower::shoot()
{
	all_sun = 0;
	shoot_CD[1]++;
	if (shoot_CD[1] == shoot_CD[0])
	{
		all_sun = 25;
		shoot_CD[1] = 0;
	}
}

void Sunflower::defance()
{
	Lawn L;
	for (size_t j = 0; j < L.get_num(); j++)
	{
		//找到该植物前一个草坪
		if (L.all[j].pos[0] == get_who().pos[0] && L.all[j].pos[1] == get_who().pos[1])
		{
			for (size_t k = 0; k < L.all[j].what_Z_AT.size(); k++)
			{
				//如果是僵尸的攻击（子弹或其他）
				if (L.all[j].what_Z_AT[k].type >50 && L.all[j].what_P_AT[k].type < 60)
				{
					//这是子弹的直接伤害
					vector<double>my_data = get_who().data;
					if (L.all[j].what_Z_AT[k].type < 60)
					{
						if (my_data[5] > L.all[j].what_Z_AT[k].data[4])
						{
							my_data[5] -= L.all[j].what_Z_AT[k].data[4];
						}
						else
						{
							my_data[5] = 0;
							my_data[3] -= L.all[j].what_Z_AT[k].data[4] - my_data[5];
						}
					}
					else if (L.all[j].what_P_AT[k].type == 60)
					{
						//这是压扁,直接死
					}
					else
					{
						//这里可能有眩晕
					}
				}
				else
				{
					//僵尸本尊
					vector<double>my_data = get_who().data;
					if (my_data[5] > L.all[j].what_Z_AT[k].data[4])
					{
						my_data[5] -= L.all[j].what_Z_AT[k].data[4];
					}
					else
					{
						my_data[5] = 0;
						my_data[3] -= L.all[j].what_Z_AT[k].data[4] - my_data[5];
					}
					set_data(my_data);
				}
			}
			if (get_who().data[3] < 0)
				is_alive = 0;
		}
	}

	
}

void Sunflower::move()
{
	//wu
}

void Sunflower::write_text()
{
	/*Lawn L;
	string name = "./Law/";
	int i = (pos[0] - 1)*get_screen_data()[2] + pos[1];
	string n1 = name + to_string(i) + "- plants.txt";
	ofstream out1;
	out1.open(n1, ios::app);
	if (!out1.is_open())
	{
		cout << "系统文件写入失败，无法加载游戏！";
		exit(-1);
	}
	out1 << ID << data[0] << " " << data[1] << " " << data[2] << " " << data[3] << " " << data[4] << " " << data[5] << endl;
*/
	//my_Bullets->write_text();
}

//大蒜
void Garlic::create(const vector<int> & where, const int &b_type)
{
	this->set_pos(where);
	this->push();
}

void Garlic::create_tmp(const vector<int> & where, const int &b_type)
{
	//这里只是假装种植一下，不放入容器，目的是看一下配备该子弹后的总价钱
	this->set_pos(where);
}

void Garlic::print()
{
	MoveTo(get_who().pos[2], get_who().pos[3]);
	cout << name;
}

void Garlic::attack()
{
	//大蒜的攻击其实是自己的消亡
	Lawn L;
	is_can_attack = 0;
	for (size_t j = 0; j < L.get_num(); j++)
	{
		//查看所在草坪有无僵尸，即僵尸咬一口
		if (L.all[j].pos[0] == get_who().pos[0] && L.all[j].pos[1] == get_who().pos[1])
		{
			for (size_t k = 0; k < L.all[j].what_Z_AT.size(); k++)
			{
				if (L.all[j].what_Z_AT[k].type < 50)
					is_can_attack = 1;
			}
		}
	}
	if (is_can_attack == 1)
	{
		shoot();
	}
}

void Garlic::shoot()
{
	shoot_CD[1]++;
	if (shoot_CD[1] == shoot_CD[0])
	{
		is_alive = 0;
	}
}

void Garlic::defance()
{
	//Lawn L;
	//for (size_t j = 0; j < L.get_num(); j++)
	//{
	//	//找到该植物前一个草坪
	//	if (L.all[j].pos[0] == get_who().pos[0] && L.all[j].pos[1] == get_who().pos[1])
	//	{
	//		for (size_t k = 0; k < L.all[j].what_Z_AT.size(); k++)
	//		{
	//			//如果是僵尸的攻击（子弹或其他）
	//			if (L.all[j].what_Z_AT[k].type >50 && L.all[j].what_P_AT[k].type < 60)
	//			{
	//				//这是子弹的直接伤害
	//				vector<double>my_data = get_who().data;
	//				if (L.all[j].what_Z_AT[k].type < 60)
	//				{
	//					if (my_data[5] > L.all[j].what_Z_AT[k].data[4])
	//					{
	//						my_data[5] -= L.all[j].what_Z_AT[k].data[4];
	//					}
	//					else
	//					{
	//						my_data[5] = 0;
	//						my_data[3] -= L.all[j].what_Z_AT[k].data[4] - my_data[5];
	//					}
	//					set_data(my_data);
	//				}
	//				else if (L.all[j].what_P_AT[k].type == 60)
	//				{
	//					//这是压扁,直接死
	//				}
	//				else
	//				{
	//					//这里可能有眩晕
	//				}
	//			}
	//			else
	//			{
	//				//僵尸本尊
	//				vector<double>my_data = get_who().data;
	//				if (my_data[5] > L.all[j].what_Z_AT[k].data[4])
	//				{
	//					my_data[5] -= L.all[j].what_Z_AT[k].data[4];
	//				}
	//				else
	//				{
	//					my_data[5] = 0;
	//					my_data[3] -= L.all[j].what_Z_AT[k].data[4] - my_data[5];
	//				}
	//				set_data(my_data);
	//			}
	//		}
	//		if (get_who().data[3] < 0)
	//			is_alive = 0;
	//	}
	//}

	//Lawn L;
	//for (size_t i = 0; i < this->get_num(); i++)
	//{
	//	for (size_t j = 0; j < L.get_num(); j++)
	//	{
	//		//找到该植物前一个草坪
	//		if (L.all[j].pos[0] == all[i].get_who().pos[0] && L.all[j].pos[1] == all[i].get_who().pos[1]+1)
	//		{
	//			for (size_t k = 0; k < L.all[j].what_Z_AT.size(); k++)
	//			{
	//				//如果是僵尸的攻击（子弹或其他）
	//				if (L.all[j].what_Z_AT[k].type >50 && L.all[j].what_P_AT[k].type < 60)
	//				{
	//					//这是子弹的直接伤害
	//					if (L.all[j].what_Z_AT[k].type < 60)
	//					{
	//						if (all[i].get_who().data[5] > L.all[j].what_Z_AT[k].data[4])
	//						{
	//							all[i].get_who().data[5] -= L.all[j].what_Z_AT[k].data[4];
	//						}
	//						else
	//						{
	//							all[i].get_who().data[5] = 0;
	//							all[i].get_who().data[3] -= L.all[j].what_Z_AT[k].data[4] - all[i].get_who().data[5];
	//						}
	//					}
	//					else if (L.all[j].what_P_AT[k].type == 60)
	//					{
	//						//这是压扁,直接死
	//					}
	//					else
	//					{
	//						//这里可能有眩晕
	//					}
	//				}
	//				else
	//				{
	//					//僵尸本尊
	//					if (all[i].get_who().data[5] > L.all[j].what_Z_AT[k].data[4])
	//					{
	//						all[i].get_who().data[5] -= L.all[j].what_Z_AT[k].data[4];
	//					}
	//					else
	//					{
	//						all[i].get_who().data[5] = 0;
	//						all[i].get_who().data[3] -= L.all[j].what_Z_AT[k].data[4] - all[i].get_who().data[5];
	//					}
	//				}
	//			}
	//			if (all[i].get_who().data[3] < 0)
	//				all[i].is_alive = 0;
	//		}
	//	}
	//}
}

void Garlic::move()
{
	//wu
}

void Garlic::write_text()
{
	/*Lawn L;
	string name = "./Law/";
	int i = (pos[0] - 1)*get_screen_data()[2] + pos[1];
	string n1 = name + to_string(i) + "- plants.txt";
	ofstream out1;
	out1.open(n1, ios::app);
	if (!out1.is_open())
	{
	cout << "系统文件写入失败，无法加载游戏！";
	exit(-1);
	}
	out1 << ID << data[0] << " " << data[1] << " " << data[2] << " " << data[3] << " " << data[4] << " " << data[5] << endl;
	*/
	//my_Bullets->write_text();
}


