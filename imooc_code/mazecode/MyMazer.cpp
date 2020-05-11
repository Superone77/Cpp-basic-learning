#include<iostream>
#include <windows.h>
#include<stdio.h>
#include"MyMazer.h"
#include"MyMazeMap.h"

using namespace std;

const int UP = 0;
const int LEFT = 1;
const int DOWN = 2;
const int RIGHT = 3;

void
MyMazer::gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = y;
	pos.Y = x;
	SetConsoleCursorPosition(hOut, pos);
}

MyMazer::MyMazer()
{
	direction = UP;
}

void 
MyMazer::setPersonPosition(int x, int y)
{
	PersonX = x;
	PersonY = y;
	gotoxy(PersonX, PersonY);
}
void 
MyMazer::setPersonSpeed(int speed)
{
	SleepTime = speed * 500;
}

void 
MyMazer::setPersonChar(char personchar)
{
	PersonChar = personchar;
	cout << PersonChar;
}
void 
MyMazer::start()
{
	while (true)
	{
		switch (MyMazer::turnDirection())
		{
		case UP:direction = UP; direction_up(); break;
		case RIGHT:direction = RIGHT; direction_right(); break;
		case LEFT:direction = LEFT; direction_left(); break;
		case DOWN:direction = DOWN; direction_down(); break;
		}
	}
}
void 
MyMazer::direction_up()
{

		LastPersonX = PersonX;
		LastPersonY = PersonY;
		PersonX = PersonX - 1;
		gotoxy(LastPersonX, LastPersonY);
		cout << map.m_waySign;
		gotoxy(PersonX, PersonY);
		cout << PersonChar;
		Sleep(SleepTime);
	
}
void 
MyMazer::direction_down()
{
	
		LastPersonX = PersonX;
		LastPersonY = PersonY;
		PersonX = PersonX + 1;
		gotoxy(LastPersonX, LastPersonY);
		cout << map.m_waySign;
		gotoxy(PersonX, PersonY);
		cout << PersonChar;
		Sleep(SleepTime);
	
}
void 
MyMazer::direction_left()
{
	LastPersonX = PersonX;
	LastPersonY = PersonY;
	PersonY = PersonY-1;
	gotoxy(LastPersonX, LastPersonY);
	cout << map.m_waySign;
	gotoxy(PersonX, PersonY);
	cout << PersonChar;
	Sleep(SleepTime);
}
void 
MyMazer::direction_right()
{
	LastPersonX = PersonX;
	LastPersonY = PersonY;
	PersonY = PersonY + 1;
	gotoxy(LastPersonX, LastPersonY);
	cout << map.m_waySign;
	gotoxy(PersonX, PersonY);
	cout << PersonChar;
	Sleep(SleepTime);
}

int 
MyMazer::turnDirection()
{
	if (direction == UP) 
	{
		if (PersonX == 0)
		{
			cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			cout << "successful" << endl;
			system("pause");
			exit(0);
		}

		if (map.checkWall(PersonX,PersonY-1))
		{
			if (!map.checkWall(PersonX - 1, PersonY))

				return UP;
			else if (!map.checkWall(PersonX, PersonY + 1))
				return RIGHT;
			else 
				return DOWN;
		}
		else
				return LEFT;
	}
	if (direction == RIGHT)
	{
		if (PersonY == map.getmazeY())
		{
			cout << endl << endl << endl << endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout << "successful" << endl;
			system("pause");
			exit(0);
		}

		if (map.checkWall(PersonX-1, PersonY))
		{
			if (!map.checkWall(PersonX, PersonY + 1))

				return RIGHT;
			else if (!map.checkWall(PersonX + 1, PersonY))
				return DOWN;
			else
				return LEFT;
		}
		else
				return UP;
	}

	if (direction == DOWN)
	{
		if (PersonX == map.getmazeX())
		{
			cout << endl << endl << endl;
			cout << "successful" << endl;
			system("pause");
			exit(0);
		}

		if (map.checkWall(PersonX, PersonY+1))
		{
			if (!map.checkWall(PersonX+1, PersonY))

				return DOWN;
			else if (!map.checkWall(PersonX, PersonY-1))
				return LEFT;
			else
				return UP;
		}
		else
				return RIGHT;
	}
	if (direction == LEFT)
	{
		if (PersonY == 0)
		{
			cout << endl << endl << endl;
			cout << "successful" << endl;
			system("pause");
			exit(0);
		}

		if (map.checkWall(PersonX+1, PersonY ))
		{
			if (!map.checkWall(PersonX, PersonY-1))
				return LEFT;
			else if (!map.checkWall(PersonX-1, PersonY))
				return UP;
			else
				return RIGHT;
		}
		else
				return DOWN;
	}

}  