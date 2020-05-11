#include <iostream>
#include <stdlib.h>
#include "MyMazeMap.h"
#include "MyMazer.h"

using namespace std;

const int WALL = 1;
const int ROAD = 0;
const int SLOW = 3;
const int MEDIUM = 2;
const int FAST = 1;

const int SUCCESS = 0;
int main()
{
	int map[8][9] = {
					{WALL,WALL,WALL,WALL,WALL,WALL,WALL,ROAD,WALL},
					{WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
					{WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
					{WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
					{WALL,WALL,ROAD,ROAD,ROAD,ROAD,WALL,ROAD,WALL},
					{WALL,WALL,ROAD,WALL,WALL,ROAD,ROAD,ROAD,WALL},
					{WALL,ROAD,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
					{WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL,WALL}
	};
	MyMazeMap maze;

	maze.setMazeMap(&map[0][0], 8, 9);
	maze.setMazeWall('*');
	//maze.showFactor();
	maze.drawMap();
	MyMazer mazer;
	mazer.map = maze;
	mazer.setPersonPosition(7, 1);
	mazer.setPersonSpeed(FAST);
	mazer.setPersonChar('T');
	mazer.start();
	
	cout << endl;
	system("pause");
	return SUCCESS;
}