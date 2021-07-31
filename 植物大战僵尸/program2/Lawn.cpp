#include"Lawn.h"
#include"Plant.h"
#include"Zombie.h"


vector<Plants *> all_plants;
vector<Zombies *> all_zombies;


vector<Lawn> Lawn::all;

void Lawn::init_lawn()
{
	//ɾ��������һ�δ�����ֲ��ͽ�ʬ
	for (size_t p_i = 0; p_i < all_plants.size(); p_i++)
	{
		all_plants[p_i]->clear();
	}
	for (size_t z_i = 0; z_i < all_zombies.size(); z_i++)
	{
		all_zombies[z_i]->clear();
	}
	all_plants.clear();
	all_zombies.clear();

	//������ƺ
	int max_row = get_chicun()[0];
	int max_col = get_chicun()[1];
	for (int i = 1; i <= max_row; i++)
	{
		for (int j = 1; j <= max_col; j++)
		{
			Lawn *L = new Lawn;
			L->pos = create_pos(i, j);
			L->push();
		}
	}
	//������ƺ�Ĵ洢�ļ�
	/*ofstream out1, out2;
	string name = "./Law/";
	for (size_t i = 0; i < all.size(); i++)
	{
		string n1 = name + to_string(i + 1) + "-plants.txt";
		string n2 = name + to_string(i + 1) + "-zombies.txt";
		out1.open(n1, ios::out);
		out2.open(n2, ios::out);
		if (!out1.is_open())
		{
			cout << "�����ڴ治����ϵͳ�ļ�����ʧ�ܣ��޷�������Ϸ��";
			exit(-1);
		}
		if (!out2.is_open())
		{
			cout << "�����ڴ治����ϵͳ�ļ�����ʧ�ܣ��޷�������Ϸ��";
			exit(-1);
		}
		out1.close();
		out2.close();
	}*/
}
void Lawn::plant_attack(one_uint who)
{
	what_P_AT.push_back(who);
}

void Lawn::zombie_attack(one_uint who)
{
	what_Z_AT.push_back(who);
}
void Lawn::add_one_zombie(Zombies *p)
{
	all_zombies.push_back(p);
}
void Lawn::add_one_plant(Plants *p)
{
	all_plants.push_back(p);
}

void Lawn::p_attack_Z()
{
	//��������ֲ�﷢�ӹ�������Ч��
	for (size_t i = 0; i < all_plants.size(); i++)
	{
		Plants *p;
		for (size_t j2 = 0; j2 < all_plants[i]->get_num(); j2++)
		{
			p = all_plants[i]->get_one_object(j2);

			//ֻ��ֲ���й�������Ч�����ӵ�û��
			if (p->get_who().type < 50)
			{
				//if (p->get_is_can()[1]==1)
					p->attack();
			}
			else if (p->get_who().type ==60)
				p->attack();
		}
	}
	//�����ý�ʬ���з���
	for (size_t i = 0; i < all_zombies.size(); i++)
	{
		Zombies *p;
		for (size_t j2 = 0; j2 < all_zombies[i]->get_num(); j2++)
		{
			p = all_zombies[i]->get_one_object(j2);
			//ֻ�н�ʬ�з�������ʬ���ӵ�û��
			if (p->get_who().type < 50)
			{
					p->defance();
			}
		}
	}

}

void Lawn::z_attack_p()
{
	//�������ý�ʬ���ӹ�������Ч��
	for (size_t i = 0; i < all_zombies.size(); i++)
	{
		Zombies *p;
		for (size_t j2 = 0; j2 < all_zombies[i]->get_num(); j2++)
		{
			p = all_zombies[i]->get_one_object(j2);
			//ֻ�н�ʬ�й�������Ч������ʬ���ӵ�û��
			if (p->get_who().type < 50)
			{
				//if (p->get_is_can()[1] == 1)
					p->attack();
			}
		}
	}
	//������ֲ����з���
	for (size_t i = 0; i < all_plants.size(); i++)
	{
		Plants *p;
		for (size_t j2 = 0; j2 < all_plants[i]->get_num(); j2++)
		{
			p = all_plants[i]->get_one_object(j2);
			//ֻ��ֲ���з������ӵ�û��
			if (p->get_who().type < 50)
			{
				p->defance();
			}
		}
	}
}

int Lawn::all_move()
{
	int is_game_over = 0;
	for (size_t i = 0; i < all_plants.size(); i++)
	{
		Plants *p;
		for (size_t j2 = 0; j2 < all_plants[i]->get_num(); j2++)
		{
			p = all_plants[i]->get_one_object(j2);
			//if (p->get_is_can()[3] == 1)   ������Ҫע�ͣ���Ϊֲ�ﱾ���ƶ������ӵ��ƶ�
				p->move();
				
		}
	}
	int tmp;
	for (size_t i = 0; i < all_zombies.size(); i++)
	{
		Zombies *p;
		for (size_t j2 = 0; j2 < all_zombies[i]->get_num(); j2++)
		{
			p = all_zombies[i]->get_one_object(j2);
			if (p->get_is_can()[3] == 1)
				tmp=p->move();
			if (tmp == 1)
				is_game_over = 1;
		}
	}
	return is_game_over;
}

