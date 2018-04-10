/*************************************************************************
	> File Name: singleton.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月22日 星期五 18时11分51秒
 ************************************************************************/

#include<iostream>
using namespace std;
class singleton
{
private:
    static singleton *instance = NULL;
    singleton(){};
public:
    singleton * getinstance()
    {
        if( instace == NULL )
        {
            lock();
            if( instance == NULL )
                instance = new singleton();
            unlock();
        }
        return instance;
    }
}
