
#include "Control.h"
#define  R 50
#define  z_l 3
//void old();


void menu()
{
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\t★---------------------------------------------★" << endl;
	cout << "\t\t\t           1.重新开始  2.退出游戏         " << endl;
	cout << "\t\t★---------------------------------------------★" << endl;
}



int main()
{
	int is_quit = 0;
	while (is_quit==0)
	{
		// 初始化屏幕（草坪）
		set_screen();
		//进行游戏
		play();
		//游戏结束
		menu();
		switch (_getch())
		{
		case '1':
				break;
		case '2':
			is_quit = 1;
			break;
		default:
			is_quit = 1;
			break;
		}

	}
	return 0;
}







//
//void old()
//{
//	string bullit = " > ";
//	int count = 0;
//	vector<int> location;
//	int m_l = 3;
//	int what_bullit = 0;
//	for (int i = 4, j = 0, k = R, m = 0; j < 10;)
//	{
//		MoveTo(0, j);
//		cout << "doudou";
//		if (count > 0)
//		{
//			for (int c2 = 0; c2 < count; c2++)
//			{
//				MoveTo(location[c2] + 1, j);
//				cout << bullit;
//				location[c2] += 1;
//			}
//		}
//		MoveTo(k, j);
//		cout << " 僵尸 ";
//		MoveTo(0, j + 1);
//		cout << "--------------------------------------------------------------";
//		i++;
//		k--;
//		if (i % 5 == 0)
//		{
//			MoveTo(5, j);
//			cout << bullit;
//			count++;
//			location.push_back(5);
//		}
//		if (count > 0)
//		{
//			if (location[what_bullit] == k - 2 || location[what_bullit] == k - 2 || location[what_bullit] == k - 2 || location[what_bullit] == k || location[what_bullit] == k - 1 || location[what_bullit] == k - 3 || location[what_bullit] == k - 4)
//			{
//				m_l--;
//				what_bullit++;
//			}
//		}
//		if (m_l < 0)
//		{
//			MoveTo(k + 1, j);
//			cout << "死尸";
//			j += 2;
//			i = 4;
//			k = R;
//			count = 0;
//			location.clear();
//			what_bullit = 0;
//			m_l = 3;
//		}
//		Sleep(300);
//	}
//}