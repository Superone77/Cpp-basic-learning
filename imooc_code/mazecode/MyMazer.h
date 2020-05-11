#pragma once\
#include<iostream>
#include"MyMazeMap.h"

using namespace std;

class MyMazer
{
public:
	MyMazer();
	MyMazeMap map;
	void setPersonPosition(int x, int y);
	void setPersonSpeed(int speed);
	void setPersonChar(char personchar);
	void start();
private:
	int LastPersonX;
	int LastPersonY;
	int PersonX;
	int PersonY;
	int SleepTime;
	char PersonChar;
	int direction;
private:
	void gotoxy(int x, int y);
	void direction_up();
	void direction_down();
	void direction_left();
	void direction_right();
	int turnDirection();
	
	
	
	
	
	

};
