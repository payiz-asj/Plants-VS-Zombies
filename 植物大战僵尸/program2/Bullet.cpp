#include "Bullet.h"
#include "UI.h"
#include"Lawn.h"
//��̬������ʼ����
//vector<Org_pea> Org_pea::all;
//vector<Snow_pea> Snow_pea::all;
//vector<Melon> Melon::all;


//�����ӵ����ʵ����
void Org_pea::print()
{
	MoveTo(get_who().pos[2], get_who().pos[3]);
	cout <<shap;
}

void Org_pea::move()
{
	Lawn L;
	if (get_who().pos[1] <= get_screen_data()[1])
	{
		bool is_time_to_break = 0;
		for (size_t j = 0; j < L.get_num(); j++)
		{
			//�ҵ����ӵ���ǰ��ƺ
			if (L.all[j].pos[0] == get_who().pos[0] && L.all[j].pos[1] == get_who().pos[1])
			{
				int meet_zombie = 0;
				is_time_to_break = 1;
				for (size_t j1 = 0; j1 < L.all[j].what_Z_AT.size(); j1++)
				{	//���ֽ�ʬ��ʬ�ӵ�	
					meet_zombie = 1;
					if (L.all[j].what_Z_AT[j1].type < 50)
					{
						//������ʬ�����ˣ��ӵ���ʧ
						if (L.all[j].what_Z_AT[j1].pos[2] == get_who().pos[2] || L.all[j].what_Z_AT[j1].pos[2] + 2 == get_who().pos[2])//||L.all[j].what_Z_AT[j1].pos[2] + 1 == all[i].get_who().pos[2] 
						{
							//��ײ
							/*MoveTo(get_who().pos[2], get_who().pos[3]);
							string kongge = "";
							for (size_t k = 0; k <shap.size(); k++)
							kongge += " ";
							cout << kongge;*/
							is_can_move = 0;
							break;
						}
						else
						{
							//��û����ײ
							shoot_CD[2]++;
							if (shoot_CD[2] == shoot_CD[1])
							{
								MoveTo(get_who().pos[2], get_who().pos[3]);
								string kongge = "";
								for (size_t k = 0; k < shap.size(); k++)
									kongge += " ";
								cout << kongge;
								if (get_who().pos[2] + shap.size() == create_pos(get_who().pos[0], get_who().pos[1] + 1)[2] - 1)
								{
									who.pos[1]++;
								}
								if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
								{
									MoveTo(get_who().pos[2] - 1,get_who().pos[3]);
									cout << get_back_ground();
								}
								who.pos[2] += 1;
								shoot_CD[2] = 0;
							}
						}
					}
					else
					{
						//������ʬ���ӵ�
						shoot_CD[2]++;
						if (shoot_CD[2] == shoot_CD[1])
						{
							MoveTo(get_who().pos[2], get_who().pos[3]);
							string kongge = "";
							for (size_t k = 0; k < shap.size(); k++)
								kongge += " ";
							cout << kongge;
							if (get_who().pos[2] + shap.size() == create_pos(get_who().pos[0], get_who().pos[1] + 1)[2] - 1)
							{
								who.pos[1]++;
							}
							if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
							{
								MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
								cout << get_back_ground();
							}
							who.pos[2] += 1;
							shoot_CD[2] = 0;
						}
					}
				}
				if (meet_zombie == 0)
				{
					//û�н�ʬ��ʬ���ӵ�
					shoot_CD[2]++;
					if (shoot_CD[2] == shoot_CD[1])
					{
						MoveTo(get_who().pos[2], get_who().pos[3]);
						string kongge = "";
						for (size_t k = 0; k < shap.size(); k++)
							kongge += " ";
						cout << kongge;
						if (get_who().pos[2] + shap.size() == create_pos(get_who().pos[0], get_who().pos[1] + 1)[2] - 1)
						{
							who.pos[1]++;
						}
						if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
						{
							MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
							cout << get_back_ground();
						}
						who.pos[2] += 1;
						shoot_CD[2] = 0;
					}
				}
			}
			if (is_time_to_break == 1)
				break;
		}//���в�ƺ
	}
	else
	{
		is_can_move = 0;
	}
		
}

void Snow_pea::print()
{
	MoveTo(get_who().pos[2], get_who().pos[3]);
	cout << shap;
}

