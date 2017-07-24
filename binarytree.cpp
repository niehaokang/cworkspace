/*************************************************************************
	> File Name: binarytree.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月13日 星期四 09时36分03秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<cstdio>
#define DATATYPE int

using namespace std;

struct btree{
    DATATYPE data;
    btree * left;
    btree * right;
}btree;

struct btree * createbtree(DATATYPE * a, int length);

void preordertraver( struct btree * root );

void inordertraver( struct btree * root );

void postordertraver( struct btree * root );

void preordertraver_nonrecursion( struct btree * root );

void inordertraver_nonrecursion( struct btree * root );

void postordertraver_nonrecursion( struct btree * root );

void leveltraver( struct btree * root );

void reversebtree( struct btree * root );

void reversebtree_queue( struct btree * root );

void reversebtree_stack( struct btree * root );

struct btree * searchbtree( struct btree * root, DATATYPE value );

int depthofbtree( struct btree * root );

int countbtree( struct btree * root );

bool isequal( struct btree * bt1, struct btree * bt2 );

bool issubbtree( struct btree * bt1, struct btree * bt2 );

bool findpath( struct btree * root, struct btree * node, list<struct btree *> &btreelist);

bool findpath_nonrecursion( struct btree * root, struct btree * node, vector<struct btree *> &path );

struct btree * firstcommonparent(struct btree * root, struct btree * n1, struct btree * n2);

void findpathequalk( struct btree * root, DATATYPE value, vector<struct btree *> &path );

static struct btree * constructcore(
    DATATYPE startpreorder, DATATYPE endpreorder,
    DATATYPE startinorder, DATATYPE endinorder);

bool ispostorderofbstree( DATATYPE sequence[], int length );

struct btree * construct( DATATYPE * preorder, DATATYPE * inorder, int length );

struct btree * bstreetolist( struct btree * root );

int main()
{
    int a[7] = { 10, 6, 14, 4, 8, 12, 16 };
    int b[15] = { 10, 6, 14, 4, 8, 12, 16, 3, 5, 7, 9, 11, 13, 15, 17 };
    int c[5] = {14, 12, 16, 11, 13};
    int preorder[] = {10, 6, 4, 8, 14, 12, 16};
    int inorder[] = {4, 6, 8, 10, 12, 14, 16};
    int postorder[] = { 4, 8, 6, 12, 16, 14, 10 };
    struct btree * root = createbtree( a, 7 );
    struct btree * rootcpy = createbtree( a, 7 );
    struct btree * Root = createbtree( b, 15 );
    struct btree * subRoot = createbtree( c, 5 );
    struct btree * prein = construct(preorder, inorder, 7);
    cout << "ispostorderofbstree ? " << ispostorderofbstree(postorder, 7) << endl;
    cout << "inordertraver: ";
    inordertraver( prein );
    cout << endl;
    cout << "preordertraver: ";
    preordertraver(root);
    cout << endl;
    cout << "inordertraver: ";
    inordertraver(root);
    cout << endl;
    cout << "postordertraver: ";
    postordertraver(root);
    cout << endl;
    cout << "preordertraver_nonrecursion: ";
    preordertraver_nonrecursion(root);
    cout << "inordertraver_nonrecursion: ";
    inordertraver_nonrecursion(root);
    cout << "postordertraver_nonrecursion: ";
    postordertraver_nonrecursion(root);
    cout << "leveltraver: ";
    leveltraver(root);
    cout <<"\nafter reversebtree\n";
    reversebtree( root );
    cout <<"inordertraver:";
    inordertraver_nonrecursion(root);
    cout << "after second reversebtree with queue: ";
    reversebtree_queue(root);
    inordertraver_nonrecursion(root);
    cout << endl <<  "root == Root ?: " << isequal( root, Root ) << endl;
    cout << "root is subbtree of Root ?: " << issubbtree( Root, root ) << endl;
    cout << "after third reversebtree with stack: ";
    reversebtree_stack(root);
    inordertraver_nonrecursion(root);
    int n = 15;
    struct btree * temp = NULL;
    temp = searchbtree( root, n );
    if(temp != NULL)
        cout << "node addr = " << temp << ", node value = " << temp->data << endl;
    else
        cout << "not find value: " << n << endl;
    cout << "depth of btree: " << depthofbtree( root ) << endl;
    cout << "total node of btree is: " << countbtree(root) << endl;
    cout << "inorder traver of Root: ";
    inordertraver(Root);
    cout << endl <<  "root == root ?: " << isequal( root, root ) << endl;
    rootcpy->left->left->data = 2;
    cout << endl <<  "root == rootcpy ?: " << isequal( root, rootcpy ) << endl;
    cout << "root is subbtree of NULL ?: " << issubbtree( NULL, root ) << endl;
    cout << "NULL is subbtree of Root ?: " << issubbtree( Root, NULL ) << endl;
    cout << "rootcpy is subbtree of Root ?: " << issubbtree( Root, root ) << endl;
    cout << "rootcpy is subbtree of Root ?: " << issubbtree( Root, rootcpy ) << endl;
    inordertraver(subRoot);
    cout << endl;
    inordertraver(Root);
    cout << endl;
    cout << "subRoot is subbtree of Root ?: " << issubbtree( Root, subRoot) << endl;
    list<struct btree *> path;
    cout << findpath( Root, Root->right->left->right, path) << endl; 
    cout << path.back()->data<< endl;
    list<struct btree *>::iterator it;
    for( it = path.begin(); it != path.end(); it++ )
        cout << (*it)->data << " ";
    cout << endl;
    cout << firstcommonparent(Root, Root->right->left->right, Root->left->left->right)->data << endl;
    cout << firstcommonparent(Root, Root->right->left->right, Root->right->left->left)->data << endl;
    cout << firstcommonparent(Root, Root->left->left->right, Root->right->left->left)->data << endl;
    vector<struct btree *> kpath;
    findpathequalk(Root, 57, kpath);
    struct btree * head = bstreetolist( Root );
    while( head->right != NULL )
    {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
    return 0;
}

static struct btree * constructcore(
    DATATYPE *startpreorder, DATATYPE *endpreorder,
    DATATYPE *startinorder, DATATYPE *endinorder )
{
    int len = 0;
    int val = startpreorder[0];
    DATATYPE *p = startinorder;
    struct btree * root = new struct btree;
    root->data = val;
    root->left = NULL;
    root->right = NULL;
    if( startpreorder == endpreorder )
    {
        if( startinorder == endinorder && *startinorder == *endinorder)
            return root;
        else
            cout << "bad input...\n";
    }

    while( p <= endinorder && *p != val ) p++;
    if( p == endinorder && *p != val )
        cout << "bad input...\n";
    len = p - startinorder;
    if( len > 0 )
        root->left = constructcore(startpreorder + 1, startpreorder + len, startinorder, p - 1);
    if( p < endinorder )
        root->right = constructcore(startpreorder + len + 1, endpreorder, p + 1, endinorder);
    return root;
}

struct btree * construct( DATATYPE * preorder, DATATYPE * inorder, int length )
{
    if( preorder == NULL || inorder == NULL || length <= 0 )
        return NULL;
    return( constructcore(preorder, preorder + length - 1, inorder,  inorder + length - 1) );
}

struct btree * createbtree(DATATYPE * a, int length)
{
    if( a == NULL || length == 0 )
        return NULL;
    struct btree * btreearray[length];
    int i = 0;
    for( i = 0; i < length; i++ )
    {
        btreearray[i] = new struct btree;
        btreearray[i]->data = a[i];
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

void preordertraver( struct btree * root )
{
    if( root == NULL )
        return;
    printf("%d ", root->data);
    preordertraver(root->left);
    preordertraver(root->right);
}

void inordertraver( struct btree * root )
{
    if( root == NULL )
        return;
    inordertraver(root->left);
    printf("%d ", root->data);
    inordertraver(root->right);
}

void postordertraver( struct btree * root )
{
    if( root == NULL )
        return;
    postordertraver(root->left);
    postordertraver(root->right);
    printf("%d ", root->data);
}

/*
void preordertraver_nonrecursion( struct btree * root )
{
    if(root == NULL)
        return;
    stack<struct btree *> btstack;
    struct btree *temp = root;
    btstack.push(temp);
    while( !btstack.empty() )
    {
        temp = btstack.top();
        btstack.pop();
        cout << temp->data << " "; 
        if( temp->right != NULL )
            btstack.push(temp->right);
        if( temp->left != NULL )
            btstack.push(temp->left);
    }
    cout << endl;
}
*/

