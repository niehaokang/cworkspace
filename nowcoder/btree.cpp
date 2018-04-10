/*************************************************************************
	> File Name: btree.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月11日 星期一 11时32分20秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

struct btree
{
    int val;
    struct btree *left;
    struct btree *right;
};

struct btree * createbtree(int * a, int length)
{
    if( a == NULL || length == 0 )
        return NULL;
    struct btree * btreearray[length];
    int i = 0;
    for( i = 0; i < length; i++ )
    {
        btreearray[i] = new struct btree;
        btreearray[i]->val = a[i];
    }
    for( i = 0; i < length; i++ )
    {
        if( 2 * i + 2 < length )
        {
            btreearray[i]->left = btreearray[2 * i + 1];
            btreearray[i]->right = btreearray[2 * i + 2];
        }
        else if( 2 * i + 1 < length )
        {
            btreearray[i]->left = btreearray[2 * i + 1];
            btreearray[i]->right = NULL;
        }
        else
        {
            btreearray[i]->left = NULL;
            btreearray[i]->right = NULL;
        }
    }
    return btreearray[0];
}

void preorder( struct btree * root )
{
    if(root == NULL)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder( struct btree * root )
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder( struct btree * root )
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void preorder_nonrecursion( struct btree *root )
{
    if( root == NULL )
        return;
    struct btree * temp = root;
    stack<struct btree *> btstack;
    while( temp != NULL || !btstack.empty()  )
    {
        while( temp != NULL )
        {
            cout << temp->val << " ";
            btstack.push(temp);
            temp = temp->left;
        }
        if( !btstack.empty() )
        {
            temp = btstack.top();
            btstack.pop();
            temp = temp->right;
        }
    }
}

void inorder_nonrecursion( struct btree *root )
{
    if( root == NULL )
        return;
    struct btree * temp = root;
    stack<struct btree *> btstack;
    while( temp != NULL || !btstack.empty()  )
    {
        while( temp != NULL )
        {
            btstack.push(temp);
            temp = temp->left;
        }
        if( !btstack.empty() )
        {
            temp = btstack.top();
            btstack.pop();
            cout << temp->val << " ";
            temp = temp->right;
        }
    }
}

void postorder_nonrecursion( struct btree *root )
{
    if(root == NULL)
        return;
    stack<struct btree *> btstack;
    btstack.push(root);
    struct btree *temp = root;
    struct btree *lastnode = NULL;
    while( !btstack.empty() )
    {
        temp = btstack.top();
        if( (temp->left == NULL && temp->right == NULL) || ( lastnode != NULL && ( lastnode == temp->right || lastnode == temp->right ) ) )
        {
            cout << temp->val << " ";
            btstack.pop();
            lastnode = temp;
        }
        else
        {
            if(temp->right != NULL)
                btstack.push(temp->right);
            if(temp->left!= NULL)
                btstack.push(temp->left);
        }
    }
}

int main()
{
    int b[15] = { 10, 6, 14, 4, 8, 12, 16, 3, 5, 7, 9, 11, 13, 15, 17  };
    struct btree * root = createbtree(b, 15);
    preorder(root);
    cout << endl;
    preorder_nonrecursion(root);
    cout << endl;
    inorder(root);
    cout << endl;
    inorder_nonrecursion(root);
    cout << endl;
    postorder(root);
    cout << endl;
    postorder_nonrecursion(root);
    return 0;
}
