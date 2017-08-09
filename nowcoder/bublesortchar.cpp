 #include<iostream>
#include<string>
using namespace std;
 
int main()
{
    string s;
    bool need = true;
    char c;
    while(cin >> s)
    {
        need = true;
        for( int i = s.size() - 1; i > 0 && need; --i )
        {
            need = false;
            for( int j = 0; j < i; j++ )
                if( s[j] < 'a' && s[j+1] >= 'a' )
                {
                    need = true;
                    c = s[j];
                    s[j] = s[j+1];
                    s[j+1] = c;
                }
        }
        cout << s << endl;
    }
    return 0;
}
