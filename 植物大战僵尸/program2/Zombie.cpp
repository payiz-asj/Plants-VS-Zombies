#include"Zombie.h"
#include "UI.h"
#include"Lawn.h"
//��̬������ʼ����
vector<Ordinary> Ordinary::all;
vector<Z_shooter> Z_shooter::all;



//���������
int Random_2(const int &a, const int &b)
{
	int r = rand() % (b - a + 1) + a;
	return r;
}
//���н�ʬ���ʵ����
//Ordinary
void Ordinary::create(const vector<int> & where)
{
	vector<int> w;
	w = create_pos(where[0], where[1] - 1);
	//��ӹ���
	switch (what_tool)
	{
	case 0:
	{
		my_Tools = NULL;
		name = "��ͨ" + name;
		this->move_CD[0] += 5;
		break;
	}
	case 1:
	{
		my_Tools = new Newspaper;
		this->move_CD[0] += my_Tools->get_cd()[1];
		this->set_data(my_Tools->get_who().data);
		name = my_Tools->get_name() + name;
		break;
	}
	case 2:
	{
		my_Tools = new Bucket;
		this->move_CD[0] += my_Tools->get_cd()[1];
		name = my_Tools->get_name() + name;
		break;
	}
	case 3:
	{
		my_Tools = new Iron_gate;
		this->move_CD[0] += my_Tools->get_cd()[1];
		name = my_Tools->get_name() + name;
		break;
	}
	/*
	case 4:
	{
	my_Tools = new Rugby;
	my_Tools->create(w);
	this->move_CD[0] += my_Tools->get_cd()[1];
	name = my_Tools->get_name() + name;
	break;
	}*/

	default:
		my_Tools = NULL;
		name = "��ͨ" + name;
		this->move_CD[0] += 5;
		break;
	}

	//���ɴ˽�ʬ
	this->set_pos(where);
	this->push();
}

void Ordinary::print()
{
	
		if (is_alive == 1)
		{
			MoveTo(get_who().pos[2],get_who().pos[3]);
			cout << name;
		}

	/*for (size_t kk = 0; kk < this->get_num(); kk++)
	{
		if (all[kk].is_alive == 1)
		{
			MoveTo(all[kk].get_who().pos[2], all[kk].get_who().pos[3]);
			cout << all[kk].name;
		}
		else
		{
			this->del_one_object(kk);
		}
	}*/
}

void Ordinary::attack()
{
	Lawn L;
	is_can_attack = 0;
	is_can_move = 1;
	for (size_t j = 0; j < L.get_num(); j++)
	{
		//�ҵ��ý�ʬ��ǰ��ƺ
		if (L.all[j].pos[0] == who.pos[0] && L.all[j].pos[1] == who.pos[1])
		{
			for (size_t k = 0; k < L.all[j].what_P_AT.size(); k++)
			{
				//�������ֲ��
				if (L.all[j].what_P_AT[k].type < 50)
				{
					is_can_attack = 1;
					is_can_move = 0;
				}
				else if (L.all[j].what_P_AT[k].type == 60)
				{

				}

			}
		}
	}
	if (is_can_attack == 1)
	{
		bite();
	}

	

}

void Ordinary::bite()
{
	//˺ҧ

	//for (size_t kk = 0; kk < this->get_num(); kk++)
	//{
	//	all[kk].bite_CD[1]++;
	//	if (all[kk].bite_CD[1] == all[kk].bite_CD[0])
	//	{
	//		Lawn L;
	//		for (size_t i = 0; i < L.get_num(); i++)
	//		{
	//			if (L.all[i].pos[0] == all[kk].pos[0] && L.all[i].pos[1] == all[kk].pos[1] - 1)
	//			{
	//				//L.all[i].what_Z_AT.push_back(0);
	//				//L.all[i].how_much_Z_AT.push_back(all[kk].data[4]);
	//			}
	//		}
	//		all[kk].bite_CD[1] = 0;
	//	}
	//}
}

