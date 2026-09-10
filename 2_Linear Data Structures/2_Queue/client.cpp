#include<iostream>
#include"Server.h"

using std ::cout;
using std ::endl;

int main(void)
{

    int iDeQueueData;

    Queue obj;

    obj.EnQueue(10);
    obj.EnQueue(20);
    obj.EnQueue(30);
    obj.EnQueue(40);

    obj.Display();

    iDeQueueData = obj.DeQueue();

    if(iDeQueueData != -1)
    {
        cout << "DeQueue Data is "
             << iDeQueueData << endl;
    }

    obj.Display();

    return 0;

    
}