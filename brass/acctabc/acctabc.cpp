/*************************************************************************
	> File Name: acctABC.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月07日 星期五 17时06分19秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

#include "acctabc.h"

AcctABC :: AcctABC(const char *s, long an, double bal)
{
    strncpy(fullName, s, MAX - 1);
    fullName[MAX - 1] = '\0';
    acctNum = an;
    balance = bal;
}

void AcctABC :: Deposit(double amt)
{
    if(amt < 0)
        cout << "Negative deposit not allowed; deposit is cancelled.\n";
    else
        balance += amt;
}

void AcctABC :: Withdraw(double amt)
{
    balance -= amt;
}

ios_base::fmtflags AcctABC::SetFormat() const
{
    ios_base :: fmtflags initialState = cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);
    return initialState;
}

void Brass :: Withdraw(double amt)
{
    if(amt < 0)
        cout << "Withdrawal amount must be positive; withdrawal cancelled.\n";
    else if(amt <= Balance())
        AcctABC::Withdraw(amt);
    else
        cout << "Withdrawal amount of $" << amt << " exceeds you balance. \n" << "Withdrawal cancelled.\n";
}

void Brass::ViewAcct()const
{
    ios_base::fmtflags initialState = SetFormat();
    cout << "Brass Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout.setf(initialState);
}

BrassPlus::BrassPlus(const char *s, long an, double bal, double ml, double r):AcctABC(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r): AcctABC(ba)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct()const
{
    ios_base::fmtflags initialState = SetFormat();
    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Balance: $" << Balance() << endl;
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout << "Loan Rate: " << rate * 100 << "%\n";
    cout.setf(initialState);
}

void BrassPlus::Withdraw(double amt)
{
    ios_base::fmtflags initialState = SetFormat();
    double bal = Balance();

    if(amt <= bal)
        AcctABC::Withdraw(amt);
    else if(amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else
        cout << "Credit limit exceed. Transaction cancelled.\n";
    cout.setf(initialState);
}