void Lawn::update_lawn()
{
	//�ȸ�ʽ����ƺ��ɾ��ԭ״̬
	for (size_t i = 0; i < this->get_num(); i++)
	{
		all[i].what_P_AT.clear();
		all[i].what_Z_AT.clear();
	}
	

	//�ȸ���һ��ֲ��
	for (size_t i = 0; i < this->get_num(); i++)
	{
		for (size_t j = 0; j < all_plants.size(); j++)
		{
			Plants *p;
			for (size_t j2 = 0; j2 < all_plants[j]->get_num(); j2++)
			{
				p = all_plants[j]->get_one_object(j2);

				//�ҵ��ò�ƺ�ϵ�ֲ��
				if (p->get_who().pos[0] == all[i].pos[0] && p->get_who().pos[1] == all[i].pos[1])
				{
					//������Զ��ֲ��
					if (p->get_who().type == 1)
					{
						all[i].plant_attack(p->get_who());
						//�����Զ��ֲ�����ӵ�
						//int how_many = p->get_bullets()->get_num();
						//���������
						if (p->get_bullet_type() == 52)
						{
							if (p->get_bullets()->get_num()>0)
							{
								//�������ֲ��������ӵ�
								Bullet *b;
								Lawn LL;
								for (size_t kk = 0; kk < p->get_bullets()->get_num(); kk++)
								{
									b = p->get_bullets()->get_one_object(kk);
									for (size_t jj = 0; jj < LL.get_num(); jj++)
									{
										if (b->get_who().pos[0] == LL.all[jj].pos[0] && b->get_who().pos[1] == LL.all[jj].pos[1])
										{
											LL.all[jj].plant_attack(b->get_who());
										}
										//��һ��
										if (b->get_who().pos[0]+1 == LL.all[jj].pos[0] && b->get_who().pos[1] == LL.all[jj].pos[1])
										{
											LL.all[jj].plant_attack(b->get_who());
										}
										//��һ��
										if (b->get_who().pos[0] -1 == LL.all[jj].pos[0] && b->get_who().pos[1] == LL.all[jj].pos[1])
										{
											LL.all[jj].plant_attack(b->get_who());
										}
									}
								}
							}
							else
							{
								//�����Զ��ֲ��û���ӵ�
							}
						}
						else
						{
							if (p->get_bullets()->get_num()>0)
							{
								//�������ֲ��������ӵ�
								Bullet *b;
								Lawn LL;
								for (size_t kk = 0; kk < p->get_bullets()->get_num(); kk++)
								{
									b = p->get_bullets()->get_one_object(kk);
									for (size_t jj = 0; jj < LL.get_num(); jj++)
									{
										if (b->get_who().pos[0] == LL.all[jj].pos[0] && b->get_who().pos[1] == LL.all[jj].pos[1])
										{
											LL.all[jj].plant_attack(b->get_who());
										}
									}
								}
							}
							else
							{
								//�����Զ��ֲ��û���ӵ�
							}
						}
					}
					else
					{
						//�����ǽ��̻�����������ֲ��
						all[i].plant_attack(p->get_who());
					}
				}
			}
		}
	}
	
	//�ø��½�ʬ��
	for (size_t i = 0; i < this->get_num(); i++)
	{
		for (size_t j = 0; j < all_zombies.size(); j++)
		{
			Zombies *p;
			for (size_t j2 = 0; j2 < all_zombies[j]->get_num(); j2++)
			{
				p = all_zombies[j]->get_one_object(j2);
				//�ҵ��ǲ�ƺ�ϵĽ�ʬ
				int kkk = p->get_who().pos[0];
				int yyyy = p->get_who().pos[1];
				if (p->get_who().pos[0] == all[i].pos[0] && p->get_who().pos[1] == all[i].pos[1])
				{
					//������Զ�̽�ʬ
					if (p->get_who().type == 2)
					{
						all[i].zombie_attack(p->get_who());
						//�����Զ�̽�ʬ���ӵ�
						int how = p->get_tools()->get_num();
						if (p->get_tools()->get_num()>0)
						{
							//���������ʬ�������ӵ�
							Tool *b;
							Lawn LL;
							for (size_t kk = 0; kk < p->get_tools()->get_num(); kk++)
							{
								b = p->get_tools()->get_one_object(kk);
								for (size_t jj = 0; jj < LL.get_num(); jj++)
								{
									if (b->get_who().pos[0] == LL.all[jj].pos[0] && b->get_who().pos[1] == LL.all[jj].pos[1])
									{
										LL.all[jj].zombie_attack(b->get_who());
									}
								}
							}
						}
						else
						{
							//�����Զ�̽�ʬû���ӵ�
						}
					}
					else
					{
						//�����ǽ��̻����������ͽ�ʬ
						all[i].zombie_attack(p->get_who());

					}
				}
			}
		}
	}
}


