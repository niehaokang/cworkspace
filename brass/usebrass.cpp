/*************************************************************************
	> File Name: usebrass.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年04月07日 星期五 11时27分30秒
 ************************************************************************/

#include<iostream>
#include "brass.h"
using namespace std;

int main()
{
    using std::cout;
    using std::endl;

    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    BrassPlus nie(Piggy, 500, 0.01);
    nie.ViewAcct();
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;
    cout << "Deposite $1000 into Hogg Account; \n";
    Hoggy.Deposit(1000.00);
    cout << "New balance: $" << Hoggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Piggy Account: \n";
    Piggy.Withdraw(42000.00);
    cout << "Pigg account balance : $" << Piggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Hogg Account: \n";
    Hoggy.Withdraw(4200);
    Hoggy.ViewAcct();

    return 0;
}
