/*************************************************************************
	> File Name: addTwoNumbers.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Mar 2017 07:39:32 PM CST
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode * next;
};

struct ListNode * creatList(int *a, int size)
{
    int i;
    struct ListNode *head = NULL, *p, *q;
    for( i = 0; i < size; i++ )
    {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        if(p == NULL)
        {
            printf("malloc error\n");
            exit(-1);
        }
        p->val = a[i];
        if(head == NULL)
        {
            head = p;
            q = p;
        } else 
        {
            q->next = p;
            q = p;
        }
        q->next = NULL;
    }
    return head;
}

void showList(struct ListNode * head)
{
    struct ListNode *p = head;
    while(p != NULL)
    {
        printf("p->val = %d ", p->val);
        p = p->next;
    }
    printf("\n");
}

void freeList(struct ListNode * head)
{
    struct ListNode *p, *q;
    if( head == NULL )
        return;
    p = head;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
}
#if 0
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int carry = 0, count;
    struct ListNode *p, *q, *r, *s;
    struct ListNode *head = NULL;
    p = l1;
    q = l2;
    while(p != NULL && q != NULL)
    {
        count = p->val + q->val + carry;
        carry = count/10;
        count = count%10;
        r = (struct ListNode *)malloc(sizeof(struct ListNode));
        if(r == NULL)
        {
            printf("malloc error\n");
            exit(-1);
        }
        r->val = count;
        if(head == NULL)
        {
            head = r;
            s = r;
        } else 
        {
            s->next = r;
            s = r;
        }
        s->next = NULL;
        p = p->next;
        q = q->next;
    }
    while(p != NULL)
    {
        count = p->val + carry;
        carry = count/10;
        count = count%10;
        r = (struct ListNode *)malloc(sizeof(struct ListNode));
        if(r == NULL)
        {
            printf("malloc error\n");
            exit(-1);
        }
        r->val = count;
        if(head == NULL)
        {
            head = r;
            s = r;
        } else 
        {
            s->next = r;
            s = r;
        }
        s->next = NULL;
        p = p->next;
    }
    while(q != NULL)
    {
        count = q->val + carry;
        carry = count/10;
        count = count%10;
        r = (struct ListNode *)malloc(sizeof(struct ListNode));
        if(r == NULL)
        {
            printf("malloc error\n");
            exit(-1);
        }
        r->val = count;
        if(head == NULL)
        {
            head = r;
            s = r;
        } else 
        {
            s->next = r;
            s = r;
        }
        s->next = NULL;
        q = q->next;
    }
    if( carry != 0 )
    {
        r = (struct ListNode *)malloc(sizeof(struct ListNode));
        if(r == NULL)
        {
            printf("malloc error\n");
            exit(-1);
        }
        r->val = carry;
        if(head == NULL)
        {
            head = r;
            s = r;
        } else 
        {
            s->next = r;
            s = r;
        }
        s->next = NULL;
    }
    return head;
}
#endif
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int carry = 0, count;
    struct ListNode *p, *q, *r, *s;
    struct ListNode *head = NULL;
    p = l1;
    q = l2;
    while(p != NULL || q != NULL)
    {
        count = 0;
        if(p != NULL)
        {
            count += p->val;
            p = p->next;
        }
        if(q != NULL)
        {
            count += q->val;
            q = q->next;
        }
        count = count + carry;
        carry = count/10;
        count = count%10;
        r = (struct ListNode *)malloc(sizeof(struct ListNode));
        if(r == NULL)
        {
            printf("malloc error\n");
            exit(-1);
        }
        r->val = count;
        if(head == NULL)
        {
            head = r;
            s = r;
        } else 
        {
            s->next = r;
            s = r;
        }
        s->next = NULL;
    }
    if( carry != 0 )
    {
        r = (struct ListNode *)malloc(sizeof(struct ListNode));
        if(r == NULL)
        {
            printf("malloc error\n");
            exit(-1);
        }
        r->val = carry;
        if(head == NULL)
        {
            head = r;
            s = r;
        } else 
        {
            s->next = r;
            s = r;
        }
        s->next = NULL;
    }
    return head;
}

int main()
{
    int a1[3] = {2, 4, 3};
    int a2[3] = {5, 6, 4};
    struct ListNode *head;
    struct ListNode *head1, *head2;
    head1 = creatList(a1, 3);
    head2 = creatList(a2, 3);
    head = addTwoNumbers(head1, head2);
    showList(head);
    showList(head1);
    showList(head2);
    freeList(head1);
    freeList(head2);
    return 0;
}
