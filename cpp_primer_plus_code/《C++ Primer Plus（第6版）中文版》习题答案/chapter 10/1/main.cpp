#include <iostream>

using namespace std;

class TBankAccount
{
public:
	TBankAccount (string name, string acc_num, unsigned balance);

	void showName (void) const;
	void showAccNum (void) const;
	void showBalance (void) const;

	void incDeposit (unsigned amount);
	void decDeposit (unsigned amount);

private:
	string		m_name;
	string		m_acc_num;
	unsigned	m_balance;
};

TBankAccount::TBankAccount (string name, string acc_num, unsigned balance)
{
	m_name = name;
	m_acc_num = acc_num;
	m_balance = balance;
}

void
TBankAccount::showName (void) const
{
	cout << m_name;
}

void
TBankAccount::showAccNum (void) const 
{
	cout << m_acc_num;
}

void
TBankAccount::showBalance (void) const
{
	cout << m_balance;
}

void
TBankAccount::incDeposit (unsigned amount)
{
	m_balance += amount;
}

void
TBankAccount::decDeposit (unsigned amount)
{
	if (m_balance <= amount) {
		m_balance = 0;
	} else {
		m_balance -= amount;
	}
}

int
main (void) 
{     
	TBankAccount	yangyang("yangyang", "1", 1024);
	yangyang.showName();
	cout << endl;
	yangyang.showAccNum();
	cout << endl;
	yangyang.showBalance();
	cout << endl;

	yangyang.incDeposit(128);
	cout << endl;
	yangyang.showBalance();
	cout << endl;

	yangyang.decDeposit(2048);
	cout << endl;
	yangyang.showBalance();
	cout << endl;


	cout << endl;
	return (0);
} 
