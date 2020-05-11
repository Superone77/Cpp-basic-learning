慕课网C++课程封装篇作业，自动走迷宫；
https://www.imooc.com/learn/405

遇到的问题与解决方案：
1.在构建地图的MyMazeMap类和小人移动的MyMazer类的交互上出现问题。
解决方案：在MyMazer类中在堆中建立MyMazeMap类对象map，使用拷贝构造函数将主程序中的建立的maze对象拷贝进入MyMazer类对象map中，使得构建地图的成员和成员函数可以被利用到MyMazer的方法中。
即通过map.（）

2.光标的移动方式与迷宫建立的坐标系的差异
使用头文件windows.h中的光标相关操作。

```
void
MyMazer::gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = y;
	pos.Y = x;
	SetConsoleCursorPosition(hOut, pos);
}
```
光标的移动方式是以，屏幕水平方向为x轴，竖直方向为y轴。

迷宫的建立方式则是以，屏幕水平方向为y轴，竖直方向为x轴。

```
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
```

所以在以上光标移动函数gotoxy中将，x,y对调输入。

3.行动方式选择
解决方法：转向函数+上下左右前进函数
上下左右前进函数负责在抹去原来位置的人，并且在他旁边指定方向的一格处输出新的人。
转向函数则是通过走迷宫的左手法则，即无论在什么方向上都可以进行判断：
是否已在迷宫最外层——是，SUCCESS
|
|
不是，左边是否有墙——没有，左转。
|
|
有，前方是否有墙——没有，前进
|
|
有，右方是否有墙——没有，右转
|
|
有，后退；

通过switch对转向函数的输出做判断，调用前进函数。

4.如何控制速度；
Sleep语句
Sleep（n）(windows.h)
程序暂停n毫秒。

5.如何在程序运行中退出程序
exit(0)，正常运行后退出程序。


C++新手，还会继续努力。