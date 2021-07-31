#pragma once 
#ifndef  ASJ_UI
#define  ASJ_UI

#include <Windows.h>
#include <string>
#include <tchar.h>
#include <time.h>
#include<vector>
#include <iostream>
#include<fstream>
#include <conio.h>
using namespace std;

wchar_t string2wchar(const string& s);
void modeset(int w, int h);
void set_screen();
void print_one_character(int x, int y, vector<string> one);
void print_letter(int x, int y, vector<string> one);
void read_pic(string file_name, vector<string> &lines);
void opening_animation(const string &title);
void begin_menu(const string &title);
void MoveTo(int x, int y);
void select_back_ground();
void init_screen(char wall, int row, int col, int weight, int hight);

vector<int> get_screen_data();
vector<int> create_pos(const int &a, const int &b);
char get_back_ground();
int * get_chicun();



#endif 