#include<iostream>
#include"server.h"


using std ::cout;
using std::cin;
using std::endl;

priorityQueue::priorityQueue()
{
    iCount = 0;
}

bool priorityQueue::IsFull()
{
    return iCount == MAX;

}

bool priorityQueue::IsEmpty()
{
    return iCount == 0;
}

void priorityQueue::Enqueue(int iNo)
{
    if(IsFull())
        {
            cout<<"Queue is full"<<endl;
            return;
        }

    arr[iCount] = iNo;
    iCount++;
    
}

void priorityQueue::Dequeue()
{
    if(IsEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }

    int iMaxIndex = 0;

    for(int index = 1; index < iCount;index++)
        {
            if(arr[index] > arr[iMaxIndex])
                iMaxIndex = index;
        }

    cout<<"Removed element is  :- "<<arr[iMaxIndex]<<endl;

    for(int index = iMaxIndex ; index < iCount-1;index++)
        arr[index] = arr[index+1];

    iCount--;

}

void priorityQueue ::Display()
{
    for(int iCounter =0 ;iCounter < iCount; iCounter++)
    {
        cout<<arr[iCounter]<<" "<<endl;
    }
}