void Snow_pea::move()
{
	Lawn L;
	if (get_who().pos[1] <= get_screen_data()[1])
	{
		bool is_time_to_break = 0;
		for (size_t j = 0; j < L.get_num(); j++)
		{
			//�ҵ����ӵ���ǰ��ƺ
			if (L.all[j].pos[0] == get_who().pos[0] && L.all[j].pos[1] == get_who().pos[1])
			{
				int meet_zombie = 0;
				is_time_to_break = 1;
				for (size_t j1 = 0; j1 < L.all[j].what_Z_AT.size(); j1++)
				{	//���ֽ�ʬ��ʬ�ӵ�	
					meet_zombie = 1;
					if (L.all[j].what_Z_AT[j1].type < 50)
					{
						//������ʬ�����ˣ��ӵ���ʧ
						if (L.all[j].what_Z_AT[j1].pos[2] == get_who().pos[2] || L.all[j].what_Z_AT[j1].pos[2] + 2 == get_who().pos[2])//||L.all[j].what_Z_AT[j1].pos[2] + 1 == all[i].get_who().pos[2] 
						{
							//��ײ
							/*MoveTo(get_who().pos[2], get_who().pos[3]);
							string kongge = "";
							for (size_t k = 0; k <shap.size(); k++)
							kongge += " ";
							cout << kongge;*/
							is_can_move = 0;
							break;
						}
						else
						{
							//��û����ײ
							shoot_CD[2]++;
							if (shoot_CD[2] == shoot_CD[1])
							{
								MoveTo(get_who().pos[2], get_who().pos[3]);
								string kongge = "";
								for (size_t k = 0; k < shap.size(); k++)
									kongge += " ";
								cout << kongge;
								if (get_who().pos[2] + shap.size() == create_pos(get_who().pos[0], get_who().pos[1] + 1)[2] - 1)
								{
									who.pos[1]++;
								}
								if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
								{
									MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
									cout << get_back_ground();
								}
								who.pos[2] += 1;
								shoot_CD[2] = 0;
							}
						}
					}
					else
					{
						//������ʬ���ӵ�
						shoot_CD[2]++;
						if (shoot_CD[2] == shoot_CD[1])
						{
							MoveTo(get_who().pos[2], get_who().pos[3]);
							string kongge = "";
							for (size_t k = 0; k < shap.size(); k++)
								kongge += " ";
							cout << kongge;
							if (get_who().pos[2] + shap.size() == create_pos(get_who().pos[0], get_who().pos[1] + 1)[2] - 1)
							{
								who.pos[1]++;
							}
							if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
							{
								MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
								cout << get_back_ground();
							}
							who.pos[2] += 1;
							shoot_CD[2] = 0;
						}
					}
				}
				if (meet_zombie == 0)
				{
					//û�н�ʬ��ʬ���ӵ�
					shoot_CD[2]++;
					if (shoot_CD[2] == shoot_CD[1])
					{
						MoveTo(get_who().pos[2], get_who().pos[3]);
						string kongge = "";
						for (size_t k = 0; k < shap.size(); k++)
							kongge += " ";
						cout << kongge;
						if (get_who().pos[2] + shap.size() == create_pos(get_who().pos[0], get_who().pos[1] + 1)[2] - 1)
						{
							who.pos[1]++;
						}
						if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
						{
							MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
							cout << get_back_ground();
						}
						who.pos[2] += 1;
						shoot_CD[2] = 0;
					}
				}
			}
			if (is_time_to_break == 1)
				break;
		}//���в�ƺ
	}
	else
	{
		is_can_move = 0;
	}

}

void Melon::print()
{
	MoveTo(get_who().pos[2], get_who().pos[3]);
	cout << shap;
}

void Melon::move()
{
	Lawn L;
	if (get_who().pos[1] <= get_screen_data()[1])
	{
		bool is_time_to_break = 0;
		for (size_t j = 0; j < L.get_num(); j++)
		{
			//�ҵ����ӵ���ǰ��ƺ
			if (L.all[j].pos[0] == get_who().pos[0] && L.all[j].pos[1] == get_who().pos[1])
			{
				int meet_zombie = 0;
				is_time_to_break = 1;
				for (size_t j1 = 0; j1 < L.all[j].what_Z_AT.size(); j1++)
				{	//���ֽ�ʬ��ʬ�ӵ�	
					meet_zombie = 1;
					if (L.all[j].what_Z_AT[j1].type < 50)
					{
						//������ʬ�����ˣ��ӵ���ʧ
						if (L.all[j].what_Z_AT[j1].pos[2] == get_who().pos[2] || L.all[j].what_Z_AT[j1].pos[2] + 1 == get_who().pos[2])//||L.all[j].what_Z_AT[j1].pos[2] + 1 == all[i].get_who().pos[2] 
						{
							//��ײ
							/*MoveTo(get_who().pos[2], get_who().pos[3]);
							string kongge = "";
							for (size_t k = 0; k <shap.size(); k++)
							kongge += " ";
							cout << kongge;*/
							is_can_move = 0;
							break;
						}
						else
						{
							//��û����ײ
							shoot_CD[2]++;
							if (shoot_CD[2] == shoot_CD[1])
							{
								MoveTo(get_who().pos[2], get_who().pos[3]);
								string kongge = "";
								for (size_t k = 0; k < shap.size(); k++)
									kongge += " ";
								cout << kongge;
								if (get_who().pos[2] + shap.size() == create_pos(get_who().pos[0], get_who().pos[1] + 1)[2] - 1)
								{
									who.pos[1]++;
								}
								if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
								{
									MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
									cout << get_back_ground();
								}
								who.pos[2] += 1;
								shoot_CD[2] = 0;
							}
						}
					}
					else
					{
						//������ʬ���ӵ�
						shoot_CD[2]++;
						if (shoot_CD[2] == shoot_CD[1])
						{
							MoveTo(get_who().pos[2], get_who().pos[3]);
							string kongge = "";
							for (size_t k = 0; k < shap.size(); k++)
								kongge += " ";
							cout << kongge;
							if (get_who().pos[2] + shap.size() == create_pos(get_who().pos[0], get_who().pos[1] + 1)[2] - 1)
							{
								who.pos[1]++;
							}
							if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
							{
								MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
								cout << get_back_ground();
							}
							who.pos[2] += 1;
							shoot_CD[2] = 0;
						}
					}
				}
				if (meet_zombie == 0)
				{
					//û�н�ʬ��ʬ���ӵ�
					shoot_CD[2]++;
					if (shoot_CD[2] == shoot_CD[1])
					{
						MoveTo(get_who().pos[2], get_who().pos[3]);
						string kongge = "";
						for (size_t k = 0; k < shap.size(); k++)
							kongge += " ";
						cout << kongge;
						if (get_who().pos[2] + shap.size() == create_pos(get_who().pos[0], get_who().pos[1] + 1)[2] - 1)
						{
							who.pos[1]++;
						}
						if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
						{
							MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
							cout << get_back_ground();
						}
						who.pos[2] += 1;
						shoot_CD[2] = 0;
					}
				}
			}
			if (is_time_to_break == 1)
				break;
		}//���в�ƺ
	}
	else
	{
		is_can_move = 0;
	}

}


