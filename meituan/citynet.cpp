/*************************************************************************
	> File Name: citynet.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月22日 星期六 20时18分16秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
struct btree
{
    int data;
    struct btree *left;
    struct btree *right;
};

void preordersearch( struct btree *root );

int main()
{
    int n, q;
    cin >> n >> q;
    int i, j;
    int val[n];
    int line[n][2];
    int travel[q][3];
    for( i = 0; i < n; i++  )
        cin >> val[i];
    for( i = 0; i < n - 1; i++ )
        cin >> line[i][0] >> line[i][1];
    for( i = 0; i < q; i++ )
        cin >> travel[i][0] >> travel[i][1] >> travel[i][2];
    /*
    for( i = 0; i < n; i++  )
        cout << val[i] << " ";
    cout << endl;
    for( i = 0; i < n - 1; i++ )
    {
        cout << line[i][0] << " " << line[i][1];
        cout << endl;
    }
    for( i = 0; i < q; i++ )
    {
        cout << travel[i][0] << " " << travel[i][1] << " "<< travel[i][2];
        cout << endl;
    }
    */
    struct btree * btreearray[n];
    struct btree * root = NULL;
    struct btree *temp, *child;
    for( i = 0; i < n; i++ )
    {
        temp = new struct btree;
        temp->data = val[i];
        temp->left = NULL;
        temp->right = NULL;
        btreearray[i] = temp;
    }

    for( i = 0; i < n; i++ )
        cout << btreearray[i]->data << " ";
    cout << endl;

    for( i = 0; i < n - 1; i++ )
    {
        if(btreearray[line[i][0] - 1]->left == NULL)
            btreearray[line[i][0] - 1]->left = btreearray[line[i][1] - 1];
        else
            btreearray[line[i][0] - 1]->right = btreearray[line[i][1] - 1];
    }
    root = btreearray[0];
    preordersearch( root );
    return 0;
}

void preordersearch( struct btree *root )
{
    if( root == NULL )
        return;
    cout << root->data << " ";
    preordersearch(root->left);
    preordersearch(root->right);
}
