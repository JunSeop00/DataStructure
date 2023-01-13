#include "Account.h"

Bank::Bank()
{
	acno = 0;
	balance = 0;
	name = "";
	actype = "";
}

void Bank::init()
{
	cout << "New Account" << endl;
	cout << "Enter the Name of the depositor : ";
	cin >> name;
	cout << "Enter the Account Number : ";
	cin >> acno;
	cout << "Enter the Account Type : (CURR / SAVG / FD / RD / DMAT) ";
	cin >> actype;
	cout << "Enter the Amount to Deposit : ";
	cin >> balance;
}

void Bank::deposit()
{
	float money;
	cout << "Depositing" << endl;
	cout << "Enter the amount to deposit : ";
	cin >> money;
	balance += money;
}

void Bank::withdraw()
{
	float money;
	cout << "Withdrawl" << endl;
	cout << "Enter the amount to withdraw : ";
	cin >> money;
	balance -= money;
}

void Bank::disp_det()
{
	cout << "Account Details" << endl;
	cout << "Name of the depositor : " << name << endl;
	cout << "Account Number : " << acno << endl;
	cout << "Account Type : " << actype << endl;
	cout << "Balance : " << "$" << balance << endl;
}
