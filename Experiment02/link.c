#include "link_list.h"

int main(void)
{
    PNODE  polyAddLeft, polyAddRight ,polyAddResult ;

    polyAddLeft = createPoly();
    polyAddRight = createPoly();
//    printPoly(polyAddLeft);
//    printPoly(polyAddRight);

    polyAddResult = addPoly(polyAddLeft,polyAddRight);
    printPoly(polyAddResult);
    destroyPoly(polyAddLeft);
    destroyPoly(polyAddRight);
    destroyPoly(polyAddResult);

}