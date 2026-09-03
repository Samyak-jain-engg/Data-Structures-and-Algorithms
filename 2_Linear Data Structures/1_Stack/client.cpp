#include<iostream>
#include"server.h"

using std::cout;
using std::endl;

int main(void)
{
    int iPopData;

    list obj;

    obj.Push(10);
    obj.Push(20);
    obj.Push(30);
    obj.Push(40);

    obj.Display();

    iPopData = obj.Pop();

    if(iPopData != -1)
        cout << "Pop Data is " << iPopData << endl;

    obj.Display();

    return 0;
}