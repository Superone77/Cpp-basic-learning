#pragma once
#include<iostream>

using namespace std;

class MyMazeMap
{
public:
	MyMazeMap();
	MyMazeMap(const MyMazeMap& C);
	void setMazeMap(int *mazeArr, int x, int y);
	void setMazeWall(const char wallSign);
	void setMazeWay(const char waySign);
	void showFactor();
	void drawMap();
    bool checkWall(int x, int y);
	int getmazeX();
	int getmazeY();
	char m_wallSign;
	char m_waySign;
private:
	int m_mazeArr[10][10];
	int m_mazeX;
	int m_mazeY;
	
	

};
