#include "insert_sort.h"

int main(void)
{
    int data ;
    int cnt ;

    linkObject *head,*p ;
    head = (linkObject*)malloc(sizeof(linkObject));
    head->next = NULL;
    scanf("%d",&cnt);

    for(int i=0;i<cnt;i++)
    {
        scanf("%d",&data);
        p = (linkObject*)malloc(sizeof(linkObject));
        p->next = head->next;
        p->info = data;
        head->next = p ;
    }
    printf("the result of linkSort:\n");
    listSort(head);



}