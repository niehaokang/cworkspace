/*************************************************************************
	> File Name: list.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月06日 星期四 15时41分16秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#define DATATYPE int

struct listnode{
    DATATYPE data;
    struct listnode * next;
};

void print( struct listnode *head );

struct listnode * creatlist( DATATYPE * a, int len );

void addtail(struct listnode **head, int value);

void insertsortlist( struct listnode **head );

struct listnode * selectsortlist( struct listnode *head );

struct listnode * mergelist( struct listnode *ahead, struct listnode *bhead );

int judgering(struct listnode *head);

struct listnode * myjudgering(struct listnode *head);

void constructurering(struct listnode *head);

struct listnode * findbackward(struct listnode *head, int k);

void reverselist(struct listnode **head);

/* print list */
void print( struct listnode *head )
{
    if( head == NULL )
        return;
    struct listnode *ptrace = head;
    if(judgering(head))                 /* if list has a ring */
    {
        printf("%d ", ptrace->data);
        ptrace = ptrace->next;
        while( ptrace != head )
        {
            printf("%d ", ptrace->data);
            ptrace = ptrace->next;
        }
            
    }
    else                                /* if list has no ring */
    {
        while( ptrace != NULL )
        {
            printf("%d ", ptrace->data);
            ptrace = ptrace->next;
        }
    }
    printf("\n");
}

/* add element to list tail */
void addtail(struct listnode ** head, DATATYPE value)
{
    struct listnode *ptemp, *ptail;
    ptemp = ( struct listnode * ) malloc( sizeof(struct listnode) );
    ptemp->data = value;
    ptemp->next = NULL;
    if( *head == NULL )
        *head = ptemp;
    else
    {
        ptail = *head;
        while( (ptail->next) != NULL)
            ptail = ptail->next;
        ptail->next = ptemp;
    }
}

/* create list */
struct listnode * creatlist( DATATYPE * a, int len )
{
    if(len <= 0)
        return 0;
    int i;
    struct listnode * head = NULL;
    struct listnode *ptemp, *ptail; 
    for( i = 0; i < len; i++ )
    {
        ptemp = ( struct listnode *) malloc( sizeof(struct listnode) );
        ptemp->data = a[i];
        ptemp->next = NULL;
        if( head == NULL )
        {
            head = ptemp;
            ptail = ptemp;
        }
        else
        {
            ptail->next = ptemp;
            ptail = ptemp;
        }
    }
    return head;
}

/* insert sort for list */
void insertsortlist( struct listnode **head )
{
    if( *head == NULL || (*head)->next == NULL)
        return;
    struct listnode *temp;
    struct listnode *preindex, *index;
    struct listnode *preposition, *position;
    for( preindex = *head, index = (*head)->next; index != NULL; )
    {
        for( position = *head; position != index; preposition = position, position = position->next )
        {
            if(position->data >= index->data)       /* index->data is not bigest of current sort list */
            {
                temp = index;
                preindex->next = index->next;
                index = preindex->next;
                if( position == *head )
                {
                    temp->next = *head;
                    *head = temp;
                }
                else
                {
                    temp->next = position;
                    preposition->next = temp;
                }
                break;
            }
        }
        if(position == index)                       /* index->data is bigest of current sort list */
        {
            preindex = index;
            index = index->next;
        }
    }
}

/* select sort for list */
struct listnode * selectsortlist( struct listnode *head )
{
    if(head == NULL)
        return NULL;
    if( head->next == NULL )
        return head;
    struct listnode *tail;
    struct listnode *premin, *min, *p, *pre;
/* find minimum value of list */
    min = head;
    pre = head;
    p = head->next;
    while( p != NULL )
    {
        if(p->data < min->data)
        {
            min = p;
            premin = pre;
        }
        pre = p;
        p = p->next;
    }
    if( min != head )
    {
        premin->next = min->next;
        min->next = head;
        head = min;
    }
    tail = head;
/* core loop */ 
    while( tail->next != NULL )
    {
        for( min = tail->next, pre = min, p = min->next; p != NULL; pre = p, p = p->next  )
        {
            if( p->data < min->data )
            {
                min = p;
                premin = pre;
            }
        }
        if( min != tail->next ) /* if minimum value is tail->next-value */
        {
            premin->next = min->next;
            min->next =tail->next;
            tail->next = min;
        }
        tail = min;
    }
    return head;
}

/* merge two ordered list */
struct listnode * mergelist( struct listnode *ahead, struct listnode *bhead )
{
    if( ahead == NULL )
        return bhead;
    else if( bhead == NULL )
        return ahead;
    struct listnode *tail, *head =  NULL;
    struct listnode *atrace, *btrace; 
    if(ahead->data <= bhead->data)      /* if head value of a < b */
    {
        head = ahead;
        atrace = ahead->next;
        btrace = bhead;
    }
    else
    {
        head = bhead;
        btrace = bhead->next;
        atrace = ahead;
    }
    tail = head;
    while( atrace != NULL && btrace != NULL ) /* list a and list b all not NULL */
    {
        if(atrace->data <= btrace->data )
        {
            tail->next = atrace;
            tail = atrace;
            atrace = atrace->next;
        }
        else
        {
            tail->next = btrace;
            tail = btrace;
            btrace = btrace->next;
        }
    }
    tail->next = (atrace == NULL) ? btrace:atrace; /* add the not NULL list to the end */
    return head;
}

