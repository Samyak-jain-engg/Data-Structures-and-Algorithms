#include<iostream>
#include"server.h"

using std ::cout;
using std ::endl;

int main(void)
{
    Queue que;

    que.Display();
    que.EnQueue(10);
    que.EnQueue(20);
    que.EnQueue(30);
    que.EnQueue(40);

    que.CountNode();

    que.Display();
    cout<<"Dequeue :-"<<que.DeQueue()<<endl;
    cout<<"Dequeue :-"<<que.DeQueue()<<endl;
    cout<<"Dequeue :-"<<que.DeQueue()<<endl;
    

    que.Display();
    que.EnQueue(50);

    que.Display();

    return 0;

}