#include "UI.h"
#include "User.h"

char back_ground_style = '.';
int zhiliuqu = 4;//草坪上方的滞留区，用来显示别的内容
int all_row = 5;
int all_col = 9;
int one_weight = 10;
int one_hight = 4;



vector<int> create_pos(const int &a, const int &b)
{
	vector<int> p;
	int xx, yy;
	p.push_back(a);
	p.push_back(b);
	xx = (one_weight+1 )* (b - 1) + 1;
	yy = (one_hight + 1)* (a - 1) + zhiliuqu + 1;
	p.push_back(xx);
	p.push_back(yy);
	return p;
}

char get_back_ground()
{
	return back_ground_style;
}
int * get_chicun()
{
	int a[4];
	a[0] = all_row;
	a[1] = all_col;
	a[2] = one_weight;
	a[3] = one_weight;
	int *pp = a;
	return pp;
}
vector<int> get_screen_data()
{
	vector<int> p;
	p.push_back(all_row);
	p.push_back(all_col);
	p.push_back(one_weight);
	p.push_back(one_hight);
	return p;
}
//实现屏幕定位
void MoveTo(int x, int y)
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crPlayer = { x, y };
	SetConsoleCursorPosition(hStd, crPlayer);
}

//wchar_t string2wchar(const string& s)
//{
//	int len;
//	int slength = (int)s.length() + 1;
//	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
//	wchar_t* buf = new wchar_t[len];
//	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
//	return *buf;
//}

void set_screen()
{
	// 获取标准输出设备句柄
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// 获取窗口缓冲区信息
	PCONSOLE_SCREEN_BUFFER_INFO bInfo = new CONSOLE_SCREEN_BUFFER_INFO;
	GetConsoleScreenBufferInfo(hOut, bInfo);
	
	// 设置窗口标题
	LPWSTR title = _T("植物大战僵尸ASJ版");
	//GetConsoleTitle(title, 255); // 获取窗口标题
	SetConsoleTitle(title);    

	/*COORD size = { 150, 37};
	SetConsoleScreenBufferSize(hOut, size);
	SMALL_RECT rc = { 0, 0, 140, 32 };
	SetConsoleWindowInfo(hOut, 1, &rc);*/

	//HWND ho = GetConsoleWindow();
	//MoveWindow(ho, 0, 0, 1000, 600, 1);
	
	
	//system("mode con cols=100 lines=25");   //用控制台方法实现
	
	//COORD pos = { 0, 0 };
	//FillConsoleOutputCharacter(hOut, 'A', bInfo->dwSize.X * bInfo->dwSize.Y,pos, NULL);

	//用API实现
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */
	HWND hwnd = GetForegroundWindow();
	
	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* 获取窗口信息 */
	/* 设置窗口信息 最大化 取消标题栏及边框 */
	//SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
	SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_MAXIMIZE)  & ~WS_THICKFRAME);
	
	COORD front_size;
	front_size.X = cx/8-1;
	front_size.Y = cy/18-3;
	SetConsoleScreenBufferSize(hOut, front_size);
	//SMALL_RECT rc = { 0, 0,front_size.X-1,front_size.Y-1 };
	//SetConsoleWindowInfo(hOut, 1, &rc);
	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx,cy, 0);
	//_tsetlocale(LC_ALL, _T("chs"));
	system(" CHCP 936");
	system("cls");
	//CloseHandle(hOut); // 关闭标准输出设备句柄	

	string my_title = "植物大战僵尸（ASJ版1.1.0）";
	//开场动画
	opening_animation(my_title);

	//注册和登录
	begin_menu(my_title);

	cin.clear();
	cin.sync();
	
	//设置墙体
	system("cls");
	select_back_ground();
	//init_screen(back_ground_style, all_row, all_col, one_weight, one_hight);
}

void print_one_character(int x,int y,vector<string> one)
{
	for (size_t i = 0; i < one.size(); i++)
	{
		MoveTo(x, y+i);
		cout << one[i];
		Sleep(100);
	}
}

void print_letter(int x, int y, vector<string> one)
{
	int a = 90, b = one.size()+1;
	for (int i = x; i <x+a; i++)
	{
		MoveTo(i, y);
		cout << "~";
		MoveTo(i, y+b+3);
		cout << "~";
	}
	//竖线
	for (int j = y; j < y+b+3; j++)
	{
		MoveTo(x, j);
		cout << ":";
		MoveTo(x+a, j);
		cout << ":";
	}
	y += 2;
	x += 2;
	for (size_t i = 0; i < one.size(); i++)
	{
		MoveTo(x, y + i);
		for (size_t j = 0; j < one[i].size(); j++)
		{
			cout << one[i][j];
			Sleep(50);
		}		
	}
	Sleep(1000);
}

void read_pic(string file_name,vector<string> &lines)
{
	ifstream in;
	in.open(file_name, ios::in);
	if (!in.is_open())
	{
		cerr << "文件" << file_name << "打开失败";
		//exit(-1)
	}
	else
	{
		while (!in.eof())
		{
			string str;
			getline(in, str);
			lines.push_back(str);
		}
	}
	in.close();
}




void opening_animation(const string &title)
{
	MoveTo(70, 1);
	
	for (size_t i = 0; i < title.size(); i++)
	{
		cout << title[i];
		Sleep(90);
	}
	Sleep(500);
	vector<string> intro;
	vector<string> pea;
	vector<string> cxk;
	read_pic("./pic/intro.txt", intro);
	read_pic("./pic/p.txt", pea);
	read_pic("./pic/z.txt", cxk);
	print_one_character(0, 3, pea);
	print_one_character(87, 5, cxk);	
	
	MoveTo(70, 30);
	cout << "---《按任意键开始游戏》---";
	Sleep(3000);
	_getch();
	system("cls");
	print_letter(37, 2, intro);
	cin.clear();
	cin.sync();
	MoveTo(60, 34);
	cout << "---《这么嚣张！有本事自己来拿！！！》---";
	Sleep(3000);
	_getch();
	cin.clear();
	cin.sync();

}


