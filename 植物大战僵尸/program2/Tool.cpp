#include"Tool.h"
#include "UI.h"
#include"Lawn.h"
//��̬������ʼ����
//vector<Newspaper> Newspaper::all;



//���й������ʵ����
void Newspaper::print()
{
	MoveTo(get_who().pos[2], get_who().pos[3]);
	cout << shap;
}

void Newspaper::move()
{
	Lawn L;
	if (get_who().pos[1] >0)
	{
		bool is_time_to_break = 0;
		for (size_t j = 0; j < L.get_num(); j++)
		{
			//�ҵ����ӵ���ǰ��ƺ
			if (L.all[j].pos[0] == get_who().pos[0] && L.all[j].pos[1] == get_who().pos[1])
			{
				int meet_plant = 0;
				is_time_to_break = 1;
				for (size_t j1 = 0; j1 < L.all[j].what_P_AT.size(); j1++)
				{	//����ֲ���ֲ���ӵ�	
					meet_plant = 1;
					if (L.all[j].what_P_AT[j1].type < 50 || L.all[j].what_P_AT[j1].type >= 60)
					{
						//����ֲ�ﱾ���ˣ��ӵ���ʧ
						if (L.all[j].what_P_AT[j1].pos[2] == get_who().pos[2] || L.all[j].what_P_AT[j1].pos[2] - 1 == get_who().pos[2])//||L.all[j].what_Z_AT[j1].pos[2] + 1 == all[i].get_who().pos[2] 
						{
							//��ײ
							/*MoveTo(get_who().pos[2], get_who().pos[3]);
							string kongge = "";
							for (size_t k = 0; k <shap.size(); k++)
							kongge += " ";
							cout << kongge;*/
							is_can_move = 0;
							is_alive = 0;
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
									who.pos[1]--;
								}
								if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
								{
									MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
									cout << get_back_ground();
								}
								who.pos[2] -= 1;
								shoot_CD[2] = 0;
							}
						}
					}
					else
					{
						//����ֲ����ӵ�
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
								who.pos[1]--;
							}
							if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
							{
								MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
								cout << get_back_ground();
							}
							who.pos[2] -= 1;
							shoot_CD[2] = 0;
						}
					}
				}
				if (meet_plant == 0)
				{
					//û��ֲ���ֲ����ӵ�
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
							who.pos[1]--;
						}
						if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
						{
							MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
							cout << get_back_ground();
						}
						who.pos[2] -= 1;
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
		is_alive = 0;
	}
}

void Bucket::print()
{
	MoveTo(get_who().pos[2], get_who().pos[3]);
	cout << shap;
}

void Bucket::move()
{
	Lawn L;
	if (get_who().pos[1] >0)
	{
		bool is_time_to_break = 0;
		for (size_t j = 0; j < L.get_num(); j++)
		{
			//�ҵ����ӵ���ǰ��ƺ
			if (L.all[j].pos[0] == get_who().pos[0] && L.all[j].pos[1] == get_who().pos[1])
			{
				int meet_plant = 0;
				is_time_to_break = 1;
				for (size_t j1 = 0; j1 < L.all[j].what_P_AT.size(); j1++)
				{	//����ֲ���ֲ���ӵ�	
					meet_plant = 1;
					if (L.all[j].what_P_AT[j1].type < 50 || L.all[j].what_P_AT[j1].type >= 60)
					{
						//����ֲ�ﱾ���ˣ��ӵ���ʧ
						if (L.all[j].what_P_AT[j1].pos[2] == get_who().pos[2] || L.all[j].what_P_AT[j1].pos[2] - 1 == get_who().pos[2])//||L.all[j].what_Z_AT[j1].pos[2] + 1 == all[i].get_who().pos[2] 
						{
							//��ײ
							/*MoveTo(get_who().pos[2], get_who().pos[3]);
							string kongge = "";
							for (size_t k = 0; k <shap.size(); k++)
							kongge += " ";
							cout << kongge;*/
							is_can_move = 0;
							is_alive = 0;
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
									who.pos[1]--;
								}
								if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
								{
									MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
									cout << get_back_ground();
								}
								who.pos[2] -= 1;
								shoot_CD[2] = 0;
							}
						}
					}
					else
					{
						//����ֲ����ӵ�
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
								who.pos[1]--;
							}
							if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
							{
								MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
								cout << get_back_ground();
							}
							who.pos[2] -= 1;
							shoot_CD[2] = 0;
						}
					}
				}
				if (meet_plant == 0)
				{
					//û��ֲ���ֲ����ӵ�
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
							who.pos[1]--;
						}
						if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
						{
							MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
							cout << get_back_ground();
						}
						who.pos[2] -= 1;
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
		is_alive = 0;
	}
}

