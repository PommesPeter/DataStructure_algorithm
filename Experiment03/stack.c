//#include "stack_list.h"

//int main(void)
//{
//    char express[80];
//    gets(express);
//
////    printf("%d",calExp(express));
//}

#include "stack_list.h"

int main(void)
{
    char express[80];
    gets(express);
    // printf("%s",express);
    Stack s = inToPost(express);
    print(s);
}