/* constructure ring list */
void constructurering(struct listnode *head)
{
    if(head == NULL)
        return;
    if(judgering(head) == 0)                /* if list has no ring, than constructure a ring */
    {
        struct listnode *p = head;
        while( p->next != NULL )
            p = p->next;
        p->next = head;
    }
}

/* use two pointer, the first one step per time, the second two steps per time */
int judgering(struct listnode *head)
{
    if(head == NULL)
        return 0;
    struct listnode *p, *q;
    p = q = head;
    while(p != NULL)                /* while ahead pointer is not NULL */
    {
        if(p->next != NULL)
            p = p->next;
        else
            return 0;
        if(p->next != NULL)         /* judge p is NULL or not per step */
            p = p->next;
        else
            return 0;
        q = q->next;
        if(p == q)
            return 1;
    }
}

/* find element in an array, 1 for find, 0 for not find */
static int find( unsigned long *a, int len, unsigned long addr)
{
    int i;
    if( len == 0 )
        return 0;
    for( i = 0; i < len; i++ )
        if( addr == a[i] )
            return 1;
    return 0;
}

/* my method of judge a list has ring or not,
 * storage addr of all traced element in an array,
 * until the end is NULL or current addr has appear
 * in the addr array, return 0 or addr of ring head addr */
struct listnode * myjudgering(struct listnode *head)
{
    if( head == NULL )
        return 0;
    unsigned long a[100];
    int i = 0;
    int num;
    struct listnode *p = head;
    while( p != NULL )
    {
        if(find( a, i, (unsigned long)p ) )     /* judge current addr is appear or not */
            return p;
        else
            a[i++] = (long)p;
        p = p->next;
    }
    return 0;
}

/* find the Kth element in the backwards */
struct listnode * findbackward(struct listnode *head, int k)
{
    if(head == NULL || k == 0)
        return NULL;
    if(judgering(head))
    {
        printf("list has a ring\n");
        return NULL;
    }
    struct listnode *behind = head, *ahead = head;
    while( k-- > 0 && ahead != NULL)        /* the ahead pointer go k-1 steps first */
        ahead = ahead->next;
    if(ahead == NULL)
        return NULL;
    else while(ahead != NULL)
    {
        ahead = ahead->next;
        behind = behind->next;
    }
    return behind;
}

/* reverse list use head insert method */
void reverselist(struct listnode **head)
{
    if( *head == NULL || (*head)->next == NULL)
        return;
    struct listnode *temp, *pre = *head, *tail = *head;
    while(tail->next != NULL)
    {
        temp = tail->next;
        tail->next = temp->next;
        (*head) = temp;
        temp->next = pre;
        pre = *head;
    }
}

int main()
{
    int a[20] = { 1, 3, 5, 7, 9, 11, 11, 11 };
    int b[10] = { 0, 0, 0, 0, 2, 4, 6, 8 };
    int c[20] = { 1, 9, 3, 8, 5, 4, 6, 7, 2, 0 };
    struct listnode *ahead = creatlist(a, 8);
    struct listnode *bhead = creatlist(b, 8);
    struct listnode *chead = creatlist(c, 10);
    struct listnode *dhead = NULL;
    struct listnode *temp = NULL;
    printf("list a: ");
    print(ahead);
    printf("list b: ");
    print(bhead);
    printf("add 20 to the tail of list a: ");
    addtail(&ahead, 20);
    print(ahead);
    printf("add 10 to the tail of list c: ");
    addtail(&chead, 10);
    print(chead);
    printf("sort list c: ");
    insertsortlist(&chead);
    chead = selectsortlist(chead);
    print(chead);
    printf("merge list a and list b to list d: ");
    dhead = mergelist(ahead, bhead);
    print(dhead);
    temp = findbackward(dhead, 3);
    if(temp != NULL)
        printf("the 3th value is %d in the backwards\n", temp->data);
    reverselist(&dhead);
    printf("after reverse of list d: ");
    print(dhead);
    temp = findbackward(dhead, 3);
    if(temp != NULL)
        printf("the 3th value is %d in the backwards\n", temp->data);
    printf("before constructurering of list c and list d: \n");
    printf("list c has ring ? %d\n", judgering(chead));
    printf("list d has ring ? %d\n", judgering(dhead));
    constructurering(chead);
    constructurering(dhead);
    printf("after constructurering of list c and list d: \n");
    printf("list c has ring ? %d\n", judgering(chead));
    printf("list d has ring ? %d\n", judgering(dhead));
    print(chead);
    print(dhead);
    printf("ring addr of list c = %p\n", myjudgering(chead));
    return 0;
}
