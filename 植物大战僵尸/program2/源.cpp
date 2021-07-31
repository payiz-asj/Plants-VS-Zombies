//#include<iostream>
//#include<stdlib.h>
//#include<Windows.h>
//
//using namespace std;
//
//int crzn[100];
//int crznn = 0;
//int crcrzn = 0;
//void getnumber()
//{
//	for (crcrzn = 0; crcrzn < 100; crcrzn++)
//	{
//		crzn[crcrzn] = rand() % 5;
//	}
//}
//
//int map[5][9] =
//{
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//};
//
//void cw()
//{
//	cout << "plant at?" << endl;
//	int a, b;
//	cin >> a >> b;
//	if ((a > 0 && a < 6) && (b>0 && b < 9))
//	{
//		if (map[a - 1][b - 1] != 0)
//			cout << "not empty" << endl;
//		else
//			map[a - 1][b - 1] = 1;
//	}
//	else cout << "wrong!" << endl;
//}
//
//void cz()
//{
//	int line;
//	line = crzn[crznn % 100];
//	crznn++;
//	map[line][8] = 2;
//}
//
//void mz()
//{
//	int i, j;
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 9; j++)
//		{
//			if (map[i][j] == 2 && j != 0)
//			{
//				map[i][j - 1] = 2;
//				map[i][j] = 0;
//			}
//			else if (map[i][j] == 2 && j == 0)
//			{
//				system("cls");
//				cout << "zombie eat your brain!!" << endl;
//				break;
//			}
//		}
//	}
//}
//
//void kz()
//{
//	int i, j, k;
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 9; j++)
//		{
//			if (map[i][j] == 1)
//			{
//				for (k = j; k < 9; k++)
//				{
//					if (map[i][k] == 2)
//					{
//						map[i][k] = 0;
//						break;
//					}
//				}
//			}
//		}
//	}
//}
//
//
//
//
//
//
//
//void print()
//{
//	int i, j;
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 9; j++)
//		{
//			if (map[i][j] == 0)
//				cout << " ";
//			else if (map[i][j] == 1)
//				cout << "¡ú";
//			else if (map[i][j] == 2)
//				cout << "¡â";
//
//		}
//		cout << endl;
//	}
//	cout << "fresh per second.0 is empty,1 is plant,2 is zombie" << endl << "one plant kill one zombie in 1 second" << endl;
//}
//
//void main()
//{
//	getnumber();
//	for (int i = 0; i < 120; i++)
//	{
//		print();
//
//
//		mz();
//		cz();
//		kz();
//
//		cw();
//		system("cls");
//	}
//}
