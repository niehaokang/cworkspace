/*************************************************************************
	> File Name: list.c
	> Author: Datou_Nie
	> Mail: niehaokang@gmail.com
	> Created Time: 2017年07月06日 星期四 15时41分16秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
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

struct listnode *partition( struct listnode *begin, struct listnode *end ); 

void quicksortlist( struct listnode *head, struct listnode* end );

struct listnode * mergelist( struct listnode *ahead, struct listnode *bhead );

int judgering(struct listnode *head);

struct listnode * myjudgering(struct listnode *head);

void constructurering(struct listnode *head);

struct listnode * findbackward(struct listnode *head, int k);

void reverselist(struct listnode **head);

void reverseprint_nonrecursion(struct listnode * head);

void reverseprint(struct listnode * head);

void deletenode( struct listnode **head, int k );

struct listnode * firstcommonnode(struct listnode * ln1, struct listnode *ln2);

struct listnode * deleteduplication( struct listnode * head );

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

static void swap( struct listnode * node1, struct listnode * node2 )
{
    DATATYPE temp;
    temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

/* qsort partition function */
/*
struct listnode *partition( struct listnode *begin, struct listnode *end )
{
    if( begin == NULL )
    {
        printf("bad input...\n");
        exit(-1);
    }
    DATATYPE temp, key = begin->data;
    struct listnode *small = begin;
    struct listnode *index = begin->next;
    while( index != end)
    {
        if( index->data < key )
        {
            small = small->next;
            if( small != index )
                swap( small, index );
        }
        index = index->next;
    }
    swap( begin, small );
    return small;
}
*/
struct listnode * partition( struct listnode *begin, struct listnode* end )
{
    struct listnode *small = begin;
    struct listnode *index = begin->next;
    DATATYPE key = begin->data;
    while( index != end )
    {
        if( index->data < key )
        {
            small = small->next;
            if( small != index )
                swap(small, index);
        }
        index = index->next;
    }
    swap( begin, small );
    return small;
}

