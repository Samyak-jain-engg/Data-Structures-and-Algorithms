#include<iostream>
#include"server.h"

using std::cout;
using std::endl;

int main(void)
{
    priorityQueue obj;

    obj.Enqueue(20);
    obj.Enqueue(30);
    obj.Enqueue(80);
    obj.Enqueue(50);
    obj.Enqueue(55);
    obj.Enqueue(60);

    cout<<"Old Priority Queue"<<endl;
    obj.Display();

    obj.Dequeue();

    cout<<"After Dequeue The largest element"<<endl;
    obj.Display();

    return 0;
}