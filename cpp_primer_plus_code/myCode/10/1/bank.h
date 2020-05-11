#include <iostream>
#include<string>

using namespace std;

class bank 
{
public:
	bank(string name,string number,unsigned money);
	~bank();
	void showName();
	void showNumber();
	void showMoney();
	void increaseMoney(unsigned amount);
	void decreaseMoney(unsigned amount);
private:
	string m_name;
	string m_number;
	unsigned m_money;
};