void Lawn::print_lawn()
{
	for (size_t i = 0; i < all_plants.size(); i++)
	{
		Plants *p;
		for (size_t j2 = 0; j2 < all_plants[i]->get_num(); j2++)
		{
			p = all_plants[i]->get_one_object(j2);
			if (p->get_is_can()[0] == 0)
			{
				MoveTo(p->get_who().pos[2], p->get_who().pos[3]);
				string kongge = "";
				for (size_t k = 0; k < p->get_name().size(); k++)
					kongge += " ";
				cout << kongge;
				p->del_one_object(j2);
			}
			else
				p->print();
		}
	}
		
	for (size_t i = 0; i < all_zombies.size(); i++)
	{
		Zombies *p;
		for (size_t j2 = 0; j2 < all_zombies[i]->get_num(); j2++)
		{
			p = all_zombies[i]->get_one_object(j2);
			if (p->get_is_can()[0] == 0)
			{
				MoveTo(p->get_who().pos[2], p->get_who().pos[3]);
				string kongge = "";
				for (size_t k = 0; k < p->get_name().size(); k++)
					kongge += " ";
				cout << kongge;
				p->del_one_object(j2);
			}
			else
				p->print();
		}
	}
		
}

void Lawn::chage_plant_text(vector<Plants *>all_P)
{
	//for (size_t m1 = 0; m1 < all_P.size(); m1++)
	//{
	//	/*for (size_t m2 = 0; m2 < all_P[m1].)
	//	{
	//	}*/

	//}
	//ofstream out1;
	//string name = "./Law/";
	//for (size_t i = 0; i < all.size(); i++)
	//{
	//	string n1 = name + to_string(i + 1) + "-plants.txt";
	//	out1.open(n1, ios::app);
	//	if (!out1.is_open())
	//	{
	//		cout << "ϵͳ�ļ�д��ʧ�ܣ��޷�������Ϸ��";
	//		exit(-1);
	//	}
	//	for (size_t j1 = 0; j1 < all[i].what_P_AT.size(); j1++)
	//	{
	//		out1 << all[i].what_P_AT[j1] << "   " << all[i].how_much_P_AT[j1] << endl;
	//	}
	//	out1.close();
	//}
}

void Lawn::chage_zombie_text(vector<Zombies *> all_Z)
{
	/*ofstream out2;
	string name = "./Law/";
	for (size_t i = 0; i < all.size(); i++)
	{
	string n2 = name + to_string(i + 1) + "-zombies.txt";
	out2.open(n2, ios::app);
	if (!out2.is_open())
	{
	cout << "ϵͳ�ļ�д��ʧ�ܣ��޷�������Ϸ��";
	exit(-1);
	}
	for (size_t j1 = 0; j1 < all[i].what_Z_AT.size(); j1++)
	{
	out2 << all[i].what_Z_AT[j1] << "   " << all[i].how_much_Z_AT[j1] << endl;
	}
	out2.close();
	}*/
}


void Lawn::del_zombie_attack(const int &a, const double&b)
{
	/*for (size_t kk = 0; kk < what_Z_AT.size(); kk++)
	{
		if (what_Z_AT[kk] == a&&how_much_Z_AT[kk] == b)
			del_one_zombie(kk);
	}*/
}

void Lawn::del_plant_attack(const int &a, const double&b)
{
	/*for (size_t kk = 0; kk < what_P_AT.size(); kk++)
	{
		if (what_P_AT[kk] == a&&how_much_P_AT[kk] == b)
			del_one_plant(kk);
	}*/
}

Lawn Lawn::get_one_object(const size_t &i)
{
	return all[i];
}

void Lawn::del_one_object(const size_t &i)
{
	size_t k = 0;
	vector<Lawn>::iterator it;
	for (it = all.begin(); it != all.end(); it++, k++)
	{
		if (k == i)
		{
			it = all.erase(it);
			break;
		}
	}
}

void Lawn::del_one_plant(const size_t &i)
{
	/*size_t k = 0;
	vector<int>::iterator it;
	for (it = what_P_AT.begin(); it != what_P_AT.end(); it++, k++)
	{
		if (k == i)
		{
			it = what_P_AT.erase(it);
			break;
		}
	}
	size_t kk = 0;
	vector<double>::iterator it2;
	for (it2 = how_much_P_AT.begin(); it2 != how_much_P_AT.end(); it2++, kk++)
	{
		if (kk == i)
		{
			it2 = how_much_P_AT.erase(it2);
			break;
		}
	}*/
}

void Lawn::del_one_zombie(const size_t &i)
{
	/*size_t k = 0;
	vector<int>::iterator it;
	for (it = what_Z_AT.begin(); it != what_Z_AT.end(); it++, k++)
	{
	if (k == i)
	{
	it = what_Z_AT.erase(it);
	break;
	}
	}
	size_t kk = 0;
	vector<double>::iterator it2;
	for (it2 = how_much_Z_AT.begin(); it2 != how_much_Z_AT.end(); it2++, kk++)
	{
	if (kk == i)
	{
	it2 = how_much_Z_AT.erase(it2);
	break;
	}
	}*/
}
