#include<iostream>
#include"server.h"

using std::cout;
using std::endl;

int main(void)
{
    Deque obj;
    obj.InsertFrist(40);
    obj.InsertFrist(30);
    obj.InsertFrist(20);
    obj.InsertFrist(10);

    obj.Display();
    
    obj.InsertLast(50);
    obj.InsertLast(60);

    obj.Display();

    obj.DeleteFrist();

    obj.DeleteLast();

    obj.InsertFrist(60);

    obj.InsertLast(10);

    obj.Display();

    return 0;

}