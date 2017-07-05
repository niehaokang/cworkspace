/*************************************************************************
	> File Name: vect.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年06月12日 星期一 09时36分16秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Review
{
    string title;
    int rating;
};

bool FillReview( Review & rr );
void ShowReview( const Review & rr );

int main()
{
    vector<Review> books;
    Review temp;
    while( FillReview( temp ) )
        books.push_back( temp );
    int num = books.size();
    if( num > 0 )
    {
        cout << "Thank you. You entered the following:\n" << "Rating\tBook\n";
        for( int i = 0; i < num; i++ )
            ShowReview(books[i]);
        cout << "Reprising:\n" << "Rating\tBook\n";
        vector<Review>::iterator pr;
        for( pr = books.begin(); pr != books.end(); pr++ )
            ShowReview(*pr);
        vector<Review> oldlist(books);
        if( num > 3 )
        {
            books.erase(books.begin() + 1, books.begin() + 3);
            cout << "After arasure:\n";
            for( pr = books.begin(); pr != books.end(); pr++ )
                ShowReview(*pr);
            books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
            cout << "After insertion:\n";
            for( pr = books.begin(); pr != books.end(); pr++ )
                ShowReview(*pr);
        }
        books.swap(oldlist);
        cout << "Swappin oldlist with books:\n";
        for( pr = books.begin(); pr != books.end(); pr++ )
            ShowReview(*pr);
    }
    else
        cout <<"Nothing entered, nothing gained.\n";
    return 0;
}

bool FillReview( Review &rr )
{
    cout << "Entered book title (quit to quit): ";
    getline(cin, rr.title);
    if( rr.title == "quit" )
        return false;
    cout << "Enter book rating: ";
    cin >> rr.rating;
    if( !cin )
        return false;
    cin.get();
    return true;
}

void ShowReview( const Review &rr )
{
    cout << rr.rating << "\t" << rr.title << endl;
}