void Iron_gate::print()
{
	MoveTo(get_who().pos[2], get_who().pos[3]);
	cout << shap;
}

void Iron_gate::move()
{
	Lawn L;
	if (get_who().pos[1] >0)
	{
		bool is_time_to_break = 0;
		for (size_t j = 0; j < L.get_num(); j++)
		{
			//�ҵ����ӵ���ǰ��ƺ
			if (L.all[j].pos[0] == get_who().pos[0] && L.all[j].pos[1] == get_who().pos[1])
			{
				int meet_plant = 0;
				is_time_to_break = 1;
				for (size_t j1 = 0; j1 < L.all[j].what_P_AT.size(); j1++)
				{	//����ֲ���ֲ���ӵ�	
					meet_plant = 1;
					if (L.all[j].what_P_AT[j1].type < 50 || L.all[j].what_P_AT[j1].type >= 60)
					{
						//����ֲ�ﱾ���ˣ��ӵ���ʧ
						if (L.all[j].what_P_AT[j1].pos[2] == get_who().pos[2] || L.all[j].what_P_AT[j1].pos[2] - 1 == get_who().pos[2])//||L.all[j].what_Z_AT[j1].pos[2] + 1 == all[i].get_who().pos[2] 
						{
							//��ײ
							/*MoveTo(get_who().pos[2], get_who().pos[3]);
							string kongge = "";
							for (size_t k = 0; k <shap.size(); k++)
							kongge += " ";
							cout << kongge;*/
							is_can_move = 0;
							is_alive = 0;
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
									who.pos[1]--;
								}
								if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
								{
									MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
									cout << get_back_ground();
								}
								who.pos[2] -= 1;
								shoot_CD[2] = 0;
							}
						}
					}
					else
					{
						//����ֲ����ӵ�
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
								who.pos[1]--;
							}
							if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
							{
								MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
								cout << get_back_ground();
							}
							who.pos[2] -= 1;
							shoot_CD[2] = 0;
						}
					}
				}
				if (meet_plant == 0)
				{
					//û��ֲ���ֲ����ӵ�
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
							who.pos[1]--;
						}
						if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
						{
							MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
							cout << get_back_ground();
						}
						who.pos[2] -= 1;
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
		is_alive = 0;
	}
}

void Baseball::print()
{
	MoveTo(get_who().pos[2], get_who().pos[3]);
	cout << shap;
}