void begin_menu(const string &title)
{
	//登录注册界面
	User me;
	int is_can_play = 0;
	while (!is_can_play)
	{
		system("cls");
		MoveTo(70, 1);
		cout << title;
		MoveTo(60, 10);
		cout << "玩家名：";
		MoveTo(60, 12);
		cout << "密码：";
		MoveTo(60, 15);
		cout << "1.登录\t2.注册";
		MoveTo(70, 10);
		cin >> me.name;
		MoveTo(68, 12);
		cin >> me.pass_word;
		switch (_getch())
		{
		case '1':
			is_can_play = me.log_in();
			break;
		case '2':
			is_can_play = me.sign_up();
			break;
		default:
			break;
		}
	}
	//登陆成功
	cin.clear();
	cin.sync();
}


void select_back_ground()
{

	size_t flag = 0;
	int if_quit = 0;
	vector<char> p = { '.', ',', '-','x', '@', '#', 'c', 'v', '/', '\\', '5' };
	//int ppppp = _getch();
	cin.clear();
	cin.sync();
	while (1)
	{
		MoveTo(55, 1);
		cout << "植物大战僵尸（ASJ版1.1.0）";
		MoveTo(35, 2);
		cout << "墙体设置：请按 向上键(或s) 、向下键(或s)进行选择，按 Enter 进行确认 ";
		int key1 = _getch();
		if (key1 == 13)
		{
			init_screen(p[flag],all_row,all_col,one_weight,one_hight);
			break;
		}

		int key2 = _getch();

		//if (_kbhit())
		switch (key2)
		{
		case 13:
			init_screen(p[flag], all_row, all_col, one_weight, one_hight);
			if_quit = 1;
			break;
		case 72:
			if (flag > 0)
				flag--;
			else
				flag = p.size() - 1;
			init_screen(p[flag], all_row, all_col, one_weight, one_hight);
			break;
		case 80:
			if (flag < p.size() - 1)
				flag++;
			else
				flag = 0;
			init_screen(p[flag], all_row, all_col, one_weight, one_hight);
			break;
		default:
			if (key1 == 119)
			{
				if (flag > 0)
					flag--;
				else
					flag = p.size() - 1;
				init_screen(p[flag], all_row, all_col, one_weight, one_hight);
				break;
			}
			else if (key1 == 115)
			{
				if (flag < p.size() - 1)
					flag++;
				else
					flag = 0;
				init_screen(p[flag], all_row, all_col, one_weight, one_hight);
				break;
			}
			else
			{
				flag = 0;
				init_screen(p[flag], all_row, all_col, one_weight, one_hight);
				break;
			}
		}
		if (if_quit)
			break;
	}
	back_ground_style = p[flag];
}

void init_screen(char wall,int row,int col,int weight,int hight)
{
	system("cls");
	int count = 0;
	for (int j = zhiliuqu; j < (row*(hight+1)+1+zhiliuqu); j++)
	{
		//画连续的横线
		if (count == hight+1 || j == zhiliuqu)
		{
			for (int i = 0; i <(col*(weight+1)+1); i++)
			{
				MoveTo(i, j);
				cout <<wall;
			}
			count = 0;
		}
		else
		{
			//画跳跃的点，即中间空的草坪区域
			for (int i = 0; i < (col*(weight + 1) + 1); i +=(weight+1))
			{
				MoveTo(i, j);
				cout <<wall;
			}
		}
		count++;
	}
	
	//画出僵尸产生区
	int how_far = 30;
	//横线
	for (int i = (col*(weight + 1) + 1); i < (col*(weight + 1) + 1)+how_far; i++)
	{
		MoveTo(i, zhiliuqu);
		cout << "!";
		MoveTo(i, (row*(hight + 1) + 1 + zhiliuqu)-1);
		cout <<"!";
	}
	//竖线
	for (int j = zhiliuqu; j < (row*(hight + 1) + 1 + zhiliuqu); j++)
	{
		MoveTo((col*(weight + 1) + 1) + how_far, j);
		cout << "!";
	}

	//画出积分区
	//横线
	for (int i = (col*(weight + 1) + 1) + how_far + 8; i <= (col*(weight + 1) + 1) + how_far+8+30; i++)
	{
		MoveTo(i, zhiliuqu);
		cout << "-";
	}
	//竖线
	for (int j = 0; j <= 38; j++)
	{
		MoveTo((col*(weight + 1) + 1) + how_far+8, j);
		cout << "|";
	}
	MoveTo((col*(weight + 1) + 1) + how_far + 10, 1);
	cout << "玩家：";
	MoveTo((col*(weight + 1) + 1) + how_far + 10, 2);
	cout << "金币：";
	MoveTo((col*(weight + 1) + 1) + how_far + 17,zhiliuqu+2);
	cout << "---《财富榜》---";

	//画出商店
	//横线
	for (int i = 0; i <= (col*(weight + 1) + 1) + how_far; i++)
	{
		MoveTo(i, (row*(hight + 1) + 1 + zhiliuqu)+1);
		cout << "$";
		MoveTo(i, 38);
		cout << "$";
	}
	//竖线
	for (int j = (row*(hight + 1) + 1 + zhiliuqu)+1; j < 38; j++)
	{
		MoveTo(0, j);
		cout << "$";
		MoveTo((col*(weight + 1) + 1) + how_far, j);
		cout << "$";
	}

	MoveTo(55, (row*(hight + 1) + 1 + zhiliuqu) + 2);
	cout << "---《商店》---";




}