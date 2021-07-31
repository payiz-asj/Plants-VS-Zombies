#ifndef  ASJ_CONTROL
#define  ASJ_CONTROL

#include <Windows.h>
#include <string>
#include <tchar.h>
#include <time.h>
#include<vector>
#include <iostream>
#include <conio.h>

#include "Plant.h"
#include "Zombie.h"
#include"Bullet.h"
#include "Tool.h"
#include "UI.h"
#include "Lawn.h"


using namespace std;

int Random(const int &a, const int &b);
void put_little_zombie();
int choose_plant(Plants *&p, vector<int> &pos);
int get_order();
void play();



void game_over();
#endif 