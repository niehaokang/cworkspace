/*************************************************************************
	> File Name: complexlistnode.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月23日 星期日 11时10分16秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#define DATATYEP char
using namespace std;

struct complexlistnode
{
    DATATYEP data;
    struct complexlistnode *next;
    struct complexlistnode *sibling;
};

struct complexlistnode * creat( DATATYEP *s );

void print( struct complexlistnode *head );

void clone( struct complexlistnode * head );

void connectsibling( struct complexlistnode * head );

struct complexlistnode * disconnect( struct complexlistnode * head );

int main()
{
    char s[6] = { 'A', 'B', 'C', 'D', 'E' };
    struct complexlistnode *head = NULL, *head1 = NULL;
    head = creat( s );
    print(head);
    clone(head);
    print(head);
    connectsibling(head);
    print(head);
    head1 = disconnect(head);
    print(head);
    print(head1);
    return 0;
}

void print( struct complexlistnode *head )
{
    struct complexlistnode *temp = head;
    while( temp != NULL )
    {
        cout << temp->data << " ";
        if( temp->sibling != NULL )
            cout << temp->sibling->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

struct complexlistnode * creat( DATATYEP *s )
{
    if( s == NULL )
        return NULL;
    struct complexlistnode *pre, *temp, *head = NULL;
    int i;
    int len = strlen(s);
    for( i = len - 1; i >= 0; --i )
    {
        pre = new complexlistnode;
        pre->data = s[i];
        pre->sibling = NULL;
        if( i == len - 1 )
            pre->next = NULL;
        else
            pre->next = temp;
        temp = pre;
    }
    head = temp;
    while( temp != NULL )
    {
        if( temp->data == 'A' )
            temp->sibling = temp->next->next;
        if( temp->data == 'B' )
        {
            temp->sibling = temp->next->next->next;
            temp->next->next->sibling = temp;
        }
        temp = temp->next;
    }
    return head;
}

void clone( struct complexlistnode * head )
{
    if( head == NULL )
        return;
    struct complexlistnode *clone, *temp = head;
    while( temp != NULL )
    {
        clone = new complexlistnode;
        clone->data = temp->data;
        clone->next = temp->next;
        clone->sibling = NULL;
        temp->next = clone;
        temp = clone->next;
    }
}

void connectsibling( struct complexlistnode * head )
{
    if( head == NULL )
        return;
    struct complexlistnode *pre = head, *p = NULL;
    while( pre != NULL )
    {
        p = pre->next;
        if( pre->sibling != NULL )
            p->sibling = pre->sibling->next;
        pre = p->next;
    }
}

struct complexlistnode * disconnect( struct complexlistnode * head )
{
    if( head == NULL )
        return NULL;
    struct complexlistnode *original = head, *copy = head->next;
    struct complexlistnode * head1 = head->next;
    while( original != NULL )
    {
        original->next = copy->next;
        original = original->next;
        if( original == NULL )
            break;
        copy->next = original->next;
        copy = copy->next;
    }
    return head1;
}