void Ordinary::defance()
{
	srand((int)time(0));  // �����������  ��0����NULLҲ��
	Lawn L;
	for (size_t j = 0; j < L.get_num(); j++)
	{
		//�ҵ��ý�ʬ���ڲ�ƺ
		if (L.all[j].pos[0] == get_who().pos[0] && L.all[j].pos[1] == get_who().pos[1])
		{
			for (size_t k = 0; k < L.all[j].what_P_AT.size(); k++)
			{
				//�����ֲ��Ĺ������ӵ���������
				if (L.all[j].what_P_AT[k].type >50 && L.all[j].what_P_AT[k].type < 60)
				{
					//�ӵ��˺��ɷ�Ϊ��ײ�Ժ�һ����ƺ��
					if (L.all[j].what_P_AT[k].type ==51)
					{
						//��ײ���
						if (L.all[j].what_P_AT[k].pos[2] == get_who().pos[2])//&& L.all[j].what_P_AT[k].pos[3] == get_who().pos[3]
						{
							//��������ײ���ӵ��˺�������������ʬѭ�����
							vector<int> w = create_pos(get_who().pos[0], get_who().pos[1]);
							vector<double>my_data = get_who().data;
							if (get_who().pos[3] == w[3])//��һ�н�ʬ������ǰ��Ľ�ʬ
							{
								if (my_data[5] > L.all[j].what_P_AT[k].data[4])
								{
									my_data[5] -= L.all[j].what_P_AT[k].data[4];
								}
								else
								{
									my_data[5] = 0;
									my_data[3] -= L.all[j].what_P_AT[k].data[4] - my_data[5];
								}
							}
							set_data(my_data);
						}
						else
						{
							//�ӵ���û������
						}
					}
					else
					{
						//������һ����ƺ�Ե��˺�

					}
					
				}
				else if (L.all[j].what_P_AT[k].type == 60)
				{
					//���Ǵ���Ĺ�����Ҫ����
					if (get_who().pos[0] == 1 )
					{
						move_down();
					}
					else if (get_who().pos[0] == 5)
						move_up();
					else
					{
						int rrrrr=Random_2(1, 2);
						if (rrrrr==1)
							move_up();
						else
							move_down();
					}
					break;
				}

			}
			if (get_who().data[3] < 0)
				is_alive = 0;
		}
	}

}

void Ordinary::move_up()
{
	MoveTo(who.pos[2], who.pos[3]);
	string kongge = "";
	for (size_t k = 0; k < name.size(); k++)
		kongge += " ";
	cout << kongge;
	who.pos = create_pos(who.pos[0]-1, who.pos[1]+1);
}

void Ordinary::move_down()
{
	MoveTo(who.pos[2], who.pos[3]);
	string kongge = "";
	for (size_t k = 0; k < name.size(); k++)
		kongge += " ";
	cout << kongge;
	who.pos = create_pos(who.pos[0]+1, who.pos[1]+1);
}

int  Ordinary::move()
{
	Lawn L;
	int is_game_over = 0;
	if (get_who().pos[1] > 0)
	{
		if (get_who().pos[1] <= get_screen_data()[1])
		{
			move_CD[1]++;
			if (move_CD[1] ==move_CD[0])
			{
				MoveTo(get_who().pos[2],get_who().pos[3]);
				string kongge = "";
				for (size_t k = 0; k < name.size(); k++)
					kongge += " ";
				cout << kongge;
				if (get_who().pos[2] == create_pos(get_who().pos[0],get_who().pos[1])[2])
				{
					who.pos[1]--;
				}
				if (get_who().pos[2] + name.size() == create_pos(get_who().pos[0], get_who().pos[1])[2] + get_screen_data()[2])
				{
					MoveTo(get_who().pos[2] + name.size(), get_who().pos[3]);
					cout << get_back_ground();
				}
				who.pos[2] -= 1;
				move_CD[1] = 0;
			}
			//
			if (get_who().pos[1] == 1)
			{
				if (get_who().pos[2] == 0 )//|| get_who().pos[2] == 2 || get_who().pos[2] == 3 || get_who().pos[2] == 4)
					is_game_over = 1;
			}
			
		}
		else
		{
			move_CD[1]++;
			if (move_CD[1] == move_CD[0])
			{
				MoveTo(get_who().pos[2], get_who().pos[3]);
				string kongge = "";
				for (size_t k = 0; k < name.size(); k++)
					kongge += " ";
				cout << kongge;
				if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
				{
					who.pos[1]--;
				}
				who.pos[2] -= 1;
				move_CD[1] = 0;
			}
		}
		
	}
	else
	{
		is_alive=0;
		is_game_over = 1;
	}
	return is_game_over;
}


