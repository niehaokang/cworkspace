/*************************************************************************
	> File Name: tree.cpp
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年09月 2日 16:02:14
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
struct file
{
    string name;
    int parent;
    struct file *next;
    struct file *child;
}file;

void print( struct file * root)
{
    while( root != NULL)
    {
        cout << root->name << endl;
        print(root->child);
        root = root->next;
    }
}

int main()
{
    int n;
    while( cin >> n)
    {
        struct file f[n];
        for( int i = 0; i < n; i++)
        {
            cin >> f[i].name >> f[i].parent;
            f[i].next = NULL;
            f[i].child = NULL;
        }
        for( int i = 0; i < n; i++)
        {
            if(f[i].parent != -1)
            {
                if(f[f[i].parent].child == NULL)
                    f[f[i].parent].child= &f[i];
                else
                {
                    struct file *temp = f[f[i].parent].child; 
                    if(strcmp(temp->name.c_str(), f[i].name.c_str()) > 0)
                    {
                        f[i].next = temp;
                        f[f[i].parent].child = &f[i];
                    }
                    else
                    {
                        struct file *pretemp = temp; 
                        temp = temp->next;
                        while( temp != NULL)
                        {
                            if(strcmp(temp->name.c_str(), f[i].name.c_str()) > 0)
                            {
                                pretemp->next = &f[i];
                                f[i].next = temp;
                                break;
                            }
                                temp = temp->next;
                        }
                        if(temp == NULL)
                            pretemp->next = &f[i];
                            f[i].next = temp;
                    }
                }
            }
        }
        print(&f[0]);
    }
    return 0;
}