void preordertraver_nonrecursion( struct btree * root )
{
    if( root == NULL )
        return;
    stack<struct btree *> btstack;
    struct btree * temp = root;
    while( temp != NULL || !btstack.empty() )
    {
        while( temp != NULL )
        {
            cout << temp->data << " ";
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
    cout << endl;
}

void inordertraver_nonrecursion( struct btree * root )
{
    if(root == NULL)
        return;
    stack<struct btree *> btstack;
    struct btree *temp = root;
    while( temp != NULL || !btstack.empty() )
    {
        while( temp != NULL )
        {
            btstack.push(temp);
            temp = temp->left;
        }
        if(!btstack.empty())
        {
            temp = btstack.top();
            btstack.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
    cout << endl;
}

void postordertraver_nonrecursion( struct btree * root )
{
    if( root == NULL )
        return;
    stack<struct btree *> btreestack;
    struct btree *lastnode = NULL, * temp = root;
    btreestack.push(root);
    while( !btreestack.empty() )
    {
        temp = btreestack.top();
        if( ( temp->left == NULL && temp->right == NULL ) || (lastnode != NULL && (lastnode == temp->left || lastnode == temp->right)) )
        {
            printf("%d ", temp->data);
            btreestack.pop();
            lastnode = temp;
        }
        else
        {
            if( temp->right != NULL )
                btreestack.push(temp->right);
            if( temp->left != NULL )
                btreestack.push(temp->left);
        }
    }
    cout << endl;
}

void leveltraver(struct btree * root)
{
    if( root == NULL )
        return;
    queue< struct btree *> btreequeue;
    struct btree * temp;
    btreequeue.push(root);
    while( !btreequeue.empty())
    {
        temp = btreequeue.front();
        cout << temp->data << " ";
        btreequeue.pop();
        if( temp->left != NULL )
            btreequeue.push( temp->left );
        if( temp->right!= NULL )
            btreequeue.push( temp->right);
    }
    cout << endl;
}

void reversebtree( struct btree * root )
{
    if( root == NULL )
        return;
    if(!(root->left == NULL && root->right == NULL))
    {
        struct btree * temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        if( root->right!= NULL )
            reversebtree(root->right);
        if( root->left != NULL )
            reversebtree(root->left);
    }
}

void reversebtree_queue( struct btree * root )
{
    if( root == NULL )
        return;
    queue<struct btree *> btreequeue;
    struct btree * temp, *front;
    btreequeue.push(root);
    while(!btreequeue.empty())
    {
        front = btreequeue.front();
        btreequeue.pop();
        temp = front->left;
        front->left = front->right;
        front->right = temp;
        if( front->right != NULL )
            btreequeue.push(front->right);
        if( front->left!= NULL )
            btreequeue.push(front->left);
    }
}

void reversebtree_stack( struct btree * root )
{
    if( root == NULL )
        return;
    stack<struct btree *> btreestack;
    struct btree *temp = NULL, *top = NULL;
    btreestack.push(root);
    while( !btreestack.empty() )
    {
        top = btreestack.top();
        btreestack.pop();
        temp = top->left;
        top->left = top->right;
        top->right = temp;
        if( top->right != NULL )
            btreestack.push(top->right);
        if( top->left!= NULL )
            btreestack.push(top->left);
    }
}

struct btree * searchbtree( struct btree * root, DATATYPE value )
{
    if( root == NULL )
        return NULL;
    struct btree * temp;
    if( root->data == value )
        return root;
    else
    {
        temp = searchbtree(root->left, value);
        if( temp != NULL )
            return searchbtree(root->left, value);
        else
            return searchbtree(root->right, value);
    }
}

int depthofbtree( struct btree * root )
{
    if( root == NULL )
        return 0;
    int left = 0, right = 0;
    left = depthofbtree( root->left );
    right = depthofbtree( root->right);
    return (left>right?left:right) + 1;
}

int countbtree( struct btree * root )
{
    if( root == NULL )
        return 0;
    return (countbtree(root->left) + countbtree(root->right) + 1);
}

bool isequal( struct btree * bt1, struct btree * bt2 )
{
    if( bt1 == NULL && bt2 == NULL )
        return true;
    else if(( bt1 == NULL && bt2 != NULL ) || (bt1 != NULL && bt2 == NULL))
        return false;
    if( bt1->data == bt2->data )
        return (isequal(bt1->left, bt2->left) && isequal(bt1->right, bt2->right));
    return false;
}

static bool subbtree( struct btree * bt1, struct btree * bt2 )
{
    if( bt2 == NULL )
        return true;
    else if( bt1 == NULL )
        return false;
    else if( bt1->data == bt2->data )
        return ( subbtree(bt1->left, bt2->left) && subbtree(bt1->right, bt2->right) );
    return false;
}

bool issubbtree( struct btree * bt1, struct btree * bt2 )
{
    if( bt2 == NULL )
        return true;
    else if( bt1 == NULL )
        return false;
    struct btree * temp = bt1;
    if( subbtree(temp, bt2) )
        return true;
    return( issubbtree(temp->left, bt2) || issubbtree(temp->right, bt2) );
}

bool findpath( struct btree * root, struct btree * node, list<struct btree *> &path)
{
    if( root == NULL || node == NULL)
        return false;
    if( root == node )
        return true;
    path.push_back(root);
    if( !findpath(root->left, node, path) && !findpath(root->right, node, path) )
    {
        path.pop_back();
        return false;
    }
    return true;
}

void findpathequalk( struct btree * root, DATATYPE value, vector<struct btree *> &path )
{
    path.push_back(root);
    bool isleaf = ( root->left == NULL && root->right == NULL );
    if( isleaf && root->data == value )
    {
        cout << "a path is found: ";
        vector<struct btree *>::iterator it = path.begin();;
        for( ; it != path.end(); ++it )
            cout << (*it)->data << " ";
        cout << endl;
    }
    else
    {
        if( root->left != NULL )
            findpathequalk( root->left, value - root->data, path );
        if( root->right != NULL )
            findpathequalk( root->right, value - root->data, path );
        
    }
    path.pop_back();
}

struct btree * firstcommonparent(struct btree * root, struct btree * n1, struct btree * n2)
{
    if( root == NULL || n1 == NULL || n2 == NULL )
        return NULL;
    list<struct btree *>path1;
    list<struct btree *>path2;
    findpath(root, n1, path1);
    findpath(root, n2, path2);
    list<struct btree *>::iterator it1 = path1.begin(), it2 = path2.begin();
    struct btree * firstparent;
    while( it1 != path1.end() && it2 != path2.end() )
    {
        if( *it1 == *it2)
        {
            firstparent = *it1;
            it1++;
            it2++;
        }
        else
            break;
    }
    return firstparent;
}

bool ispostorderofbstree( DATATYPE sequence[], int length )
{
    if( length == 0 || sequence == NULL )
        return false;
    int root = sequence[length - 1];
    int i = 0, j = 0;
    for( i = 0; i < length - 1; i++ )
        if( sequence[i] > root )
            break;
    for( j = i; j < length - 1; j++ )
        if( sequence[j] < root )
            return false;
    if( i > 0 )
        bool left = ispostorderofbstree( sequence, i );
    if( i < length )
        bool right = ispostorderofbstree( sequence + i, length - i - 1 );
    return ( left && right );
}

static void convert( struct btree * root, struct btree ** lastnodeinlist )
{
    if( root == NULL )
        return;
    if( root->left != NULL )
        convert( root->left, lastnodeinlist );
    root->left = (*lastnodeinlist);
    if( *lastnodeinlist != NULL )
        (*lastnodeinlist)->right = root;
    (*lastnodeinlist) = root;
    if( root->right != NULL )
        convert( root->right, lastnodeinlist );
}

struct btree * bstreetolist( struct btree * root )
{
    if( root == NULL )
        return NULL;
    struct btree *lastnodeinlist = NULL;
    convert( root, &lastnodeinlist );
    struct btree *head= lastnodeinlist;
    while( head != NULL && head->left != NULL )
        head = head->left;
    return head;
}
