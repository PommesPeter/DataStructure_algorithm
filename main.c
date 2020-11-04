#include "rlink_list.h"
//6 5 2 1 2 2 7 2
int main()
{
    struct node *head = createRlist();
    int num, data;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &data);
        insertOrder(head, data);
    }
    printRlist(head);
    scanf("%d", &data);
    printf("\n%d ", deleteData(head, data));

    printf("\n%d ", destroyRlist(head));

    return 0;
}