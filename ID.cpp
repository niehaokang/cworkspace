/*************************************************************************
	> File Name: ID.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年08月25日 星期五 20时42分33秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>
#define char_to_int(c) ( c - '0' )
using namespace std;

string verify( string id, string *regionArray, int regionlen );

bool isvalid_birthdate( string birthdate );

bool isvalid_checkcode( char id);

int main()
{
    string id = "411481199408033315";
    string regionArray[] = { "110101", "110102", "411481" };
    verify( id, regionArray, 3 );
    return 0;
}

bool isvalid_birthdate( string birthdate )
{
    string year = birthdate.substr( 0, 4 );
    string month = birthdate.substr( 4, 2 );
    string day = birthdate.substr( 6, 2 );
    return true;
}

bool isvalid_checkcode( string id)
{
    unsigned int temp = 0;
    int checkcode;

    if( id[17] == 'x' )
        checkcode = 10;
    else
        checkcode = char_to_int(id[17]);

    for( int i = 0; i < 17; i++ )
        temp += char_to_int( id[i] ) << ( 17 - i );
    if( (temp + checkcode) % 11 == 1 )
        return true;
    else
        return false;
}

string verify( string id, string *regionArray, int regionlen )
{
    bool valid = false;
    string result;
    string regioncode = id.substr( 0, 6 );
    string birthdate = id.substr( 6, 8 );
    int i = 0;
    while( i < regionlen )
    {
        if( regioncode == regionArray[i] )
        {
            valid = true;
            break;
        }
        ++i;
    }
    if( valid )
        valid = isvalid_birthdate( birthdate );
    else
    {
        result = "invalid";
        return result;
    }
    if( valid )
        valid = isvalid_checkcode( id );
    else
    {
        result = "invalid";
        return result;
    }
    if( valid )
    {
        if( char_to_int(id[17]) % 2 )
            result = "Male";
        else
            result = "Female";
    }
    else
        result = "Invalid";
    cout << result << endl;
    return result;
}
