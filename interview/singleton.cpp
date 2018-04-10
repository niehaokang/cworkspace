/*************************************************************************
	> File Name: singleton.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月20日 星期三 19时20分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

class singleton_lazy
{
private:
    static singleton_lazy *instance;
    singleton_lazy(  );
    ~singleton_lazy(  );
    singleton_lazy( singleton_lazy & );
    singleton_lazy & operator =( const singleton_lazy & );
public:
public:
    static singleton_lazy & getinstance(  )
    {
        if( instance == NULL )
            instance = new singleton_lazy();
        return *instance;
    }
};

class singleton_eager
{
private:
    static singleton_eager instance;
private:
    singleton_eager();
    ~singleton_eager();
    singleton_eager( singleton_eager& );
    singleton_eager & operator =( const singleton_eager & );
public:
    static singleton_eager& getinstance()
    {
        return instance;
    }
};

class singleton_meyers
{
private:
    singleton_meyers();
    ~singleton_meyers();
    singleton_meyers( singleton_meyers & );
    singleton_meyers & operator =(singleton_meyers &);
public:
    static singleton_meyers & getinstance()
    {
        static singleton_meyers instance;
        return instance;
    }
};
