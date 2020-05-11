#include<iostream>
#include"MyMazeMap.h"

using namespace std;

MyMazeMap::MyMazeMap()
{
	m_wallSign = '+';
	m_waySign = ' ';
}

MyMazeMap::MyMazeMap(const MyMazeMap &b)
{
	m_wallSign=b.m_wallSign;
	m_waySign = b.m_waySign;
	m_mazeX = b.m_mazeX;
	m_mazeY = b.m_mazeY;
	for (int i = 0; i < m_mazeX; i++)
	{
		for (int j = 0; j < m_mazeY; j++) {
			m_mazeArr[i][j] = b.m_mazeArr[i][j];
		}
	}


}

void 
MyMazeMap::setMazeMap(int *mazeArr, int x, int y)
{
	m_mazeArr[0][0] = *mazeArr;

	m_wallSign = '+';
	m_waySign = ' ';

	int k = 0;

	if (x > 10) {
		x = 10;
		
	}
	if (y > 10) {
		y = 10;
	    k = y - 10;
	}
	m_mazeX = x;
	m_mazeY = y;
	for (int i = 0; i < m_mazeX; i++)
	{
		for (int j = 0; j < m_mazeY; j++) {
			m_mazeArr[i][j] = *mazeArr;
			*mazeArr++;
		}
		*mazeArr = *mazeArr+k;
	}
}

void 
MyMazeMap::setMazeWall(const char wallSign)
{
	m_wallSign = wallSign;
}
void 
MyMazeMap::setMazeWay(const char waySign)
{
	m_waySign = waySign;
}

void 
MyMazeMap::showFactor()
{
	cout << m_mazeArr[0][0] << endl;
	cout << m_mazeX << endl;
	cout << m_mazeY << endl;
	cout << m_wallSign << " " << m_waySign << endl;
}
void 
MyMazeMap::drawMap()
{
	for (int i = 0; i < m_mazeX; i++)
	{
		for (int j = 0; j < m_mazeY; j++) {
			if (m_mazeArr[i][j] == 1)
				cout << m_wallSign;
			else
				cout << m_waySign;
		}
		cout << endl;
	}
}
bool
MyMazeMap::checkWall(int x, int y)
{
	if (x==-1||y==-1||x==getmazeX()||y==getmazeY())
	{
		return false;
	}
	else if (m_mazeArr[x][y] == 1)
	{
		return true;
	}
	else return false;
}

int 
MyMazeMap::getmazeX()
{
	return m_mazeX;
}
int 
MyMazeMap::getmazeY()
{
	return m_mazeY;
}