void Baseball::move()
{
	Lawn L;
	if (get_who().pos[1] >0)
	{
		bool is_time_to_break = 0;
		for (size_t j = 0; j < L.get_num(); j++)
		{
			//�ҵ����ӵ���ǰ��ƺ
			if (L.all[j].pos[0] == get_who().pos[0] && L.all[j].pos[1] == get_who().pos[1])
			{
				int meet_plant = 0;
				is_time_to_break = 1;
				for (size_t j1 = 0; j1 < L.all[j].what_P_AT.size(); j1++)
				{	//����ֲ���ֲ���ӵ�	
					meet_plant = 1;
					if (L.all[j].what_P_AT[j1].type < 50 || L.all[j].what_P_AT[j1].type >=60)
					{
						//����ֲ�ﱾ���ˣ��ӵ���ʧ
						if (L.all[j].what_P_AT[j1].pos[2] == get_who().pos[2] || L.all[j].what_P_AT[j1].pos[2] - 1 == get_who().pos[2])//||L.all[j].what_Z_AT[j1].pos[2] + 1 == all[i].get_who().pos[2] 
						{
							//��ײ
							/*MoveTo(get_who().pos[2], get_who().pos[3]);
							string kongge = "";
							for (size_t k = 0; k <shap.size(); k++)
							kongge += " ";
							cout << kongge;*/
							is_can_move = 0;
							is_alive = 0;
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
								if (get_who().pos[2] + shap.size() == create_pos(get_who().pos[0], get_who().pos[1])[2] + get_screen_data()[2])
								{
									who.pos[1]--;
								}
								if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
								{
									MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
									cout << get_back_ground();
								}
								who.pos[2] -= 1;
								shoot_CD[2] = 0;
							}
						}
					}
					else
					{
						//����ֲ����ӵ�
						shoot_CD[2]++;
						if (shoot_CD[2] == shoot_CD[1])
						{
							MoveTo(get_who().pos[2], get_who().pos[3]);
							string kongge = "";
							for (size_t k = 0; k < shap.size(); k++)
								kongge += " ";
							cout << kongge;
							if (get_who().pos[2] + shap.size() == create_pos(get_who().pos[0], get_who().pos[1])[2] + get_screen_data()[2])
							{
								who.pos[1]--;
							}
							if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
							{
								MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
								cout << get_back_ground();
							}
							who.pos[2] -= 1;
							shoot_CD[2] = 0;
						}
					}
				}
				if (meet_plant == 0)
				{
					//û��ֲ���ֲ����ӵ�
					shoot_CD[2]++;
					if (shoot_CD[2] == shoot_CD[1])
					{
						MoveTo(get_who().pos[2], get_who().pos[3]);
						string kongge = "";
						for (size_t k = 0; k < shap.size(); k++)
							kongge += " ";
						cout << kongge;
						if (get_who().pos[2] + shap.size() == create_pos(get_who().pos[0], get_who().pos[1])[2] + get_screen_data()[2])
						{
							who.pos[1]--;
						}
						if (get_who().pos[2] == create_pos(get_who().pos[0], get_who().pos[1])[2])
						{
							MoveTo(get_who().pos[2] - 1, get_who().pos[3]);
							cout << get_back_ground();
						}
						who.pos[2] -= 1;
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
		is_alive = 0;
	}

	
}


//
//vector<Bucket> Bucket::all;
//
//void Bucket::print()
//{
//	vector<Bucket>::iterator it;
//	for (it = all.begin(); it != all.end(); it++)
//	{
//		MoveTo(it->pos[2], it->pos[3]);
//		cout << it->shap;
//	}
//}
//
//void Bucket::move()
//{
//	Lawn L;
//	for (size_t kk = 0; kk < this->get_num(); kk++)
//	{
//		if (pos[1] < 11)
//		{
//			for (size_t i = 0; i < L.get_num(); i++)
//			{
//				//�ҵ����ӵ�ǰһ����ƺ
//				if (L.all[i].pos[0] == this->pos[0] && L.all[i].pos[1] == this->pos[1] - 1)
//				{
//					for (size_t j = 0; j < L.all[i].what_P_AT.size(); j++)
//					{
//						//�������ֲ��
//						if (L.all[i].what_P_AT[j] == 0 || L.all[i].what_P_AT[j] == 9)//�Ѵ���Ҳ����
//						{
//							L.all[i].what_Z_AT.push_back(1);
//							L.all[i].how_much_Z_AT.push_back(all[kk].data[4]);
//							this->del_one_object(kk);
//						}
//						else
//						{
//							all[kk].shoot_CD[2]++;
//							if (all[kk].shoot_CD[2] == all[kk].shoot_CD[1])
//							{
//								MoveTo(all[kk].pos[2], all[kk].pos[3]);
//								for (size_t k = 0; k < all[kk].shap.size(); k++)
//									cout << " ";
//								if (all[kk].pos[2] + all[kk].shap.size() == 11 * (all[kk].pos[1] - 1))
//								{
//									MoveTo(all[kk].pos[2] + all[kk].shap.size(), all[kk].pos[1]);
//									cout << get_back_ground();
//									all[kk].pos[1]--;
//								}
//								all[kk].pos[2] -= 1;
//								all[kk].shoot_CD[2] = 0;
//							}
//						}
//					}//����ֲ��
//				}
//			}//���в�ƺ
//		}
//	}//�����ӵ�
//}
//
//vector<Iron_gate> Iron_gate::all;
//
//void Iron_gate::print()
//{
//	vector<Iron_gate>::iterator it;
//	for (it = all.begin(); it != all.end(); it++)
//	{
//		MoveTo(it->pos[2], it->pos[3]);
//		cout << it->shap;
//	}
//}
//
//void Iron_gate::move()
//{
//	Lawn L;
//	for (size_t kk = 0; kk < this->get_num(); kk++)
//	{
//		if (pos[1] < 11)
//		{
//			for (size_t i = 0; i < L.get_num(); i++)
//			{
//				//�ҵ����ӵ�ǰһ����ƺ
//				if (L.all[i].pos[0] == this->pos[0] && L.all[i].pos[1] == this->pos[1] - 1)
//				{
//					for (size_t j = 0; j < L.all[i].what_P_AT.size(); j++)
//					{
//						//�������ֲ��
//						if (L.all[i].what_P_AT[j] == 0 || L.all[i].what_P_AT[j] == 9)//�Ѵ���Ҳ����
//						{
//							L.all[i].what_Z_AT.push_back(1);
//							L.all[i].how_much_Z_AT.push_back(all[kk].data[4]);
//							this->del_one_object(kk);
//						}
//						else
//						{
//							all[kk].shoot_CD[2]++;
//							if (all[kk].shoot_CD[2] == all[kk].shoot_CD[1])
//							{
//								MoveTo(all[kk].pos[2], all[kk].pos[3]);
//								for (size_t k = 0; k < all[kk].shap.size(); k++)
//									cout << " ";
//								if (all[kk].pos[2] + all[kk].shap.size() == 11 * (all[kk].pos[1] - 1))
//								{
//									MoveTo(all[kk].pos[2] + all[kk].shap.size(), all[kk].pos[1]);
//									cout << get_back_ground();
//									all[kk].pos[1]--;
//								}
//								all[kk].pos[2] -= 1;
//								all[kk].shoot_CD[2] = 0;
//							}
//						}
//					}//����ֲ��
//				}
//			}//���в�ƺ
//		}
//	}//�����ӵ�
//}
//
//vector<Rugby> Rugby::all;
//
//void Rugby::print()
//{
//	vector<Rugby>::iterator it;
//	for (it = all.begin(); it != all.end(); it++)
//	{
//		MoveTo(it->pos[2], it->pos[3]);
//		cout << it->shap;
//	}
//}
//
//void Rugby::move()
//{
//	Lawn L;
//	for (size_t kk = 0; kk < this->get_num(); kk++)
//	{
//		if (pos[1] < 11)
//		{
//			for (size_t i = 0; i < L.get_num(); i++)
//			{
//				//�ҵ����ӵ�ǰһ����ƺ
//				if (L.all[i].pos[0] == this->pos[0] && L.all[i].pos[1] == this->pos[1] - 1)
//				{
//					for (size_t j = 0; j < L.all[i].what_P_AT.size(); j++)
//					{
//						//�������ֲ��
//						if (L.all[i].what_P_AT[j] == 0 || L.all[i].what_P_AT[j] == 9)//�Ѵ���Ҳ����
//						{
//							L.all[i].what_Z_AT.push_back(1);
//							L.all[i].how_much_Z_AT.push_back(all[kk].data[4]);
//							this->del_one_object(kk);
//						}
//						else
//						{
//							all[kk].shoot_CD[2]++;
//							if (all[kk].shoot_CD[2] == all[kk].shoot_CD[1])
//							{
//								MoveTo(all[kk].pos[2], all[kk].pos[3]);
//								for (size_t k = 0; k < all[kk].shap.size(); k++)
//									cout << " ";
//								if (all[kk].pos[2] + all[kk].shap.size() == 11 * (all[kk].pos[1] - 1))
//								{
//									MoveTo(all[kk].pos[2] + all[kk].shap.size(), all[kk].pos[1]);
//									cout << get_back_ground();
//									all[kk].pos[1]--;
//								}
//								all[kk].pos[2] -= 1;
//								all[kk].shoot_CD[2] = 0;
//							}
//						}
//					}//����ֲ��
//				}
//			}//���в�ƺ
//		}
//	}//�����ӵ�
//}
//
//vector<Pole_Vaulting> Pole_Vaulting::all;
//
//void Pole_Vaulting::print()
//{
//	vector<Pole_Vaulting>::iterator it;
//	for (it = all.begin(); it != all.end(); it++)
//	{
//		MoveTo(it->pos[2], it->pos[3]);
//		cout << it->shap;
//	}
//}
//
//void Pole_Vaulting::move()
//{
//	Lawn L;
//	for (size_t kk = 0; kk < this->get_num(); kk++)
//	{
//		if (pos[1] < 11)
//		{
//			for (size_t i = 0; i < L.get_num(); i++)
//			{
//				//�ҵ����ӵ�ǰһ����ƺ
//				if (L.all[i].pos[0] == this->pos[0] && L.all[i].pos[1] == this->pos[1] - 1)
//				{
//					for (size_t j = 0; j < L.all[i].what_P_AT.size(); j++)
//					{
//						//�������ֲ��
//						if (L.all[i].what_P_AT[j] == 0 || L.all[i].what_P_AT[j] == 9)//�Ѵ���Ҳ����
//						{
//							L.all[i].what_Z_AT.push_back(1);
//							L.all[i].how_much_Z_AT.push_back(all[kk].data[4]);
//							this->del_one_object(kk);
//						}
//						else
//						{
//							all[kk].shoot_CD[2]++;
//							if (all[kk].shoot_CD[2] == all[kk].shoot_CD[1])
//							{
//								MoveTo(all[kk].pos[2], all[kk].pos[3]);
//								for (size_t k = 0; k < all[kk].shap.size(); k++)
//									cout << " ";
//								if (all[kk].pos[2] + all[kk].shap.size() == 11 * (all[kk].pos[1] - 1))
//								{
//									MoveTo(all[kk].pos[2] + all[kk].shap.size(), all[kk].pos[1]);
//									cout << get_back_ground();
//									all[kk].pos[1]--;
//								}
//								all[kk].pos[2] -= 1;
//								all[kk].shoot_CD[2] = 0;
//							}
//						}
//					}//����ֲ��
//				}
//			}//���в�ƺ
//		}
//	}//�����ӵ�
//}
//
//vector<Baseball> Baseball::all;
//
//void Baseball::print()
//{
//	vector<Baseball>::iterator it;
//	for (it = all.begin(); it != all.end(); it++)
//	{
//		MoveTo(it->pos[2], it->pos[3]);
//		cout << it->shap;
//	}
//}
//
//void Baseball::move()
//{
//	Lawn L;
//	for (size_t kk = 0; kk < this->get_num(); kk++)
//	{
//		if (pos[1] < 11)
//		{
//			for (size_t i = 0; i < L.get_num(); i++)
//			{
//				//�ҵ����ӵ�ǰһ����ƺ
//				if (L.all[i].pos[0] == this->pos[0] && L.all[i].pos[1] == this->pos[1] - 1)
//				{
//					for (size_t j = 0; j < L.all[i].what_P_AT.size(); j++)
//					{
//						//�������ֲ��
//						if (L.all[i].what_P_AT[j] == 0 || L.all[i].what_P_AT[j] == 9)//�Ѵ���Ҳ����
//						{
//							L.all[i].what_Z_AT.push_back(1);
//							L.all[i].how_much_Z_AT.push_back(all[kk].data[4]);
//							this->del_one_object(kk);
//						}
//						else
//						{
//							all[kk].shoot_CD[2]++;
//							if (all[kk].shoot_CD[2] == all[kk].shoot_CD[1])
//							{
//								MoveTo(all[kk].pos[2], all[kk].pos[3]);
//								for (size_t k = 0; k < all[kk].shap.size(); k++)
//									cout << " ";
//								if (all[kk].pos[2] + all[kk].shap.size() == 11 * (all[kk].pos[1] - 1))
//								{
//									MoveTo(all[kk].pos[2] + all[kk].shap.size(), all[kk].pos[1]);
//									cout << get_back_ground();
//									all[kk].pos[1]--;
//								}
//								all[kk].pos[2] -= 1;
//								all[kk].shoot_CD[2] = 0;
//							}
//						}
//					}//����ֲ��
//				}
//			}//���в�ƺ
//		}
//	}//�����ӵ�
//}
//
//vector<Chemist> Chemist::all;
//
//
//void Chemist::print()
//{
//	vector<Chemist>::iterator it;
//	for (it = all.begin(); it != all.end(); it++)
//	{
//		MoveTo(it->pos[2], it->pos[3]);
//		cout << it->shap;
//	}
//}
//
//void Chemist::move()
//{
//	Lawn L;
//	for (size_t kk = 0; kk < this->get_num(); kk++)
//	{
//		if (pos[1] < 11)
//		{
//			for (size_t i = 0; i < L.get_num(); i++)
//			{
//				//�ҵ����ӵ�ǰһ����ƺ
//				if (L.all[i].pos[0] == this->pos[0] && L.all[i].pos[1] == this->pos[1] - 1)
//				{
//					for (size_t j = 0; j < L.all[i].what_P_AT.size(); j++)
//					{
//						//�������ֲ��
//						if (L.all[i].what_P_AT[j] == 0 || L.all[i].what_P_AT[j] == 9)//�Ѵ���Ҳ����
//						{
//							L.all[i].what_Z_AT.push_back(1);
//							L.all[i].how_much_Z_AT.push_back(all[kk].data[4]);
//							this->del_one_object(kk);
//						}
//						else
//						{
//							all[kk].shoot_CD[2]++;
//							if (all[kk].shoot_CD[2] == all[kk].shoot_CD[1])
//							{
//								MoveTo(all[kk].pos[2], all[kk].pos[3]);
//								for (size_t k = 0; k < all[kk].shap.size(); k++)
//									cout << " ";
//								if (all[kk].pos[2] + all[kk].shap.size() == 11 * (all[kk].pos[1] - 1))
//								{
//									MoveTo(all[kk].pos[2] + all[kk].shap.size(), all[kk].pos[1]);
//									cout << get_back_ground();
//									all[kk].pos[1]--;
//								}
//								all[kk].pos[2] -= 1;
//								all[kk].shoot_CD[2] = 0;
//							}
//						}
//					}//����ֲ��
//				}
//			}//���в�ƺ
//		}
//	}//�����ӵ�
//}