//Z_shooter
void Z_shooter::create(const vector<int> & where)
{
	//��ӹ���
	switch (what_tool)
	{
	case 1:
	{
		my_Tools = new Baseball;
		break;
	}
	/*case 2:
	{
	my_Tools = new Bucket;
	my_Tools->create(w);
	this->move_CD[0] += my_Tools->get_cd()[1];
	name = my_Tools->get_name() + name;
	break;
	}
	case 3:
	{
	my_Tools = new Iron_gate;
	my_Tools->create(w);
	this->move_CD[0] += my_Tools->get_cd()[1];
	name = my_Tools->get_name() + name;
	break;
	}
	case 4:
	{
	my_Tools = new Rugby;
	my_Tools->create(w);
	this->move_CD[0] += my_Tools->get_cd()[1];
	name = my_Tools->get_name() + name;
	break;
	}*/

	default:
		my_Tools = new Baseball;
		break;
	}

	//���ɴ˽�ʬ
	shoot_CD[0] = my_Tools->get_cd()[0];
	this->move_CD[0] += my_Tools->get_cd()[1];
	this->set_data(my_Tools->get_who().data);
	name = my_Tools->get_name() + name;
	this->set_pos(where);
	this->push();
}

void Z_shooter::print()
{

	if (is_alive == 1)
	{
		MoveTo(get_who().pos[2], get_who().pos[3]);
		cout << name;
	}
	//��ʬ��ӡ�꣬���ӵ���
	Tool *b;
	for (size_t i = 0; i < my_Tools->get_num(); i++)
	{
		b = my_Tools->get_one_object(i);
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

void Z_shooter::attack()
{
	Lawn L;
	is_can_attack = 0;
	is_can_move = 1;
	for (size_t j = 0; j < L.get_num(); j++)
	{
		//�ҵ��ý�ʬ��ǰyihang��ƺ
		if (L.all[j].pos[0] == who.pos[0] )
		{
			for (size_t k = 0; k < L.all[j].what_P_AT.size(); k++)
			{
				//�������ֲ��
				if (L.all[j].what_P_AT[k].type < 50)
				{
					is_can_attack = 1;
					if (L.all[j].pos[1] == who.pos[1])
						is_can_move = 0;
				}
				else if (L.all[j].what_P_AT[k].type == 60)
				{

				}

			}
		}
	}
	if (is_can_attack == 1)
	{
		shoot();
	}



}

void Z_shooter::shoot()
{
	shoot_CD[1]++;
	if (shoot_CD[1] == shoot_CD[0])
	{
		vector<int> w;
		w = create_pos(who.pos[0], who.pos[1]);
		my_Tools->create(w);
		shoot_CD[1] = 0;
	}
}

void Z_shooter::defance()
{
	srand((int)time(0));  // �����������  ��0����NULLҲ��
	Lawn L;
	for (size_t j = 0; j < L.get_num(); j++)
	{
		//�ҵ��ý�ʬ���ڲ�ƺ
		if (L.all[j].pos[0] == get_who().pos[0] && L.all[j].pos[1] == get_who().pos[1])
		{
			for (size_t k = 0; k < L.all[j].what_P_AT.size(); k++)
			{
				//�����ֲ��Ĺ������ӵ���������
				if (L.all[j].what_P_AT[k].type >50 && L.all[j].what_P_AT[k].type < 60)
				{
					//�ӵ��˺��ɷ�Ϊ��ײ�Ժ�һ����ƺ��
					if (L.all[j].what_P_AT[k].type == 51)
					{
						//��ײ���
						if (L.all[j].what_P_AT[k].pos[2] == get_who().pos[2])//&& L.all[j].what_P_AT[k].pos[3] == get_who().pos[3]
						{
							//��������ײ���ӵ��˺�������������ʬѭ�����
							vector<int> w = create_pos(get_who().pos[0], get_who().pos[1]);
							vector<double>my_data = get_who().data;
							if (get_who().pos[3] == w[3])//��һ�н�ʬ������ǰ��Ľ�ʬ
							{
								if (my_data[5] > L.all[j].what_P_AT[k].data[4])
								{
									my_data[5] -= L.all[j].what_P_AT[k].data[4];
								}
								else
								{
									my_data[5] = 0;
									my_data[3] -= L.all[j].what_P_AT[k].data[4] - my_data[5];
								}
							}
							set_data(my_data);
						}
						else
						{
							//�ӵ���û������
						}
					}
					else
					{
						//������һ����ƺ�Ե��˺�

					}

				}
				else if (L.all[j].what_P_AT[k].type == 60)
				{
					//���Ǵ���Ĺ�����Ҫ����
					if (get_who().pos[0] == 1)
					{
						move_down();
					}
					else if (get_who().pos[0] == 5)
						move_up();
					else
					{
						int rrrrr = Random_2(1, 2);
						if (rrrrr == 1)
							move_up();
						else
							move_down();
					}
					break;
				}

			}
			if (get_who().data[3] < 0)
				is_alive = 0;
		}
	}

}

void Z_shooter::move_up()
{
	MoveTo(who.pos[2], who.pos[3]);
	string kongge = "";
	for (size_t k = 0; k < name.size(); k++)
		kongge += " ";
	cout << kongge;
	who.pos = create_pos(who.pos[0] - 1, who.pos[1] + 1);
}

void Z_shooter::move_down()
{
	MoveTo(who.pos[2], who.pos[3]);
	string kongge = "";
	for (size_t k = 0; k < name.size(); k++)
		kongge += " ";
	cout << kongge;
	who.pos = create_pos(who.pos[0] + 1, who.pos[1] + 1);
}

int  Z_shooter::move()
{
	Lawn L;
	int is_game_over = 0;
	if (get_who().pos[1] > 0)
	{
		if (get_who().pos[1] <= get_screen_data()[1])
		{
			move_CD[1]++;
			if (move_CD[1] == move_CD[0])
			{
				MoveTo(get_who().pos[2], get_who().pos[3]);
				string kongge = "";
				for (size_t k = 0; k < name.size(); k++)
					kongge += " ";
				cout << kongge;
				if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
				{
					who.pos[1]--;
				}
				if (get_who().pos[2] + name.size() == create_pos(get_who().pos[0], get_who().pos[1])[2] + get_screen_data()[2])
				{
					MoveTo(get_who().pos[2] + name.size(), get_who().pos[3]);
					cout << get_back_ground();
				}
				who.pos[2] -= 1;
				move_CD[1] = 0;
			}
			//
			if (get_who().pos[1] == 1)
			{
				if (get_who().pos[2] == 0)//|| get_who().pos[2] == 2 || get_who().pos[2] == 3 || get_who().pos[2] == 4)
					is_game_over = 1;
			}

		}
		else
		{
			move_CD[1]++;
			if (move_CD[1] == move_CD[0])
			{
				MoveTo(get_who().pos[2], get_who().pos[3]);
				string kongge = "";
				for (size_t k = 0; k < name.size(); k++)
					kongge += " ";
				cout << kongge;
				if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
				{
					who.pos[1]--;
				}
				who.pos[2] -= 1;
				move_CD[1] = 0;
			}
		}

	}
	else
	{
		is_alive = 0;
		is_game_over = 1;
	}
	//��ʬ�����ӵ���
	Tool *b;
	for (size_t i = 0; i < my_Tools->get_num(); i++)
	{
		b = my_Tools->get_one_object(i);
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
	return is_game_over;
}


