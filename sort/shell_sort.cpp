#include "insert_sort.h"

int main(void)
{
    int cnt ;
    SortObject *p ;
    p = (SortObject*)malloc(sizeof(SortObject));
    linkObject *head ;
    head = (linkObject*)malloc(sizeof(linkObject));
    head->next = NULL;
    scanf("%d",&cnt);
    p->NUM = cnt ;
    p->data = (DataType*)malloc(sizeof(DataType)*cnt);

    for(int i=0;i<cnt;i++)
    {
        scanf("%d",&p->data[i]);

    }
    shellSort(p,cnt/2);



}