/* quick sort for list */
void quicksortlist( struct listnode *head, struct listnode *end )
{
    if( head == NULL )
        return;
    if( head != end )
    {
        struct listnode * index = partition( head, end );
        quicksortlist( head, index );
        quicksortlist( index->next, end);
    }
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

/* delete node in consta time */
void deletenodeinconsttime(struct listnode **head, struct listnode *nodetodelete)
{
    if( !head || !nodetodelete )
        return;
    struct listnode *temp = NULL;
    if( nodetodelete->next != NULL )
    {
        nodetodelete->data = nodetodelete->next->data;
        temp = nodetodelete->next;
        nodetodelete->next = temp->next; 
        free(temp);
    }
    else if( *head == nodetodelete )
    {
        free(nodetodelete);
        nodetodelete = NULL;
        *head = NULL;
    }
    else
    {
        temp = *head;
        while( temp->next != nodetodelete )
            temp = temp->next;
        temp->next = NULL;
        free(nodetodelete);
    }
}

/* delete first node which value equal k */
void deletenode( struct listnode **head, int k )
{
    if( head == NULL || *head == NULL )
        return;
    struct listnode *nodetodelete = NULL, *ptrace = *head;;
    if( (*head)->data == k )
    {
        nodetodelete = *head;
        *head = (*head)->next;
    }
    else
    {
        while( ptrace->next != NULL && ptrace->next->data != k )
            ptrace = ptrace->next;
        if( ptrace->next != NULL && ptrace->next->data == k)
        {
            nodetodelete = ptrace->next;
            ptrace->next = ptrace->next->next;
        }
    }
    if( nodetodelete != NULL )
    {
        free(nodetodelete);
        nodetodelete = NULL;
    }
}

/* reverse output all element of list */
void reverseprint(struct listnode * head)
{
    if(head == NULL)
        return;
    reverseprint(head->next);
    printf("%d ", head->data);
}

/* reverse output all element of list */
void reverseprint_nonrecursion(struct listnode * head)
{
    if(head == NULL)
        return;
    struct listnode * liststack[20];
    struct listnode *temp = head;
    int top = 0;
    while( temp != NULL )
    {
        liststack[top++] = temp;
        temp = temp->next;
    }
    while( top > 0 )
    {
        temp = liststack[--top];
        printf("%d ", temp->data);
    }
    printf("\n");
}

/* find and return first common node of list ln1 and list ln2 */
struct listnode * firstcommonnode(struct listnode * ln1, struct listnode *ln2)
{
    if( ln1 == NULL || ln2 == NULL )
        return NULL;
    struct listnode *first = ln1, *second = ln2;
    int lenln1 = 0, lenln2 = 0;
    int diff;
    /* compulate length of two list */
    while(first != NULL)
    {
        first = first->next;
        lenln1++;
    }
    while(second != NULL)
    {
        second = second->next;
        lenln2++;
    }
    /* compulate diff of two list length, longer move diff step firs */
    if( lenln1 >= lenln2 )
    {
        diff = lenln1 - lenln2;
        first = ln1;
        second = ln2;
    }
    else
    {
        diff = lenln2 - lenln1;
        first = ln2;
        second = ln1;
    }
    while( diff > 0)
    {
        first = first->next;
        diff--;
    }
    /* search firs common node */
    while( first != '\0' && second != '\0' )
    {
        if( first == second )
            return first;
        else
        {
            first = first->next;
            second = second->next;
        }
    }
    return NULL;
}

struct listnode * deleteduplication( struct listnode * head )
{
    if ( head == NULL )
        return NULL;
    struct listnode *root = head;
    struct listnode * p = root;
    struct listnode *nodetodelete = NULL;
    while( p != NULL )
    {
        if( p->next->data == p->data )
        {
            nodetodelete = p->next;
            p->next = p->next->next;
            free(nodetodelete);
        }
        else
            p = p->next;
    }
    return root;
}

int compare( const void *a, const void *b )
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int a[20] = { 1, 3, 5, 7, 9, 11, 11, 11 };
    int b[10] = { 0, 0, 0, 0, 2, 4, 6, 8 };
    int c[20] = { 1, 9, 3, 8, 5, 4, 6, 7, 2, 0 };
    int r[20];
    srand( time(NULL) );
    int i;
    for( i = 0; i < 20; i++ )
        r[i] = rand() % 20;
    struct listnode *ahead = creatlist(a, 8);
    struct listnode *bhead = creatlist(b, 8);
    struct listnode *chead = creatlist(c, 10);
    struct listnode *dhead = NULL;
    struct listnode *rhead = creatlist(r, 20);
    struct listnode *temp = NULL;
    printf("list a: ");
    print(ahead);
    deletenode(&ahead, 11);
    printf("after delete first 11: ");
    print(ahead);
    printf("list b: ");
    print(bhead);
    printf("add 20 to the tail of list a: ");
    addtail(&ahead, 20);
    print(ahead);
    printf("add 10 to the tail of list c: ");
    addtail(&chead, 10);
    print(chead);
    printf("qsort list c: ");
    quicksortlist( chead, NULL );
    print(chead);
    printf("sort list c: ");
    insertsortlist(&chead);
    chead = selectsortlist(chead);
    print(chead);
    for( i = 0; i < 20; i++ )
        printf("%d ", r[i]);
    printf("\n");
    qsort( r, 20, sizeof(int), compare );
    for( i = 0; i < 20; i++ )
        printf("%d ", r[i]);
    printf("\n");
    print(rhead);
    quicksortlist( rhead, NULL );
    print(rhead);
    /*
    printf("merge list a and list b to list d: ");
    dhead = mergelist(ahead, bhead);
    print(dhead);

    temp = dhead;
    while( temp->next != NULL )
        temp = temp->next;
    deletenodeinconsttime( &dhead, temp ); 
    print(dhead);

    printf("first common node's value of list a and list b: %d\n", firstcommonnode(ahead, bhead)->data);
    temp = findbackward(dhead, 3);
    if(temp != NULL)
        printf("the 3th value is %d in the backwards\n", temp->data);
    reverselist(&dhead);
    printf("after reverse of list d: ");
    print(dhead);
    printf("reverse output list d: ");
    reverseprint(dhead);
    printf("\nreverse with non-recurision output list d: ");
    reverseprint_nonrecursion(dhead);
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
    */
    return 0;
}
