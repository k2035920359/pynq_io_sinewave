#include <iostream>
#include "pokemon.h"

using namespace std;

int main()
{
    struct Pokemon p1,p2;
 
    InputData(&p1);
    InputData(&p2);

    ShowInfo(p1);
    ShowInfo(p2);
    system("PAUSE");
 
    return 0;
}
