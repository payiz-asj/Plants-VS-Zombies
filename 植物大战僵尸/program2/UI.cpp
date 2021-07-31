#include "UI.h"
#include "User.h"

char back_ground_style = '.';
int zhiliuqu = 4;//��ƺ�Ϸ�����������������ʾ�������
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
//ʵ����Ļ��λ
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
	// ��ȡ��׼����豸���
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// ��ȡ���ڻ�������Ϣ
	PCONSOLE_SCREEN_BUFFER_INFO bInfo = new CONSOLE_SCREEN_BUFFER_INFO;
	GetConsoleScreenBufferInfo(hOut, bInfo);
	
	// ���ô��ڱ���
	LPWSTR title = _T("ֲ���ս��ʬASJ��");
	//GetConsoleTitle(title, 255); // ��ȡ���ڱ���
	SetConsoleTitle(title);    

	/*COORD size = { 150, 37};
	SetConsoleScreenBufferSize(hOut, size);
	SMALL_RECT rc = { 0, 0, 140, 32 };
	SetConsoleWindowInfo(hOut, 1, &rc);*/

	//HWND ho = GetConsoleWindow();
	//MoveWindow(ho, 0, 0, 1000, 600, 1);
	
	
	//system("mode con cols=100 lines=25");   //�ÿ���̨����ʵ��
	
	//COORD pos = { 0, 0 };
	//FillConsoleOutputCharacter(hOut, 'A', bInfo->dwSize.X * bInfo->dwSize.Y,pos, NULL);

	//��APIʵ��
	int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� ���� */
	int cy = GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� ���� */
	HWND hwnd = GetForegroundWindow();
	
	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* ��ȡ������Ϣ */
	/* ���ô�����Ϣ ��� ȡ�����������߿� */
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
	//CloseHandle(hOut); // �رձ�׼����豸���	

	string my_title = "ֲ���ս��ʬ��ASJ��1.1.0��";
	//��������
	opening_animation(my_title);

	//ע��͵�¼
	begin_menu(my_title);

	cin.clear();
	cin.sync();
	
	//����ǽ��
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
	//����
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
		cerr << "�ļ�" << file_name << "��ʧ��";
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
	cout << "---�����������ʼ��Ϸ��---";
	Sleep(3000);
	_getch();
	system("cls");
	print_letter(37, 2, intro);
	cin.clear();
	cin.sync();
	MoveTo(60, 34);
	cout << "---����ô���ţ��б����Լ����ã�������---";
	Sleep(3000);
	_getch();
	cin.clear();
	cin.sync();

}


void begin_menu(const string &title)
{
	//��¼ע�����
	User me;
	int is_can_play = 0;
	while (!is_can_play)
	{
		system("cls");
		MoveTo(70, 1);
		cout << title;
		MoveTo(60, 10);
		cout << "�������";
		MoveTo(60, 12);
		cout << "���룺";
		MoveTo(60, 15);
		cout << "1.��¼\t2.ע��";
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
	//��½�ɹ�
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
		cout << "ֲ���ս��ʬ��ASJ��1.1.0��";
		MoveTo(35, 2);
		cout << "ǽ�����ã��밴 ���ϼ�(��s) �����¼�(��s)����ѡ�񣬰� Enter ����ȷ�� ";
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
		//�������ĺ���
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
			//����Ծ�ĵ㣬���м�յĲ�ƺ����
			for (int i = 0; i < (col*(weight + 1) + 1); i +=(weight+1))
			{
				MoveTo(i, j);
				cout <<wall;
			}
		}
		count++;
	}
	
	//������ʬ������
	int how_far = 30;
	//����
	for (int i = (col*(weight + 1) + 1); i < (col*(weight + 1) + 1)+how_far; i++)
	{
		MoveTo(i, zhiliuqu);
		cout << "!";
		MoveTo(i, (row*(hight + 1) + 1 + zhiliuqu)-1);
		cout <<"!";
	}
	//����
	for (int j = zhiliuqu; j < (row*(hight + 1) + 1 + zhiliuqu); j++)
	{
		MoveTo((col*(weight + 1) + 1) + how_far, j);
		cout << "!";
	}

	//����������
	//����
	for (int i = (col*(weight + 1) + 1) + how_far + 8; i <= (col*(weight + 1) + 1) + how_far+8+30; i++)
	{
		MoveTo(i, zhiliuqu);
		cout << "-";
	}
	//����
	for (int j = 0; j <= 38; j++)
	{
		MoveTo((col*(weight + 1) + 1) + how_far+8, j);
		cout << "|";
	}
	MoveTo((col*(weight + 1) + 1) + how_far + 10, 1);
	cout << "��ң�";
	MoveTo((col*(weight + 1) + 1) + how_far + 10, 2);
	cout << "��ң�";
	MoveTo((col*(weight + 1) + 1) + how_far + 17,zhiliuqu+2);
	cout << "---���Ƹ���---";

	//�����̵�
	//����
	for (int i = 0; i <= (col*(weight + 1) + 1) + how_far; i++)
	{
		MoveTo(i, (row*(hight + 1) + 1 + zhiliuqu)+1);
		cout << "$";
		MoveTo(i, 38);
		cout << "$";
	}
	//����
	for (int j = (row*(hight + 1) + 1 + zhiliuqu)+1; j < 38; j++)
	{
		MoveTo(0, j);
		cout << "$";
		MoveTo((col*(weight + 1) + 1) + how_far, j);
		cout << "$";
	}

	MoveTo(55, (row*(hight + 1) + 1 + zhiliuqu) + 2);
	cout << "---���̵꡷---";




}