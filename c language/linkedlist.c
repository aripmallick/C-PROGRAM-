#include<stdio.h>
#include<stdlib.h>

struct slinklist
{
    int data;
    struct slinklist *next;
};
typedef struct slinklist node;
node *start = NULL;

int menu()
{
    int ch;
    printf("\n1. Create a list");
    printf("\n2. Count nodes");
    printf("\n3. Insert at beginning");
    printf("\n4. Insert at end");
    printf("\n5. Insert at middle");
    printf("\n6. View list");
    printf("\n7. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

node *getnode()
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    return newnode;
}

int countnode(node *ptr)
{
    int count = 0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void createlist(int n)
{
    node *newnode;
    node *temp;
    for(int i = 0; i < n; i++)
    {
        newnode = getnode();
        if(start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}

void insert_at_begining()
{
    node *newnode;
    newnode = getnode();
    if(start == NULL)
    {
        start = newnode;
    }
    else
    {
        newnode->next = start;
        start = newnode;
    }
}

void insert_at_end()
{
    node *newnode, *temp;
    newnode = getnode();
    if(start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void insert_at_mid()
{
    node *newnode, *temp, *prev;
    int pos,nodectr,ctr=1;
    newnode = getnode();
    printf("\n Enter the position : ");
    scanf("%d",&pos);
    nodectr = countnode(start);
    if(pos > 1 && pos < nodectr)
    {
        temp = prev = start;
        while(ctr < pos)
        {
            prev = temp;
            temp = temp->next;
            ctr++;
        }
        prev->next = newnode;
        newnode-> next = temp;
    }
    else
    {
        printf("\n Position %d is not a middle position",pos);
    }
}

void viewList(node *start)
{
    if(start==NULL)
    {
        printf("\n List empty");
    }
    else
    {
        while(start!=NULL)
        {
            printf("%d  ",start->data);
            start=start->next;
        }
    }
}

int main()
{
    int ch, n;
    while(1)
    {
        ch = menu();
        switch(ch)
        {
            case 1:
                printf("Enter How many nodes : ");
                scanf("%d", &n);
                createlist(n);
                break;
            case 2:
                printf("Total nodes: %d\n", countnode(start));
                break;
            case 3:
                insert_at_begining();
                break;
            case 4:
                insert_at_end();
                break;
            case 5:
                insert_at_mid();
                break;
            case 6:
                viewList(start);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}